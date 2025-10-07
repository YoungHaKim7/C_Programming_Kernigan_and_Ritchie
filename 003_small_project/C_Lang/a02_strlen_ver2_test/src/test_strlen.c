#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// External declarations for the strlen implementations
extern size_t strlen_simple(char* s);
extern size_t strlen_glibc(char* str);

// Test result structure
typedef struct {
    const char* test_name;
    int passed;
    const char* error_msg;
} test_result_t;

// Global test counters
static int tests_run = 0;
static int tests_passed = 0;
static int tests_failed = 0;

// Test macro for assertions
#define TEST_ASSERT(condition, message)                                        \
    do {                                                                       \
        tests_run++;                                                           \
        if (condition) {                                                       \
            tests_passed++;                                                    \
            printf("✅ %s\n", message);                                        \
        } else {                                                               \
            tests_failed++;                                                    \
            printf("❌ %s\n", message);                                        \
        }                                                                      \
    } while (0)

// Test macro for string length comparisons
#define TEST_STRLEN(str, expected_len)                                         \
    do {                                                                       \
        char buffer[256];                                                      \
        strncpy(buffer, str, sizeof(buffer));                                  \
        buffer[sizeof(buffer) - 1] = '\0';                                     \
                                                                               \
        size_t simple_len = strlen_simple(buffer);                             \
        size_t glibc_len = strlen_glibc(buffer);                               \
        size_t builtin_len = strlen(buffer);                                   \
                                                                               \
        printf("Testing: \"%s\"\n", str);                                      \
        printf("  Expected: %d\n", expected_len);                              \
        printf("  Simple:   %zu\n", simple_len);                               \
        printf("  Glibc:    %zu\n", glibc_len);                                \
        printf("  Builtin:  %zu\n", builtin_len);                              \
                                                                               \
        TEST_ASSERT(                                                           \
            simple_len == expected_len, "Simple implementation correct");      \
        TEST_ASSERT(                                                           \
            glibc_len == expected_len, "Glibc implementation correct");        \
        TEST_ASSERT(                                                           \
            builtin_len == expected_len, "Builtin implementation correct");    \
        TEST_ASSERT(simple_len == glibc_len, "Simple and Glibc match");        \
        TEST_ASSERT(simple_len == builtin_len, "Simple and Builtin match");    \
        printf("\n");                                                          \
    } while (0)

// Basic functionality tests
void test_basic_functionality()
{
    printf("=== BASIC FUNCTIONALITY TESTS ===\n");

    TEST_STRLEN("", 0);
    TEST_STRLEN("a", 1);
    TEST_STRLEN("ab", 2);
    TEST_STRLEN("abc", 3);
    TEST_STRLEN("Hello", 5);
    TEST_STRLEN("World!", 6);
    TEST_STRLEN("1234567890", 10);
    TEST_STRLEN("abcdefghijklmnopqrstuvwxyz", 26);
}

// Edge case tests
void test_edge_cases()
{
    printf("=== EDGE CASE TESTS ===\n");

    // Empty string
    TEST_STRLEN("", 0);

    // Single character
    TEST_STRLEN("a", 1);

    // String with spaces
    TEST_STRLEN(" ", 1);
    TEST_STRLEN("  ", 2);
    TEST_STRLEN("   ", 3);

    // String with special characters
    TEST_STRLEN("\n", 1);
    TEST_STRLEN("\t", 1);
    TEST_STRLEN("\r", 1);
    TEST_STRLEN("Hello\nWorld", 11);
    TEST_STRLEN("Tab\tHere", 8);

    // String with embedded null (should stop at first null)
    char embedded_null[] = "Hello\0World";
    char buffer[256];
    strncpy(buffer, embedded_null, sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0';

    size_t simple_len = strlen_simple(buffer);
    size_t glibc_len = strlen_glibc(buffer);
    size_t builtin_len = strlen(buffer);

    printf("Testing embedded null: \"Hello\\0World\"\n");
    printf("  Simple:   %zu\n", simple_len);
    printf("  Glibc:    %zu\n", glibc_len);
    printf("  Builtin:  %zu\n", builtin_len);

    TEST_ASSERT(simple_len == 5, "Simple handles embedded null");
    TEST_ASSERT(glibc_len == 5, "Glibc handles embedded null");
    TEST_ASSERT(builtin_len == 5, "Builtin handles embedded null");
    printf("\n");
}

// Long string tests
void test_long_strings()
{
    printf("=== LONG STRING TESTS ===\n");

    // Create long strings
    char long_str1[1000];
    char long_str2[2000];
    char long_str3[5000];

    // Fill with pattern
    for (int i = 0; i < 999; i++) {
        long_str1[i] = 'A' + (i % 26);
    }
    long_str1[999] = '\0';

    for (int i = 0; i < 1999; i++) {
        long_str2[i] = '0' + (i % 10);
    }
    long_str2[1999] = '\0';

    for (int i = 0; i < 4999; i++) {
        long_str3[i] = 'a' + (i % 26);
    }
    long_str3[4999] = '\0';

    TEST_STRLEN(long_str1, 999);
    TEST_STRLEN(long_str2, 1999);
    TEST_STRLEN(long_str3, 4999);
}

// Performance comparison
void test_performance()
{
    printf("=== PERFORMANCE TESTS ===\n");

    const int iterations = 1000000;
    const char* test_string
        = "This is a performance test string with moderate length";

    // Test simple implementation
    clock_t start = clock();
    for (int i = 0; i < iterations; i++) {
        strlen_simple((char*)test_string);
    }
    clock_t end = clock();
    double simple_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Test glibc implementation
    start = clock();
    for (int i = 0; i < iterations; i++) {
        strlen_glibc((char*)test_string);
    }
    end = clock();
    double glibc_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Test builtin implementation
    start = clock();
    for (int i = 0; i < iterations; i++) {
        volatile size_t len = strlen(test_string);
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
    printf("\n");
}

// Stress test with various alignments
void test_alignment_stress()
{
    printf("=== ALIGNMENT STRESS TESTS ===\n");

    // Test strings at different memory alignments
    char aligned_buffer[1024];
    char* aligned_ptr
        = (char*)(((uintptr_t)aligned_buffer + 7) & ~7); // 8-byte aligned

    for (int offset = 0; offset < 8; offset++) {
        char* test_ptr = aligned_ptr + offset;
        strcpy(test_ptr, "Alignment test string");

        size_t simple_len = strlen_simple(test_ptr);
        size_t glibc_len = strlen_glibc(test_ptr);
        size_t builtin_len = strlen(test_ptr);

        printf("Offset %d: \"%s\"\n", offset, test_ptr);
        printf("  Simple:   %zu\n", simple_len);
        printf("  Glibc:    %zu\n", glibc_len);
        printf("  Builtin:  %zu\n", builtin_len);

        TEST_ASSERT(simple_len == 21, "Simple alignment test");
        TEST_ASSERT(glibc_len == 21, "Glibc alignment test");
        TEST_ASSERT(builtin_len == 21, "Builtin alignment test");
        printf("\n");
    }
}

// Test summary
void print_test_summary()
{
    printf("=== TEST SUMMARY ===\n");
    printf("Total tests: %d\n", tests_run);
    printf("Passed: %d\n", tests_passed);
    printf("Failed: %d\n", tests_failed);
    printf("Success rate: %.1f%%\n",
        tests_run > 0 ? (100.0 * tests_passed / tests_run) : 0.0);

    if (tests_failed == 0) {
        printf("🎉 All tests passed!\n");
    } else {
        printf("⚠️  Some tests failed. Check implementation.\n");
    }
}

int main(void)
{
    printf("Starting strlen implementation tests...\n\n");

    test_basic_functionality();
    test_edge_cases();
    test_long_strings();
    test_performance();
    test_alignment_stress();

    print_test_summary();

    return tests_failed > 0 ? 1 : 0;
}