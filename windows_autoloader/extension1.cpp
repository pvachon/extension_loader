#include "extension.h"

#include <iostream>

// A simple test wrapper/demonstration of how to enumerate a list
// of callable classes, with the list being generated at compile and
// link time, rather than requiring any programmer intervention.
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

    extension1_info fmt1_info; // For usage case 1
}

// Usage 1: declare manually, use LOADABLE attribute macro
LOADABLE
extension_info *format1 = &fmt1_info;

// Usage 2: a macro that hides all the gorey details
FORMAT(extension2_info);
FORMAT(extension3_info);
FORMAT(extension4_info);
