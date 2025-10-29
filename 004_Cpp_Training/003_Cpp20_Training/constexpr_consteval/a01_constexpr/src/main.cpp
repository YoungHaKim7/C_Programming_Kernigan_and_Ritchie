#include <array>
#include <iostream>
#include <string>

// Example 1: Basic constexpr function
constexpr int square(int x) { return x * x; }

// Example 2: constexpr with conditional logic
constexpr int factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }

// Example 3: constexpr lambda (C++20)
constexpr auto add = [](int a, int b) { return a + b; };

// Example 4: constexpr struct with methods
struct Point {
    constexpr Point(double x, double y)
        : x_(x)
        , y_(y)
    {
    }

    constexpr double distance() const { return x_ * x_ + y_ * y_; }

    constexpr Point operator+(const Point& other) const
    {
        return Point(x_ + other.x_, y_ + other.y_);
    }

    double x_, y_;
};

// Example 5: constexpr if (C++17, but works in C++20)
template <typename T> constexpr bool is_positive(T value)
{
    if constexpr (std::is_integral_v<T>) {
        return value > 0;
    } else {
        return value > static_cast<T>(0);
    }
}

// Example 6: constexpr container operations
constexpr std::array<int, 5> create_fibonacci()
{
    std::array<int, 5> fib {};
    fib[0] = 0;
    fib[1] = 1;
    for (size_t i = 2; i < fib.size(); ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

// Example 7: constexpr string operations
constexpr int count_vowels(const std::string& str)
{
    int count = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A'
            || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            ++count;
        }
    }
    return count;
}

// Example 8: constexpr recursion with memoization-like pattern
constexpr int fibonacci(int n)
{
    if (n <= 1)
        return n;

    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// Example 9: constexpr evaluation of complex expressions
constexpr double calculate_circle_area(double radius)
{
    return 3.14159265358979323846 * radius * radius;
}

// Example 10: constexpr template metaprogramming
template <int N> struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

template <> struct Factorial<0> {
    static constexpr int value = 1;
};

int main()
{
    // Compile-time constant expressions
    constexpr int sq = square(5);
    constexpr int fact = factorial(5);
    constexpr int sum = add(3, 7);

    // constexpr objects
    constexpr Point p1(3.0, 4.0);
    constexpr Point p2(1.0, 2.0);
    constexpr Point p3 = p1 + p2;

    // constexpr containers
    constexpr auto fib_array = create_fibonacci();

    // constexpr template values
    constexpr int fact5 = Factorial<5>::value;

    // Runtime usage of constexpr functions
    std::cout << "=== C++20 constexpr Examples ===\n\n";

    std::cout << "1. Basic constexpr function:\n";
    std::cout << "   square(5) = " << sq << "\n\n";

    std::cout << "2. constexpr factorial:\n";
    std::cout << "   factorial(5) = " << fact << "\n\n";

    std::cout << "3. constexpr lambda:\n";
    std::cout << "   add(3, 7) = " << sum << "\n\n";

    std::cout << "4. constexpr struct operations:\n";
    std::cout << "   Point p1(3, 4) distance squared = " << p1.distance()
              << "\n";
    std::cout << "   p1 + p2 = (" << p3.x_ << ", " << p3.y_ << ")\n\n";

    std::cout << "5. constexpr if with types:\n";
    std::cout << "   is_positive(5) = " << is_positive(5) << "\n";
    std::cout << "   is_positive(-3.5) = " << is_positive(-3.5) << "\n\n";

    std::cout << "6. constexpr container:\n";
    std::cout << "   Fibonacci sequence: ";
    for (int val : fib_array) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    std::cout << "7. constexpr string operations:\n";
    std::string text = "Hello World";
    std::cout << "   Vowels in \"" << text << "\": " << count_vowels(text)
              << "\n\n";

    std::cout << "8. constexpr fibonacci (iterative):\n";
    std::cout << "   fibonacci(10) = " << fibonacci(10) << "\n\n";

    std::cout << "9. constexpr mathematical calculation:\n";
    std::cout << "   Area of circle with radius 2.5: "
              << calculate_circle_area(2.5) << "\n\n";

    std::cout << "10. constexpr template metaprogramming:\n";
    std::cout << "    Factorial<5>::value = " << fact5 << "\n\n";

    // Demonstrate that constexpr can also be used at runtime
    int runtime_val;
    std::cout << "Enter a number to square: ";
    std::cin >> runtime_val;
    std::cout << "square(" << runtime_val << ") = " << square(runtime_val)
              << "\n";

    return 0;
}
