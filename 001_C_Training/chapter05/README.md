# (목차) Chapter 5 - Pointers and Arrays.

```
Chapter 5 - Pointers and Arrays.
  5.1 Pointers and Addresses.
  5.2 Pointers and Function Arguments.
  5.3 Pointers and Arrays.
  5.4 Address Arithmetic.
  5.5 Character Pointers and Functions.
  5.6 Pointer Arrays; Pointers to Pointers.
  5.7 Multi-dimensional Arrays.
  5.8 Initialization of Pointer Arrays.
  5.9 Pointers vs. Multi-dimensional Arrays.
  5.10 Command-line Arguments.
  5.11 Pointers to Functions.
  5.12 Complicated Declarations.
```

# 지옥의 포인터 ㅋ(A Pointer)
- A pointer is a variable that contains the address of a variable. Pointers are much used in C, partly because they are sometimes the only way to express a computation, and partly because
they usually lead to more compact and efficient code than can be obtained in other ways.
Pointers and arrays are closely related; this chapter also explores this relationship and shows how to exploit it.
Pointers have been lumped with the goto statement as a marvelous way to create impossible-to-understand programs. This is certainly true when they are used carelessly, and it is easy to
create pointers that point somewhere unexpected. With discipline, however, pointers can also be used to achieve clarity and simplicity. This is the aspect that we will try to illustrate.
The main change in ANSI C is to make explicit the rules about how pointers can be manipulated, in effect mandating what good programmers already practice and good compilers
already enforce. In addition, the type void * (pointer to void) replaces char * as the proper type for a generic pointer.
  - 포인터는 변수의 주소를 포함하는 변수입니다. 포인터는 C에서 많이 사용되는데, 부분적으로는 계산을 표현하는 유일한 방법인 경우도 있고 부분적으로는 다음과 같은 이유로 포인터가 사용되기도 합니다
그들은 보통 다른 방법으로 얻을 수 있는 것보다 더 간결하고 효율적인 코드로 이어집니다.
  - 포인터와 배열은 밀접하게 관련되어 있으며, 이 장에서는 이러한 관계를 탐구하고 이를 활용하는 방법도 보여줍니다.
포인터는 이해하기 어려운 프로그램을 만드는 놀라운 방법으로 고토 문과 함께 묶여 있습니다. 이는 포인터를 부주의하게 사용할 때 확실히 사실이며 쉽게 이해할 수 있습니다
예상치 못한 곳을 가리키는 포인터를 만듭니다. 그러나 훈육을 통해 포인터는 명확성과 단순성을 달성하는 데에도 사용할 수 있습니다. 이것이 바로 우리가 설명하려고 하는 측면입니다.
ANSI C의 주요 변경 사항은 포인터를 조작하는 방법에 대한 규칙을 명시적으로 명시하는 것으로, 실제로 좋은 프로그래머와 좋은 컴파일러가 이미 연습하는 것을 의무화하는 것입니다
이미 시행 중입니다. 또한, void * (point to void) 타입이 일반 포인터의 적절한 타입으로 char *를 대체합니다.
