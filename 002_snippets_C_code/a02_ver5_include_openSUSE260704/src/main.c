#include "conio.h"
#include <stdio.h>

int main(void) {
    int nChar;

    while (1) {
        if (kbhit()) {
            nChar = getch();
            if (nChar == 'q')
                break;
            printf("%c", nChar);
        }
    }

    return 0;
}
