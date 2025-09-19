#include <stdio.h>

int main(void)
{
    // Decimal with separators
    int dec = 1'000'000; // 1000000

    // Hexadecimal with separators
    int hex = 0xDEAD'BEEF; // 0xDEADBEEF

    // Binary (not built-in, but GCC/Clang extensions allow 0b…)
    int bin = 0b1010'1100; // 0b10101100

    // Octal with separators
    int oct = 0'123'456; // same as 0123456

    printf("Decimal: %d\n", dec);
    printf("Hex:     %X\n", hex);
    printf("Binary:  %d (0b1010'1100)\n", bin);
    printf("Octal:   %o\n", oct);

    return 0;
}
