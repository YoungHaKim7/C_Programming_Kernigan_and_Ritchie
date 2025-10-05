#include <stdio.h>

// === Example 1: File-scope static variable ===
// Internal linkage: visible only in this file.
static int file_static_counter = 0;

// === Example 2: Static function (internal linkage) ===
static void helper_increment(void)
{
    file_static_counter++;
    printf("[helper_increment] file_static_counter = %d\n", file_static_counter);
}

// === Example 3: Static local variable in a function ===
void demo_static_local(void)
{
    static int call_count = 0; // initialized once, retains value
    call_count++;
    printf("[demo_static_local] called %d times\n", call_count);
}

// === Example 4: Static variable inside a loop ===
void demo_static_in_loop(void)
{
    for (int i = 0; i < 3; i++) {
        static int loop_static = 100; // initialized once
        loop_static += 10;
        printf("[demo_static_in_loop] loop_static = %d\n", loop_static);
    }
}

// === Example 5: Static variable inside conditional ===
void demo_static_conditional(void)
{
    if (1) {
        static int cond_static = 0;
        cond_static += 5;
        printf("[demo_static_conditional] cond_static = %d\n", cond_static);
    }
}

int main(void)
{
    printf("=== Example 1 — File-scope static ===\n");
    printf("Initial file_static_counter = %d\n", file_static_counter);
    helper_increment();
    helper_increment();
    printf("\n");

    printf("=== Example 2 — Static local variable ===\n");
    demo_static_local();
    demo_static_local();
    demo_static_local();
    printf("\n");

    printf("=== Example 3 — Static variable inside loop ===\n");
    demo_static_in_loop();
    demo_static_in_loop();
    printf("\n");

    printf("=== Example 4 — Static variable inside conditional ===\n");
    demo_static_conditional();
    demo_static_conditional();
    printf("\n");

    printf("✅ All static variable examples completed successfully.\n");
    return 0;
}
