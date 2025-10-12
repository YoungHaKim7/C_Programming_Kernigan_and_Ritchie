// include 순서 중요하다.  순서 정확하게 지켜줘야 컴파일 에러 안남.
#include "./headers/calc.h"

#include <stdio.h>
#include <stdlib.h>

// global variables(상수를 정의)    global variables VS local variables
// local variable은 메모리에 잠시 할당했다가 free함.
// local variable 은 scope안에서만 사용할 수 있다.

#define MAXOP 100

int main(void)
{
    printf("Type some text (Ctrl +D to end) 'ex) 2 3 + 'i : \n");

    int type;
    double op2;

    // ownership (comsume)
    // rust  let a_str = String::from("Hello, world!");
    // ownership (&   reference)
    // rust let a_str = "Hello, world";
    // array s 를 allocation을 할꺼고 [100]
    // let s: [String; 100];
    char s[MAXOP];

    // if던 while던   첫번째가 true   eval을 한다.
    // evaluation
    while ((type = getop(s)) != EOF) {
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
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    printf("\nDone!\n");

    return 0;
}
