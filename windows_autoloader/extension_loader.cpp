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
extension_info **_ext_start = (extension_info **)__start_format_loader;
extension_info **_ext_end = (extension_info **)__stop_format_loader;
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