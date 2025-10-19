#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   /* max #lines to be sorted */
#define MAXLEN 1000     /* max length of any input line */
#define ALLOCSIZE 10000 /* size of available space */

char *lineptr[MAXLINES]; /* pointers to text lines */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;   /* next free position */

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);
int my_getline(char *, int);
char *alloc(int);

void demonstrate_pointer_arrays();
void demonstrate_pointers_to_pointers();
void demonstrate_sorting();
void demonstrate_memory_layout();
void demonstrate_pointer_arithmetic();

/* Main function with 10 comprehensive examples */
int main()
{
    printf("=== Chapter 5.6: Pointer Arrays; Pointers to Pointers ===\n\n");

    /* Example 1: Basic Pointer Array Declaration */
    printf("Example 1: Basic Pointer Array Declaration\n");
    printf("-----------------------------------------\n");
    char *fruits[] = {"apple", "banana", "cherry", "date"};
    printf("Array of fruit names:\n");
    for (int i = 0; i < 4; i++) {
        printf("  fruits[%d] = \"%s\" (address: %p)\n", i, fruits[i], (void*)fruits[i]);
    }
    printf("\n");

    /* Example 2: Pointer Arrays with Dynamic Allocation */
    printf("Example 2: Pointer Arrays with Dynamic Allocation\n");
    printf("-----------------------------------------------\n");
    char *names[5];
    char name1[] = "Alice";
    char name2[] = "Bob";
    char name3[] = "Charlie";
    names[0] = name1;
    names[1] = name2;
    names[2] = name3;
    names[3] = "David";
    names[4] = "Eve";

    printf("Dynamically assigned names:\n");
    for (int i = 0; i < 5; i++) {
        printf("  names[%d] = \"%s\" (length: %zu)\n", i, names[i], strlen(names[i]));
    }
    printf("\n");

    /* Example 3: Sorting with Pointer Arrays */
    printf("Example 3: Sorting with Pointer Arrays\n");
    printf("-------------------------------------\n");
    demonstrate_sorting();
    printf("\n");

    /* Example 4: Pointers to Pointers */
    printf("Example 4: Pointers to Pointers\n");
    printf("-----------------------------\n");
    demonstrate_pointers_to_pointers();
    printf("\n");

    /* Example 5: Memory Layout Demonstration */
    printf("Example 5: Memory Layout of Pointer Arrays\n");
    printf("------------------------------------------\n");
    demonstrate_memory_layout();
    printf("\n");

    /* Example 6: Pointer Arithmetic with Pointer Arrays */
    printf("Example 6: Pointer Arithmetic with Pointer Arrays\n");
    printf("-------------------------------------------------\n");
    demonstrate_pointer_arithmetic();
    printf("\n");

    /* Example 7: Two-dimensional Arrays vs Pointer Arrays */
    printf("Example 7: Two-dimensional Arrays vs Pointer Arrays\n");
    printf("--------------------------------------------------\n");
    char two_d[][20] = {"first", "second", "third"};
    char *ptr_array[] = {"first", "second", "third"};

    printf("2D array:\n");
    for (int i = 0; i < 3; i++) {
        printf("  two_d[%d] = \"%s\" (size: %zu bytes)\n", i, two_d[i], sizeof(two_d[i]));
    }

    printf("Pointer array:\n");
    for (int i = 0; i < 3; i++) {
        printf("  ptr_array[%d] = \"%s\" (pointer size: %zu bytes)\n", i, ptr_array[i], sizeof(ptr_array[i]));
    }
    printf("\n");

    /* Example 8: Command-line Arguments Simulation */
    printf("Example 8: Command-line Arguments Simulation\n");
    printf("--------------------------------------------\n");
    char *argv[] = {"program", "arg1", "arg2", "arg3", "arg4"};
    int argc = 5;

    printf("Simulated command line: ");
    for (int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    printf("Arguments:\n");
    for (int i = 1; i < argc; i++) {
        printf("  argv[%d] = \"%s\"\n", i, argv[i]);
    }
    printf("\n");

    /* Example 9: Array of Function Pointers */
    printf("Example 9: Array of Function Pointers\n");
    printf("-------------------------------------\n");
    int (*operations[])(const char*, const char*) = {strcmp};
    char *str1 = "Hello";
    char *str2 = "hello";

    printf("Comparing \"%s\" and \"%s\":\n", str1, str2);
    printf("  Case-sensitive: %d\n", operations[0](str1, str2));
    printf("\n");

    /* Example 10: Complete Sorting Program */
    printf("Example 10: Complete Sorting Program Demonstration\n");
    printf("-------------------------------------------------\n");
    demonstrate_pointer_arrays();
    printf("\n");

    return 0;
}

void demonstrate_sorting()
{
    char *test_strings[] = {
        "zebra",
        "apple",
        "orange",
        "banana",
        "grape",
        "kiwi",
        "mango",
        "pear"
    };
    int n = 8;

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("  %s\n", test_strings[i]);
    }

    /* Simple bubble sort using pointer array */
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(test_strings[j], test_strings[j+1]) > 0) {
                char *temp = test_strings[j];
                test_strings[j] = test_strings[j+1];
                test_strings[j+1] = temp;
            }
        }
    }

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("  %s\n", test_strings[i]);
    }
}

void demonstrate_pointers_to_pointers()
{
    char *colors[] = {"red", "green", "blue"};
    char **ptr_to_colors = colors;

    printf("Original array:\n");
    for (int i = 0; i < 3; i++) {
        printf("  colors[%d] = \"%s\"\n", i, colors[i]);
    }

    printf("\nUsing pointer to pointer:\n");
    for (int i = 0; i < 3; i++) {
        printf("  *(ptr_to_colors + %d) = \"%s\"\n", i, *(ptr_to_colors + i));
    }

    printf("\nDereferencing twice:\n");
    for (int i = 0; i < 3; i++) {
        printf("  *(*(ptr_to_colors + %d) + 0) = '%c'\n", i, *(*(ptr_to_colors + i) + 0));
    }
}

void demonstrate_memory_layout()
{
    char *strings[] = {"short", "medium_length", "very_long_string_that_takes_more_space"};

    printf("Memory layout of pointer array:\n");
    for (int i = 0; i < 3; i++) {
        printf("  Element %d:\n", i);
        printf("    Pointer address: %p\n", (void*)&strings[i]);
        printf("    Points to: %p\n", (void*)strings[i]);
        printf("    String value: \"%s\"\n", strings[i]);
        printf("    String length: %zu\n", strlen(strings[i]));
    }
}

void demonstrate_pointer_arithmetic()
{
    char *words[] = {"alpha", "beta", "gamma", "delta"};
    char **ptr = words;

    printf("Pointer arithmetic demonstration:\n");
    printf("  Base address: %p\n", (void*)ptr);
    printf("  *ptr = \"%s\"\n", *ptr);
    printf("  *(ptr + 1) = \"%s\"\n", *(ptr + 1));
    printf("  *(ptr + 2) = \"%s\"\n", *(ptr + 2));
    printf("  ptr[3] = \"%s\"\n", ptr[3]);

    printf("\nIncrementing pointer:\n");
    ptr++;
    printf("  After ptr++, *ptr = \"%s\"\n", *ptr);
    printf("  New address: %p\n", (void*)ptr);
}

void demonstrate_pointer_arrays()
{
    /* Read some predefined lines for demonstration */
    char demo_lines[][50] = {
        "This is a demonstration",
        "of pointer arrays",
        "and how they work",
        "for sorting text",
        "efficiently"
    };
    int nlines = 5;

    /* Copy into our lineptr array */
    for (int i = 0; i < nlines; i++) {
        lineptr[i] = demo_lines[i];
    }

    printf("Original lines:\n");
    writelines(lineptr, nlines);

    qsort(lineptr, 0, nlines-1);

    printf("\nSorted lines:\n");
    writelines(lineptr, nlines);
}

/* my_getline: read a line into s, return length */
int my_getline(char *s, int lim)
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

/* alloc: return pointer to n characters */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else { /* not enough room */
        return 0;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("  %s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}