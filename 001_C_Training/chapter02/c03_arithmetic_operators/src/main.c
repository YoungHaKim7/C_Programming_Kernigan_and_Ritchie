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
    int a = 20;
    int b = 10;

    printf("Initial values:\n");
    printf("\ta = %d (", a);
    print_binary(a);
    printf(")\n");
    printf("\tb = %d (", b);
    print_binary(b);
    printf(")\n\n");

    // Arithmetic and bitwise operations
    printf("+a   → %d (", +a);
    print_binary(+a);
    printf(")\n");
    printf("-a   → %d (", -a);
    print_binary(-a);
    printf(")\n");
    printf("a + b → %d (", a + b);
    print_binary(a + b);
    printf(")\n");
    printf("a - b → %d (", a - b);
    print_binary(a - b);
    printf(")\n");
    printf("a * b → %d (", a * b);
    print_binary(a * b);
    printf(")\n");
    printf("a / b → %d (", a / b);
    print_binary(a / b);
    printf(")\n");
    printf("a %% b → %d (", a % b);
    print_binary(a % b);
    printf(")\n");
    printf("~a   → %d (", ~a);
    print_binary(~a);
    printf(")\n");
    printf("a & b → %d (", a & b);
    print_binary(a & b);
    printf(")\n");
    printf("a | b → %d (", a | b);
    print_binary(a | b);
    printf(")\n");
    printf("a ^ b → %d (", a ^ b);
    print_binary(a ^ b);
    printf(")\n");
    printf("a << b → %d (", a << b);
    print_binary(a << b);
    printf(")\n");
    printf("a >> b → %d (", a >> b);
    print_binary(a >> b);
    printf(")\n");

    return 0;
}
