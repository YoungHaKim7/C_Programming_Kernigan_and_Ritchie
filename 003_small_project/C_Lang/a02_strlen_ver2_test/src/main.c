#include "strlen_impl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    printf("=== STRLEN IMPLEMENTATION COMPARISON ===\n\n");

    const char* test_cases[] = {
        "", // empty string
        "a", // single char
        "Hello", // small word
        "This is a test", // sentence
        "1234567890", // digits
        "Longer string for test!", // longer text
        "With\nnewline", // with special char
        "Embedded\0null", // tricky: stops at first null
        "Spaces   inside", // spaces
        "abcdefghijklmnopqrstuvwxyz" // alphabet
    };

    size_t num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int all_match = 1;

    for (size_t i = 0; i < num_cases; i++) {
        // Copy into modifiable buffer
        char buffer[128];
        strncpy(buffer, test_cases[i], sizeof(buffer));
        buffer[sizeof(buffer) - 1] = '\0';

        size_t len1 = strlen_simple(buffer);
        size_t len2 = strlen_glibc(buffer);
        size_t len3 = strlen_recursive(buffer);
        size_t len4 = strlen_while(buffer);
        size_t len5 = strlen(buffer); // builtin for cross-check

        printf("Test %zu: \"%s\"\n", i + 1, buffer);
        printf("  strlen_simple    = %zu\n", len1);
        printf("  strlen_glibc     = %zu\n", len2);
        printf("  strlen_recursive = %zu\n", len3);
        printf("  strlen_while     = %zu\n", len4);
        printf("  strlen(builtin)  = %zu\n", len5);

        if (len1 == len2 && len2 == len3 && len3 == len4 && len4 == len5) {
            printf("  ✅ All implementations match\n");
        } else {
            printf("  ❌ Mismatch detected!\n");
            all_match = 0;
        }
        printf("--------------------------------------------------\n");
    }

    printf("\n=== SUMMARY ===\n");
    if (all_match) {
        printf("🎉 All implementations produce identical results!\n");
    } else {
        printf("⚠️  Some implementations have discrepancies.\n");
    }

    printf("\n=== PERFORMANCE COMPARISON ===\n");
    const char* perf_string = "This is a performance test string with moderate "
                              "length for benchmarking";
    const int iterations = 1000000;

    // Simple implementation
    clock_t start = clock();
    for (int i = 0; i < iterations; i++) {
        strlen_simple((char*)perf_string);
    }
    clock_t end = clock();
    double simple_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Glibc implementation
    start = clock();
    for (int i = 0; i < iterations; i++) {
        strlen_glibc((char*)perf_string);
    }
    end = clock();
    double glibc_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Builtin implementation
    start = clock();
    for (int i = 0; i < iterations; i++) {
        volatile size_t len = strlen(perf_string);
        (void)len; // Suppress unused variable warning
    }
    end = clock();
    double builtin_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Performance test (%d iterations):\n", iterations);
    printf("  Simple:   %.6f seconds\n", simple_time);
    printf("  Glibc:    %.6f seconds\n", glibc_time);
    printf("  Builtin:  %.6f seconds\n", builtin_time);

    if (glibc_time > 0 && simple_time > 0) {
        printf("  Glibc speedup: %.2fx\n", simple_time / glibc_time);
    }

    return all_match ? 0 : 1;
}
