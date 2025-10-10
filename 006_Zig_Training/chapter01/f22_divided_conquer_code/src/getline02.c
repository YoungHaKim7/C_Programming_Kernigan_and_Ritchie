#include <stdio.h>

#include "headers/common.h"

/* getline02: read a line into `line`, return length */
int getline02(void)
{
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {

        line[i] = c;
        if (c == '\n') {
            line[i] = c;
            ++i;
        }
    }
    line[i] = '\0';
    return i;
}
