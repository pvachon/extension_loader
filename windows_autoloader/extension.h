#pragma once

#include <string>

#ifdef _MSC_VER
#pragma section(".format_loader$m", read)
#define IN_SECTION(x) __declspec(allocate(x))
#define LOADABLE	IN_SECTION(".format_loader$m")
#else

#define IN_SECTION(x) __attribute__((section(x)))

#if defined(__APPLE__) && defined(__MACH__)
// MachO requires special section names that include the segment name
#define LOADABLE    IN_SECTION("__TEXT, format_loader")
#else
#define LOADABLE	IN_SECTION("format_loader")
#endif

#endif

// Helper macro. Given the name of a class that inherits from
// extension info, create a global instance of the class and a
// pointer to this instance to be used during enumeration and
// initialization.
#define FORMAT(ext_info)	\
	ext_info ext_info##_instance;	\
	LOADABLE extension_info* ext_info##_ptr = &(ext_info ## _instance)

// Interface to register/manage an extension (format, whatever)
struct extension_info {
	// Method to register a given extension/format/whatever with
	// the central registrar.
	virtual void register_extension() = 0;

	// Maybe some useful housekeeping to provide this information
	virtual std::string const& get_extension_name() const = 0;

	virtual ~extension_info() {}
};

// The function you call to initiate extension loading
unsigned load_extensions(void);
