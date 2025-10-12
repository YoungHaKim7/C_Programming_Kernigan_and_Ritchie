#include "array_utils.c"
#include "array_utils.h"
#include "math_utils.c"
#include "math_utils.h"
#include <stdio.h>

int main()
{
    printf("=== File Inclusion Demo: Managing Collections ===\n\n");

    // Math utilities collection
    printf("Math Utilities Collection:\n");
    printf("Add: 5 + 3 = %d\n", add(5, 3));
    printf("Multiply: 4 * 7 = %d\n", multiply(4, 7));
    printf("Factorial of 5 = %d\n", factorial(5));
    printf("Is 17 prime? %s\n", is_prime(17) ? "Yes" : "No");
    printf("Is 15 prime? %s\n", is_prime(15) ? "Yes" : "No");
    printf("\n");

    // Array utilities collection
    printf("Array Utilities Collection:\n");
    int numbers[] = { 64, 34, 25, 12, 22, 11, 90 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original array: ");
    print_array(numbers, size);

    printf("Max value: %d\n", find_max(numbers, size));
    printf("Min value: %d\n", find_min(numbers, size));
    printf("Average: %.2f\n", calculate_average(numbers, size));

    sort_array(numbers, size);
    printf("Sorted array: ");
    print_array(numbers, size);
    printf("\n");

    // Combining collections
    printf("Combined Operations Example:\n");
    int data[] = { 5, 3, 8, 1, 9, 2, 7 };
    int data_size = sizeof(data) / sizeof(data[0]);

    printf("Data array: ");
    print_array(data, data_size);

    // Find prime numbers in array and calculate their factorials
    printf("Prime numbers and their factorials:\n");
    for (int i = 0; i < data_size; i++) {
        if (is_prime(data[i])) {
            printf("  %d! = %d\n", data[i], factorial(data[i]));
        }
    }

    printf("\nFile inclusion makes it easy to organize and reuse collections of related functions!\n");

    return 0;
}
