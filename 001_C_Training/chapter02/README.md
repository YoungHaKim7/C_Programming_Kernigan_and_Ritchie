# link

<hr />

# 목차) Chapter 2 - Types, Operators and Expressions

```
Chapter 2 - Types, Operators and Expressions
  2.1 Variable Names.
  2.2 Data Types and Sizes.
  2.3 Constants.
  2.4 Declarations.
  2.5 Arithmetic Operators.
  2.6 Relational and Logical Operators.
  2.7 Type Conversions.
  2.8 Increment and Decrement Operators.
  2.9 Bitwise Operators.
  2.10 Assignment Operators and Expressions.
  2.11 Conditional Expressions.
  2.12 Precedence and Order of Evaluatio
```

<hr />

# The complete set of escape sequences is

|||||
|-|-|-|-|
|`\a`|alert(bell)<br />character|`\\`|backslash|
|`\b`|backspace|`\?`|question mark|
|`\f`|formfeed|`\'`|single quote|
|`\n`|newline|`\"`|double quote|
|`\r`|carriage return|`\ooo`|octal number|
|`\t`|horizontal tab|`\xhh`|hexadecimal number|
|`\v`|vertical tab|||

# `\null`

- The character constant '\0' represents the character with value zero, the null character. '\0'
is often written instead of 0 to emphasize the character nature of some expression, but the
numeric value is just 0.
  - 문자 상수 '\\0'은 값이 0인 문자, 즉 널 문자를 나타냅니다. '\\0'
어떤 표현의 성격을 강조하기 위해 종종 0 대신에 쓰이지만
숫자 값은 단지 0입니다.

- (p21)
- The body of the while now consists of an if, which in turn controls the increment ++nl. The
if statement tests the parenthesized condition, and if the condition is true, executes the
statement (or group of statements in braces) that follows. We have again indented to show
what is controlled by what.
The double equals sign== is the C notation for ``is equal to'' (like Pascal's single= or Fortran's
.EQ.). This symbol is used to distinguish the equality test from the single= that C uses for
assignment. A word of caution: newcomers to C occasionally write= when they mean==
. As
- we will see in Chapter 2, the result is usually a legal expression, so you will get no warning.
A character written between single quotes represents an integer value equal to the numerical
value of the character in the machine's character set. This is called a character constant,
although it is just another way to write a small integer. So, for example, 'A' is a character
constant; in the ASCII character set its value is 65, the internal representation of the character
A. Of course, 'A' is to be preferred over 65: its meaning is obvious, and it is independent of a
particular character set.
- The escape sequences used in string constants are also legal in character constants, so '\n'
stands for the value of the newline character, which is 10 in ASCII. You should note carefully
that '\n' is a single character, and in expressions is just an integer; on the other hand, '\n' is
a string constant that happens to contain only one character. The topic of strings versus
characters is discussed further in Chapter 2.
- While의 본문은 이제 if로 구성되며, 이는 차례로 증가 ++nl을 제어합니다. 그

If 문은 괄호 안에 있는 조건을 테스트하고, 조건이 참이면,

이어지는 문장(또는 중괄호 안의 문장 그룹). 우리는 보여주기 위해 다시 들여쓰기를 했다

무엇에 의해 통제되는가.

이중 등호==는 ``is equal to''에 대한 C 표기법이다 (파스칼의 싱글= 또는 포트란의

. EQ.). 이 기호는 C가 사용하는 single=와 평등 테스트를 구별하는 데 사용됩니다.

과제. 주의 사항: C에 새로 온 사람들은 가끔 그들이 의미할 때==를 쓴다.

. 에 따라

우리는 2장에서 보게 될 것입니다, 결과는 일반적으로 법적 표현이므로 경고를 받지 않을 것입니다.

큰따옴표 사이에 쓰여진 문자는 숫자와 같은 정수 값을 나타냅니다.

기계의 문자 집합에 있는 문자의 값. 이것을 문자 상수라고 합니다.

비록 그것은 작은 정수를 쓰는 또 다른 방법일 뿐이지만. 예를 들어, 'A'는 문자입니다.

상수; ASCII 문자 집합에서 그 값은 65이며, 문자의 내부 표현

에이. 물론, 'A'는 65세 이상 선호된다: 그 의미는 명백하며, 독립적이다.

특정 문자 집합.

문자열 상수에 사용되는 이스케이프 시퀀스는 문자 상수에서도 합법이므로 '\n'

ASCII에서 10인 줄 바꿈 문자의 값을 의미합니다. 당신은 주의 깊게 기록해야 합니다

'\N'은 단일 문자이고, 표현식에서는 정수일 뿐이다; 반면에, '\n'은

한 문자만 포함하는 문자열 상수. 문자열 대

캐릭터는 2장에서 더 논의된다.

You want a C example where a string printing (printf) runs off the end of the allocated buffer, and ASan reports a heap-buffer-overflow, stopping when it reaches the null terminator \0 outside the buffer.

Here’s a minimal reproducible example:


```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Allocate space for 4 chars (but no room for the '\0')
    char *buf = malloc(4);
    buf[0] = 'T';
    buf[1] = 'E';
    buf[2] = 'S';
    buf[3] = 'T';  // <- No null terminator inside allocated memory

    // printf will keep reading until it finds a '\0' (past the buffer)
    printf("%s\n", buf);

    free(buf);
    return 0;
}
```


```bash
# clang sanitize(ASan=address / LSan=leak / TSan=thread / MSan=memory / UBSan=undefined)

/usr/bin/clang-20 -O0 -g -fsanitize=address -fno-omit-frame-pointer ./src/main.c

==12345==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000014
READ of size 1 at 0x602000000014 thread T0
    #0 0x7f3c2c in vfprintf ...
    #1 0x7f3c2c in printf ...
    #2 0x4011d6 in main main.c:12
```

- 오류가 나지 않게 수정한 코드

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Allocate space for 5 chars: "TEST" + '\0'
    char *buf = malloc(5);
    if (!buf) {
        perror("malloc failed");
        return 1;
    }

    // Copy string safely
    strcpy(buf, "TEST");

    // Now printf will stop correctly at '\0'
    printf("%s\n", buf);

    free(buf);
    return 0;
}
```

# C Operator Precedence
- The following table lists the precedence and associativity of C operators. Operators are listed top to bottom, in descending precedence.
  - https://en.cppreference.com/w/c/language/operator_precedence.html

- Assignment operators
  - Assignment and compound assignment operators are binary operators that modify the variable to their left using the value to their right.
  - https://en.cppreference.com/w/c/language/operator_assignment.html

# `sizeof` operator
- https://en.cppreference.com/w/c/language/sizeof.html

# 2.7 Type Conversions(casting해도 안전한 패턴(p.42))
- Implicit arithmetic conversions work much as expected. In general, if an operator like + or *
that takes two operands (a binary operator) has operands of different types, the ``lower'' type is
promoted to the ``higher'' type before the operation proceeds. The result is of the integer type.
Section 6 of Appendix A states the conversion rules precisely. If there are no unsigned
operands, however, the following informal set of rules will suffice:
  - • If either operand is `long double`, convert the other to `long double`.
  - • Otherwise, if either operand is `double` , convert the other to `double` .
  - • Otherwise, if either operand is `float`.  convert the other to `float` .
  - • Otherwise, convert `char` and `short` to `int.` .
  - • Then, if either operand is `long`, convert the other to `long`.

# 2.12 Precedence and Order of Evaluation(p48)


|Operators| Associativity|
|-|-|
|() [] -> . |left to right|
|! ~ ++ -- + - * (type) sizeof |right to left|
|* / % |left to right|
|+ - |left to right|
|<< >> |left to right|
|< <= > >= |left to right|
|== != |left to right|
|& |left to right|
|^ |left to right|
|| |left to right|
|&& |left to right|
||| |left to right|
|?: |right to left|
|= += -= *= /= %= &= ^= \|= <<= >>= |right to left|
, |left to right|

# `%zu` 를 알아보자
- align `%zu`
  - https://leeiopd.tistory.com/entry/%EB%94%B0%EB%B0%B0%EC%94%A8-1512-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EC%A4%84%EB%A7%9E%EC%B6%A4-alignof-alignas

# Logical Operators In C (AND, OR, NOT, XOR) With Code Examples
- https://unstop.com/blog/logical-operators-in-c/amp



|Basis | 	Logical<br />  Operators	| Bitwise <br /> Operators | 
|-|-|-|
|Operators	| AND (`&&`),<br />  OR (`||`),<br /> NOT (`!`) |AND (`&`), <br />OR  (`|`),XOR (`^`),<br /> Complement (`^`) | 
