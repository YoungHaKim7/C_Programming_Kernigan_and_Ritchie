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
