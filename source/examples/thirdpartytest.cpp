#include "thirdpartytest.hpp"

#if defined (USE_FMT)
#include <fmt/format-inl.h>
#include <fmt/format.h>
#endif

#include <iostream>

ThirdPartyTest::ThirdPartyTest()
{

}

void ThirdPartyTest::testFmt()
{
#if defined(USE_FMT)
    using namespace fmt::literals;
    std::cout << "========FMT TEST========" << std::endl;
    fmt::print("This is a great template for C++{}.\n", 20);
    fmt::print("I'd rather be {1} than {0}.\n", "right", "happy");
    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
               fmt::arg("name", "World"), fmt::arg("number", 42));
    std::cout << "========FMT TEST========" << std::endl;
#else
    std::cout << "Please enable USE_FMT!" << std::endl;
#endif
}
