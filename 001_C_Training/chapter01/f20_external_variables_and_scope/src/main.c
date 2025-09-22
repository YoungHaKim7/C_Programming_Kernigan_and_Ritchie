#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getline02(void);
void copy(void);

int max;                 /* maximum length seen so far */
char line[MAXLINE];      /* current input line */
char longest[MAXLINE];   /* longest line saved here */

/* getline02: read a line into `line`, return length */
int getline02(void)
{
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: copy `line` into `longest` */
void copy(void)
{
    int i = 0;
    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}


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

