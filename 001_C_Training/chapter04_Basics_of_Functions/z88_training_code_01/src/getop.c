#include "headers/calc.h"

// standard library I/O   input/output
#include <ctype.h>
#include <stdio.h>

int getop(char s[])
{
    int i = 0;
    int c;

    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (!isdigit(c) && c != '.')
        return c;

    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar()))
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetc(c, stdin);

    return NUMBER;
}

bool is_number(char s[])
{
    int i = 0;

    while (s[i] != '\0')
        if (!isdigit(s[i++]))
            return false;

    return true;
}
