#pragma once

#include <string>

#ifdef _MSC_VER
#pragma section(".format_loader$m", read)
#define IN_SECTION(x) __declspec(allocate(x))
#define LOADABLE	IN_SECTION(".format_loader$m")
#else
#define IN_SECTION(x) __attribute__((section(#x)))
#define LOADABLE	IN_SECTION("format_loader")
#endif

#define FORMAT(ext_info)	\
	ext_info ext_info##_instance;	\
	LOADABLE ext_info* ext_info##_ptr = &##ext_info##_instance

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