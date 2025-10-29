#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

int main()
{
    std::cout << "=== C++20 Lambda Examples ===\n\n";

    // Example 1: Basic lambda
    std::cout << "1. Basic lambda:\n";
    auto basic_lambda = [](int x) { return x * 2; };
    std::cout << "   basic_lambda(5) = " << basic_lambda(5) << "\n\n";

    // Example 2: Lambda with capture by value
    std::cout << "2. Lambda with capture by value:\n";
    int multiplier = 3;
    auto capture_by_value = [multiplier](int x) { return x * multiplier; };
    std::cout << "   capture_by_value(4) = " << capture_by_value(4) << "\n\n";

    // Example 3: Lambda with capture by reference
    std::cout << "3. Lambda with capture by reference:\n";
    int counter = 0;
    auto increment = [&counter]() { counter++; };
    increment();
    increment();
    std::cout << "   counter after 2 increments = " << counter << "\n\n";

    // Example 4: Lambda with mutable capture
    std::cout << "4. Lambda with mutable capture:\n";
    int mutable_counter = 0;
    auto mutable_increment = [mutable_counter]() mutable {
        mutable_counter++;
        return mutable_counter;
    };
    std::cout << "   mutable_increment() = " << mutable_increment() << "\n";
    std::cout << "   mutable_increment() = " << mutable_increment() << "\n";
    std::cout << "   original mutable_counter = " << mutable_counter << "\n\n";

    // Example 5: Generic lambda (C++14)
    std::cout << "5. Generic lambda:\n";
    auto generic_add = [](auto a, auto b) { return a + b; };
    std::cout << "   generic_add(3, 4) = " << generic_add(3, 4) << "\n";
    std::cout << "   generic_add(3.5, 2.5) = " << generic_add(3.5, 2.5) << "\n";
    std::cout << "   generic_add(std::string{\"Hello \"}, \"World\") = "
              << generic_add(std::string { "Hello " }, "World") << "\n\n";

    // Example 6: constexpr lambda (C++20)
    std::cout << "6. constexpr lambda (C++20):\n";
    constexpr auto constexpr_add = [](int a, int b) constexpr { return a + b; };
    constexpr int compile_time_result = constexpr_add(10, 20);
    std::cout << "   constexpr_add(10, 20) = " << compile_time_result << "\n\n";

    // Example 7: Lambda as STL algorithm parameter
    std::cout << "7. Lambda with STL algorithms:\n";
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Find even numbers
    std::vector<int> evens;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evens),
        [](int x) { return x % 2 == 0; });

    std::cout << "   Even numbers: ";
    for (int x : evens)
        std::cout << x << " ";
    std::cout << "\n";

    // Square each number
    std::transform(numbers.begin(), numbers.end(), numbers.begin(),
        [](int x) { return x * x; });

    std::cout << "   Squared numbers: ";
    for (int x : numbers)
        std::cout << x << " ";
    std::cout << "\n\n";

    // Example 8: Lambda with std::function
    std::cout << "8. Lambda with std::function:\n";
    std::function<int(int)> factorial;
    factorial = [&factorial](
                    int n) -> int { return n <= 1 ? 1 : n * factorial(n - 1); };
    std::cout << "   factorial(5) = " << factorial(5) << "\n\n";

    // Example 9: Lambda for custom comparator
    std::cout << "9. Lambda as custom comparator:\n";
    std::vector<std::string> words = { "apple", "banana", "cherry", "date" };

    // Sort by length
    std::sort(words.begin(), words.end(),
        [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });

    std::cout << "   Words sorted by length: ";
    for (const auto& word : words)
        std::cout << word << " ";
    std::cout << "\n\n";

    // Example 10: Complex lambda with multiple captures and operations
    std::cout << "10. Complex lambda with multiple captures:\n";
    std::vector<int> data = { 3, 1, 4, 1, 5, 9, 2, 6 };
    int threshold = 4;
    int sum_of_filtered = 0;

    auto process_data = [threshold, &sum_of_filtered](
                            const std::vector<int>& vec) {
        std::vector<int> result;
        std::copy_if(vec.begin(), vec.end(), std::back_inserter(result),
            [threshold](int x) { return x > threshold; });

        sum_of_filtered = std::accumulate(result.begin(), result.end(), 0);
        return result;
    };

    auto filtered = process_data(data);
    std::cout << "   Original data: ";
    for (int x : data)
        std::cout << x << " ";
    std::cout << "\n";
    std::cout << "   Filtered (> " << threshold << "): ";
    for (int x : filtered)
        std::cout << x << " ";
    std::cout << "\n";
    std::cout << "   Sum of filtered: " << sum_of_filtered << "\n\n";

    return 0;
}
