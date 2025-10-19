#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100
#define BUFSIZE 100

enum { NAME,
    PARENS,
    BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);
int getch(void);
void ungetch(int);

int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */
char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000]; /* output string */

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*';) /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;

    if (tokentype == '(') { /* ( dcl ) */
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    } else if (tokentype == NAME) /* variable name */
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");

    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

/* gettoken: return next token */
int gettoken(void)
{
    int c, getch(void);
    void ungetch(int);
    char* p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}

/* getch: get a (possibly pushed-back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* undcl: convert word description to declaration */
int undcl(void)
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*') {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("invalid input at %s\n", token);
        printf("%s\n", out);
    }
    return 0;
}

/* test function with example declarations */
void test_declarations(void)
{
    printf("=== Testing Declaration Parser ===\n");

    /* Test examples from the book */
    char test_cases[][100] = {
        "char **argv\n",
        "int (*daytab)[13]\n",
        "int *daytab[13]\n",
        "void *comp()\n",
        "void (*comp)()\n",
        "char (*(*x())[])()\n",
        "char (*(*x[3])())[5]\n",
        "int **a[2][3]\n",
        "int (*(*fp)(int))[10]\n",
        "void (*signal(int, void (*)(int)))(int)\n"
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        printf("\nTest %d: %s", i + 1, test_cases[i]);

        /* Reset variables */
        out[0] = '\0';
        name[0] = '\0';
        datatype[0] = '\0';
        token[0] = '\0';

        /* Reset input stream - simulate input */
        bufp = 0; /* clear buffer */

        /* Process each character of the test case in reverse order */
        int len = strlen(test_cases[i]);
        for (int j = len - 1; j >= 0; j--) {
            ungetch(test_cases[i][j]);
        }

        /* Parse the declaration */
        if (gettoken() != EOF) {
            strcpy(datatype, token); /* 1st token on line is the datatype */
            out[0] = '\0';
            dcl(); /* parse rest of line */
            if (tokentype != '\n')
                printf("syntax error\n");
            if (strlen(name) > 0)
                printf("%s: %s %s\n", name, out, datatype);
            else
                printf("Parse error: no identifier found\n");
        }

        /* Clear buffer for next test */
        bufp = 0;
    }
}

/* test function for undcl */
void test_undcl(void)
{
    printf("\n=== Testing Word Description to Declaration Converter ===\n");

    /* Test cases for undcl - format: name qualifiers... type */
    char test_cases[][100] = {
        "x * char\n", /* x: pointer to char */
        "x [] * char\n", /* x: array of pointer to char */
        "x () * char\n", /* x: function returning pointer to char */
        "x [] * () * char\n", /* x: array of pointer to function returning char */
        "x () * [] * char\n", /* x: function returning pointer to array of char */
        "x [3] * () [5] char\n", /* x: array[3] of pointer to function returning array[5] of char */
        "name * int\n", /* name: pointer to int */
        "func () * int\n", /* func: function returning pointer to int */
        "arr [10] int\n", /* arr: array[10] of int */
        "ptr * arr [5] * char\n" /* ptr: pointer to array[5] of pointer to char */
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        printf("\nTest %d: %s", i + 1, test_cases[i]);

        /* Reset variables */
        out[0] = '\0';
        token[0] = '\0';

        /* Reset input stream */
        bufp = 0;

        /* Process each character of the test case in reverse order */
        int len = strlen(test_cases[i]);
        for (int j = len - 1; j >= 0; j--) {
            ungetch(test_cases[i][j]);
        }

        /* Convert word description to declaration */
        if (gettoken() != EOF) {
            strcpy(out, token);
            int type;
            while ((type = gettoken()) != '\n' && type != EOF)
                if (type == PARENS || type == BRACKETS)
                    strcat(out, token);
                else if (type == '*') {
                    char temp[MAXTOKEN];
                    sprintf(temp, "(*%s)", out);
                    strcpy(out, temp);
                } else if (type == NAME) {
                    char temp[MAXTOKEN];
                    sprintf(temp, "%s %s", token, out);
                    strcpy(out, temp);
                } else
                    printf("invalid input at %s\n", token);
            printf("=> %s\n", out);
        }

        /* Clear buffer for next test */
        bufp = 0;
    }
}

int main(void)
{
    printf("C Declaration Parser - Chapter 5.12\n");
    printf("===================================\n");

    /* Test declaration parsing */
    test_declarations();

    /* Test word description to declaration conversion */
    test_undcl();

    printf("\n=== Interactive Mode ===\n");
    printf("Enter declarations to parse (Ctrl+D to exit):\n");

    /* Interactive mode */
    while (1) {
        /* Reset variables for each new declaration */
        out[0] = '\0';
        name[0] = '\0';
        datatype[0] = '\0';
        token[0] = '\0';
        bufp = 0; /* clear buffer */

        /* Get the first token */
        if (gettoken() == EOF)
            break;

        strcpy(datatype, token); /* 1st token on line is the datatype */
        out[0] = '\0';
        dcl(); /* parse rest of line */
        if (tokentype != '\n')
            printf("syntax error\n");
        else if (strlen(name) > 0)
            printf("%s: %s %s\n", name, out, datatype);
        else
            printf("Parse error: no identifier found\n");
    }

    return 0;
}