#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char* lineptr[MAXLINES];
char line_storage[MAXLINES * MAXLEN];
int storage_pos = 0;

int readlines(char* lineptr[], int maxlines);
void writelines(char* lineptr[], int nlines);
void qsort_custom(void* lineptr[], int left, int right, int (*comp)(void*, void*), int reverse);
int numcmp(char*, char*);
int strcmp_fold(char* s1, char* s2);
int strcmp_dir(char* s1, char* s2);
int strcmp_fold_dir(char* s1, char* s2);
void swap(void* v[], int, int);
int get_line(char s[], int lim);

int readlines(char* lineptr[], int maxlines)
{
    int len, nlines;
    char* p = line_storage;
    char line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || storage_pos + len > sizeof(line_storage)) {
            return -1;
        }
        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
        p += len;
        storage_pos += len;
    }
    return nlines;
}

void writelines(char* lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

int get_line(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void qsort_custom(void* v[], int left, int right, int (*comp)(void*, void*), int reverse)
{
    int i, last;
    void swap(void* v[], int, int);

    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (reverse ? ((*comp)(v[i], v[left]) > 0) : ((*comp)(v[i], v[left]) < 0)) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort_custom(v, left, last - 1, comp, reverse);
    qsort_custom(v, last + 1, right, comp, reverse);
}

int numcmp(char* s1, char* s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}

int strcmp_fold(char* s1, char* s2)
{
    while (tolower(*s1) == tolower(*s2)) {
        if (*s1 == '\0') {
            return 0;
        }
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}

int strcmp_dir(char* s1, char* s2)
{
    char c1, c2;
    do {
        while (*s1 && !isalnum(*s1) && !isspace(*s1)) {
            s1++;
        }
        while (*s2 && !isalnum(*s2) && !isspace(*s2)) {
            s2++;
        }
        if (*s1 == '\0' || *s2 == '\0') {
            return *s1 - *s2;
        }
        c1 = *s1++;
        c2 = *s2++;
    } while (c1 == c2);
    return c1 - c2;
}

int strcmp_fold_dir(char* s1, char* s2)
{
    char c1, c2;
    do {
        while (*s1 && !isalnum(*s1) && !isspace(*s1)) {
            s1++;
        }
        while (*s2 && !isalnum(*s2) && !isspace(*s2)) {
            s2++;
        }
        if (*s1 == '\0' || *s2 == '\0') {
            return tolower(*s1) - tolower(*s2);
        }
        c1 = tolower(*s1++);
        c2 = tolower(*s2++);
    } while (c1 == c2);
    return c1 - c2;
}

void swap(void* v[], int i, int j)
{
    void* temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main(int argc, char* argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int fold = 0;
    int directory = 0;
    int (*comp)(void*, void*);

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            numeric = 1;
        } else if (strcmp(argv[i], "-r") == 0) {
            reverse = 1;
        } else if (strcmp(argv[i], "-f") == 0) {
            fold = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            directory = 1;
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (numeric) {
            comp = (int (*)(void*, void*))numcmp;
        } else if (fold && directory) {
            comp = (int (*)(void*, void*))strcmp_fold_dir;
        } else if (fold) {
            comp = (int (*)(void*, void*))strcmp_fold;
        } else if (directory) {
            comp = (int (*)(void*, void*))strcmp_dir;
        } else {
            comp = (int (*)(void*, void*))strcmp;
        }

        qsort_custom((void**)lineptr, 0, nlines - 1, comp, reverse);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}