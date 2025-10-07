# Result

- linuxOS

```bash
$ /opt/homebrew/opt/gcc@15/bin/g++-15 -std=c++2c -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a01_part4_argc_argv_array ./src/main.cpp
$ ./target/a01_part4_argc_argv_array

Hello world C++26 lang number of arguments: 1
argv[0]: ./target/a01_part4_argc_argv_array



# ~~~~

$ ./target/a01_part4_argc_argv_array test good cpp26
Hello world C++26 lang number of arguments: 4
argv[0]: ./target/a01_part4_argc_argv_array
argv[1]: test
argv[2]: good
argv[3]: cpp26
```
