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

// Conditional inclusion examples
#define SYSTEM 1 // 1=SYSV, 2=BSD, 3=MSDOS

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

// Conditional Inclusion Examples (11-20)

// Example 11: Header guard pattern using #ifndef
#ifndef HDR_GUARD
#define HDR_GUARD
    printf("Example 11: Header guard - first inclusion\n");
#else
    printf("Example 11: Header guard - subsequent inclusion\n");
#endif

// Example 12: Platform-specific code selection
#if SYSTEM == 1
    printf("Example 12: System V Unix selected\n");
#elif SYSTEM == 2
    printf("Example 12: Berkeley Unix selected\n");
#elif SYSTEM == 3
    printf("Example 12: MS-DOS selected\n");
#else
    printf("Example 12: Default system selected\n");
#endif

// Example 13: Feature testing with defined()
#define ENABLE_DEBUG 1
#if defined(ENABLE_DEBUG) && ENABLE_DEBUG == 1
    printf("Example 13: Debug mode is enabled\n");
#else
    printf("Example 13: Debug mode is disabled\n");
#endif

// Example 14: Arithmetic expression evaluation
#if (3 * 4) > 10
    printf("Example 14: 3 * 4 = 12, which is greater than 10\n");
#else
    printf("Example 14: Condition false\n");
#endif

// Example 15: Multiple condition testing
#define WINDOWS 0
#define LINUX 1
#if WINDOWS
    printf("Example 15: Windows platform\n");
#elif LINUX
    printf("Example 15: Linux platform\n");
#else
    printf("Example 15: Unknown platform\n");
#endif

// Example 16: Nested conditional compilation
#if defined(ENABLE_DEBUG)
#if SYSTEM == 1
    printf("Example 16: Debug mode on System V\n");
#elif SYSTEM == 2
    printf("Example 16: Debug mode on BSD\n");
#else
    printf("Example 16: Debug mode on other system\n");
#endif
#else
    printf("Example 16: Debug mode disabled\n");
#endif

// Example 17: Complex logical expression
#if defined(ENABLE_DEBUG) && (SYSTEM == 1 || SYSTEM == 2)
    printf("Example 17: Debug enabled on Unix-like system\n");
#else
    printf("Example 17: Either debug disabled or not Unix-like\n");
#endif

// Example 18: Version control simulation
#define VERSION_MAJOR 2
#define VERSION_MINOR 1
#if VERSION_MAJOR > 2
    printf("Example 18: Major version is greater than 2\n");
#elif VERSION_MAJOR == 2 && VERSION_MINOR >= 1
    printf("Example 18: Version 2.1 or higher\n");
#else
    printf("Example 18: Version 2.0 or lower\n");
#endif

// Example 19: Bit flag testing
#define FEATURE_FLAGS 0x03 // Binary: 11
#if (FEATURE_FLAGS & 0x01)
    printf("Example 19: Feature A is enabled\n");
#endif
#if (FEATURE_FLAGS & 0x02)
    printf("Example 19: Feature B is enabled\n");
#endif
#if (FEATURE_FLAGS & 0x04)
    printf("Example 19: Feature C is disabled (not compiled)\n");
#endif

// Example 20: Optimization level simulation
#define OPT_LEVEL 2
#if OPT_LEVEL == 0
    printf("Example 20: No optimization\n");
#elif OPT_LEVEL == 1
    printf("Example 20: Basic optimization\n");
#elif OPT_LEVEL == 2
    printf("Example 20: Full optimization\n");
#else
    printf("Example 20: Unknown optimization level\n");
#endif

    return 0;
}