#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <ctype.h>   // for isdigit(), isspace()

#define MAXOP 100   // max size of operand or operator
#define NUMBER '0'  // signal that a number was found
#define MAXVAL 100  // maximum depth of value stack
#define BUFSIZE 100 // buffer size for getch/ungetch

int getop(char s[]);
void push(double);
double pop(void);

int sp = 0;              // next free stack position
double val[MAXVAL];      // value stack
char buf[BUFSIZE];       // buffer for ungetch
int bufp = 0;            // next free position in buf

// Push f onto stack
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// Pop and return top value from stack
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// Get a (possibly numeric) operand
int getop(char s[])
{
    int i, c;

    // Skip whitespace
    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c; // not a number

    i = 0;
    if (c == '-') {
        int next = getchar();
        if (!isdigit(next) && next != '.') {
            ungetc(next, stdin);
            return '-';
        }
        s[++i] = c = next;
    }

    if (isdigit(c)) // collect integer part
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetc(c, stdin);
    return NUMBER;
}

int main(void)
{

    printf("Type some text (Ctrl+D to end): calculator ex) 3 5 + \n");

    int type;
    double op2;
    char s[MAXOP];

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
