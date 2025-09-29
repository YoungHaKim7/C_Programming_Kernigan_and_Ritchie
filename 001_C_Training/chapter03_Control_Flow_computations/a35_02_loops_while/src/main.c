#include <stdio.h>

int main(void)
{
    // ch 숫자로 선언
    int ch;

    printf("Type some text (Ctrl+D to end):\n");

    while ((ch = getchar()) != EOF) {
        putchar(ch); // echo back the character
    }

    printf("\nDone!\n");
    return 0;
}
