#include "extension.h"

#ifdef _MSC_VER
// Declare before/after section locations
#pragma section(".format_loader$a", read)
#pragma section(".format_loader$z", read)

// Borrow some tricks from the MSVC CRT - store the start and finish
// addresses of the format_loader section in locations that are just
// before and just after the location containing the list of extension
// loader pointers. For the unwashed, PE will order locations alphabet-
// ically, so we can rely on a, m, z being placed in alphabetical order,
// thus ensuring the format_loader section start/end pointers are in the
// right place.
IN_SECTION(".format_loader$a")
extension_info* _ext_start[] = { NULL };

IN_SECTION(".format_loader$z")
extension_info* _ext_end[] = { NULL };

#else

#if defined(__APPLE__) && defined(__MACH__)

// Apple was doing Bonghits when they came up with this mess...
#define ENUM_DYLD_BOOL
extern "C" {
  #include <mach-o/getsect.h>
  #include <mach-o/dyld.h>
}

extension_info **_ext_start = NULL;
extension_info **_ext_end = NULL;

// This possibly needs to be thought through a bit better.
struct get_ext_section {
    get_ext_section()
    {
        char *start = NULL, *end = NULL;

        for (int c = 0; c < _dyld_image_count(); c++) {
#ifndef __x86_64
            uint32_t size;

            mach_header const* h = _dyld_get_image_header(c);

            start = getsectdatafromheader(h,
                                          "__TEXT",
                                          "format_loader",
                                          &size);
#else
            uint64_t size;
            mach_header_64 const* h = (mach_header_64 const*)_dyld_get_image_header(c);

            start = getsectdatafromheader_64(h,
                                             "__TEXT",
                                             "format_loader",
                                             &size);
#endif
            if (start == NULL) continue; // Not found...

            end = start + size;
            break;
        }

        if (!start) {
            // Try seeing if this is a part of the application itself...
            unsigned long size = 0;

            start = getsectdata("__DATA",
                                "format_loader",
                                &size);
            end = start + size;
        }

        _ext_start = reinterpret_cast<extension_info **>(start);
        _ext_end = reinterpret_cast<extension_info **>(end);
    }
};

// Yeah, this relies on a global that gets initialized during load. Sorry.
get_ext_section get_ext;

#else // Sane cases that use ELF and COFF maybe?

// Symbols created by gcc implicitly
extern char __start_format_loader[];
extern char __stop_format_loader[];

extension_info **_ext_start = (extension_info **)__start_format_loader;
extension_info **_ext_end = (extension_info **)__stop_format_loader;
#endif

#endif

unsigned load_extensions()
{
    extension_info **ext_cur = _ext_start;
    unsigned ext_count = 0;

    while (ext_cur != _ext_end) {
        if (*ext_cur) {
            (*ext_cur)->register_extension();
            ext_count++;
        }
        ++ext_cur;
    }

    return ext_count;
}
