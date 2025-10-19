#include <stdio.h>
#include <string.h>

/* strlen: return length of string s */
int strlen_custom(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

/* Function to demonstrate array parameter equivalence */
void print_array_int(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d ", i, arr[i]);
    }
    printf("\n");
}

/* Function using pointer notation */
void print_array_ptr(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("*(arr+%d) = %d ", i, *(arr + i));
    }
    printf("\n");
}

/* Function to process subarray */
void process_subarray(int *arr, int size)
{
    printf("Processing subarray of size %d: ", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("=== Pointers and Arrays Examples ===\n\n");

    /* Example 1: Basic array declaration and pointer assignment */
    printf("1. Basic array and pointer assignment:\n");
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *pa;
    pa = &a[0];  // or pa = a;

    printf("   a[0] = %d, *pa = %d\n", a[0], *pa);
    printf("   Address of a[0]: %p, pa: %p\n\n", (void*)&a[0], (void*)pa);

    /* Example 2: Pointer arithmetic */
    printf("2. Pointer arithmetic:\n");
    printf("   *(pa+1) = %d (should be a[1] = %d)\n", *(pa+1), a[1]);
    printf("   *(pa+3) = %d (should be a[3] = %d)\n", *(pa+3), a[3]);
    printf("   pa+2 points to address: %p\n", (void*)(pa+2));
    printf("   &a[2] is at address: %p\n\n", (void*)&a[2]);

    /* Example 3: Array indexing vs pointer arithmetic */
    printf("3. Array indexing vs pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("   a[%d] = %d, *(a+%d) = %d, *(pa+%d) = %d\n",
               i, a[i], i, *(a+i), i, *(pa+i));
    }
    printf("\n");

    /* Example 4: Address equivalence */
    printf("4. Address equivalence:\n");
    for (int i = 0; i < 3; i++) {
        printf("   &a[%d] = %p, a+%d = %p\n",
               i, (void*)&a[i], i, (void*)(a+i));
    }
    printf("\n");

    /* Example 5: Pointer with array notation */
    printf("5. Pointer with array notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("   pa[%d] = %d, *(pa+%d) = %d\n",
               i, pa[i], i, *(pa+i));
    }
    printf("\n");

    /* Example 6: strlen function examples */
    printf("6. strlen function examples:\n");
    char str1[] = "hello";
    char *str2 = "world";
    char str3[100] = "C programming";

    printf("   strlen_custom(\"hello\") = %d\n", strlen_custom(str1));
    printf("   strlen_custom(\"world\") = %d\n", strlen_custom(str2));
    printf("   strlen_custom(\"C programming\") = %d\n", strlen_custom(str3));
    printf("   strlen_custom(\"hello, world\") = %d\n\n", strlen_custom("hello, world"));

    /* Example 7: Array parameters vs pointer parameters */
    printf("7. Array vs pointer parameters:\n");
    int numbers[] = {10, 20, 30, 40, 50};
    int size = 5;

    printf("   Using array notation: ");
    print_array_int(numbers, size);

    printf("   Using pointer notation: ");
    print_array_ptr(numbers, size);
    printf("\n");

    /* Example 8: Passing subarrays to functions */
    printf("8. Passing subarrays to functions:\n");
    int big_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("   Full array: ");
    process_subarray(big_array, 10);

    printf("   Subarray starting at index 2: ");
    process_subarray(&big_array[2], 8);

    printf("   Subarray starting at index 5: ");
    process_subarray(big_array + 5, 5);
    printf("\n");

    /* Example 9: Pointer increment (legal) vs array increment (illegal) */
    printf("9. Pointer manipulation:\n");
    int temp[] = {100, 200, 300};
    int *ptr = temp;

    printf("   Initial: *ptr = %d\n", *ptr);
    ptr++;
    printf("   After ptr++: *ptr = %d\n", *ptr);
    ptr++;
    printf("   After another ptr++: *ptr = %d\n", *ptr);
    ptr--;
    printf("   After ptr--: *ptr = %d\n\n", *ptr);

    /* Example 10: Array name as address */
    printf("10. Array name as address:\n");
    char message[] = "Pointers and arrays";

    printf("    Array name 'message' = %p\n", (void*)message);
    printf("    &message[0] = %p\n", (void*)&message[0]);
    printf("    message[0] = '%c'\n", message[0]);
    printf("    *message = '%c'\n", *message);

    // Demonstrate that array name is not a variable (can't do message++)
    // But we can assign it to a pointer
    char *msg_ptr = message;
    printf("    msg_ptr = message, msg_ptr[1] = '%c'\n", msg_ptr[1]);

    return 0;
}