#include <stdio.h>

int main()
{
    // Pre-defined input (consider making this a parameter or array of char)
    // For simplicity, we'll use an array for direct "hard-coded" input
    const char input[]
        = "\nHello\n123  \nWorld \n4200  68 90\n"; // Adjust to match your exact
                                                   // input

    int c;
    int nwhite = 0, n = 0, nother = 0, ndigit[10] = { 0 }; // Initialize counts

    for (c = 0; input[c] != '\0';
        c++) { // Use loop to process each character as if from getchar()
        switch (input[c]) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': // Digits
            ndigit[input[c] - '0']++;
            break;
        case ' ':
        case '\t':
            nwhite++; // Space or tab
            break;
        case '\n':
            n++; // New Line
            break;
        default: // Any other character (non-digit, non-space/tab)
            nother++;
            break;
        }
    }

    // Print results
    printf("\ndigits =\n");
    for (int i = 0; i < 10; i++) {
        if (ndigit[i])
            printf("%d the total number of numbers : %d ea\n", i, ndigit[i]);
        else
            printf("%d the total number of numbers : 0 ea\n",
                i); // Clean up empty digits if any
    }
    printf("\n White Space = %d\n New Line = %d\n Letters, etc, other = %d\n",
        nwhite, n, nother);
    printf("\nDone!\n");

    return 0;
}
