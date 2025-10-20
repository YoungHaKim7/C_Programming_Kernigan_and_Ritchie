# ⏺ I've created a complete C program implementing the month_name function as described in the text. The program includes:

- 1. The month_name function that:
  - Uses a static array of character pointers initialized with month names
  - Returns "Illegal month" for invalid inputs (n < 1 or n > 12)
  - Returns the appropriate month name for valid inputs
- 2. Comprehensive test cases in main():
  - Tests all valid months (1-12)
  - Tests edge cases (0, 13, -1)
  - Additional specific tests for various scenarios
  - A total of 15 test cases demonstrating different scenarios

- The program compiles successfully and runs correctly, showing that the pointer array initialization works as expected. The static array name[] is
initialized with character strings, and each entry stores a pointer to the corresponding string.

# Result

```bash
Testing month_name function:
==========================
month_name( 0) -> Illegal month
month_name( 1) -> January
month_name( 2) -> February
month_name( 3) -> March
month_name( 4) -> April
month_name( 5) -> May
month_name( 6) -> June
month_name( 7) -> July
month_name( 8) -> August
month_name( 9) -> September
month_name(10) -> October
month_name(11) -> November
month_name(12) -> December
month_name(13) -> Illegal month
month_name(-1) -> Illegal month

Additional specific tests:
==========================
Edge case test - month_name(1) = January
Edge case test - month_name(12) = December
Invalid test - month_name(0) = Illegal month
Invalid test - month_name(13) = Illegal month
Invalid test - month_name(-5) = Illegal month
Typical test - month_name(6) = June
Typical test - month_name(8) = August
Typical test - month_name(11) = November
```
