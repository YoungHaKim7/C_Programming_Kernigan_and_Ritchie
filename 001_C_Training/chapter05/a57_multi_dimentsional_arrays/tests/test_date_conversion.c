#include <assert.h>
#include <stdio.h>
#include <string.h>

static char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (year < 0) {
        return -1;
    }

    if (month < 1 || month > 12) {
        return -1;
    }

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if (day < 1 || day > daytab[leap][month]) {
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
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if (yearday < 1 || yearday > (leap ? 366 : 365)) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

void test_day_of_year()
{
    printf("Testing day_of_year function...\n");

    // Test normal cases
    assert(day_of_year(2023, 1, 1) == 1);
    assert(day_of_year(2023, 12, 31) == 365);
    assert(day_of_year(2024, 12, 31) == 366);
    assert(day_of_year(2023, 3, 1) == 60);
    assert(day_of_year(2024, 3, 1) == 61);
    assert(day_of_year(2024, 2, 29) == 60);

    // Test edge cases
    assert(day_of_year(2000, 2, 29) == 60); // 2000 is a leap year
    assert(day_of_year(1900, 12, 31) == 365); // 1900 is not a leap year

    // Test invalid inputs
    assert(day_of_year(2023, 2, 30) == -1);
    assert(day_of_year(2023, 13, 1) == -1);
    assert(day_of_year(2023, 0, 1) == -1);
    assert(day_of_year(2023, 1, 0) == -1);
    assert(day_of_year(-1, 1, 1) == -1);
    assert(day_of_year(2023, 4, 31) == -1); // April has 30 days

    printf("✓ day_of_year tests passed\n");
}

void test_month_day()
{
    printf("Testing month_day function...\n");

    int month, day;

    // Test normal cases
    month_day(2023, 1, &month, &day);
    assert(month == 1 && day == 1);

    month_day(2023, 365, &month, &day);
    assert(month == 12 && day == 31);

    month_day(2024, 366, &month, &day);
    assert(month == 12 && day == 31);

    month_day(2023, 60, &month, &day);
    assert(month == 3 && day == 1);

    month_day(2024, 60, &month, &day);
    assert(month == 2 && day == 29);

    // Test edge cases
    month_day(2000, 60, &month, &day); // 2000 is a leap year
    assert(month == 2 && day == 29);

    month_day(1900, 60, &month, &day); // 1900 is not a leap year
    assert(month == 3 && day == 1);

    // Test invalid inputs
    month_day(2023, 366, &month, &day);
    assert(month == -1 && day == -1);

    month_day(2023, 0, &month, &day);
    assert(month == -1 && day == -1);

    month_day(-1, 1, &month, &day);
    assert(month == -1 && day == -1);

    month_day(2024, 367, &month, &day);
    assert(month == -1 && day == -1);

    printf("✓ month_day tests passed\n");
}

void test_round_trip_conversion()
{
    printf("Testing round-trip conversions...\n");

    int test_years[] = { 2023, 2024, 2000, 1900, 2020 };
    int test_months[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    for (int i = 0; i < 5; i++) {
        int year = test_years[i];
        for (int j = 0; j < 12; j++) {
            int month = test_months[j];

            // Test first day of month
            int yearday = day_of_year(year, month, 1);
            if (yearday != -1) {
                int m, d;
                month_day(year, yearday, &m, &d);
                assert(m == month && d == 1);
            }

            // Test last day of month
            int leap = is_leap_year(year);
            int last_day = daytab[leap][month];
            yearday = day_of_year(year, month, last_day);
            if (yearday != -1) {
                int m, d;
                month_day(year, yearday, &m, &d);
                assert(m == month && d == last_day);
            }
        }
    }

    printf("✓ Round-trip conversion tests passed\n");
}

void test_specific_dates()
{
    printf("Testing specific important dates...\n");

    int month, day;

    // Test February 29 in leap years
    assert(day_of_year(2020, 2, 29) == 60);
    assert(day_of_year(2000, 2, 29) == 60);
    assert(day_of_year(2024, 2, 29) == 60);

    // Test March 1 in non-leap years
    assert(day_of_year(2023, 3, 1) == 60);
    assert(day_of_year(2021, 3, 1) == 60);
    assert(day_of_year(1900, 3, 1) == 60);

    // Test conversion of day 60
    month_day(2020, 60, &month, &day);
    assert(month == 2 && day == 29);

    month_day(2023, 60, &month, &day);
    assert(month == 3 && day == 1);

    // Test solstices and equinoxes (approximate dates)
    assert(day_of_year(2023, 3, 20) == 79); // Spring equinox
    assert(day_of_year(2023, 6, 21) == 172); // Summer solstice
    assert(day_of_year(2023, 9, 22) == 265); // Fall equinox
    assert(day_of_year(2023, 12, 21) == 355); // Winter solstice

    printf("✓ Specific date tests passed\n");
}

int main()
{
    printf("=== Date Conversion Test Suite ===\n\n");

    test_day_of_year();
    test_month_day();
    test_round_trip_conversion();
    test_specific_dates();

    printf("\n=== All tests passed! ===\n");

    return 0;
}