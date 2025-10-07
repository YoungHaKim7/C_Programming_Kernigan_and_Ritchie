#include <stdio.h>

int main(void)
{
    printf("Type some text (Ctrl+D to end):\n");

    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }

    printf("\nDone!\n");

    return 0;
}
