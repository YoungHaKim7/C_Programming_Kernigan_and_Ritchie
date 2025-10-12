#include <stdio.h>

// Simple macro definitions
#define PI 3.14159
#define FOREVER for (;;)
#define MESSAGE "Hello from macro!"

// Parameterized macros
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define SQUARE(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))

// Stringification macro
#define dprint(expr) printf(#expr " = %g\n", expr)
#define print_var(var) printf(#var " = %d\n", var)

// Token pasting macro
#define paste(front, back) front##back
#define make_var(name, num) paste(var, name)##num

// Debug macro with line numbers
#define DEBUG(msg) printf("Debug at line %d: " #msg "\n", __LINE__)

int main()
{
    // Example 1: Simple macro substitution
    printf("Example 1: PI value is %f\n", PI);

    // Example 2: Using a macro to define an infinite loop (demonstration only)
    printf("Example 2: ");
    int count = 0;
    for (;;) { // Using FOREVER macro would be: FOREVER {
        printf("%d ", count);
        count++;
        if (count > 3)
            break;
    }
    printf("(simulated infinite loop)\n");

    // Example 3: Simple message macro
    printf("Example 3: %s\n", MESSAGE);

    // Example 4: Parameterized macro for finding maximum
    int a = 10, b = 20;
    printf("Example 4: Max of %d and %d is %d\n", a, b, MAX(a, b));

    // Example 5: Square macro with proper parentheses
    int x = 5;
    printf("Example 5: Square of %d is %d\n", x, SQUARE(x));
    printf("Example 5b: Square of (%d+1) is %d\n", x, SQUARE(x + 1));

    // Example 6: Absolute value macro
    int negative_num = -15;
    printf("Example 6: Absolute value of %d is %d\n", negative_num, ABS(negative_num));

    // Example 7: Stringification macro
    float pi_val = 3.14159;
    printf("Example 7: ");
    dprint(pi_val);

    // Example 8: Variable name printing macro
    int test_var = 42;
    printf("Example 8: ");
    print_var(test_var);

    // Example 9: Token pasting macro
    int var_test1 = 100, var_test2 = 200;
    printf("Example 9: var_test1 = %d, var_test2 = %d\n", var_test1, var_test2);

    // Example 10: Debug macro with line numbers
    printf("Example 10: ");
    DEBUG(Program is running);

    return 0;
}