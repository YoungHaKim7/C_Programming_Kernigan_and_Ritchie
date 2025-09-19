#include <stdio.h>

int main(void) {
    int num = 255;
    int c23_num_bi = 0b1111'1111;

    printf("Decimal: %d\n", num);
    printf("Octal (%%o): %o\n", num);
    printf("Octal with leading 0 (%%#o): %#o\n", num);
    printf("c23 binary : %b", c23_num_bi);

    return 0;
}
