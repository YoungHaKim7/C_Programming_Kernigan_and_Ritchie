#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define TEST_INPUT_FILE "test_input.txt"
#define MAX_OUTPUT 1024

int run_program_with_input(char* argv[], char* input, char* output, int output_size)
{
    int pipefd[2];
    pid_t pid;

    // Create a pipe for communication
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return -1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    }

    if (pid == 0) { // Child process
        close(pipefd[1]); // Close write end

        // Redirect stdin to read from pipe
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        // Redirect stdout to a file for capture
        int temp_fd = open("temp_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (temp_fd == -1) {
            perror("open");
            exit(1);
        }
        dup2(temp_fd, STDOUT_FILENO);
        close(temp_fd);

        // Execute the program
        execv("./target/a510_command_line_arguments_ver4", argv);
        perror("execv");
        exit(1);
    } else { // Parent process
        close(pipefd[0]); // Close read end

        // Write input to pipe
        write(pipefd[1], input, strlen(input));
        close(pipefd[1]);

        // Wait for child to finish
        int status;
        waitpid(pid, &status, 0);

        // Read the output
        FILE* temp_file = fopen("temp_output.txt", "r");
        if (temp_file) {
            size_t bytes_read = fread(output, 1, output_size - 1, temp_file);
            output[bytes_read] = '\0';
            fclose(temp_file);
            unlink("temp_output.txt");
        } else {
            output[0] = '\0';
        }

        return WEXITSTATUS(status);
    }
}

void test_basic_pattern_search()
{
    printf("Testing basic pattern search...\n");

    char* argv[] = { "a510_command_line_arguments_ver4", "hello", NULL };
    char input[] = "hello world\nthis is a test\nhello again\n";
    char output[MAX_OUTPUT];

    int exit_code = run_program_with_input(argv, input, output, MAX_OUTPUT);

    assert(exit_code == 2); // Should find 2 matches
    assert(strstr(output, "hello world") != NULL);
    assert(strstr(output, "hello again") != NULL);
    assert(strstr(output, "this is a test") == NULL);

    printf("✓ Basic pattern search test passed\n");
}

void test_numbered_output()
{
    printf("Testing numbered output (-n option)...\n");

    char* argv[] = { "a510_command_line_arguments_ver4", "-n", "test", NULL };
    char input[] = "first line\nthis is a test\nthird line\nanother test\n";
    char output[MAX_OUTPUT];

    int exit_code = run_program_with_input(argv, input, output, MAX_OUTPUT);

    assert(exit_code == 2); // Should find 2 matches
    assert(strstr(output, "2:this is a test") != NULL);
    assert(strstr(output, "4:another test") != NULL);

    printf("✓ Numbered output test passed\n");
}

void test_except_option()
{
    printf("Testing except option (-x option)...\n");

    char* argv[] = { "a510_command_line_arguments_ver4", "-x", "test", NULL };
    char input[] = "first line\nthis is a test\nthird line\nanother test\n";
    char output[MAX_OUTPUT];

    int exit_code = run_program_with_input(argv, input, output, MAX_OUTPUT);

    assert(exit_code == 2); // Should find 2 non-matches
    assert(strstr(output, "first line") != NULL);
    assert(strstr(output, "third line") != NULL);
    assert(strstr(output, "this is a test") == NULL);
    assert(strstr(output, "another test") == NULL);

    printf("✓ Except option test passed\n");
}

void test_combined_options()
{
    printf("Testing combined options (-x -n)...\n");

    char* argv[] = { "a510_command_line_arguments_ver4", "-x", "-n", "test", NULL };
    char input[] = "first line\nthis is a test\nthird line\nanother test\n";
    char output[MAX_OUTPUT];

    int exit_code = run_program_with_input(argv, input, output, MAX_OUTPUT);

    assert(exit_code == 2); // Should find 2 non-matches
    assert(strstr(output, "1:first line") != NULL);
    assert(strstr(output, "3:third line") != NULL);

    printf("✓ Combined options test passed\n");
}

void test_no_matches()
{
    printf("Testing no matches...\n");

    char* argv[] = { "a510_command_line_arguments_ver4", "nonexistent", NULL };
    char input[] = "first line\nsecond line\nthird line\n";
    char output[MAX_OUTPUT];

    int exit_code = run_program_with_input(argv, input, output, MAX_OUTPUT);

    assert(exit_code == 0); // Should find 0 matches
    assert(strlen(output) == 0);

    printf("✓ No matches test passed\n");
}

void test_invalid_option()
{
    printf("Testing invalid option...\n");

    char* argv[] = { "a510_command_line_arguments_ver4", "-z", "test", NULL };
    char input[] = "test line\n";
    char output[MAX_OUTPUT];

    int exit_code = run_program_with_input(argv, input, output, MAX_OUTPUT);

    assert(exit_code == 255); // Should return 255 (-1 as unsigned) for invalid option
    assert(strstr(output, "illegal option") != NULL);

    printf("✓ Invalid option test passed\n");
}

void test_no_arguments()
{
    printf("Testing no arguments...\n");

    char* argv[] = { "a510_command_line_arguments_ver4", NULL };
    char input[] = "test line\n";
    char output[MAX_OUTPUT];

    int exit_code = run_program_with_input(argv, input, output, MAX_OUTPUT);

    assert(exit_code == 0); // Should return 0 for no arguments
    assert(strstr(output, "Usage:") != NULL);

    printf("✓ No arguments test passed\n");
}

void test_empty_input()
{
    printf("Testing empty input...\n");

    char* argv[] = { "a510_command_line_arguments_ver4", "test", NULL };
    char input[] = "";
    char output[MAX_OUTPUT];

    int exit_code = run_program_with_input(argv, input, output, MAX_OUTPUT);

    assert(exit_code == 0); // Should find 0 matches
    assert(strlen(output) == 0);

    printf("✓ Empty input test passed\n");
}

int main()
{
    printf("Running tests for find command line arguments program...\n\n");

    // Run all tests
    test_basic_pattern_search();
    test_numbered_output();
    test_except_option();
    test_combined_options();
    test_no_matches();
    test_invalid_option();
    test_no_arguments();
    test_empty_input();

    printf("\n✅ All tests passed!\n");
    return 0;
}