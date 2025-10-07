# Result

- linuxOS

```bash
$ /opt/homebrew/opt/gcc@15/bin/g++-15 -std=c++2c -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a01_part3_argc_argv ./src/main.cpp

$ ./target/a01_part3_argc_argv

Hello world C++ reverse sort
2, 3, 7, 9,
9, 7, 3, 2,
number of arguments: 1
argv[0]: ./target/a01_part3_argc_argv
Usage: ./target/a01_part3_argc_argv <name>
error: Recipe `r` failed on line 116 with exit code 1


# ~~~~~~

$ ./target/a01_part3_argc_argv hello test good
Hello world C++ reverse sort
2, 3, 7, 9,
9, 7, 3, 2,
number of arguments: 4
argv[0]: ./target/a01_part3_argc_argv
argv[1]: hello
argv[2]: test
argv[3]: good
Hello, hello!
```
