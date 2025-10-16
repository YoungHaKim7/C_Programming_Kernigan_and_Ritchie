#include "headers/Calculator.h"
#include <print>
#include <cstdio>

int main()
{
    std::print("\nPress Ctrl+D to exit.\n\n");
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';

    std::println("Calculator Console Application");
    std::println("Please enter the operation to perform. Format: a+b | a-b | a*b | a/b");

    Calculator c;

    while (std::scanf(" %lf %c %lf", &x, &oper, &y) == 3) {
        result = c.Calculate(x, oper, y);
        std::println("Result of : {} {} {} is {}", x, oper, y, result);
    }

    std::print("Thank you for using the calculator. Goodbye!\n");

    return 0;
}
