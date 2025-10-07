#include <stdio.h>

#include "headers/common.h"

char line[MAXLINE];
char longest[MAXLINE];
int max;

/* print longest input line */
int main(void)
{
    printf("Type some text (Ctrl+D to end):\n");

    int len;

    max = 0;
    while ((len = getline02()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0) { /* there was a line */
        printf("%s", longest);
    }

    printf("\nDone!\n");

    return 0;
}
