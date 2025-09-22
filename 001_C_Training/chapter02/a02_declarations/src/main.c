#include <stdio.h>
#define MAXLINE 1000

int main(void)
{
    /* Integers */
    int lower = 0, upper = 300, step = 20;
    int count = 42;
    unsigned int ucount = 100u;
    long big = 1000000L;
    short small = -10;

    /* Characters and strings */
    char c = 'A';
    char newline = '\n';
    char esc = '\\';
    char str1[] = "Hello, C!";
    const char msg[] = "warning: ";

    /* Floating point */
    float eps = 1.0e-5f;
    double pi = 3.141592653589793;
    const double e = 2.71828182845905;

    /* Arrays */
    char line[MAXLINE];   /* character buffer */
    int numbers[5] = {1, 2, 3, 4, 5};
    float grades[3] = {90.5, 85.0, 78.5};

    /* Enum */
    enum boolean { NO, YES };
    enum boolean flag = YES;

    /* Struct */
    struct Point {
        int x;
        int y;
    };
    struct Point p1 = {10, 20};

    /* Union */
    union Data {
        int i;
        float f;
        char s[4];
    };
    union Data data;
    data.i = 123;

    /* ---- USE ALL VARIABLES ---- */
    printf("Range example: lower=%d, upper=%d, step=%d\n", lower, upper, step);
    for (int t = lower; t <= upper; t += step) {
        printf("  t=%d\n", t);
    }

    printf("\nCount=%d, Unsigned=%u, Long=%ld, Short=%d\n", count, ucount, big, small);

    printf("\nCharacters: c='%c', esc='%c', newline='\\n'\n", c, esc);

    printf("\nMessage: %s %s\n", msg, str1);

    printf("\nFloating values: eps=%g, pi=%.6f, e=%.5f\n", eps, pi, e);

    /* Arrays */
    printf("\nFirst numbers: %d %d %d\n", numbers[0], numbers[1], numbers[2]);
    printf("Grades: %.1f %.1f %.1f\n", grades[0], grades[1], grades[2]);

    /* Pretend to use the buffer `line` */
    snprintf(line, sizeof(line), "Buffer says: pi=%.2f", pi);
    printf("%s\n", line);

    /* Enum */
    printf("\nEnum flag=%d (YES=1, NO=0)\n", flag);

    /* Struct */
    printf("Point p1 = (%d, %d)\n", p1.x, p1.y);

    /* Union */
    printf("Union data.i=%d\n", data.i);
    data.f = 3.14f;
    printf("Union data.f=%.2f\n", data.f);

    return 0;
}

