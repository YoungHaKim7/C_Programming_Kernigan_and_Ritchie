#include <stdio.h>

/* month_name: return name of n-th month */
char* month_name(int n)
{
    static char* name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(void)
{
    int test_cases[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, -1 };
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("Testing month_name function:\n");
    printf("==========================\n");

    for (int i = 0; i < num_tests; i++) {
        int month_num = test_cases[i];
        char* month_str = month_name(month_num);
        printf("month_name(%2d) -> %s\n", month_num, month_str);
    }

    // Additional specific test cases
    printf("\nAdditional specific tests:\n");
    printf("==========================\n");

    // Test edge cases
    printf("Edge case test - month_name(1) = %s\n", month_name(1));
    printf("Edge case test - month_name(12) = %s\n", month_name(12));

    // Test invalid values
    printf("Invalid test - month_name(0) = %s\n", month_name(0));
    printf("Invalid test - month_name(13) = %s\n", month_name(13));
    printf("Invalid test - month_name(-5) = %s\n", month_name(-5));

    // Test typical usage
    printf("Typical test - month_name(6) = %s\n", month_name(6));
    printf("Typical test - month_name(8) = %s\n", month_name(8));
    printf("Typical test - month_name(11) = %s\n", month_name(11));

    return 0;
}