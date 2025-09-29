#include <stdio.h>

int main(void)
{
    int ch;

    printf("Type some text (Ctrl+D to end):\n");

    // for loop version
    for (ch = getchar(); ch != EOF; ch = getchar()) {
        putchar(ch); // echo back the character
    }

    printf("\nDone!\n");
    return 0;
}
