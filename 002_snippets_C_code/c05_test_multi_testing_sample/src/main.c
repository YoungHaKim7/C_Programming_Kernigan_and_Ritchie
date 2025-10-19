#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define MAXFIELDS 10

char* lineptr[MAXLINES];
char line_storage[MAXLINES * MAXLEN];
size_t storage_pos = 0;

typedef struct {
    int numeric;
    int reverse;
    int fold;
    int directory;
    int field_num;
    int field_count;
    struct {
        int numeric;
        int reverse;
        int fold;
        int directory;
    } field_opts[MAXFIELDS];
} SortOptions;

SortOptions* global_opts;

int readlines(char* lineptr[], int maxlines);
void writelines(char* lineptr[], int nlines);
void qsort_custom(void* lineptr[], int left, int right, int (*comp)(void*, void*), SortOptions* opts);
int numcmp(char*, char*);
int strcmp_fold(char* s1, char* s2);
int strcmp_dir(char* s1, char* s2);
int strcmp_fold_dir(char* s1, char* s2);
void swap(void* v[], int, int);
int fieldcmp(void* v1, void* v2, SortOptions* opts);
int fieldcmp_wrapper(void* v1, void* v2);
int numcmp_wrapper(void* v1, void* v2);
int strcmp_fold_wrapper(void* v1, void* v2);
int strcmp_dir_wrapper(void* v1, void* v2);
int strcmp_fold_dir_wrapper(void* v1, void* v2);
int strcmp_wrapper(void* v1, void* v2);
char* get_field(char* line, int field_num);
void parse_field_options(char* opt_str, SortOptions* opts);
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

void qsort_custom(void* v[], int left, int right, int (*comp)(void*, void*), SortOptions* opts)
{
    int i, last;
    void swap(void* v[], int, int);

    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (opts->reverse ? ((*comp)(v[i], v[left]) > 0) : ((*comp)(v[i], v[left]) < 0)) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort_custom(v, left, last - 1, comp, opts);
    qsort_custom(v, last + 1, right, comp, opts);
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

char* get_field(char* line, int field_num)
{
    int field = 0;
    char* start = line;

    while (*start && field < field_num) {
        while (*start && !isspace(*start)) {
            start++;
        }
        while (*start && isspace(*start)) {
            start++;
        }
        field++;
    }
    return start;
}

int fieldcmp(void* v1, void* v2, SortOptions* opts)
{
    char* s1 = (char*)v1;
    char* s2 = (char*)v2;
    char* field1 = get_field(s1, opts->field_num);
    char* field2 = get_field(s2, opts->field_num);
    int result;

    if (opts->field_opts[opts->field_num].numeric) {
        result = numcmp(field1, field2);
    } else if (opts->field_opts[opts->field_num].fold && opts->field_opts[opts->field_num].directory) {
        result = strcmp_fold_dir(field1, field2);
    } else if (opts->field_opts[opts->field_num].fold) {
        result = strcmp_fold(field1, field2);
    } else if (opts->field_opts[opts->field_num].directory) {
        result = strcmp_dir(field1, field2);
    } else {
        result = strcmp(field1, field2);
    }

    return result;
}

int fieldcmp_wrapper(void* v1, void* v2)
{
    return fieldcmp(v1, v2, global_opts);
}

int numcmp_wrapper(void* v1, void* v2)
{
    return numcmp((char*)v1, (char*)v2);
}

int strcmp_fold_wrapper(void* v1, void* v2)
{
    return strcmp_fold((char*)v1, (char*)v2);
}

int strcmp_dir_wrapper(void* v1, void* v2)
{
    return strcmp_dir((char*)v1, (char*)v2);
}

int strcmp_fold_dir_wrapper(void* v1, void* v2)
{
    return strcmp_fold_dir((char*)v1, (char*)v2);
}

int strcmp_wrapper(void* v1, void* v2)
{
    return strcmp((char*)v1, (char*)v2);
}

void swap(void* v[], int i, int j)
{
    void* temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void parse_field_options(char* opt_str, SortOptions* opts)
{
    opts->field_count = 0;
    char* token = strtok(opt_str, ",");
    while (token && opts->field_count < MAXFIELDS) {
        opts->field_opts[opts->field_count].numeric = 0;
        opts->field_opts[opts->field_count].reverse = 0;
        opts->field_opts[opts->field_count].fold = 0;
        opts->field_opts[opts->field_count].directory = 0;

        for (int i = 0; token[i]; i++) {
            switch (token[i]) {
            case 'n':
                opts->field_opts[opts->field_count].numeric = 1;
                break;
            case 'r':
                opts->field_opts[opts->field_count].reverse = 1;
                break;
            case 'f':
                opts->field_opts[opts->field_count].fold = 1;
                break;
            case 'd':
                opts->field_opts[opts->field_count].directory = 1;
                break;
            }
        }
        opts->field_count++;
        token = strtok(NULL, ",");
    }
}

int main(int argc, char* argv[])
{
    int nlines;
    SortOptions opts = { 0, 0, 0, 0, 0, 0, { { 0 } } };
    int (*comp)(void*, void*);

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            opts.numeric = 1;
        } else if (strcmp(argv[i], "-r") == 0) {
            opts.reverse = 1;
        } else if (strcmp(argv[i], "-f") == 0) {
            opts.fold = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            opts.directory = 1;
        } else if (strncmp(argv[i], "-k", 2) == 0) {
            opts.field_num = atoi(argv[i] + 2) - 1;
        } else if (strncmp(argv[i], "-field", 6) == 0) {
            parse_field_options(argv[i] + 6, &opts);
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (opts.field_num > 0) {
            global_opts = &opts;
            comp = fieldcmp_wrapper;
            qsort_custom((void**)lineptr, 0, nlines - 1, comp, &opts);
        } else if (opts.numeric) {
            comp = numcmp_wrapper;
        } else if (opts.fold && opts.directory) {
            comp = strcmp_fold_dir_wrapper;
        } else if (opts.fold) {
            comp = strcmp_fold_wrapper;
        } else if (opts.directory) {
            comp = strcmp_dir_wrapper;
        } else {
            comp = strcmp_wrapper;
        }

        qsort_custom((void**)lineptr, 0, nlines - 1, comp, &opts);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}