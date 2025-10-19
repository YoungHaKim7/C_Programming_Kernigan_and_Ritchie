#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void run_test(const char* test_name, const char* program_args, const char* input_file)
{
    printf("\n=== TEST: %s ===\n", test_name);
    printf("Command: ./sort_program %s\n", program_args);
    printf("Input:\n");

    FILE* input = fopen(input_file, "r");
    if (input) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), input)) {
            printf("%s", buffer);
        }
        fclose(input);
    }

    printf("\nOutput:\n");
    char command[512];
    snprintf(command, sizeof(command), "./sort_program %s < %s", program_args, input_file);
    system(command);
    printf("\n");
}

int main()
{
    printf("Compiling the sort program...\n");
    system("gcc -o sort_program sort_program.c");

    // Test 1: Basic lexicographic sort
    FILE* f1 = fopen("test1.txt", "w");
    fprintf(f1, "zebra\napple\nbanana\ncherry\ndate\n");
    fclose(f1);
    run_test("Basic lexicographic sort", "", "test1.txt");

    // Test 2: Numeric sort
    FILE* f2 = fopen("test2.txt", "w");
    fprintf(f2, "42\n7\n100\n3\n25\n");
    fclose(f2);
    run_test("Numeric sort", "-n", "test2.txt");

    // Test 3: Reverse sort
    FILE* f3 = fopen("test3.txt", "w");
    fprintf(f3, "zebra\napple\nbanana\ncherry\ndate\n");
    fclose(f3);
    run_test("Reverse lexicographic sort", "-r", "test3.txt");

    // Test 4: Numeric reverse sort
    FILE* f4 = fopen("test4.txt", "w");
    fprintf(f4, "42\n7\n100\n3\n25\n");
    fclose(f4);
    run_test("Reverse numeric sort", "-n -r", "test4.txt");

    // Test 5: Case folding sort
    FILE* f5 = fopen("test5.txt", "w");
    fprintf(f5, "Apple\nbanana\nCHERRY\nDate\napple\n");
    fclose(f5);
    run_test("Case folding sort", "-f", "test5.txt");

    // Test 6: Directory order sort
    FILE* f6 = fopen("test6.txt", "w");
    fprintf(f6, "hello-world\nhello_world\nhello world\nhello,world\n");
    fclose(f6);
    run_test("Directory order sort", "-d", "test6.txt");

    // Test 7: Combined flags
    FILE* f7 = fopen("test7.txt", "w");
    fprintf(f7, "Hello-world\nHELLO_WORLD\nhello world\nHELLO,WORLD\n");
    fclose(f7);
    run_test("Combined directory and case folding", "-d -f", "test7.txt");

    // Test 8: Field sorting (2nd field)
    FILE* f8 = fopen("test8.txt", "w");
    fprintf(f8, "apple 42 red\nbanana 7 blue\ncherry 100 green\ndate 3 yellow\n");
    fclose(f8);
    run_test("Field sort (2nd field numeric)", "-k2 -n", "test8.txt");

    // Test 9: Field sorting (1st field case-insensitive)
    FILE* f9 = fopen("test9.txt", "w");
    fprintf(f9, "Apple fruit\nBerry fruit\nCherry fruit\napple fruit\n");
    fclose(f9);
    run_test("Field sort (1st field case folding)", "-k1 -f", "test9.txt");

    // Test 10: Complex test with mixed numbers and text
    FILE* f10 = fopen("test10.txt", "w");
    fprintf(f10, "100 apples\n3 bananas\n7 cherries\n25 dates\n42 eggs\n");
    fclose(f10);
    run_test("Complex mixed sort", "-n", "test10.txt");

    // Test 11: Field sorting with directory order
    FILE* f11 = fopen("test11.txt", "w");
    fprintf(f11, "user-id:123 name:John Doe\nuser-id:456 name:Jane Smith\nuser-id:789 name:Bob Johnson\n");
    fclose(f11);
    run_test("Field sort with directory order", "-k2 -d", "test11.txt");

    // Test 12: Reverse field sort
    FILE* f12 = fopen("test12.txt", "w");
    fprintf(f12, "productA 10.99\ncategoryB 5.99\nproductC 15.99\ncategoryD 2.99\n");
    fclose(f12);
    run_test("Reverse field sort (2nd field numeric)", "-k2 -n -r", "test12.txt");

    // Cleanup
    system("rm -f test1.txt test2.txt test3.txt test4.txt test5.txt test6.txt test7.txt test8.txt test9.txt test10.txt test11.txt test12.txt");
    system("rm -f sort_program");

    printf("\n=== All tests completed ===\n");
    return 0;
}