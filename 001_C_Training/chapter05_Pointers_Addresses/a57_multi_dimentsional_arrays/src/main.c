#include <stdio.h>
#include <stdlib.h>

static char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (year < 0) {
        printf("Error: Invalid year %d\n", year);
        return -1;
    }

    if (month < 1 || month > 12) {
        printf("Error: Invalid month %d\n", month);
        return -1;
    }

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if (day < 1 || day > daytab[leap][month]) {
        printf("Error: Invalid day %d for month %d in year %d\n", day, month, year);
        return -1;
    }

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int* pmonth, int* pday)
{
    int i, leap;

    if (year < 0) {
        printf("Error: Invalid year %d\n", year);
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if (yearday < 1 || yearday > (leap ? 366 : 365)) {
        printf("Error: Invalid day of year %d for year %d\n", yearday, year);
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int year, month, day, yearday;
    int m, d;

    printf("=== Date Conversion Examples ===\n\n");

    // Example 1: March 1 in non-leap year (should be day 60)
    year = 2023;
    month = 3;
    day = 1;
    yearday = day_of_year(year, month, day);
    printf("Example 1: March 1, %d is day %d of the year\n", year, yearday);
    month_day(year, yearday, &m, &d);
    printf("  Converted back: Month %d, Day %d\n\n", m, d);

    // Example 2: March 1 in leap year (should be day 61)
    year = 2024;
    month = 3;
    day = 1;
    yearday = day_of_year(year, month, day);
    printf("Example 2: March 1, %d is day %d of the year\n", year, yearday);
    month_day(year, yearday, &m, &d);
    printf("  Converted back: Month %d, Day %d\n\n", m, d);

    // Example 3: February 29 in leap year
    year = 2020;
    month = 2;
    day = 29;
    yearday = day_of_year(year, month, day);
    printf("Example 3: February 29, %d is day %d of the year\n", year, yearday);
    month_day(year, yearday, &m, &d);
    printf("  Converted back: Month %d, Day %d\n\n", m, d);

    // Example 4: December 31 in non-leap year
    year = 2023;
    month = 12;
    day = 31;
    yearday = day_of_year(year, month, day);
    printf("Example 4: December 31, %d is day %d of the year\n", year, yearday);
    month_day(year, yearday, &m, &d);
    printf("  Converted back: Month %d, Day %d\n\n", m, d);

    // Example 5: January 1
    year = 2023;
    month = 1;
    day = 1;
    yearday = day_of_year(year, month, day);
    printf("Example 5: January 1, %d is day %d of the year\n", year, yearday);
    month_day(year, yearday, &m, &d);
    printf("  Converted back: Month %d, Day %d\n\n", m, d);

    // Example 6: Day 60 to month/day in non-leap year
    year = 2023;
    yearday = 60;
    month_day(year, yearday, &m, &d);
    printf("Example 6: Day %d of %d is Month %d, Day %d\n", yearday, year, m, d);
    yearday = day_of_year(year, m, d);
    printf("  Converted back to day of year: %d\n\n", yearday);

    // Example 7: Day 60 to month/day in leap year
    year = 2024;
    yearday = 60;
    month_day(year, yearday, &m, &d);
    printf("Example 7: Day %d of %d is Month %d, Day %d\n", yearday, year, m, d);
    yearday = day_of_year(year, m, d);
    printf("  Converted back to day of year: %d\n\n", yearday);

    // Example 8: Day 366 in leap year
    year = 2020;
    yearday = 366;
    month_day(year, yearday, &m, &d);
    printf("Example 8: Day %d of %d is Month %d, Day %d\n", yearday, year, m, d);
    yearday = day_of_year(year, m, d);
    printf("  Converted back to day of year: %d\n\n", yearday);

    // Example 9: July 4 (Independence Day)
    year = 2023;
    month = 7;
    day = 4;
    yearday = day_of_year(year, month, day);
    printf("Example 9: July 4, %d is day %d of the year\n", year, yearday);
    month_day(year, yearday, &m, &d);
    printf("  Converted back: Month %d, Day %d\n\n", m, d);

    // Example 10: Century year (1900 is not a leap year)
    year = 1900;
    month = 3;
    day = 1;
    yearday = day_of_year(year, month, day);
    printf("Example 10: March 1, %d is day %d of the year\n", year, yearday);
    month_day(year, yearday, &m, &d);
    printf("  Converted back: Month %d, Day %d\n\n", m, d);

    printf("=== Error Handling Examples ===\n\n");

    // Error examples
    printf("Error Example 1: Invalid day (February 30)\n");
    day_of_year(2023, 2, 30);

    printf("\nError Example 2: Invalid month (13)\n");
    day_of_year(2023, 13, 1);

    printf("\nError Example 3: Invalid day of year (366 in non-leap year)\n");
    month_day(2023, 366, &m, &d);

    printf("\nError Example 4: Invalid day of year (0)\n");
    month_day(2023, 0, &m, &d);

    printf("\nError Example 5: Invalid year (-1)\n");
    day_of_year(-1, 1, 1);

    return 0;
}