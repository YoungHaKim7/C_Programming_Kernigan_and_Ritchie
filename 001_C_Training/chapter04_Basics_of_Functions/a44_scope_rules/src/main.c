#include <stdio.h>

// Global variables used in examples
int global_x = 42;
int counter = 0;
int total = 5;
int val = 123;
int numbers[3] = {10, 20, 30};
int mode = 42;

// === Example 4 globals and functions ===
#define MAXVAL 100
int sp = 0;
double val_stack[MAXVAL];

void push(double f) {
    val_stack[sp++] = f;
}

double pop(void) {
    return val_stack[--sp];
}

// === Example 9–10 functions ===
void greet(void) {
    printf("Hello from greet!\n");
}

void show_mode(void) {
    printf("mode = %d\n", mode);
}

int main(void)
{
    printf("=== Example 1 — Simple global definition ===\n");
    printf("x = %d\n\n", global_x);

    printf("=== Example 2 — Declaration without definition (simulated) ===\n");
    printf("// (In single-file demo, this works because global_x is defined above)\n");
    extern int global_x;
    printf("extern global_x = %d\n\n", global_x);

    printf("=== Example 3 — Simulated separate definition file ===\n");
    extern int counter;
    counter = 100;
    printf("counter = %d\n\n", counter);

    printf("=== Example 4 — push/pop with extern vars ===\n");
    push(10.5);
    push(20.5);
    printf("pop1 = %.1f\n", pop());
    printf("pop2 = %.1f\n\n", pop());

    printf("=== Example 5 — Multiple extern declarations allowed ===\n");
    extern int total;
    printf("total = %d\n\n", total);

    printf("=== Example 6 — extern + initialization ===\n");
    extern int val;
    printf("val = %d\n\n", val);

    printf("=== Example 7 — extern inside a function ===\n");
    {
        extern int counter;
        counter = 10;
        printf("counter (extern inside block) = %d\n\n", counter);
    }

    printf("=== Example 8 — extern with arrays ===\n");
    extern int numbers[];
    for (int i = 0; i < 3; i++)
        printf("%d ", numbers[i]);
    putchar('\n');
    printf("\n");

    printf("=== Example 9 — extern with functions ===\n");
    extern void greet(void);
    greet();
    printf("\n");

    printf("=== Example 10 — Global shared across sections ===\n");
    extern int mode;
    extern void show_mode(void);
    show_mode();
    mode = 99;
    show_mode();
    printf("\n");

    printf("✅ All 10 extern examples completed successfully.\n");

    return 0;
}
