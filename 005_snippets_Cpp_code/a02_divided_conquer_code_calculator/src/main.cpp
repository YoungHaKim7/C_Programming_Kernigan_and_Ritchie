#include "headers/Calculator.h"
#include <iostream>
#include <print>

int main()
{
    std::print("\nPress Ctrl+D to exit.\n\n");
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';

    std::cout << "Calculator Console Application" << "\n";
    std::cout << "Please enter the operation to perform. Format: a+b | a-b | "
                 "a*b | a/b"
              << "\n";

    Calculator c;
    while (std::cin >> x >> oper >> y) {
        result = c.Calculate(x, oper, y);
        std::cout << "Result " << "of " << x << oper << y << " is: " << result
                  << "\n";
    }

    std::print("Thank you for using the calculator. Goodbye!\n");

    return 0;
}
