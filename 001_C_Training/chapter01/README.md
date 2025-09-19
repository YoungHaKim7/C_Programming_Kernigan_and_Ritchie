# build(c23)

```bash
$ gcc --std=c23 src/main.c

$ ls
a.out*  README.md  src/

$ ./a.out
Decimal: 1000000
Hex:     DEADBEEF
Binary:  172 (0b1010'1100)
Octal:   123456
```


# ebook

- 고해상도 C eBooks
  - https://colorcomputerarchive.com/repo/Documents/Books/The%20C%20Programming%20Language%20%28Kernighan%20Ritchie%29.pdf
- https://www.cc4e.com/book/chap01.md

# C provides several other data types besides `int` and `float`, including:

|||
|-|-|
|char|character -a single byte|
|short|short integer|
|long|long integer|
|double|double-precison floating point|

- outout

|||
|-|-|
|`%d`|print as decimal integer|
|`%6d`|print as decimal integer, at least 6 characters wide|
|`f`|print as floating point|
|`6f`|print as floating point, at least 6 characters wide|
|`.2f`|print as floating point, 2 characters after decimal point |
|`6 .2f`|print as floating point, at least 6 wide and 2 after decimal point |

- octal, hexadecimal, character, string, itself.

|||
|-|-|
|`%o`|octal|
|`%x`|hexadecimal|
|`%c`|character|
|`%s`|character string|
|`%%`|itself|

