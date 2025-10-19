#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 100
#define MAXLEN 1000
#define ALLOCSIZE 5000

char* lineptr[MAXLINES];
static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

/* Function declarations from main program */
int readlines(char* lineptr[], int maxlines);
void writelines(char* lineptr[], int nlines);
void qsort(char* lineptr[], int left, int right);
void swap(char* v[], int i, int j);
int my_getline(char*, int);
char* alloc(int);

/* Test helper functions */
void test_alloc();
void test_swap();
void test_qsort();
void test_sorting_algorithm();
void test_edge_cases();

int main()
{
    printf("=== Testing Chapter 5.6 Pointer Arrays Implementation ===\n\n");

    test_alloc();
    test_swap();
    test_qsort();
    test_sorting_algorithm();
    test_edge_cases();

    printf("=== All tests completed! ===\n");
    return 0;
}

void test_alloc()
{
    printf("Testing alloc() function:\n");

    allocp = allocbuf; /* Reset allocator */

    char* ptr1 = alloc(10);
    char* ptr2 = alloc(20);
    char* ptr3 = alloc(5);

    printf("  Test 1: Basic allocation - ");
    if (ptr1 != NULL && ptr2 != NULL && ptr3 != NULL) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    printf("  Test 2: Memory addresses are sequential - ");
    if (ptr2 == ptr1 + 10 && ptr3 == ptr2 + 20) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    printf("  Test 3: Out of memory handling - ");
    char* big_alloc = alloc(ALLOCSIZE + 1000);
    if (big_alloc == NULL) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    printf("\n");
}

void test_swap()
{
    printf("Testing swap() function:\n");

    char* strings[] = { "first", "second", "third" };

    printf("  Before swap: strings[0]=\"%s\", strings[1]=\"%s\"\n", strings[0], strings[1]);
    swap(strings, 0, 1);
    printf("  After swap: strings[0]=\"%s\", strings[1]=\"%s\"\n", strings[0], strings[1]);

    printf("  Test 1: Elements swapped correctly - ");
    if (strcmp(strings[0], "second") == 0 && strcmp(strings[1], "first") == 0) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    printf("  Test 2: Third element unchanged - ");
    if (strcmp(strings[2], "third") == 0) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    printf("\n");
}

void test_qsort()
{
    printf("Testing qsort() function:\n");

    char* test_data[] = { "zebra", "apple", "orange", "banana", "grape" };
    int n = 5;

    printf("  Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("    %s\n", test_data[i]);
    }

    qsort(test_data, 0, n - 1);

    printf("  After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("    %s\n", test_data[i]);
    }

    printf("  Test 1: Array is sorted - ");
    int sorted = 1;
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(test_data[i], test_data[i + 1]) > 0) {
            sorted = 0;
            break;
        }
    }
    if (sorted) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    printf("  Test 2: All original elements present - ");
    char* expected[] = { "apple", "banana", "grape", "orange", "zebra" };
    int all_present = 1;
    for (int i = 0; i < n; i++) {
        if (strcmp(test_data[i], expected[i]) != 0) {
            all_present = 0;
            break;
        }
    }
    if (all_present) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    printf("\n");
}

void test_sorting_algorithm()
{
    printf("Testing complete sorting algorithm:\n");

    /* Test with different types of strings */
    struct {
        char* input[10];
        int count;
        char* expected[10];
    } test_cases[] = {
        { { "cat", "dog", "bird", "fish" }, 4, { "bird", "cat", "dog", "fish" } },
        { { "Zebra", "apple", "Banana", "cherry" }, 4, { "Banana", "Zebra", "apple", "cherry" } },
        { { "a", "aa", "aaa", "a" }, 4, { "a", "a", "aa", "aaa" } },
        { { "", "a", "aa", "aaa" }, 4, { "", "a", "aa", "aaa" } }
    };

    for (int t = 0; t < 4; t++) {
        printf("  Test case %d:\n", t + 1);

        printf("    Input: ");
        for (int i = 0; i < test_cases[t].count; i++) {
            printf("\"%s\" ", test_cases[t].input[i]);
        }
        printf("\n");

        /* Copy test case to avoid modifying original */
        char* temp[10];
        for (int i = 0; i < test_cases[t].count; i++) {
            temp[i] = test_cases[t].input[i];
        }

        qsort(temp, 0, test_cases[t].count - 1);

        printf("    Output: ");
        for (int i = 0; i < test_cases[t].count; i++) {
            printf("\"%s\" ", temp[i]);
        }
        printf("\n");

        /* Check if sorted correctly */
        int correct = 1;
        for (int i = 0; i < test_cases[t].count - 1; i++) {
            if (strcmp(temp[i], temp[i + 1]) > 0) {
                correct = 0;
                break;
            }
        }

        printf("    Result: %s\n", correct ? "PASSED" : "FAILED");
    }

    printf("\n");
}

void test_edge_cases()
{
    printf("Testing edge cases:\n");

    /* Test with empty array */
    printf("  Test 1: Empty array - ");
    qsort(lineptr, 0, -1); /* Should not crash */
    printf("PASSED (no crash)\n");

    /* Test with single element */
    printf("  Test 2: Single element - ");
    char* single[] = { "single" };
    qsort(single, 0, 0);
    if (strcmp(single[0], "single") == 0) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    /* Test with duplicate elements */
    printf("  Test 3: Duplicate elements - ");
    char* duplicates[] = { "same", "same", "same", "same" };
    qsort(duplicates, 0, 3);
    int all_same = 1;
    for (int i = 0; i < 4; i++) {
        if (strcmp(duplicates[i], "same") != 0) {
            all_same = 0;
            break;
        }
    }
    if (all_same) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    /* Test with already sorted array */
    printf("  Test 4: Already sorted array - ");
    char* sorted[] = { "a", "b", "c", "d" };
    qsort(sorted, 0, 3);
    int still_sorted = 1;
    for (int i = 0; i < 3; i++) {
        if (strcmp(sorted[i], sorted[i + 1]) > 0) {
            still_sorted = 0;
            break;
        }
    }
    if (still_sorted) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    printf("\n");
}

/* Include implementations from main program */
char* alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

void swap(char* v[], int i, int j)
{
    char* temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(char* v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

int my_getline(char* s, int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int readlines(char* lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char* lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}