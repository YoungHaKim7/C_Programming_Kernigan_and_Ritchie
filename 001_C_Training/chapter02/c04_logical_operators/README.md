# `!`  bool로 판단함.

# Result

```bash
Initial values:
a = 3 (0000 0000 0000 0011 )
b = 10 (0000 0000 0000 1010 )

!a      → 0 (0000 0000 0000 0000 )
~a      → -4 (1111 1111 1111 1100 )
a && b  → 1 (0000 0000 0000 0001 )
a || b  → 1 (0000 0000 0000 0001 )
```


# `!` In the C programming language, the exclamation mark !
- represents the logical NOT operator. It is a unary operator, meaning it operates on a single operand.
- Purpose:
- The logical NOT operator inverts the truth value of its operand. In C, a non-zero value is considered "true," and a zero value is considered "false."
- How it works:
  - If the operand evaluates to "true" (any non-zero value), applying ! to it results in "false" (0).
  - If the operand evaluates to "false" (0), applying ! to it results in "true" (1).

- C 프로그래밍 언어에서 느낌표!는 논리적 NOT 연산자를 나타냅니다. 이 연산자는 단항 연산자로, 단일 피연산자에서 작동합니다.
- 목적:
- 논리적 NOT 연산자는 피연산자의 진리 값을 반전시킵니다. C에서 0이 아닌 값은 "참"으로 간주되고, 0이 아닌 값은 "거짓"으로 간주됩니다
- 작동 방식:
  - 피연산자가 "참"(영이 아닌 값)으로 평가하면, "!"을 적용하면 "거짓" (0)이 됩니다.
  - 피연산자가 "거짓" (0)으로 평가되면, "!"을 적용하면 "참" (1)이 됩니다.
