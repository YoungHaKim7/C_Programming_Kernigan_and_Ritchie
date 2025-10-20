# Result

```bash
Usage: find -x -n pattern
```


```bash
$ echo -e "hello world\nmain function\nanother line" | ./build/./target/a510_command_line_arguments_ver4 -x -n main
1:hello world
3:another line

$ cat src/main.c | ./build/./target/a510_command_line_arguments_ver4 -n main
23:int main(int argc, char* argv[])
```

# Looking at the code, this is a pattern-finding program similar to grep. Here's how to use it:

- Usage:

```bash
./build/./target/a510_command_line_arguments_ver4 [options] pattern
```

- Options:

  - `-x`: Except mode - print lines that DON'T match the pattern
  - `-n`: Number mode - print line numbers before matching lines

- How it works:

  - 1. The program reads lines from standard input
  - 2. It searches for the pattern you provide
  - 3. It prints matching lines (or non-matching lines with -x)
  - 4. With -n, it includes line numbers

- Example usage:

```bash
# Find lines containing "main" from input
echo -e "hello world\nmain function\nanother line" | ./build/./target/a510_command_line_arguments_ver4 main

# Find lines NOT containing "main" with line numbers
echo -e "hello world\nmain function\nanother line" | ./build/./target/a510_command_line_arguments_ver4 -x -n main

# Find lines with "error" and show line numbers
cat logfile.txt | ./build/./target/a510_command_line_arguments_ver4 -n error
```

- The error you saw was because -5 isn't a valid option - only x and n are supported.

# I've created a comprehensive test suite for your command line arguments program. The test covers:

- Test Coverage:
  - 1. Basic pattern search - Tests basic functionality of finding patterns
  - 2. Numbered output (-n) - Tests line numbering option
  - 3. Except option (-x) - Tests inverse matching
  - 4. Combined options (-x -n) - Tests multiple flags together
  - 5. No matches - Tests behavior when no patterns are found
  - 6. Invalid option - Tests error handling for unknown flags
  - 7. No arguments - Tests usage message when args are missing
  - 8. Empty input - Tests behavior with empty input

- The test uses fork() and exec() to run your program in a separate process with controlled input, capturing both stdout and exit codes for verification.
