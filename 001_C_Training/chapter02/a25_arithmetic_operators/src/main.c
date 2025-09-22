#include <stdio.h>

#define MAXLINE 1000

int main(void)
{
    int year = 2024; // integer variable
    char newline = '\n'; // character
    char line[MAXLINE]; // character array
    float grades[3] = { 90.5, 85.0, 78.5 }; // float array
    int lower = 0, upper = 300, step = 20; // integers
    float eps = 1.0e-5; // float constant
    const double e = 2.71828182845905; // mathematical constant
    const char msg[] = "warning: "; // string constant

    // Leap year check using year
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        printf("%d is a leap year%c", year, newline);
    } else {
        printf("%d is not a leap year%c", year, newline);
    }

    // Use lower, upper, step in a simple Fahrenheit to Celsius table
    printf("\nFahrenheit to Celsius table:\n");
    for (int fahr = lower; fahr <= upper; fahr += step) {
        float celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3d F = %6.2f C\n", fahr, celsius);
    }

    // Use grades array
    printf("\nStudent grades:\n");
    for (int i = 0; i < 3; i++) {
        printf("Grade[%d] = %.2f\n", i, grades[i]);
    }

    // Use eps and e
    printf("\nConstant e = %.14f\n", e);
    printf("Epsilon (eps) = %g\n", eps);

    // Use msg and line
    snprintf(line, sizeof(line), "%s This is just a test.", msg);
    printf("\nMessage buffer: %s\n", line);

    return 0;
}
