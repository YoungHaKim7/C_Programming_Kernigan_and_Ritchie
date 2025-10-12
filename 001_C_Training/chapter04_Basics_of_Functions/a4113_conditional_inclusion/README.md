- Perfect! I've created a main.c file with 10 example sentences that demonstrate macro substitution concepts. The program includes:

```
● I've successfully added 10 examples demonstrating conditional inclusion (Examples 11-20) to the main program. The examples cover:

  1. Header guard pattern (#ifndef)
  2. Platform-specific code selection (#if, #elif, #else)
  3. Feature testing with defined()
  4. Arithmetic expression evaluation
  5. Multiple condition testing
  6. Nested conditional compilation
  7. Complex logical expressions
  8. Version control simulation
  9. Bit flag testing
  10. Optimization level simulation

```

- The examples demonstrate various conditional inclusion techniques from the textbook section 4.11.3, including `#if`, `#ifdef`, `#ifndef`, `#elif`, `#else`, and the `defined()` operator.

# Result

```bash
/opt/gcc-15/bin/gcc -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a4113_conditional_inclusion ./src/main.c
./target/a4113_conditional_inclusion
Example 1: PI value is 3.141590
Example 2: 0 1 2 3 (simulated infinite loop)
Example 3: Hello from macro!
Example 4: Max of 10 and 20 is 20
Example 5: Square of 5 is 25
Example 5b: Square of (5+1) is 36
Example 6: Absolute value of -15 is 15
Example 7: pi_val = 3.14159
Example 8: test_var = 42
Example 9: var_test1 = 100, var_test2 = 200
Example 10: Debug at line 75: Program is running
Example 11: Header guard - first inclusion
Example 12: System V Unix selected
Example 13: Debug mode is enabled
Example 14: 3 * 4 = 12, which is greater than 10
Example 15: Linux platform
Example 16: Debug mode on System V
Example 17: Debug enabled on Unix-like system
Example 18: Version 2.1 or higher
Example 19: Feature A is enabled
Example 19: Feature B is enabled
Example 20: Full optimization
```
