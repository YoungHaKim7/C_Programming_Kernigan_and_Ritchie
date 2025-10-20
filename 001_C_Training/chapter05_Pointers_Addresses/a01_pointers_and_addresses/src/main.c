#include <stdio.h>

int main()
{
    printf("=== Pointer Examples ===\n\n");

    // Example 1: Basic pointer declaration and assignment
    printf("1. Basic pointer declaration and assignment:\n");
    int x = 42;
    int* ptr = &x;
    printf("   Value of x: %d\n", x);
    printf("   Address of x: %p\n", (void*)&x);
    printf("   Pointer ptr points to: %p\n", (void*)ptr);
    printf("   Value pointed to by ptr: %d\n\n", *ptr);

    // Example 2: Pointer arithmetic
    printf("2. Pointer arithmetic:\n");
    int arr[] = { 10, 20, 30, 40, 50 };
    int* arr_ptr = arr;
    printf("   First element: %d\n", *arr_ptr);
    printf("   Second element (arr_ptr + 1): %d\n", *(arr_ptr + 1));
    printf("   Third element (arr_ptr + 2): %d\n\n", *(arr_ptr + 2));

    // Example 3: Pointer to pointer
    printf("3. Pointer to pointer:\n");
    int y = 100;
    int* p1 = &y;
    int** p2 = &p1;
    printf("   Value of y: %d\n", y);
    printf("   Value pointed to by p1: %d\n", *p1);
    printf("   Value pointed to by *p2: %d\n\n", **p2);

    // Example 4: Null pointer
    printf("4. Null pointer:\n");
    int* null_ptr = NULL;
    printf("   Null pointer value: %p\n", (void*)null_ptr);
    if (null_ptr == NULL) {
        printf("   Pointer is NULL\n\n");
    }

    // Example 5: Pointer to char (string)
    printf("5. Pointer to char (string):\n");
    char* str = "Hello, World!";
    printf("   String: %s\n", str);
    printf("   First character: %c\n", *str);
    printf("   Second character: %c\n\n", *(str + 1));

    // Example 6: Function pointer
    printf("6. Function pointer:\n");
    int (*func_ptr)(int, int) = NULL;
    printf("   Function pointer declared\n\n");

    // Example 7: Pointer and array relationship
    printf("7. Pointer and array relationship:\n");
    int numbers[] = { 1, 2, 3, 4, 5 };
    int* num_ptr = numbers;
    printf("   Array access using []: %d\n", numbers[2]);
    printf("   Pointer access using *: %d\n", *(num_ptr + 2));
    printf("   Array size using sizeof: %zu\n", sizeof(numbers));
    printf("   Pointer size: %zu\n\n", sizeof(num_ptr));

    // Example 8: Dynamic memory allocation simulation
    printf("8. Dynamic memory allocation simulation:\n");
    int dynamic_val = 999;
    int* dynamic_ptr = &dynamic_val;
    printf("   Dynamically allocated value: %d\n", *dynamic_ptr);
    printf("   Address of dynamically allocated: %p\n\n", (void*)dynamic_ptr);

    // Example 9: Pointer comparison
    printf("9. Pointer comparison:\n");
    int a = 10, b = 20;
    int *ptr_a = &a, *ptr_b = &b;
    printf("   Address of a: %p\n", (void*)ptr_a);
    printf("   Address of b: %p\n", (void*)ptr_b);
    printf("   ptr_a < ptr_b: %s\n\n", ptr_a < ptr_b ? "true" : "false");

    // Example 10: Pointer with different data types
    printf("10. Pointer with different data types:\n");
    char c = 'A';
    short s = 32767;
    long l = 1234567890L;

    char* char_ptr = &c;
    short* short_ptr = &s;
    long* long_ptr = &l;

    printf("    Char value: %c, size: %zu bytes\n", *char_ptr, sizeof(char));
    printf("    Short value: %d, size: %zu bytes\n", *short_ptr, sizeof(short));
    printf("    Long value: %ld, size: %zu bytes\n", *long_ptr, sizeof(long));

    return 0;
}
