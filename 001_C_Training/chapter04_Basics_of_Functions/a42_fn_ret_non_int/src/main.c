#include <stdio.h>
#include <ctype.h>  // for isspace, isdigit

double atof_custom(char s[])
{
    double val, power;
    int i, sign;

    // Skip leading whitespace
    for (i = 0; isspace((unsigned char)s[i]); i++)
        ;

    // Handle sign
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    // Integer part
    for (val = 0.0; isdigit((unsigned char)s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // Fractional part
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit((unsigned char)s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}

int main(void)
{
    char *tests[] = {
        "123",
        "-456",
        "+42",
        "3.14159",
        "-0.001",
        "10.0",
        "0",
        "123.456",
        "007.89",
        "   -987.654"
    };

    int ntests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < ntests; i++) {
        printf("Test %2d: input=\"%s\"  =>  result=%f\n",
               i + 1, tests[i], atof_custom(tests[i]));
    }

    return 0;
}
