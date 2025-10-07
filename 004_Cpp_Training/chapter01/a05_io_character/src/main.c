#include <stdio.h>

int main(void)
{
    // ch 숫자로 선언
    int ch;

    printf("Type some text (Ctrl+D to end):\n");

    // EOF end of file
    // getchar() returns int, not char (to handle EOF properly)
    // global variable     // local variable 지역 변수
    // ch -> local variable
    while ((ch = getchar()) != EOF) {
        putchar(ch); // echo back the character
    }

    printf("\nDone!\n");
    return 0;
}
