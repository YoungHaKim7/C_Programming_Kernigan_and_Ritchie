#include <stdio.h>

/* print Fahrenheit-Celsius table
for f = 0, 20, ..., 300 */

int main()
{
    // i32
    int lower, upper, step;
    // f32   용량이 작아서
    float fahr, celsius;
    lower = 0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;

    printf("℉  \t  ℃  \n");
    // while { true}
    // if { true}   evaluation  -> eval
    // if {} else {}
    // if {} else if {}
    // false가 될때까지 무한 루프
    while (fahr <= upper) {
        // ℃   celsius  
        // ℉  Fahrenheit
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
