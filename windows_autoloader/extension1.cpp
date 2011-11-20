#include "extension.h"

#include <iostream>

namespace {
	class extension1_info : public extension_info
	{
	public:
        extension1_info() : m_ext_name("extension1") {}

		void register_extension()
		{
			std::cout << "Registering extension 1" << std::endl;
		}

		std::string const& get_extension_name() const
		{
            return m_ext_name;
		}
    private:
        std::string m_ext_name;
	};

	class extension2_info : public extension_info
	{
	public:
        extension2_info() : m_ext_name("extension2") {}

		void register_extension()
		{
			std::cout << "Registering extension 2" << std::endl;
		}

		std::string const& get_extension_name() const
		{
            return m_ext_name;
		}
    private:
        std::string m_ext_name;
	};

	class extension3_info : public extension_info
	{
	public:
        extension3_info() : m_ext_name("extension3") {}

		void register_extension()
		{
			std::cout << "Registering extension 3" << std::endl;
		}

		std::string const& get_extension_name() const
		{
            return m_ext_name;
		}
    private:
        std::string m_ext_name;
	};

	class extension4_info : public extension_info
	{
	public:
        extension4_info() : m_ext_name("extension4") {}

		void register_extension()
		{
			std::cout << "Registering extension 4" << std::endl;
		}

		std::string const& get_extension_name() const
		{
            return m_ext_name;
		}
    private:
        std::string m_ext_name;
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
