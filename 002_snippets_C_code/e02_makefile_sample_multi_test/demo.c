/*
 * Chapter 5.11: Pointers to Functions - Demonstration
 *
 * This program demonstrates the key concepts from section 5.11:
 * 1. Function pointers and their usage
 * 2. Different comparison functions (lexicographic, numeric, case folding, directory order)
 * 3. Using function pointers to customize sorting behavior
 * 4. Exercise solutions: -r, -f, -d flags
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 10
#define MAXLEN 100

char *lineptr[MAXLINES];

// Function prototypes demonstrating function pointers
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort_demo(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);

// Different comparison functions that can be passed as function pointers
int numcmp(char *, char *);                    // Numeric comparison
int strcmp_fold(char *s1, char *s2);           // Case-insensitive comparison
int strcmp_dir(char *s1, char *s2);            // Directory order comparison
int strcmp_fold_dir(char *s1, char *s2);       // Combined case-insensitive + directory

void swap(void *v[], int, int);
void demo_function_pointers();
int get_line(char s[], int lim);

// Read lines from input
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    printf("Enter up to %d lines (Ctrl+D to stop):\n", maxlines);

    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines) {
            printf("Maximum number of lines reached.\n");
            return -1;
        }

        line[len - 1] = '\0';  // Remove newline
        p = malloc(len);       // Allocate memory
        strcpy(p, line);       // Copy line
        lineptr[nlines++] = p;
    }
    return nlines;
}

// Write lines to output
void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

// Custom qsort that uses function pointers
void qsort_demo(void *v[], int left, int right, int (*comp)(void *, void *), int reverse) {
    int i, last;

    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++) {
        // Use function pointer to compare, with reverse option
        int result = (*comp)(v[i], v[left]);
        if (reverse ? (result > 0) : (result < 0)) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort_demo(v, left, last - 1, comp, reverse);
    qsort_demo(v, last + 1, right, comp, reverse);
}

// Numeric comparison function
int numcmp(char *s1, char *s2) {
    double v1 = atof(s1);
    double v2 = atof(s2);

    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

// Case-insensitive string comparison
int strcmp_fold(char *s1, char *s2) {
    while (tolower(*s1) == tolower(*s2)) {
        if (*s1 == '\0') return 0;
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}

// Directory order comparison (letters, numbers, and blanks only)
int strcmp_dir(char *s1, char *s2) {
    char c1, c2;

    do {
        // Skip non-alphanumeric, non-blank characters
        while (*s1 && !isalnum(*s1) && !isspace(*s1)) s1++;
        while (*s2 && !isalnum(*s2) && !isspace(*s2)) s2++;

        if (*s1 == '\0' || *s2 == '\0') {
            return *s1 - *s2;
        }

        c1 = *s1++;
        c2 = *s2++;
    } while (c1 == c2);

    return c1 - c2;
}

// Combined case-insensitive and directory order
int strcmp_fold_dir(char *s1, char *s2) {
    char c1, c2;

    do {
        while (*s1 && !isalnum(*s1) && !isspace(*s1)) s1++;
        while (*s2 && !isalnum(*s2) && !isspace(*s2)) s2++;

        if (*s1 == '\0' || *s2 == '\0') {
            return tolower(*s1) - tolower(*s2);
        }

        c1 = tolower(*s1++);
        c2 = tolower(*s2++);
    } while (c1 == c2);

    return c1 - c2;
}

// Swap two pointers
void swap(void *v[], int i, int j) {
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Read a line
int get_line(char s[], int lim) {
    int c, i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

// Demonstrate function pointer concepts
void demo_function_pointers() {
    printf("\n=== FUNCTION POINTER DEMONSTRATION ===\n");

    // Array of function pointers
    int (*comparisons[])(const char *, const char *) = {
        strcmp,                            // Standard strcmp
        (int (*)(const char *, const char *))numcmp,                            // Numeric comparison
        (int (*)(const char *, const char *))strcmp_fold,                       // Case-insensitive
        (int (*)(const char *, const char *))strcmp_dir,                        // Directory order
        (int (*)(const char *, const char *))strcmp_fold_dir                    // Combined
    };

    const char *names[] = {
        "Standard lexicographic",
        "Numeric",
        "Case-insensitive",
        "Directory order",
        "Case-insensitive + Directory"
    };

    char s1[] = "apple";
    char s2[] = "Banana";

    printf("Comparing '%s' and '%s' using different functions:\n", s1, s2);
    for (int i = 0; i < 5; i++) {
        int result = comparisons[i](s1, s2);
        printf("%s: %d\n", names[i], result);
    }

    // Demonstrate function pointer assignment and calling
    printf("\nFunction pointer syntax examples:\n");
    int (*func_ptr)(const char *, const char *);  // Declare function pointer
    func_ptr = strcmp;                // Assign function to pointer
    printf("Using func_ptr = strcmp: %d\n", func_ptr("hello", "world"));

    func_ptr = (int (*)(const char *, const char *))numcmp;                // Reassign to different function
    printf("Using func_ptr = numcmp: %d\n", func_ptr("10", "2"));

    printf("\nNote: &strcmp and strcmp are equivalent as function names decay to pointers\n");
}

int main() {
    printf("CHAPTER 5.11: POINTERS TO FUNCTIONS - DEMONSTRATION\n");
    printf("==================================================\n");

    // First demonstrate function pointer concepts
    demo_function_pointers();

    printf("\n\n=== INTERACTIVE SORTING DEMO ===\n");

    int nlines = readlines(lineptr, MAXLINES);
    if (nlines < 0) {
        printf("Error reading input\n");
        return 1;
    }

    printf("\nOriginal input:\n");
    writelines(lineptr, nlines);

    printf("\nSelect sorting method:\n");
    printf("1. Lexicographic (default)\n");
    printf("2. Numeric\n");
    printf("3. Case-insensitive\n");
    printf("4. Directory order\n");
    printf("5. Case-insensitive + Directory order\n");
    printf("Choice: ");

    int choice;
    scanf("%d", &choice);

    printf("Reverse order? (0=no, 1=yes): ");
    int reverse;
    scanf("%d", &reverse);

    // Select appropriate comparison function
    int (*comp)(void *, void *);
    switch (choice) {
        case 2: comp = (int (*)(void *, void *))numcmp; break;
        case 3: comp = (int (*)(void *, void *))strcmp_fold; break;
        case 4: comp = (int (*)(void *, void *))strcmp_dir; break;
        case 5: comp = (int (*)(void *, void *))strcmp_fold_dir; break;
        default: comp = (int (*)(void *, void *))strcmp; break;
    }

    // Sort using the selected function
    qsort_demo((void **)lineptr, 0, nlines - 1, comp, reverse);

    printf("\nSorted output:\n");
    writelines(lineptr, nlines);

    // Clean up
    for (int i = 0; i < nlines; i++) {
        free(lineptr[i]);
    }

    printf("\n=== COMMAND LINE USAGE EXAMPLES ===\n");
    printf("./sort_program                    # Lexicographic sort\n");
    printf("./sort_program -n                 # Numeric sort\n");
    printf("./sort_program -r                 # Reverse sort\n");
    printf("./sort_program -f                 # Case-insensitive sort\n");
    printf("./sort_program -d                 # Directory order sort\n");
    printf("./sort_program -n -r              # Numeric reverse sort\n");
    printf("./sort_program -f -d              # Case-insensitive directory order\n");

    return 0;
}