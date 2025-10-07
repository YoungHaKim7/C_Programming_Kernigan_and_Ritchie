#include <iostream>
#include <print>

int main(int argc, char* argv[])
{
    std::print("Hello world C++26 lang ");

    std::print("number of arguments: {}\n", argc);

    for (int i = 0; i < argc; ++i) {
        std::print("argv[{}]: {}\n", i, argv[i]);
    }
    return 0;
}
