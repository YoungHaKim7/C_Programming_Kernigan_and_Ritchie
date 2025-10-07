#include "strlen_impl.h"
#include <stdint.h>

// Simple strlen implementation - straightforward approach
size_t strlen_simple(char* s)
{
    char* p;
    for (p = s; *p; ++p)
        ;
    return p - s;
}

// Optimized "glibc-like" strlen implementation
// This version fixes the bugs in the original implementation
size_t strlen_glibc(char* str)
{
    const char* ptr = str;

    // Handle unaligned bytes first
    while (((uintptr_t)ptr & (sizeof(unsigned long) - 1)) != 0) {
        if (*ptr == '\0') {
            return ptr - str;
        }
        ++ptr;
    }

    // Now ptr is aligned to word boundary
    const unsigned long* longword_ptr = (const unsigned long*)ptr;
    const unsigned long himagic = 0x80808080UL;
    const unsigned long lomagic = 0x01010101UL;

    // Check 4 bytes at a time
    for (;;) {
        unsigned long longword = *longword_ptr++;

        // Check if any byte in the word is zero
        if (((longword - lomagic) & ~longword & himagic) != 0) {
            const char* cp = (const char*)(longword_ptr - 1);

            // Check each byte in the word
            if (cp[0] == 0)
                return cp - str;
            if (cp[1] == 0)
                return cp - str + 1;
            if (cp[2] == 0)
                return cp - str + 2;
            if (cp[3] == 0)
                return cp - str + 3;
        }
    }
}

// Recursive strlen implementation (for educational purposes)
size_t strlen_recursive(char* s)
{
    if (*s == '\0') {
        return 0;
    }
    return 1 + strlen_recursive(s + 1);
}

// While loop strlen implementation
size_t strlen_while(char* s)
{
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}