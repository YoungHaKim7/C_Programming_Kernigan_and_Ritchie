#include <cmath>
#include <print>

int round_custom(double d, bool round_up = true)
{
    return (round_up) ? ceil(d) : d; // don't: "invisible" dependency
}

int main(void)
{
    std::print("c++26 hello world\n");

    // Example 1: Round up with explicit flag
    std::print("round_custom(3.2, true) = {}\n", round_custom(3.2, true));

    // Example 2: Round down with explicit flag
    std::print("round_custom(3.8, false) = {}\n", round_custom(3.8, false));

    // Example 3: Default round up
    std::print("round_custom(2.5) = {}\n", round_custom(2.5));

    // Example 4: Round up negative number
    std::print("round_custom(-1.2, true) = {}\n", round_custom(-1.2, true));

    // Example 5: Round down negative number
    std::print("round_custom(-1.8, false) = {}\n", round_custom(-1.8, false));

    // Example 6: Zero value
    std::print("round_custom(0.0) = {}\n", round_custom(0.0));

    // Example 7: Large number round up
    std::print("round_custom(1234.567) = {}\n", round_custom(1234.567));

    // Example 8: Large number round down
    std::print(
        "round_custom(1234.567, false) = {}\n", round_custom(1234.567, false));

    // Example 9: Very small number
    std::print("round_custom(0.001, true) = {}\n", round_custom(0.001, true));

    // Example 10: Negative small number
    std::print(
        "round_custom(-0.999, false) = {}\n", round_custom(-0.999, false));

    return 0;
}
