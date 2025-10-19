# Chapter 5.7: Multi-dimensional Arrays - Date Conversion Program

This program implements the date conversion functions from Chapter 5.7 of "The C Programming Language" by Kernighan and Ritchie, with additional error checking as suggested in Exercise 5-8.

## Files

- `date_conversion.c` - Main program with example usage and error demonstration
- `test_date_conversion.c` - Comprehensive test suite
- `Makefile` - Build configuration
- `README.md` - This file

## Functions

### `day_of_year(int year, int month, int day)`
Converts month and day to day of the year.
- Returns the day of year (1-366) on success
- Returns -1 on error with appropriate error message

### `month_day(int year, int yearday, int *pmonth, int *pday)`
Converts day of year to month and day.
- Sets `*pmonth` and `*pday` to the corresponding month and day
- Sets both to -1 on error

## Features

- **Leap year calculation**: Correctly handles leap years using the Gregorian calendar rules
- **Error checking**: Validates all input parameters:
  - Year must be non-negative
  - Month must be 1-12
  - Day must be valid for the given month/year
  - Day of year must be valid for the given year
- **Two-dimensional array**: Uses a 2D array to store days per month for leap/non-leap years

## Example Output

```
=== Date Conversion Examples ===

Example 1: March 1, 2023 is day 60 of the year
  Converted back: Month 3, Day 1

Example 2: March 1, 2024 is day 61 of the year
  Converted back: Month 3, Day 1

Example 3: February 29, 2020 is day 60 of the year
  Converted back: Month 2, Day 29
```

## Error Handling

The program includes comprehensive error checking for:
- Invalid dates (e.g., February 30)
- Invalid months (0 or 13+)
- Invalid days of year (0 or 367+ in non-leap year)
- Invalid years (negative)

## Test Coverage

The test suite includes:
- Unit tests for both functions
- Round-trip conversion tests
- Edge case testing (leap years, century years)
- Error condition testing
- Specific date validation (solstices, equinoxes)

## Implementation Details

- Uses a static 2D array `daytab[2][13]` where index 0 represents non-leap years and index 1 represents leap years
- The leap year calculation follows Gregorian calendar rules:
  - Years divisible by 4 are leap years
  - Except years divisible by 100 are not leap years
  - Except years divisible by 400 are leap years
- Error messages are printed to stderr for debugging, but functions return error codes for programmatic handling

## Key Concepts Demonstrated

1. **Two-dimensional array declaration and usage**
2. **Array initialization with nested braces**
3. **Multi-dimensional array as function parameter**
4. **Pointer arithmetic with multi-dimensional arrays**
5. **Leap year calculation using logical expressions**
6. **Error handling and input validation**
7. **Round-trip conversion testing**


# Result


```bash
$ just cr

just fm
fd -e c   -e h   -e cpp   -e hpp   -e cc   -e cxx -x /opt/homebrew/opt/llvm/bin/clang-format -style=file -i {} \;
rm -rf build
mkdir -p build
export CC=/opt/homebrew/opt/gcc@15/bin/gcc-15
cmake -D CMAKE_C_COMPILER=/opt/homebrew/opt/gcc@15/bin/gcc-15 -G Ninja .
-- The C compiler identification is GNU 15.1.0
-- Checking whether C compiler has -isysroot
-- Checking whether C compiler has -isysroot - yes
-- Checking whether C compiler supports OSX deployment target flag
-- Checking whether C compiler supports OSX deployment target flag - yes
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /opt/homebrew/opt/gcc@15/bin/gcc-15 - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done (0.7s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/001_C_Training/chapter05/a57_multi_dimentsional_arrays
ninja
[1/4] Building C object CMakeFiles/a57_multi_dimentsional_arrays.dir/src/main.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[2/4] Building C object CMakeFiles/test_date_conversion.dir/tests/test_date_conversion.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[4/4] Linking C executable target/a57_multi_dimentsional_arrays
mv build.ninja CMakeCache.txt CMakeFiles cmake_install.cmake target .ninja_deps .ninja_log build
./build/./target/a57_multi_dimentsional_arrays
=== Date Conversion Examples ===

Example 1: March 1, 2023 is day 60 of the year
  Converted back: Month 3, Day 1

Example 2: March 1, 2024 is day 61 of the year
  Converted back: Month 3, Day 1

Example 3: February 29, 2020 is day 60 of the year
  Converted back: Month 2, Day 29

Example 4: December 31, 2023 is day 365 of the year
  Converted back: Month 12, Day 31

Example 5: January 1, 2023 is day 1 of the year
  Converted back: Month 1, Day 1

Example 6: Day 60 of 2023 is Month 3, Day 1
  Converted back to day of year: 60

Example 7: Day 60 of 2024 is Month 2, Day 29
  Converted back to day of year: 60

Example 8: Day 366 of 2020 is Month 12, Day 31
  Converted back to day of year: 366

Example 9: July 4, 2023 is day 185 of the year
  Converted back: Month 7, Day 4

Example 10: March 1, 1900 is day 60 of the year
  Converted back: Month 3, Day 1

=== Error Handling Examples ===

Error Example 1: Invalid day (February 30)
Error: Invalid day 30 for month 2 in year 2023

Error Example 2: Invalid month (13)
Error: Invalid month 13

Error Example 3: Invalid day of year (366 in non-leap year)
Error: Invalid day of year 366 for year 2023

Error Example 4: Invalid day of year (0)
Error: Invalid day of year 0 for year 2023

Error Example 5: Invalid year (-1)
Error: Invalid year -1

####

# test
$ ./test_date_conversion
=== Date Conversion Test Suite ===

Testing day_of_year function...
✓ day_of_year tests passed
Testing month_day function...
✓ month_day tests passed
Testing round-trip conversions...
✓ Round-trip conversion tests passed
Testing specific important dates...
✓ Specific date tests passed

=== All tests passed! ===

# ctest
$ just ctest
rm -rf build
mkdir -p build
cmake -D CMAKE_C_COMPILER=/opt/homebrew/opt/gcc@15/bin/gcc-15 -S . -B build
-- The C compiler identification is GNU 15.1.0
-- Checking whether C compiler has -isysroot
-- Checking whether C compiler has -isysroot - yes
-- Checking whether C compiler supports OSX deployment target flag
-- Checking whether C compiler supports OSX deployment target flag - yes
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /opt/homebrew/opt/gcc@15/bin/gcc-15 - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Configuring done (0.7s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/001_C_Training/chapter05/a57_multi_dimentsional_arrays/build
cmake --build build
[ 25%] Building C object CMakeFiles/a57_multi_dimentsional_arrays.dir/src/main.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[ 50%] Linking C executable target/a57_multi_dimentsional_arrays
[ 50%] Built target a57_multi_dimentsional_arrays
[ 75%] Building C object CMakeFiles/test_date_conversion.dir/tests/test_date_conversion.c.o
clang: warning: overriding deployment version from '16.0' to '26.0' [-Woverriding-deployment-version]
[100%] Linking C executable test_date_conversion
[100%] Built target test_date_conversion
ctest --test-dir ./build
Test project /Users/gy-gyoung/my_project/Rust_Lang/9999/2222/C_Programming_Kernigan_and_Ritchie/001_C_Training/chapter05/a57_multi_dimentsional_arrays/build
    Start 1: DateConversionTest
1/1 Test #1: DateConversionTest ...............   Passed    0.38 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.38 sec
```
