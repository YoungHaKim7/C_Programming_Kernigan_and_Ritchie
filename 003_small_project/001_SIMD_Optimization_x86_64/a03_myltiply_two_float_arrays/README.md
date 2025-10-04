# Result(`-mavx` 추가해야함)

```bash
$ /opt/gcc-15/bin/gcc -std=c23 -mavx -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a03_myltiply_two_float_arrays ./src/main.c
./target/a03_myltiply_two_float_arrays

2.000000 6.000000 12.000000 20.000000 30.000000 42.000000 56.000000 72.000000

```
