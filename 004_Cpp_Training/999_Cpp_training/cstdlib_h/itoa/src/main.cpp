/* itoa example */

/*
 * itoa: convert an int to a NUL-terminated string in the given base (2..36).
 *
 * Not part of the C standard (glibc/musl on Linux don't provide it), so we
 * implement it here. Signature mirrors the cplusplus.com itoa() reference.
 * Returns str. The caller must ensure str is large enough (33 bytes covers a
 * 32-bit int in base 2, the widest case).
 */
char *itoa(int value, char *str, int base) {
    static const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    char *p = str;

    if (base < 2 || base > 36) {
        *str = '\0';
        return str;
    }

    unsigned int n;
    if (value < 0 && base == 10) {
        *p++ = '-';
        /* Safe magnitude: avoids UB when value == INT_MIN. */
        n = (unsigned int)(-(value + 1)) + 1u;
    } else {
        n = (unsigned int)value; /* non-decimal bases treat it as unsigned */
    }

    /* Generate digits (least significant first). */
    char *low = p;
    do {
        *p++ = digits[n % base];
        n /= base;
    } while (n);
    *p = '\0';

    /* Reverse the digit run in place. */
    char *high = p - 1;
    while (low < high) {
        char tmp = *low;
        *low++ = *high;
        *high-- = tmp;
    }

    return str;
}

#include <stdio.h>
int main(void) {
    int i;
    char buffer[33];

    printf("Enter a number: ");
    scanf("%d", &i);
    itoa(i, buffer, 10);
    printf("decimal: %s\n", buffer);
    itoa(i, buffer, 16);
    printf("hexadecimal: %s\n", buffer);
    itoa(i, buffer, 2);
    printf("binary: %s\n", buffer);

    return 0;
}
