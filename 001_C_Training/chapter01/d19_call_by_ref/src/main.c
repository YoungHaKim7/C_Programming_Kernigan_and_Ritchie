#include <stdio.h>

int power(int *pbase, int *pn);
/* test power function */

// Now takes *pbase and *pn (pointers)
int power_ref(int *pbase, int *pn) {
    int p = 1;
    int base = *pbase;
    int n = *pn;

    for (; n > 0; --n)
        p = p * base;

    // Example side effect: modify *pn
    *pn = 0;  // reset exponent in caller
    return p;
}

int main(void) {
    int base = 2, n = 4;

    int result = power_ref(&base, &n);

    printf("Result: %d\n", result);
    printf("After call -> base=%d, n=%d\n", base, n);

    return 0;
}
