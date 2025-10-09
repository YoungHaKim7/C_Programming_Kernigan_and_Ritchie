#include <iostream>
#include <string>
#include <vector>
#include <memory>

void print_string_info(const std::string& str, const std::string& label) {
    std::cout << label << ":\n";
    std::cout << "  Content: \"" << str << "\"\n";
    std::cout << "  Size: " << str.size() << " characters\n";
    std::cout << "  Capacity: " << str.capacity() << " characters\n";
    std::cout << "  Data pointer: " << static_cast<const void*>(str.data()) << "\n";
    std::cout << "  Empty: " << (str.empty() ? "Yes" : "No") << "\n\n";
}

int main() {
    std::cout << "=== std::string Dynamic Memory Management Demo ===\n\n";

    // 1. Default construction
    std::string empty_string;
    print_string_info(empty_string, "1. Default constructed string");

    // 2. Small string optimization (SSO)
    std::string small_string = "Hello";
    print_string_info(small_string, "2. Small string (likely SSO)");

    // 3. String that triggers heap allocation
    std::string large_string = "This is a longer string that will definitely exceed the small string optimization threshold and require heap allocation for storage.";
    print_string_info(large_string, "3. Large string (heap allocated)");

    // 4. Reserve memory explicitly
    std::string reserved_string;
    reserved_string.reserve(100);
    print_string_info(reserved_string, "4. String with reserved capacity");

    // 5. Append operations and reallocation
    std::string growing_string = "Starting text";
    print_string_info(growing_string, "5a. Initial growing string");

    growing_string += " - Appending more text to observe reallocation behavior";
    print_string_info(growing_string, "5b. After first append");

    growing_string += " - Even more text to force capacity increase and memory reallocation";
    print_string_info(growing_string, "5c. After second append");

    // 6. Move semantics demonstration
    std::string source_string = "This string will be moved to avoid copying";
    void* original_ptr = static_cast<void*>(source_string.data());
    print_string_info(source_string, "6a. Source string before move");

    std::string moved_string = std::move(source_string);
    print_string_info(moved_string, "6b. Destination string after move");
    print_string_info(source_string, "6c. Source string after move (should be empty)");

    std::cout << "Original data pointer vs moved pointer same? "
              << (original_ptr == static_cast<void*>(moved_string.data()) ? "Yes" : "No") << "\n\n";

    // 7. Shrink to fit
    std::string over_allocated = "Small content";
    over_allocated.reserve(1000);
    print_string_info(over_allocated, "7a. String with over-allocation");

    over_allocated.shrink_to_fit();
    print_string_info(over_allocated, "7b. After shrink_to_fit()");

    // 8. Vector of strings showing multiple allocations
    std::vector<std::string> string_vector;
    std::cout << "8. Vector of strings growth:\n";

    for (int i = 0; i < 5; ++i) {
        string_vector.push_back("String " + std::to_string(i) + " with some additional content to make it longer");
        std::cout << "  Vector size: " << string_vector.size()
                  << ", Capacity: " << string_vector.capacity() << "\n";
        print_string_info(string_vector.back(), "  Latest string added");
    }

    // 9. String with smart pointer management
    auto smart_string = std::make_unique<std::string>("Smart pointer managed string");
    print_string_info(*smart_string, "9. String managed by unique_ptr");

    std::cout << "=== Memory Management Summary ===\n";
    std::cout << "• std::string automatically manages dynamic memory\n";
    std::cout << "• Small String Optimization (SSO) avoids heap allocation for small strings\n";
    std::cout << "• Capacity grows exponentially to minimize reallocations\n";
    std::cout << "• Move semantics transfer ownership without copying data\n";
    std::cout << "• shrink_to_fit() can release excess allocated memory\n";
    std::cout << "• Works seamlessly with smart pointers for additional safety\n";

    return 0;
}
