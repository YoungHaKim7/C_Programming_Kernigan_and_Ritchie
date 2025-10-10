#include <iostream>
#include <memory>
#include <print>

int main() {
    std::cout << "std::unique_ptr Examples\n";

    std::unique_ptr<int> ptr = std::make_unique<int>(42);

    std::unique_ptr<int[]> arr = std::make_unique<int[]>(10); // Transfer ownership

    auto ptr2 = std::move(ptr); // ptr is now null

    std::print("ptr : {}\n", ptr ? *ptr : 0);
    std::print("arr : {}\n", arr ? "array" : "null");
    std::print("ptr2 : {}\n", ptr2 ? *ptr2 : 0);

    std::cout << "\n=== Program completed ===\n";
    std::cout << "All resources should be automatically destroyed\n";

    return 0;
}
