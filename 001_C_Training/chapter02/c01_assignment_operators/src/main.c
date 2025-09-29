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
    int a, b;

    // 0001 0100
    a = 20;

    // 0000 1010
    b = 10;

    printf("Initial values: \n\ta = %d (", a);
    print_binary(a);
    printf("), \n\tb = %d (", b);
    print_binary(b);
    printf(")\n\n");

    a = 20;
    a += b;
    printf("(+=)  a += b → %d (", a);
    print_binary(a);
    printf(")\n");

    a = 20;
    a -= b;
    printf("(-=)  a -= b → %d (", a);
    print_binary(a);
    printf(")\n");

    a = 20;
    a *= b;
    printf("(*=)  a *= b → %d (", a);
    print_binary(a);
    printf(")\n");

    a = 20;
    a /= b;
    printf("(/=)  a /= b → %d (", a);
    print_binary(a);
    printf(")\n");

    a = 20;
    b = 7;
    a %= b;
    printf("(%%=)  a %%= b → %d (", a);
    print_binary(a);
    printf(")  a=20, b=7 \n");

    a = 20;
    a &= b;
    printf("(&=)  a &= b → %d (", a);
    print_binary(a);
    printf(")\n");

    a = 20;
    a |= b;
    printf("(|=)  a |= b → %d (", a);
    print_binary(a);
    printf(")\n");

    a = 20;
    a ^= b;
    printf("(^=)  a ^= b → %d (", a);
    print_binary(a);
    printf(")\n");

    a = 20;
    a <<= b;
    printf("(<<=) a <<= b → %d (", a);
    print_binary(a);
    printf(")\n");

    a = 20;
    a >>= b;
    printf("(>>=) a >>= b → %d (", a);
    print_binary(a);
    printf(")\n");

    int aa = 0b0100;
    aa <<= 2;
    printf("(<<=) aa <<= 2 → %d (", aa);
    print_binary(aa);
    printf(")\n");

    return 0;
}
