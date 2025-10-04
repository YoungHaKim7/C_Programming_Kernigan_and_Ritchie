#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

// Get a (possibly pushed-back) character
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// Push character back on input
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int main(void)
{
    printf("Example 1: push 'A' and getch() it back\n");
    ungetch('A');
    printf("  Output: %c\n\n", getch());

    printf("Example 2: push 'B' and 'C', then read twice\n");
    ungetch('B');
    ungetch('C'); // Last-in, first-out
    printf("  Output 1: %c\n", getch());
    printf("  Output 2: %c\n\n", getch());

    printf("Example 3: push then overwrite (check LIFO)\n");
    ungetch('X');
    ungetch('Y');
    ungetch('Z');
    printf("  Expected order: Z, Y, X\n");
    printf("  Output: %c %c %c\n\n", getch(), getch(), getch());

    printf("Example 4: getch() with no push — type something manually:\n");
    int c = getch(); // waits for keyboard input
    printf("  You typed: %c\n\n", c);

    printf("Example 5: simulate string input using ungetch\n");
    const char* msg = "Hello";
    for (int i = 0; msg[i] != '\0'; i++)
        ungetch(msg[i]);
    printf("  Reading characters back: ");
    for (int i = 0; i < 5; i++)
        putchar(getch());
    putchar('\n');
    putchar('\n');

    printf("Example 6: push numeric chars '1','2','3'\n");
    ungetch('1');
    ungetch('2');
    ungetch('3');
    printf("  Output: %c %c %c\n\n", getch(), getch(), getch());

    printf("Example 7: push space and punctuation\n");
    ungetch('!');
    ungetch(' ');
    ungetch('?');
    printf("  Output: %c%c%c\n\n", getch(), getch(), getch());

    printf("Example 8: fill buffer and test overflow message\n");
    for (int i = 0; i < BUFSIZE + 1; i++)
        ungetch('x');
    printf("  (Should print overflow warning once)\n\n");

    printf("Example 9: mix push and typed input\n");
    ungetch('M');
    printf("  You will type one char: ");
    int user = getchar();
    printf("\n  getch() gives: %c, then typed: %c\n\n", getch(), user);

    printf("Example 10: verify buffer is empty after all reads\n");
    if (bufp == 0)
        printf("  Buffer is empty ✅\n");
    else
        printf("  Buffer still has %d chars ❌\n", bufp);

    return 0;
}
