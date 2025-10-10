#include <print>

int main()
{
    std::print("\xahello, ");
    std::print("world");
    // escape letters 
    std::print("\xa\xa");
    std::print("world\xa");
}
