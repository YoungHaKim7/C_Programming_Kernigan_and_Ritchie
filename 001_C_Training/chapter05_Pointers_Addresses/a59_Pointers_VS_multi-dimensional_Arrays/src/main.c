#include <stdio.h>
#include <string.h>

// Example 1: Two-dimensional array vs array of pointers
void demonstrate_array_difference()
{
    printf("=== Demonstrating Array vs Pointer Array Differences ===\n");

    // True two-dimensional array
    int a[3][4] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };

    // Array of pointers
    int* b[3];
    int row0[] = { 1, 2, 3, 4 };
    int row1[] = { 5, 6, 7, 8 };
    int row2[] = { 9, 10, 11, 12 };

    b[0] = row0;
    b[1] = row1;
    b[2] = row2;

    printf("Two-dimensional array a[3][4]:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("a[%d][%d] = %d (address: %p)\n", i, j, a[i][j], (void*)&a[i][j]);
        }
    }

    printf("\nArray of pointers b[3]:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("b[%d][%d] = %d (address: %p)\n", i, j, b[i][j], (void*)&b[i][j]);
        }
    }

    // Demonstrate different row lengths with pointer array
    printf("\n=== Different Row Lengths with Pointer Array ===\n");
    int short_row[] = { 100, 200 };
    int long_row[] = { 300, 400, 500, 600, 700, 800 };
    int single_row[] = { 900 };

    b[0] = short_row;
    b[1] = long_row;
    b[2] = single_row;

    int lengths[] = { 2, 6, 1 };
    for (int i = 0; i < 3; i++) {
        printf("Row %d (length %d): ", i, lengths[i]);
        for (int j = 0; j < lengths[i]; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

// Example 2: Character strings - array of pointers vs 2D array
void demonstrate_string_arrays()
{
    printf("\n=== String Arrays: Pointers vs 2D Array ===\n");

    // Array of pointers to strings
    char* name[] = { "Illegal month", "Jan", "Feb", "Mar", "Apr", "May", "Jun" };

    // Two-dimensional array
    char aname[][15] = { "Illegal month", "Jan", "Feb", "Mar", "Apr", "May", "Jun" };

    printf("Array of pointers:\n");
    for (int i = 0; i < 7; i++) {
        printf("name[%d] = \"%s\" (length: %zu)\n", i, name[i], strlen(name[i]));
    }

    printf("\nTwo-dimensional array:\n");
    for (int i = 0; i < 7; i++) {
        printf("aname[%d] = \"%s\" (length: %zu)\n", i, aname[i], strlen(aname[i]));
    }

    // Memory usage comparison
    printf("\nMemory usage comparison:\n");
    printf("Array of pointers: %zu bytes for pointers + string storage\n", sizeof(name));
    printf("2D array: %zu bytes (fixed size for all strings)\n", sizeof(aname));
}

// Original day_of_year and month_day functions (from previous exercises)
static char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

// Original day_of_year function with indexing
int day_of_year_original(int year, int month, int day)
{
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

// Original month_day function with indexing
void month_day_original(int year, int yearday, int* pmonth, int* pday)
{
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

// Rewritten day_of_year function using pointers
int day_of_year_pointers(int year, int month, int day)
{
    char* dayptr;
    int leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    dayptr = daytab[leap] + 1; // Point to first month (skip index 0)

    while (--month > 0) {
        day += *dayptr++;
    }
    return day;
}

// Rewritten month_day function using pointers
void month_day_pointers(int year, int yearday, int* pmonth, int* pday)
{
    char* dayptr;
    int leap, month = 1;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    dayptr = daytab[leap] + 1; // Point to first month (skip index 0)

    while (yearday > *dayptr) {
        yearday -= *dayptr++;
        month++;
    }
    *pmonth = month;
    *pday = yearday;
}

// Example 3: Month name function using pointers
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

// Example 4: Advanced pointer manipulation
void demonstrate_advanced_pointers()
{
    printf("\n=== Advanced Pointer Manipulation ===\n");

    int matrix[3][4] = {
        { 10, 20, 30, 40 },
        { 50, 60, 70, 80 },
        { 90, 100, 110, 120 }
    };

    // Access using pointer arithmetic
    int* ptr = &matrix[0][0];

    printf("Matrix using pointer arithmetic:\n");
    for (int i = 0; i < 12; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    // Row-major order demonstration
    printf("\nRow-major order access:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            printf("matrix[%d][%d] = %d (computed as *(&matrix[0][0] + %d*%d + %d))\n",
                row, col, matrix[row][col], 4, row, col);
        }
    }
}

// Test function for day_of_year and month_day
void test_date_functions()
{
    printf("\n=== Testing Date Functions ===\n");

    struct {
        int year;
        int month;
        int day;
    } test_dates[] = {
        { 2024, 1, 1 }, // New Year (leap year)
        { 2024, 2, 29 }, // Leap day
        { 2024, 12, 31 }, // End of year (leap year)
        { 2023, 2, 28 }, // Non-leap Feb
        { 2023, 12, 31 }, // End of year (non-leap)
        { 2000, 2, 29 }, // Century leap year
        { 1900, 2, 28 }, // Century non-leap year
        { 2024, 7, 4 }, // Mid-year
        { 2023, 3, 15 }, // Random date
        { 2024, 10, 31 } // Halloween
    };

    int num_tests = sizeof(test_dates) / sizeof(test_dates[0]);

    for (int i = 0; i < num_tests; i++) {
        int year = test_dates[i].year;
        int month = test_dates[i].month;
        int day = test_dates[i].day;

        // Test day_of_year functions
        int day_orig = day_of_year_original(year, month, day);
        int day_ptr = day_of_year_pointers(year, month, day);

        // Test month_day functions
        int m_orig, d_orig, m_ptr, d_ptr;
        month_day_original(year, day_orig, &m_orig, &d_orig);
        month_day_pointers(year, day_ptr, &m_ptr, &d_ptr);

        printf("Test %d: %d/%02d/%02d\n", i + 1, year, month, day);
        printf("  Day of year - Original: %d, Pointers: %d %s\n",
            day_orig, day_ptr, (day_orig == day_ptr) ? "✓" : "✗");
        printf("  Month/Day - Original: %d/%d, Pointers: %d/%d %s\n",
            m_orig, d_orig, m_ptr, d_ptr,
            (m_orig == m_ptr && d_orig == d_ptr) ? "✓" : "✗");
    }
}

int main()
{
    printf("Chapter 5.9: Pointers vs Multi-dimensional Arrays\n");
    printf("================================================\n");

    // Example 1: Basic array differences
    demonstrate_array_difference();

    // Example 2: String arrays
    demonstrate_string_arrays();

    // Example 3: Month names
    printf("\n=== Month Name Function ===\n");
    for (int i = 0; i <= 12; i++) {
        printf("Month %2d: %s\n", i, month_name(i));
    }

    // Example 4: Advanced pointer manipulation
    demonstrate_advanced_pointers();

    // Example 5: Testing date functions
    test_date_functions();

    // Example 6: Memory layout demonstration
    printf("\n=== Memory Layout Demonstration ===\n");
    int a[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
    printf("2D array a[2][3]:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("a[%d][%d] = %d at %p\n", i, j, a[i][j], (void*)&a[i][j]);
        }
    }
    printf("Flattened view: ");
    int* flat = &a[0][0];
    for (int i = 0; i < 6; i++) {
        printf("%d ", flat[i]);
    }
    printf("\n");

    return 0;
}
