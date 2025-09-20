#include <stdio.h>

#define ROWS 3
#define COLS 4

int main(void)
{

    // Decimal with separators
    // clang-format off
    int dec = 1'000'000; // 1000000

    // Hexadecimal with separators
    // 0xDEADBEEF
    int hex = 0xDEAD'BEEF;

    // Binary (not built-in, but GCC/Clang extensions allow 0b…)
    // 0b10101100
    int bin = 0b1010'1100;

    // Octal with separators
    // same as 0123456
    int oct = 0'123'456;
    // clang-format on

    printf("Decimal: %d\n", dec);
    printf("Hex:     %X\n", hex);
    printf("Binary:  %d (0b1010'1100)\n", bin);
    printf("Octal:   %o\n", oct);

    printf("\n");
    printf("2D array (matrix)\n");

    // 2D array (matrix) with digit separators for readability
    // clang-format off
    int matrix[ROWS][COLS] = {
        { 1,     2,     3,     4 },
        { 10,   20,   30,   40 },
        { 100, 200, 300, 400 }
    };
    // clang-format on

    printf("Matrix (%dx%d):\n", ROWS, COLS);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", matrix[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
