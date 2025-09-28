#include <stdio.h>
#include <stdalign.h>  // for alignof (C23) and _Alignof (C11)

int square(int x) {
    return x * x;
}

struct Sample {
    char c;
    int i;
};

int main(void) {
    int a = 5;
    int b = 10;

    // Function call: a(...)
    printf("square(a) = %d\n", square(a));

    // Comma operator: a, b
    int result = (a++, b++);  // evaluates a++, then b++, result is value of b++
    printf("After (a++, b++): a = %d, b = %d, result = %d\n", a, b, result);

    // Cast: (type) a
    double d = (double)b / 3;
    printf("Cast (double)b / 3 = %f\n", d);

    // Conditional operator: a ? b : c
    int bigger = (a > b) ? a : b;
    printf("Conditional (a > b ? a : b) = %d\n", bigger);

    // sizeof
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(struct Sample) = %zu\n", sizeof(struct Sample));

    // _Alignof (C11)
    printf("_Alignof(int) = %zu\n", _Alignof(int));
    printf("_Alignof(struct Sample) = %zu\n", _Alignof(struct Sample));

#if __STDC_VERSION__ >= 202311L
    // alignof (since C23)
    printf("alignof(int) = %zu\n", alignof(int));
    printf("alignof(struct Sample) = %zu\n", alignof(struct Sample));
#endif

    return 0;
}
