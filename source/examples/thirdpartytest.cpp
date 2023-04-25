#include "thirdpartytest.hpp"

#if defined (USE_FMT)
#   include <fmt/format-inl.h>
#   include <fmt/format.h>
#   include <fmt/core.h>
#   include <fmt/compile.h>
#   include <fmt/ranges.h>
#   include <fmt/chrono.h>
#endif

#if defined (USE_CTRE)
#include <ctre.hpp>
#include <ctre-unicode.hpp>
#include <ctre/range.hpp>
#endif

#include <iostream>
#include <string_view>
#include <optional>

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
    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n", fmt::arg("name", "World"), fmt::arg("number", 42));

    //!9.1.0
    auto v = std::vector{1, 2, 3};
    fmt::print("{:n}\n", v); // prints 1, 2, 3

    std::cout << "========FMT TEST========" << std::endl;
#else
    std::cout << "Please enable USE_FMT!" << std::endl;
#endif
}

#if defined(USE_CTRE)

std::string_view cast_from_unicode(std::u8string_view input) noexcept {
    return std::string_view(reinterpret_cast<const char *>(input.data()), input.size());
}

constexpr auto match(std::string_view sv) noexcept {
    return ctre::match<"h.*">(sv);
}

#endif


void ThirdPartyTest::testCtre()
{
#if defined(USE_CTRE)
    std::cout << "========CTRE TEST========" << std::endl;

    using namespace std::literals;
    std::u8string_view original = u8"Tu es un génie"sv;
    for (auto match : ctre::range<"\\p{Letter}+">(original))
        std::cout << cast_from_unicode(match) << std::endl;

    /////
    auto input = "123,456,768"sv;
    for (auto match : ctre::range<"([0-9]+),?">(input)) {
        std::cout << std::string_view{match.get<0>()} << "\n";
    }

    std::cout << "Check the more test example from : "
                 "https://github.com/hanickadot/compile-time-regular-expressions/tree/main/tests \n";

    std::cout << "========CTRE TEST========" << std::endl;
#else
    std::cout << "Please enable USE_CTRE!" << std::endl;
#endif
}
