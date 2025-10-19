#include <stdio.h>
#include <string.h>
#include <assert.h>

/* Test version of strlen */
int strlen_test(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

/* Test function to verify pointer arithmetic */
void test_pointer_arithmetic()
{
    printf("Testing pointer arithmetic...\n");

    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    // Test basic pointer dereferencing
    assert(*ptr == 10);
    assert(*(ptr + 1) == 20);
    assert(*(ptr + 2) == 30);

    // Test pointer increment
    ptr++;
    assert(*ptr == 20);

    // Test array indexing with pointer
    assert(ptr[0] == 20);
    assert(ptr[1] == 30);
    assert(ptr[2] == 40);

    printf("✓ Pointer arithmetic tests passed\n\n");
}

/* Test array and pointer equivalence */
void test_array_pointer_equivalence()
{
    printf("Testing array-pointer equivalence...\n");

    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    // Test that array name and &arr[0] are equivalent
    assert(arr == &arr[0]);

    // Test that arr[i] == *(arr + i) == *(ptr + i) == ptr[i]
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == *(arr + i));
        assert(arr[i] == *(ptr + i));
        assert(arr[i] == ptr[i]);
        assert(&arr[i] == arr + i);
        assert(&arr[i] == ptr + i);
    }

    printf("✓ Array-pointer equivalence tests passed\n\n");
}

/* Test strlen implementation */
void test_strlen()
{
    printf("Testing strlen implementation...\n");

    // Test various strings
    assert(strlen_test("") == 0);
    assert(strlen_test("a") == 1);
    assert(strlen_test("hello") == 5);
    assert(strlen_test("hello, world") == 12);

    // Test with char array
    char str[] = "C programming";
    assert(strlen_test(str) == 13);

    printf("✓ strlen tests passed\n\n");
}

/* Test subarray operations */
void test_subarrays()
{
    printf("Testing subarray operations...\n");

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Test that &arr[2] == arr + 2
    assert(&arr[2] == arr + 2);

    // Test accessing elements through subarray pointers
    int *subarray = &arr[3];
    assert(subarray[0] == 4);  // arr[3]
    assert(subarray[1] == 5);  // arr[4]
    assert(subarray[2] == 6);  // arr[5]

    // Test backward indexing (be careful not to go out of bounds)
    int *ptr = &arr[5];
    assert(ptr[-1] == 5);  // arr[4]
    assert(ptr[-2] == 4);  // arr[3]

    printf("✓ Subarray tests passed\n\n");
}

/* Test pointer operations */
void test_pointer_operations()
{
    printf("Testing pointer operations...\n");

    int arr[] = {100, 200, 300};
    int *ptr1 = arr;
    int *ptr2 = &arr[1];

    // Test pointer assignment
    int *ptr3 = ptr1;
    assert(ptr3 == ptr1);
    assert(*ptr3 == *ptr1);

    // Test pointer arithmetic
    ptr1++;
    assert(ptr1 == ptr2);
    assert(*ptr1 == *ptr2);

    // Test pointer difference
    int diff = ptr2 - arr;
    assert(diff == 1);

    printf("✓ Pointer operations tests passed\n\n");
}

/* Test string operations with pointers */
void test_string_pointers()
{
    printf("Testing string pointer operations...\n");

    char str[] = "hello";
    char *ptr = str;

    // Test character access
    assert(*ptr == 'h');
    assert(*(ptr + 1) == 'e');
    assert(ptr[2] == 'l');

    // Test traversing string with pointer
    int count = 0;
    while (*ptr != '\0') {
        count++;
        ptr++;
    }
    assert(count == 5);

    printf("✓ String pointer tests passed\n\n");
}

int main()
{
    printf("=== Running Pointer and Array Tests ===\n\n");

    test_pointer_arithmetic();
    test_array_pointer_equivalence();
    test_strlen();
    test_subarrays();
    test_pointer_operations();
    test_string_pointers();

    printf("🎉 All tests passed successfully!\n");

    return 0;
}