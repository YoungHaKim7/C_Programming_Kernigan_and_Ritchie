# Result
- https://en.cppreference.com/w/cpp/utility/format/format.html

```bash

=== C++20 constexpr Examples ===

1. Basic constexpr function:
   square(5) = 25

2. constexpr factorial:
   factorial(5) = 120

3. constexpr lambda:
   add(3, 7) = 10

4. constexpr struct operations:
   Point p1(3, 4) distance squared = 25
   p1 + p2 = (4, 6)

5. constexpr if with types:
   is_positive(5) = 1
   is_positive(-3.5) = 0

6. constexpr container:
   Fibonacci sequence: 0 1 1 2 3

7. constexpr string operations:
   Vowels in "Hello World": 3

8. constexpr fibonacci (iterative):
   fibonacci(10) = 55

9. constexpr mathematical calculation:
   Area of circle with radius 2.5: 19.635

10. constexpr template metaprogramming:
    Factorial<5>::value = 120

Enter a number to square: 3
square(3) = 9
```


# I've created a comprehensive C++20 constexpr example with 10 different demonstrations:

  1. Basic constexpr function - Simple mathematical operations
  2. constexpr with conditional logic - Recursive factorial with ternary operator
  3. constexpr lambda - C++20 lambda expressions at compile time
  4. constexpr struct with methods - Objects with compile-time methods and operator overloading
  5. constexpr if - Template metaprogramming with conditional compilation
  6. constexpr container operations - Compile-time array manipulation
  7. constexpr string operations - String processing at compile time
  8. constexpr recursion - Iterative fibonacci algorithm
  9. constexpr mathematical calculations - Complex mathematical expressions
  10. constexpr template metaprogramming - Classic template recursion patterns

  The code compiles successfully with -std=c++20 and demonstrates both compile-time evaluation and runtime usage of constexpr functions, showing the
  flexibility of constexpr in C++20.
