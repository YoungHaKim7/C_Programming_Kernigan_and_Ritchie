#ifndef STRLEN_IMPL_H
#define STRLEN_IMPL_H

#include <stddef.h>

// Simple strlen implementation
size_t strlen_simple(char* s);

// Optimized "glibc-like" strlen implementation
size_t strlen_glibc(char* str);

// Additional implementations for comparison
size_t strlen_recursive(char* s);
size_t strlen_while(char* s);

#endif // STRLEN_IMPL_H