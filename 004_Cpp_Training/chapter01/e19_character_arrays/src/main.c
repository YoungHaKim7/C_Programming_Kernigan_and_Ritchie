#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline01(char s[], int lim);

void copy(char to[], char from[]);
/* print the longest input line */

/* getline: read a line into s, return length int getline(char s[],int lim)
 */
int getline01(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int main()
{
    printf("Type some text (Ctrl+D to end):\n");

    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = getline01(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("%s", longest);

    printf("\nDone!\n");

    return 0;
}
