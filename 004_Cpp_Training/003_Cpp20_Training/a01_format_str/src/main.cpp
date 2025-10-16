#include <format>
#include <iostream>
#include <set>
#include <string>
#include <string_view>

template <typename... Args>
std::string dyna_print(std::string_view rt_fmt_str, Args&&... args)
{
    return std::vformat(rt_fmt_str, std::make_format_args(args...));
}

int main()
{
#ifdef __cpp_lib_format_ranges
    const std::set<std::string_view> continents { "Africa", "America",
        "Antarctica", "Asia", "Australia", "Europe" };
    std::cout << std::format("Hello {}!\n", continents);
#else
    std::cout << std::format("Hello {}!\n", "continents");
#endif

    std::string fmt;
    for (int i {}; i != 3; ++i) {
        fmt += "{} "; // constructs the formatting string
        std::cout << fmt << " : ";
        std::cout << dyna_print(fmt, "alpha", 'Z', 3.14, "unused");
        std::cout << '\n';
    }
}
