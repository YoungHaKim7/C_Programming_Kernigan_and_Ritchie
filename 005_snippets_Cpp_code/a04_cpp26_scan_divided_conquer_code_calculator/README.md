# Result


```bash
Press Ctrl+D to exit.

Calculator Console Application
Please enter the operation to perform. Format: a+b | a-b | a*b | a/b
3+5
Result of 3+5 is: 8
Thank you for using the calculator. Goodbye!
```


# `scan()` 구현 안되었다고 한다. 난중에 해보자

```cpp
#include "headers/Calculator.h"
#include <print>
#include <format>   // for std::scan
#include <optional> // for error checking (optional, but clean)

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

    while (true) {
        std::print("> ");
        std::string input;
        if (!std::getline(std::cin, input)) {
            break; // EOF or error
        }

        // Parse user input safely using std::scan (C++26)
        auto [ok, end] = std::scan(input, " {} {} {}", x, oper, y);
        if (!ok) {
            std::println("Invalid input format. Try again (e.g., 2+3 or 4 * 5)");
            continue;
        }

        result = c.Calculate(x, oper, y);
        std::println("Result of {} {} {} is {}", x, oper, y, result);
    }

    std::print("Thank you for using the calculator. Goodbye!\n");
    return 0;
}

```

