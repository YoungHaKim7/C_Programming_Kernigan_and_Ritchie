#include <stddef.h>
#include <stdio.h>

#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char* allocp = allocbuf; /* next free position */

char* alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else /* not enough room */
        return 0;
}

void afree(char* p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

/* strlen: return length of string s */
int strlen(char* s)
{
    char* p = s;
    while (*p != '\0')
        p++;
    return p - s;
}

/* Test functions demonstrating pointer arithmetic */
void test_alloc_afree(void)
{
    printf("=== Testing alloc and afree ===\n");

    char *p1, *p2, *p3;

    p1 = alloc(100);
    printf("Allocated 100 chars at %p\n", (void*)p1);

    p2 = alloc(200);
    printf("Allocated 200 chars at %p\n", (void*)p2);

    p3 = alloc(300);
    printf("Allocated 300 chars at %p\n", (void*)p3);

    printf("Buffer usage: %ld/%d bytes\n",
        allocp - allocbuf, ALLOCSIZE);

    afree(p3);
    printf("Freed p3, buffer usage: %ld/%d bytes\n",
        allocp - allocbuf, ALLOCSIZE);

    afree(p2);
    printf("Freed p2, buffer usage: %ld/%d bytes\n",
        allocp - allocbuf, ALLOCSIZE);

    afree(p1);
    printf("Freed p1, buffer usage: %ld/%d bytes\n",
        allocp - allocbuf, ALLOCSIZE);
}

void test_pointer_arithmetic(void)
{
    printf("\n=== Testing Pointer Arithmetic ===\n");

    int arr[] = { 10, 20, 30, 40, 50 };
    int* p = arr;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Pointer arithmetic demonstrations:\n");
    printf("p points to: %d (address %p)\n", *p, (void*)p);
    printf("p+1 points to: %d (address %p)\n", *(p + 1), (void*)(p + 1));
    printf("p+2 points to: %d (address %p)\n", *(p + 2), (void*)(p + 2));

    printf("Pointer increment:\n");
    p++;
    printf("After p++, p points to: %d (address %p)\n", *p, (void*)p);

    printf("Pointer addition:\n");
    p += 2;
    printf("After p+=2, p points to: %d (address %p)\n", *p, (void*)p);

    printf("Pointer subtraction:\n");
    ptrdiff_t diff = p - arr;
    printf("p - arr = %ld (elements between them)\n", (long)diff);
}

void test_strlen(void)
{
    printf("\n=== Testing strlen with Pointer Arithmetic ===\n");

    char* test_strings[] = {
        "Hello",
        "C Programming",
        "",
        "Pointer arithmetic is cool!",
        NULL
    };

    for (int i = 0; test_strings[i] != NULL; i++) {
        int len = strlen(test_strings[i]);
        printf("String: \"%s\" has length %d\n", test_strings[i], len);
    }
}

void test_pointer_comparisons(void)
{
    printf("\n=== Testing Pointer Comparisons ===\n");

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* start = arr;
    int* end = arr + sizeof(arr) / sizeof(arr[0]) - 1;
    int* middle = arr + 4;

    printf("Array: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]\n");
    printf("start points to: %d\n", *start);
    printf("middle points to: %d\n", *middle);
    printf("end points to: %d\n", *end);

    printf("Pointer comparisons:\n");
    printf("start < middle: %s\n", start < middle ? "true" : "false");
    printf("middle < end: %s\n", middle < end ? "true" : "false");
    printf("start == middle: %s\n", start == middle ? "true" : "false");
    printf("start != end: %s\n", start != end ? "true" : "false");
}

void test_array_pointer_equivalence(void)
{
    printf("\n=== Testing Array-Pointer Equivalence ===\n");

    int arr[] = { 100, 200, 300, 400, 500 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Using array notation:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d (address %p)\n", i, arr[i], (void*)&arr[i]);
    }

    printf("\nUsing pointer notation:\n");
    for (int i = 0; i < n; i++) {
        printf("*(arr+%d) = %d (address %p)\n", i, *(arr + i), (void*)(arr + i));
    }

    printf("\nUsing pointer variable:\n");
    int* p = arr;
    for (int i = 0; i < n; i++) {
        printf("p[%d] = %d (address %p)\n", i, p[i], (void*)&p[i]);
    }
}

void test_pointer_and_null(void)
{
    printf("\n=== Testing NULL Pointer ===\n");

    char* p = NULL;
    printf("NULL pointer value: %p\n", (void*)p);

    p = alloc(50);
    if (p != NULL) {
        printf("Alloc successful, pointer is not NULL: %p\n", (void*)p);
    } else {
        printf("Alloc failed, pointer is NULL\n");
    }

    /* Try to allocate too much */
    char* big_alloc = alloc(ALLOCSIZE + 1000);
    if (big_alloc == NULL) {
        printf("Big allocation failed as expected (returned NULL)\n");
    }
}

void test_memory_alignment(void)
{
    printf("\n=== Testing Memory Alignment ===\n");

    /* Test different data types */
    int* int_ptr = (int*)alloc(sizeof(int) * 5);
    double* double_ptr = (double*)alloc(sizeof(double) * 3);
    char* char_ptr = alloc(10);

    printf("int pointer address: %p (alignment: %ld)\n",
        (void*)int_ptr, (size_t)int_ptr % sizeof(int));
    printf("double pointer address: %p (alignment: %ld)\n",
        (void*)double_ptr, (size_t)double_ptr % sizeof(double));
    printf("char pointer address: %p\n", (void*)char_ptr);

    /* Store some values */
    if (int_ptr != NULL) {
        for (int i = 0; i < 5; i++) {
            int_ptr[i] = (i + 1) * 100;
        }
        printf("Stored integers: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", int_ptr[i]);
        }
        printf("\n");
    }

    if (double_ptr != NULL) {
        for (int i = 0; i < 3; i++) {
            double_ptr[i] = (i + 1) * 3.14159;
        }
        printf("Stored doubles: ");
        for (int i = 0; i < 3; i++) {
            printf("%.2f ", double_ptr[i]);
        }
        printf("\n");
    }
}

int main(void)
{
    printf("Chapter 5.4: Address Arithmetic Examples\n");
    printf("========================================\n");

    test_alloc_afree();
    test_pointer_arithmetic();
    test_strlen();
    test_pointer_comparisons();
    test_array_pointer_equivalence();
    test_pointer_and_null();
    test_memory_alignment();

    printf("\nAll tests completed successfully!\n");
    return 0;
}