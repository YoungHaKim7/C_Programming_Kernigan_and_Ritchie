#include <iostream>
#include <print>

int main(int argc, char* argv[])
{
    std::print("Hello world C++26 lang ");

    std::cout << "number of arguments: " << argc << std::endl;

    for (int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
    return 0;
}
