#include "extension.h"

#include <iostream>

namespace {
	class extension1_info : public extension_info
	{
	public:
		void register_extension()
		{
			std::cout << "Registering extension 1" << std::endl;
		}

		std::string const& get_extension_name() const
		{
			return "extension1";
		}
	};

	class extension2_info : public extension_info
	{
	public:
		void register_extension()
		{
			std::cout << "Registering extension 2" << std::endl;
		}

		std::string const& get_extension_name() const
		{
			return "extension2";
		}
	};

	class extension3_info : public extension_info
	{
	public:
		void register_extension()
		{
			std::cout << "Registering extension 3" << std::endl;
		}

		std::string const& get_extension_name() const
		{
			return "extension3";
		}
	};

	class extension4_info : public extension_info
	{
	public:
		void register_extension()
		{
			std::cout << "Registering extension 4" << std::endl;
		}

		std::string const& get_extension_name() const
		{
			return "extension4";
		}
	};

	extension1_info fmt1_info;
	extension2_info fmt2_info;
	extension3_info fmt3_info;
}

LOADABLE
extension_info *format1 = &fmt1_info;

LOADABLE
extension_info *format2 = &fmt2_info;

LOADABLE
extension_info *format3 = &fmt3_info;

FORMAT(extension4_info);