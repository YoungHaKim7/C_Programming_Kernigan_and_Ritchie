#include <stdio.h>

int main(void)
{
    int ch;

    printf("Type some text (Ctrl+D to end):\n");

    // getchar() returns int, not char (to handle EOF properly)
    while ((ch = getchar()) != EOF) {
        putchar(ch); // echo back the character
    }

    printf("\nDone!\n");
    return 0;
}
