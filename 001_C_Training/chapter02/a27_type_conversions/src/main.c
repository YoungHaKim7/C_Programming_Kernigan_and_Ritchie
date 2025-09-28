#include <stdio.h>

int main(void)
{
    char c = 'A'; // ASCII 65
    int i = 10;
    float f = 3.5f;
    double d = 7.25;

    // --- Implicit conversions ---
    double sum = i + f; // int promoted to float, result promoted to double
    printf("Implicit: i + f = %f (double)\n", sum);

    int ch_val = c + i; // char promoted to int
    printf("Implicit: c + i = %d (int)\n", ch_val);

    // --- Explicit conversions (casts) ---
    int int_from_double = (int)d; // truncate fractional part
    printf("Explicit: (int)d = %d\n", int_from_double);

    float float_from_int = (float)i; // int -> float
    printf("Explicit: (float)i = %f\n", float_from_int);

    unsigned int ui = (unsigned int)-42; // signed -> unsigned conversion
    printf("Explicit: (unsigned int)-42 = %u\n", ui);

    // Mixed example: integer division vs float division
    int div1 = 5 / 2; // integer division → 2
    float div2 = (float)5 / 2; // cast forces float division → 2.5
    printf("5 / 2 (int) = %d, (float)5 / 2 = %f\n", div1, div2);

    return 0;
}
