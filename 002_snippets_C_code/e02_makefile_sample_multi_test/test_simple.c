#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_test(const char *test_name, const char *program_args, const char *input_data) {
    printf("\n=== TEST: %s ===\n", test_name);
    printf("Command: ./simple_sort %s\n", program_args);
    printf("Input:\n%s", input_data);

    printf("\nOutput:\n");
    char command[1024];
    snprintf(command, sizeof(command), "echo '%s' | ./simple_sort %s", input_data, program_args);
    FILE *fp = popen(command, "r");
    if (fp) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), fp)) {
            printf("%s", buffer);
        }
        pclose(fp);
    }
    printf("\n");
}

int main() {
    printf("Compiling the simple sort program...\n");
    system("gcc -o simple_sort simple_sort.c");

    // Test 1: Basic lexicographic sort
    run_test("Basic lexicographic sort", "", "zebra\napple\nbanana\ncherry\ndate\n");

    // Test 2: Numeric sort
    run_test("Numeric sort", "-n", "42\n7\n100\n3\n25\n");

    // Test 3: Reverse sort
    run_test("Reverse lexicographic sort", "-r", "zebra\napple\nbanana\ncherry\ndate\n");

    // Test 4: Numeric reverse sort
    run_test("Reverse numeric sort", "-n -r", "42\n7\n100\n3\n25\n");

    // Test 5: Case folding sort
    run_test("Case folding sort", "-f", "Apple\nbanana\nCHERRY\nDate\napple\n");

    // Test 6: Directory order sort
    run_test("Directory order sort", "-d", "hello-world\nhello_world\nhello world\nhello,world\n");

    // Test 7: Combined flags
    run_test("Combined directory and case folding", "-d -f", "Hello-world\nHELLO_WORLD\nhello world\nHELLO,WORLD\n");

    // Test 8: Complex test with mixed numbers and text
    run_test("Complex mixed sort", "-n", "100 apples\n3 bananas\n7 cherries\n25 dates\n42 eggs\n");

    // Test 9: Negative numbers
    run_test("Negative numbers", "-n", "-10\n5\n-3\n0\n8\n");

    // Test 10: Decimal numbers
    run_test("Decimal numbers", "-n", "3.14\n2.71\n1.618\n0.577\n4.669\n");

    system("rm -f simple_sort");
    printf("\n=== All tests completed ===\n");
    return 0;
}