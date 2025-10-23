# link

<hr />

# build(c23)[|🔝|](#link)

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


# ebook[|🔝|](#link)

- 고해상도 C eBooks
  - https://colorcomputerarchive.com/repo/Documents/Books/The%20C%20Programming%20Language%20%28Kernighan%20Ritchie%29.pdf
- https://www.cc4e.com/book/chap01.md

# 러스트 개발자를 위한 C언어 기초 (1)
- 개고생하면서 배우는 C언어(c23)
  - 교제 - Brian W. Kernighan & Dennis M. Ritchie
  - C Programming Language
- 목차
```
chapter 01 A Tutorial Introduction
                1.1 Getting Started
                1.2 Variables and Arithmetic Expressions
                1.3 The for statement
                1.4 Symbolic Constants
                1.5 Character Input and Output
                1.5.1 File Copying
                1.5.2 Character Counting
                1.5.3 Line Counting
                1.5.4 Word Counting
                1.6 Arrays.
                1.7 Functions
                1.8 Arguments - Call by Value.
                1.9 Character Arrays
                1.10 External Variables and Scope
```

# C provides several other data types besides `int` and `float`, including:[|🔝|](#link)

|||
|-|-|
|char|character -a single byte|
|short|short integer|
|long|long integer|
|double|double-precison floating point|

- print output

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


<hr />

# printf, fprintf, sprintf, snprintf, printf_s, fprintf_s, sprintf_s, snprintf_s[|🔝|](#link)
- https://en.cppreference.com/w/c/io/fprintf.html

# no std

- [Hello World with no libraries Old Man Yells at Code](https://youtu.be/gVaXLlGqQ-c?si=I3OUEcnDBDh3rPns)


```c
int main(void)
{
    const char hello[] = "Hello, world!\n";

    // clang-format off
    asm volatile (
       "mov $1, %%rax\n\t"  // syscall number for write
       "mov $1, %%rdi\n\t"  // stdout (fd = 1)
       "lea %0, %%rsi\n\t"  // address of message
       "mov $14, %%rdx\n\t" // length
       "syscall\n\t"
        :
        : "m"(hello)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
    // clang-format on

    return 0;
}

```

```bash
Hello, world!
```
