#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

// === External and Static Global Variables ===
int global_counter; // uninitialized external → defaults to 0
double global_pi; // uninitialized external → defaults to 0.0
static int static_global = 42; // static global initialized explicitly
long milliseconds_per_day = 1000L * 60L * 60L * 24L; // constant expression initializer

// Helper function: demonstrates static local variable
void static_example(void)
{
    static int call_count = 0; // initialized only once
    call_count++;
    printf("🔹 static_example() called %d times\n", call_count);
}

int main(void)
{
    printf("=== 4.9 Initialization Examples ===\n\n");

    // ---------------------------------------------------------
    // ✅ Example group 1: declare all 10 variables at once
    // ---------------------------------------------------------
    int a = 0, x = 1, y = 3, z = 9;
    int b = 10;
    int c = b + 5;
    char squote = '\'', newline = '\n';
    int d = printf("1️⃣ Hello from printf initializer!\n");
    register int reg_x = 123;
    static int uninit_static; // automatically zeroed

    // Note: combining different initializations in one block
    // is valid as long as their storage classes and types are compatible.

    printf("\n=== Combined Declarations ===\n");
    printf("a (uninitialized, garbage) = %d (undefined)\n", a);
    printf("b = %d, c = %d, d (printf returned) = %d\n", b, c, d);
    printf("x=%d, y=%d, z=%d\n", x, y, z);
    printf("squote='%c', newline below:%c<-- newline\n", squote, newline);
    printf("reg_x (register) = %d\n", reg_x);
    printf("uninit_static (static, default) = %d\n", uninit_static);
    printf("static_global = %d\n", static_global);
    printf("milliseconds_per_day = %ld\n", milliseconds_per_day);

    // ---------------------------------------------------------
    // ✅ Example group 2: demonstrate behavior differences
    // ---------------------------------------------------------
    printf("\n=== Behavior Demonstrations ===\n");

    // Example 6: Static local variable persists across calls
    static_example();
    static_example();
    static_example();

    // Example 7: external variables auto-initialized before main
    printf("Global vars: counter=%d, pi=%f, ms/day=%ld\n",
        global_counter, global_pi, milliseconds_per_day);

    // ---------------------------------------------------------
    // ✅ Binary Search Example
    // ---------------------------------------------------------
    printf("\n=== Binary Search Examples ===\n");

    int sorted_array[] = { 2, 4, 7, 11, 15, 19, 23, 28, 31, 42 };
    int n = sizeof(sorted_array) / sizeof(sorted_array[0]);

    // Test cases
    int search_values[] = { 7, 15, 42, 2, 99, -5, 23 };
    int num_tests = sizeof(search_values) / sizeof(search_values[0]);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n\n");

    for (int i = 0; i < num_tests; i++) {
        int target = search_values[i];
        int result = binsearch(target, sorted_array, n);

        printf("Searching for %d: ", target);
        if (result != -1) {
            printf("Found at index %d\n", result);
        } else {
            printf("Not found\n");
        }
    }

    printf("\n=== End of Initialization Examples ===\n");

    return 0;
}
