#include "headers/Calculator.h"
#include <cstdio> // for fgets and stdin
#include <optional> // for error checking (optional, but clean)
#include <print>
#include <sstream> // for std::istringstream

int main()
{
    std::print("\nPress Ctrl+D to exit.\n\n");

    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';

    std::println("Calculator Console Application");
    std::println(
        "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b");

    Calculator c;

    while (true) {
        std::print("> ");
        char input[256];
        if (!fgets(input, sizeof(input), stdin)) {
            break; // EOF or error
        }

        // Remove trailing newline
        std::string input_str(input);
        if (!input_str.empty() && input_str.back() == '\n') {
            input_str.pop_back();
        }

        // Parse user input using std::istringstream (alternative to std::scan)
        std::istringstream iss(input_str);
        if (!(iss >> x >> oper >> y)) {
            std::println("Invalid input format. Try again (e.g., 2+3 or 4*5)");
            continue;
        }

        result = c.Calculate(x, oper, y);
        std::println("Result of {} {} {} is {}", x, oper, y, result);
    }

    std::print("Thank you for using the calculator. Goodbye!\n");
    return 0;
}
