#include <stdio.h>

// Print an integer in binary (32-bit wide)
void print_binary(int x)
{
    // for (int i = 31; i >= 0; i--) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if (i % 4 == 0)
            printf(" "); // group bits in 4s
    }
}

int main(void)
{
    int a;

    a = 20;

    printf("\n--- Increment / Decrement ---\n");

    a = 20;
    printf("Initial a = %d (", a);
    print_binary(a);
    printf(")\n");

    printf("++a  → %d (after increment: ", ++a);
    print_binary(a);
    printf(")\n");
    printf("--a  → %d (after decrement: ", --a);
    print_binary(a);
    printf(")\n");

    printf("\n");
    printf("a++  출력 먼저하고 increment연산은 나중에 함.  출력할때는 증가한거 안 보임\n\n");
    

    printf("a++  → %d (before increment: ", a++);
    print_binary(a - 1);
    printf(", after increment: ");
    print_binary(a);
    printf(")\n");

    printf("a--  → %d (before decrement: ", a--);
    print_binary(a + 1);
    printf(", after decrement: ");
    print_binary(a);
    printf(")\n");

    return 0;
}
