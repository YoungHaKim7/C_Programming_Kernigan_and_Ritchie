// file: read_lines_until_eof.cpp
#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::cout << "Enter text (Ctrl+D on UNIX / Ctrl+Z on Windows to send EOF):\n";
    // std::getline returns false at EOF or on input error
    while (std::getline(std::cin, line)) {
        std::cout << "Read: " << line << '\n';
    }

    if (std::cin.eof()) {
        std::cout << "Reached EOF.\n";
    } else if (std::cin.fail()) {
        std::cout << "Input failed (something other than EOF).\n";
    }
    return 0;
}
