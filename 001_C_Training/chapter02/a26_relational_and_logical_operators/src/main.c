#include <stdio.h>

int main(void)
{
    int i; // loop index
    int lim = 100; // maximum input size
    int c; // character input
    char s[100]; // character array (string buffer)
    int valid = 1; // boolean flag (1 = true, 0 = false)

    printf("Type some text (max %d chars, press Enter to stop):\n", lim - 1);

    // Read characters until limit-1, newline, or EOF
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        s[i] = c;
    }
    s[i] = '\0'; // terminate string

    // Check if input is valid (non-empty)
    if (i == 0) {
        valid = 0;
    }

    if (!valid) {
        printf("No valid input provided.\n");
        return 0;
    }

    // Use all variables:
    printf("\n--- Results ---\n");
    printf("You typed: %s\n", s); // uses s[]
    printf("Characters read: %d\n", i); // uses i
    printf("Last character code: %d\n", c); // uses c
    printf("Limit was: %d\n", lim); // uses lim
    printf("Valid flag: %d\n", valid); // uses valid

    return 0;
}
