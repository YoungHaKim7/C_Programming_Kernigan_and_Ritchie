#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void)  /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int* pn)
{
    int c, sign;
    while (isspace(c = getch()))
        /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

/* Correct swap function using pointers */
void swap(int *px, int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

/* Function to modify an integer value */
void increment(int *x)
{
    (*x)++;
}

/* Function to double a value */
void double_value(int *x)
{
    *x = *x * 2;
}

/* Function to reset a value to zero */
void reset_to_zero(int *x)
{
    *x = 0;
}

/* Function to calculate square and store result */
void square(int *x)
{
    *x = *x * *x;
}

/* Function to add two numbers and store in first */
void add_to_first(int *a, int b)
{
    *a = *a + b;
}

/* Function to swap characters */
void swap_chars(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to set a boolean flag */
void set_flag(int *flag, int value)
{
    *flag = value;
}

/* Function to calculate absolute value */
void absolute_value(int *x)
{
    if (*x < 0)
        *x = -*x;
}

/* Function to find maximum of two values and store in first */
void max_of_two(int *a, int b)
{
    if (b > *a)
        *a = b;
}

int main()
{
    // Example 1: Basic swap using pointers
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    // Example 2: Increment a value
    int x = 7;
    printf("Before increment: x = %d\n", x);
    increment(&x);
    printf("After increment: x = %d\n", x);

    // Example 3: Double a value
    int y = 8;
    printf("Before doubling: y = %d\n", y);
    double_value(&y);
    printf("After doubling: y = %d\n", y);

    // Example 4: Reset to zero
    int z = 42;
    printf("Before reset: z = %d\n", z);
    reset_to_zero(&z);
    printf("After reset: z = %d\n", z);

    // Example 5: Square a number
    int num = 6;
    printf("Before square: num = %d\n", num);
    square(&num);
    printf("After square: num = %d\n", num);

    // Example 6: Add to first argument
    int first = 15, second = 7;
    printf("Before addition: first = %d, second = %d\n", first, second);
    add_to_first(&first, second);
    printf("After addition: first = %d, second = %d\n", first, second);

    // Example 7: Swap characters
    char c1 = 'A', c2 = 'Z';
    printf("Before char swap: c1 = %c, c2 = %c\n", c1, c2);
    swap_chars(&c1, &c2);
    printf("After char swap: c1 = %c, c2 = %c\n", c1, c2);

    // Example 8: Set a flag
    int flag = 0;
    printf("Before setting flag: flag = %d\n", flag);
    set_flag(&flag, 1);
    printf("After setting flag: flag = %d\n", flag);

    // Example 9: Absolute value
    int neg_num = -25;
    printf("Before absolute: neg_num = %d\n", neg_num);
    absolute_value(&neg_num);
    printf("After absolute: neg_num = %d\n", neg_num);

    // Example 10: Find maximum
    int max_val = 12, compare_val = 18;
    printf("Before max: max_val = %d, compare_val = %d\n", max_val, compare_val);
    max_of_two(&max_val, compare_val);
    printf("After max: max_val = %d, compare_val = %d\n", max_val, compare_val);

    return 0;
}
