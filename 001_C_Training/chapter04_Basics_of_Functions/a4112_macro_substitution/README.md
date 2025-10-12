- Perfect! I've created a main.c file with 10 example sentences that demonstrate macro substitution concepts. The program includes:

```
1. Simple macro substitution (PI constant)
2. Infinite loop macro (FOREVER)
3. String message macro (MESSAGE)
4. Parameterized macro for maximum (MAX)
5. Square macro with proper parentheses
6. Absolute value macro (ABS)
7. Stringification macro (dprint)
8. Variable name printing macro (print_var)
9. Token pasting macro (paste)
10. Debug macro with line numbers (DEBUG)
```

- The program compiles and runs successfully, demonstrating various macro substitution techniques as described in the Kernighan and Ritchie text.

# Result

```bash

/opt/gcc-15/bin/gcc -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a4112_macro_substitution ./src/main.c
./target/a4112_macro_substitution
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
Example 10: Debug at line 72: Program is running
```
