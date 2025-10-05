#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../src/headers/calc.h"

#define MAXOP 100

void run_test(const char* input, double expected) {
    // Simulate input by pushing characters to ungetch
    for (int i = strlen(input) - 1; i >= 0; i--) {
        ungetch(input[i]);
    }

    char s[MAXOP];
    int type;
    double op2;

    while ((type = getop(s)) != EOF && type != '\n') {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    double result = pop();
    if (fabs(result - expected) < 1e-9) {
        printf("Test passed: %s = %f\n", input, result);
    } else {
        printf("Test failed: %s = %f, expected %f\n", input, result, expected);
    }
}

int main() {
    FILE *file = fopen("test/test_cases.txt", "r");
    if (file == NULL) {
        perror("Error opening test_cases.txt");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *input = strtok(line, ";");
        char *expected_str = strtok(NULL, ";");
        if (input && expected_str) {
            double expected = atof(expected_str);
            run_test(input, expected);
        }
    }

    fclose(file);
    return 0;
}
