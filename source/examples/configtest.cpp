#include "configtest.hpp"
#include "common.hpp"
#include "config.hpp"
#include <iostream>

ConfigTest::ConfigTest()
{

}

void ConfigTest::readConfig() const noexcept
{
    std::cout << "========CONFIG TEST========" << std::endl;
    std::cout << "Project Name : "          << PROJECT_NAME << std::endl;
    std::cout << "Project Description : "   << PROJECT_DESCRIPTION << std::endl;
    std::cout << "Project Homepage Url : "  << PROJECT_HOMEPAGE_URL << std::endl;
    std::cout << "Project Language : "      << PROJECT_LANGUAGES << std::endl;
    std::cout << "Project Full Version : "  << PROJECT_VERSION_STRING << std::endl;
    std::cout << "Project Creator : "       << PROJECT_CREATOR << std::endl;
    std::cout << "Project License Type : "  << PROJECT_LICENSE_TYPE << std::endl;
    std::cout << "========CONFIG TEST========" << std::endl;
}
