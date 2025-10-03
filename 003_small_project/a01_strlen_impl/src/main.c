#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Simple strlen
size_t strlen_simple(char* s)
{
    char* p;
    for (p = s; *p; ++p)
        ;
    return p - s;
}

// Simplified "glibc-like" strlen (truncated for demo)
size_t strlen_glibc_simple(char* str)
{
    char* ptr;
    unsigned long* longword_ptr;
    unsigned long longword, himagic, lomagic;

    for (ptr = str; ((unsigned long)ptr & (sizeof(unsigned long) - 1)) != 0; ++ptr) {
        if (*ptr == '\0') {
            return ptr - str;
        }
    }

    longword_ptr = (unsigned long*)ptr;
    himagic = 0x80808080UL;
    lomagic = 0x01010101UL;

    for (;;) {
        longword = *longword_ptr++;
        if ((longword - lomagic) & ~longword & himagic) {
            char* cp = (char*)(longword_ptr - 1);
            if (cp[0] == 0) return cp - str;
            if (cp[1] == 0) return cp - str + 1;
            if (cp[2] == 0) return cp - str + 2;
            if (cp[3] == 0) return cp - str + 3;
        }
    }
}

int main(void)
{
    const char* test_cases[] = {
        "",                         // empty string
        "a",                        // single char
        "Hello",                    // small word
        "This is a test",           // sentence
        "1234567890",               // digits
        "Longer string for test!",  // longer text
        "With\nnewline",            // with special char
        "Embedded\0null",           // tricky: stops at first null
        "Spaces   inside",          // spaces
        "abcdefghijklmnopqrstuvwxyz" // alphabet
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_cases; i++) {
        // Copy into modifiable buffer
        char buffer[128];
        strncpy(buffer, test_cases[i], sizeof(buffer));
        buffer[sizeof(buffer)-1] = '\0';

        size_t len1 = strlen_simple(buffer);
        size_t len2 = strlen_glibc_simple(buffer);
        size_t len3 = strlen(buffer); // builtin for cross-check

        printf("Test %zu: \"%s\"\n", i+1, buffer);
        printf("  strlen_simple = %zu\n", len1);
        printf("  strlen_glibc  = %zu\n", len2);
        printf("  strlen(builtin) = %zu\n", len3);

        if (len1 == len2 && len2 == len3) {
            printf("  ✅ Match\n");
        } else {
            printf("  ❌ Mismatch!\n");
        }
        printf("--------------------------------------------------\n");
    }

    return 0;
}
