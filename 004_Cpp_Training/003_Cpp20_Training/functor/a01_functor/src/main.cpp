#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// Example 1: Basic functor class
class Square {
public:
    int operator()(int x) const { return x * x; }
};

// Example 2: Functor with state
class Accumulator {
private:
    int sum_;

public:
    Accumulator()
        : sum_(0)
    {
    }

    int operator()(int x)
    {
        sum_ += x;
        return sum_;
    }

    int get_sum() const { return sum_; }
    void reset() { sum_ = 0; }
};

// Example 3: Functor with constructor parameters
class Multiplier {
private:
    int factor_;

public:
    explicit Multiplier(int factor)
        : factor_(factor)
    {
    }

    int operator()(int x) const { return x * factor_; }
    int get_factor() const { return factor_; }
};

// Example 4: Template functor for generic operations
template <typename T> class Adder {
private:
    T value_;

public:
    explicit Adder(T value)
        : value_(value)
    {
    }

    T operator()(const T& x) const { return x + value_; }
    T get_value() const { return value_; }
};

// Example 5: Functor for predicate (returns bool)
class EvenChecker {
public:
    bool operator()(int x) const { return x % 2 == 0; }
};

// Example 6: Functor for comparison
class DescendingOrder {
public:
    bool operator()(int a, int b) const { return a > b; }
};

// Example 7: Functor composition (function composition)
class Composition {
private:
    std::function<int(int)> f_;
    std::function<int(int)> g_;

public:
    template <typename F, typename G>
    Composition(F&& f, G&& g)
        : f_(std::forward<F>(f))
        , g_(std::forward<G>(g))
    {
    }

    int operator()(int x) const { return f_(g_(x)); }
};

// Example 8: Functor with multiple overloads
class Calculator {
public:
    int operator()(int a, int b) const { return a + b; }
    double operator()(double a, double b) const { return a * b; }
    std::string operator()(const std::string& a, const std::string& b) const
    {
        return a + " " + b;
    }
};

// Example 9: Functor for mathematical operations
class Power {
private:
    int exponent_;

public:
    explicit Power(int exponent)
        : exponent_(exponent)
    {
    }

    double operator()(double base) const
    {
        double result = 1.0;
        for (int i = 0; i < exponent_; ++i) {
            result *= base;
        }
        return result;
    }
};

// Example 10: Modern C++20 functor with constexpr
constexpr class Factorial {
public:
    constexpr int operator()(int n) const
    {
        if (n <= 1)
            return 1;
        int result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
} factorial;

int main()
{
    std::cout << "=== C++20 Functor Examples ===\n\n";

    // Example 1: Basic functor
    std::cout << "1. Basic functor class:\n";
    Square square;
    std::cout << "   square(5) = " << square(5) << "\n";
    std::cout << "   square(10) = " << square(10) << "\n\n";

    // Example 2: Functor with state
    std::cout << "2. Functor with state:\n";
    Accumulator acc;
    std::cout << "   acc(1) = " << acc(1) << "\n";
    std::cout << "   acc(2) = " << acc(2) << "\n";
    std::cout << "   acc(3) = " << acc(3) << "\n";
    std::cout << "   acc.get_sum() = " << acc.get_sum() << "\n\n";

    // Example 3: Functor with constructor parameters
    std::cout << "3. Functor with constructor parameters:\n";
    Multiplier times3(3);
    Multiplier times5(5);
    std::cout << "   times3(7) = " << times3(7) << "\n";
    std::cout << "   times5(8) = " << times5(8) << "\n\n";

    // Example 4: Template functor
    std::cout << "4. Template functor:\n";
    Adder<int> add_int(10);
    Adder<double> add_double(3.14);
    Adder<std::string> add_str("Hello");
    std::cout << "   add_int(5) = " << add_int(5) << "\n";
    std::cout << "   add_double(2.0) = " << add_double(2.0) << "\n";
    std::cout << "   add_str(\"World\") = " << add_str("World") << "\n\n";

    // Example 5: Predicate functor with STL algorithms
    std::cout << "5. Predicate functor with STL:\n";
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    EvenChecker is_even;
    auto even_count = std::count_if(numbers.begin(), numbers.end(), is_even);
    std::cout << "   Even numbers in {1..10}: " << even_count << "\n\n";

    // Example 6: Comparison functor with sorting
    std::cout << "6. Comparison functor for sorting:\n";
    std::vector<int> data = { 5, 2, 8, 1, 9, 3 };
    DescendingOrder desc_order;
    std::sort(data.begin(), data.end(), desc_order);
    std::cout << "   Sorted in descending order: ";
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    // Example 7: Functor composition
    std::cout << "7. Functor composition:\n";
    Square sq;
    Multiplier mul2(2);
    Composition compose(mul2, sq); // 2 * (x^2)
    std::cout << "   compose(mul2, square)(3) = " << compose(3) << "\n";
    std::cout << "   compose(mul2, square)(4) = " << compose(4) << "\n\n";

    // Example 8: Functor with multiple overloads
    std::cout << "8. Functor with multiple overloads:\n";
    Calculator calc;
    std::cout << "   calc(3, 4) = " << calc(3, 4) << "\n";
    std::cout << "   calc(2.5, 3.0) = " << calc(2.5, 3.0) << "\n";
    std::cout << "   calc(\"Hello\", \"World\") = " << calc("Hello", "World")
              << "\n\n";

    // Example 9: Mathematical functor
    std::cout << "9. Mathematical functor:\n";
    Power power2(2);
    Power power3(3);
    std::cout << "   power2(5) = " << power2(5) << "\n";
    std::cout << "   power3(3) = " << power3(3) << "\n\n";

    // Example 10: Modern C++20 constexpr functor
    std::cout << "10. C++20 constexpr functor:\n";
    constexpr int fact5 = factorial(5);
    constexpr int fact6 = factorial(6);
    std::cout << "    factorial(5) = " << fact5 << "\n";
    std::cout << "    factorial(6) = " << fact6 << "\n";
    std::cout << "    factorial(7) = " << factorial(7) << "\n\n";

    // Example 11: Lambda as functor (bonus)
    std::cout << "11. Lambda as functor:\n";
    auto lambda_square = [](int x) { return x * x; };
    auto lambda_add = [factor = 5](int x) { return x + factor; };
    std::cout << "    lambda_square(6) = " << lambda_square(6) << "\n";
    std::cout << "    lambda_add(10) = " << lambda_add(10) << "\n\n";

    // Example 12: Functors with std::function (bonus)
    std::cout << "12. Using functors with std::function:\n";
    std::function<int(int)> func1 = Square {};
    std::function<int(int)> func2 = Multiplier { 7 };
    std::cout << "    func1(8) = " << func1(8) << "\n";
    std::cout << "    func2(6) = " << func2(6) << "\n\n";

    return 0;
}