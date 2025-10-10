# Result


```bash

$ /opt/homebrew/opt/gcc@15/bin/g++-15 -std=c++2c -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a01_make_interfaces_explicit ./src/main.cpp
$ ./target/a01_make_interfaces_explicit

c++26 hello world
round_custom(3.2, true) = 4
round_custom(3.8, false) = 3
round_custom(2.5) = 3
round_custom(-1.2, true) = -1
round_custom(-1.8, false) = -1
round_custom(0.0) = 0
round_custom(1234.567) = 1235
round_custom(1234.567, false) = 1234
round_custom(0.001, true) = 1
round_custom(-0.999, false) = 0
```
