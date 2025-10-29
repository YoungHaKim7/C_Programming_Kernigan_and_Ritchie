#include <array>
#include <iostream>
#include <string>
#include <type_traits>

// Example 1: Basic consteval function - MUST be evaluated at compile time
consteval int square(int x) { return x * x; }

// Example 2: consteval with conditional logic
consteval int factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }

// Example 3: consteval for compile-time validation
consteval bool is_power_of_two(unsigned int n)
{
    return n != 0 && (n & (n - 1)) == 0;
}

// Example 4: consteval struct with compile-time methods
struct Point {
    constexpr Point(double x, double y)
        : x_(x)
        , y_(y)
    {
    }

    consteval double distance_squared() const { return x_ * x_ + y_ * y_; }

    consteval Point operator+(const Point& other) const
    {
        return Point(x_ + other.x_, y_ + other.y_);
    }

    double x_, y_;
};

// Example 5: consteval for array bounds checking
template <size_t N> consteval std::array<int, N> create_sequence(int start = 0)
{
    std::array<int, N> result {};
    for (size_t i = 0; i < N; ++i) {
        result[i] = start + static_cast<int>(i);
    }
    return result;
}

// Example 6: consteval for string literal processing
template <size_t N> consteval size_t string_length(const char (&)[N])
{
    return N - 1; // Exclude null terminator
}

// Example 7: consteval for compile-time hash calculation
consteval unsigned int djb2_hash(const char* str)
{
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

// Example 8: consteval for bit manipulation
consteval int count_set_bits(unsigned int n)
{
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Example 9: consteval for mathematical constants
consteval double calculate_pi()
{
    // Leibniz formula approximation
    double pi = 0.0;
    for (int i = 0; i < 100000; ++i) {
        pi += (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1.0);
    }
    return pi * 4.0;
}

// Example 10: consteval for type checking and validation
template <typename T> consteval bool validate_type_requirements()
{
    return std::is_trivial_v<T> && std::is_standard_layout_v<T>;
}

// Helper struct for type validation example
struct ValidPod {
    int x;
    double y;
};

int main()
{
    std::cout << "=== C++20 consteval Examples ===\n";
    std::cout << "consteval functions MUST be evaluated at compile time\n\n";

    // Example 1: Basic consteval function
    constexpr int sq = square(5);
    std::cout << "1. Basic consteval function:\n";
    std::cout << "   square(5) = " << sq << " (evaluated at compile time)\n\n";

    // Example 2: consteval factorial
    constexpr int fact = factorial(5);
    std::cout << "2. consteval factorial:\n";
    std::cout << "   factorial(5) = " << fact
              << " (evaluated at compile time)\n\n";

    // Example 3: consteval for validation
    constexpr bool power_check1 = is_power_of_two(16);
    constexpr bool power_check2 = is_power_of_two(15);
    std::cout << "3. consteval for compile-time validation:\n";
    std::cout << "   is_power_of_two(16) = " << power_check1 << "\n";
    std::cout << "   is_power_of_two(15) = " << power_check2 << "\n\n";

    // Example 4: consteval struct operations
    constexpr Point p1(3.0, 4.0);
    constexpr Point p2(1.0, 2.0);
    constexpr Point p3 = p1 + p2;
    constexpr double dist_sq = p3.distance_squared();
    std::cout << "4. consteval struct operations:\n";
    std::cout << "   Point p1(3, 4) + p2(1, 2) = (" << p3.x_ << ", " << p3.y_
              << ")\n";
    std::cout << "   Distance squared = " << dist_sq << "\n\n";

    // Example 5: consteval array generation
    constexpr auto sequence = create_sequence<5>(10);
    std::cout << "5. consteval for array generation:\n";
    std::cout << "   create_sequence<5>(10) = ";
    for (int val : sequence) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    // Example 6: consteval string length
    constexpr auto str_len = string_length("Hello, consteval!");
    std::cout << "6. consteval for string literal processing:\n";
    std::cout << "   string_length(\"Hello, consteval!\") = " << str_len
              << "\n\n";

    // Example 7: consteval hash calculation
    constexpr auto hash_val = djb2_hash("consteval");
    std::cout << "7. consteval for compile-time hash calculation:\n";
    std::cout << "   djb2_hash(\"consteval\") = " << hash_val << "\n\n";

    // Example 8: consteval bit manipulation
    constexpr int bits_15 = count_set_bits(15);
    constexpr int bits_8 = count_set_bits(8);
    std::cout << "8. consteval for bit manipulation:\n";
    std::cout << "   count_set_bits(15) = " << bits_15 << " (binary: 1111)\n";
    std::cout << "   count_set_bits(8) = " << bits_8 << " (binary: 1000)\n\n";

    // Example 9: consteval mathematical constants
    constexpr double pi_approx = calculate_pi();
    std::cout << "9. consteval for mathematical constants:\n";
    std::cout << "   calculate_pi() ≈ " << pi_approx << "\n";
    std::cout << "   Actual pi = " << 3.14159265358979323846 << "\n\n";

    // Example 10: consteval type validation
    constexpr bool valid_pod = validate_type_requirements<ValidPod>();
    std::cout << "10. consteval for type checking and validation:\n";
    std::cout << "    validate_type_requirements<ValidPod>() = " << valid_pod
              << "\n";
    std::cout << "    (ValidPod is trivial and standard layout)\n\n";

    std::cout << "=== Key Differences between constexpr and consteval ===\n";
    std::cout << "- constexpr: Can be evaluated at compile time OR runtime\n";
    std::cout << "- consteval: MUST be evaluated at compile time only\n";
    std::cout << "- consteval provides stronger compile-time guarantees\n";
    std::cout << "- consteval functions can only be called in contexts "
                 "requiring constant expressions\n\n";

    std::cout << "Note: Try calling a consteval function with runtime values - "
                 "it won't compile!\n";

    return 0;
}
