#include <stdio.h>

#define MAXLINE 1000
char line[MAXLINE + 1];

#define LEAP 1 /* in leap years */
int days[31 + 28 + LEAP + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31];

enum boolean { NO, YES };

enum escapes {
    BELL = '\a',
    BACKSPACE = '\b',
    TAB = '\t',
    NEWLINE = '\n',
    VTAB = '\v',
    RETURN = '\r'
};

enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

/* strlen: return length of s */
int strlen(char s[])
{
    int i = 0; // initialize i
    while (s[i] != '\0') // loop until null terminator
        ++i;
    return i;
}

int main(void)
{
    char test[] = "Hello, world!";

    printf("String: %s\n", test);
    printf("Length (using custom strlen): %d\n", strlen(test));

    printf("Boolean NO=%d, YES=%d\n", NO, YES);

    printf("Escape example: TAB='%c', NEWLINE='\\n'\n", TAB);
    printf("Months: JAN=%d, FEB=%d, DEC=%d\n", JAN, FEB, DEC);

    printf("Days array has %zu entries\n", sizeof(days) / sizeof(days[0]));

    return 0;
}
