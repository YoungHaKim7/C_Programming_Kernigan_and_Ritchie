# Result

```bash
=== C++20 Lambda Examples ===

1. Basic lambda:
   basic_lambda(5) = 10

2. Lambda with capture by value:
   capture_by_value(4) = 12

3. Lambda with capture by reference:
   counter after 2 increments = 2

4. Lambda with mutable capture:
   mutable_increment() = 1
   mutable_increment() = 2
   original mutable_counter = 0

5. Generic lambda:
   generic_add(3, 4) = 7
   generic_add(3.5, 2.5) = 6
   generic_add(std::string{"Hello "}, "World") = Hello World

6. constexpr lambda (C++20):
   constexpr_add(10, 20) = 30

7. Lambda with STL algorithms:
   Even numbers: 2 4 6 8 10
   Squared numbers: 1 4 9 16 25 36 49 64 81 100

8. Lambda with std::function:
   factorial(5) = 120

9. Lambda as custom comparator:
   Words sorted by length: date apple banana cherry

10. Complex lambda with multiple captures:
   Original data: 3 1 4 1 5 9 2 6
   Filtered (> 4): 5 9 6
   Sum of filtered: 20

```


# The C++20 lambda examples are working correctly. Let me mark the task as completed.

⏺ I've successfully created 10 comprehensive C++20 lambda examples that demonstrate various lambda features:

  1. Basic lambda - Simple lambda that doubles a number
  2. Capture by value - Lambda that captures external variables by value
  3. Capture by reference - Lambda that modifies external variables via reference
  4. Mutable capture - Lambda that can modify captured variables
  5. Generic lambda - Lambda that works with different types using auto
  6. constexpr lambda - C++20 feature allowing lambdas in constant expressions
  7. STL algorithms - Using lambdas with std::copy_if and std::transform
  8. std::function - Recursive lambda using std::function wrapper
  9. Custom comparator - Lambda as custom comparator for sorting
  10. Complex captures - Lambda with multiple captures and nested lambdas

  The program compiles and runs successfully, demonstrating all these lambda concepts with clear output and examples.
