#include <stdio.h>

void print_binary(unsigned int n) {
    int bits = sizeof(n) * 8;
    int leading = 1;

    for (int i = bits - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        if (bit) leading = 0;
        if (!leading) putchar(bit ? '1' : '0');
    }

    if (leading) putchar('0'); // if number was 0
}

int main(void) {
    int num = 255;
    int c23_num_bi = 0b1111'1111; // binary literal with separators (C23)
    int c23_bi = 10;

    // decimal 10진수
    printf("Decimal: %d\n", num);
    // octal 8진수
    printf("Octal (%%o): %o\n", num);
    // %% 내 자신을 print
    printf("Octal with leading 0 (%%#o): %#o\n", num);

    // p pointer type  (메모 리주소를 출력)  %p

    printf("\nc23 binary (0b1111'1111): %d", c23_num_bi);

    printf("\nc23 binary (0b1111'1111): ");
    print_binary(c23_num_bi);
    putchar('\n');

    printf("c23 10 in binary: ");
    print_binary(c23_bi);
    putchar('\n');

    return 0;
}
