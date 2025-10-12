# (목차)Chapter 4 - Functions and Program Structure

```
Chapter 4 - Functions and Program Structure.
  4.1 Basics of Functions.
  4.2 Functions Returning Non-integers.
  4.3 External Variables.
  4.4 Scope Rules.
  4.5 Header Files.
  4.6 Static Variables.
  4.7 Register Variables.
  4.8 Block Structure.
  4.9 Initialization.
  4.10 Recursion.
  4.11 The C Preprocessor.
    4.11.1 File Inclusion.
    4.11.2 Macro Substitution.
```
- Functions break large computing tasks into smaller ones, and enable people to build on what
others have done instead of starting over from scratch. Appropriate functions hide details of
operation from parts of the program that don't need to know about them, thus clarifying the
whole, and easing the pain of making changes.
- C has been designed to make functions efficient and easy to use; C programs generally consist
of many small functions rather than a few big ones. A program may reside in one or more
source files. Source files may be compiled separately and loaded together, along with
previously compiled functions from libraries. We will not go into that process here, however,
since the details vary from system to system.
- Function declaration and definition is the area where the ANSI standard has made the most
changes to C. As we saw first in Chapter 1, it is now possible to declare the type of arguments
when a function is declared. The syntax of function declaration also changes, so that
declarations and definitions match. This makes it possible for a compiler to detect many more
errors than it could before. Furthermore, when arguments are properly declared, appropriate
type coercions are performed automatically.

- # 4장 - 기능 및 프로그램 구조
- 함수는 큰 컴퓨팅 작업을 작은 작업으로 나누고 사람들이 무엇을 기반으로 구축할 수 있도록 합니다
다른 사람들은 처음부터 다시 시작하는 대신에 그렇게 했습니다. 적절한 함수는 다음과 같은 세부 사항을 숨깁니다
프로그램의 일부에 대해 알 필요가 없는 부분부터 운영하여 다음을 명확히 합니다
전체적으로 변화를 주는 고통을 덜어줍니다.
- C는 기능을 효율적이고 사용하기 쉽게 설계되었습니다. C 프로그램은 일반적으로 다음과 같이 구성됩니다
몇 가지 큰 함수가 아닌 여러 작은 함수의 경우. 프로그램은 하나 이상의 함수에 존재할 수 있습니다
소스 파일. 소스 파일은 별도로 컴파일하여 함께 로드할 수 있습니다
이전에 라이브러리에서 컴파일된 함수들. 그러나 여기서는 그 과정에 대해 다루지 않겠습니다,
시스템마다 세부 사항이 다르기 때문입니다.
- 함수 선언 및 정의는 ANSI 표준이 가장 많이 활용한 분야입니다
C의 변경 사항. 1장에서 먼저 살펴본 것처럼 이제 인수 유형을 선언할 수 있습니다
함수가 선언될 때. 함수 선언의 구문도 변경되므로 다음과 같이 할 수 있습니다
선언과 정의가 일치합니다. 이를 통해 컴파일러는 더 많은 것을 감지할 수 있습니다
이전보다 더 큰 오류. 또한 인수가 적절하게 선언되면 적절합니다
타입 강제가 자동으로 수행됩니다.

# The question is, which method has better performance? And by how much?
- https://stackoverflow.com/questions/34847662/is-accessing-statically-or-dynamically-allocated-memory-faster

- There are 2 ways of allocating global array in C:

  - 1. statically

```c
char data[65536];
```

  - 2. dynamically

```c
char *data;
…
data = (char*)malloc(65536);  /* or whatever size */
```

As understand it, the first method should be faster.

Because with the second method, to access the array you have to dereference element's address each time it is accessed, like this:

```bash

    read the variable data which contains the pointer to the beginning of the array
    calculate the offset to specific element
    access the element
```

With the first method, the compiler hard-codes the address of the data variable into the code, first step is skipped, so we have:

```bash
    calculate the offset to specific element from fixed address defined at compile time
    access the element of the array
```

Each memory access is equivalent to about 40 CPU clock cycles, so , using dynamic allocation, specially for not frequent reads can have significant performance decrease vs static allocation because the data variable may be purged from the cache by some more frequently accessed variable. On the contrary , the cost of dereferencing statically allocated global variable is 0, because its address is already hard-coded in the code.

질문은, 어떤 방법이 더 나은 성능을 가지고 있느냐는 것입니다. 그리고 얼마나?

이해한 바에 따르면, 첫 번째 방법이 더 빨라야 합니다.

두 번째 방법에서는 배열에 접근할 때마다 요소의 주소를 다음과 같이 참조 해제해야 하기 때문입니다:

    배열의 시작을 가리키는 포인터가 포함된 변수 데이터를 읽습니다
    특정 요소에 대한 오프셋 계산
    요소에 액세스합니다

첫 번째 메서드를 사용하면 컴파일러가 데이터 변수의 주소를 코드에 하드코딩하여 첫 번째 단계를 건너뛸 수 있으므로 다음과 같이 할 수 있습니다:

    컴파일 시 정의된 고정 주소에서 특정 요소로 오프셋을 계산합니다
    배열의 요소에 액세스합니다

각 메모리 액세스는 약 40개의 CPU 클럭 사이클에 해당하므로, 동적 할당, 특히 빈번하지 않은 읽기의 경우 정적 할당에 비해 성능이 크게 저하될 수 있습니다. 이는 데이터 변수가 더 자주 접근하는 변수에 의해 캐시에서 제거될 수 있기 때문입니다. 반대로, 정적으로 할당된 글로벌 변수의 디퍼런스 비용은 0입니다. 왜냐하면 해당 변수의 주소는 이미 코드에 하드코딩되어 있기 때문입니다.


# 🧠 Notes(register 메모리는 접근 할 수 없다.)

- register is only a hint — compilers may or may not place the variable in a CPU register.

- You cannot take the address of a register variable:

```c
register int x = 5;
int *p = &x;  // ❌ Error: cannot take address of register variable

```


- result


```bash
/opt/homebrew/opt/gcc@15/bin/gcc-15 -std=c23 -pedantic -pthread -pedantic-errors -lm -Wall -Wextra -ggdb -Werror -o ./target/a47_register_variables ./src/main.c
./src/main.c: In function 'main':
./src/main.c:33:5: error: address of register variable 'x' requested
   33 |     int *p = &x;  // ❌ Error: cannot take address of register variable
      |     ^~~
./src/main.c:34:5: error: address of register variable 'x' requested
   34 |     printf("register *p = %p", &x);
      |     ^~~~~~
./src/main.c:33:10: error: unused variable 'p' [-Werror=unused-variable]
   33 |     int *p = &x;  // ❌ Error: cannot take address of register variable
      |          ^
cc1: all warnings being treated as errors
error: Recipe `r` failed on line 115 with exit code 1



# static VS const(Rust)


- static ( 장점)
  - 대용량의 게임 맵같은 할당.(덩치 큰거 할당 좋다.)
  - 프로그램이 종료될때까지 메모리 살아있어야하깐.
  - 내가 지정한 메모리 에 박아 넣는다

- const(장점)
  - copy & 복사하기 붙혀넣기
  - 같은메모리 메모리에 실행되게 해서 빠르다.
  - assembly jump가 없다.
  - 왔다리 갔다리갔다.
  - fn마다 주소 다 틀려요
  - 0x4000000 공간이 없이 빠짝 붙혀서  0x4000004 고속도로처럼 쭉가면됨.
    - 단점 컴파일 길어지겠죠.. 복사하고 붙혀넣고 용량이 약간 커진다.

# C++ constexpr(러스트에서는 const fn  -> C++에서 좋은 기능 가져옴.)



# When you would want to use each one:
- https://stackoverflow.com/questions/408670/stack-static-and-heap-in-c

    Statics/globals are useful for memory that you know you will always need and you know that you don't ever want to deallocate. (By the way, embedded environments may be thought of as having only static memory... the stack and heap are part of a known address space shared by a third memory type: the program code. Programs will often do dynamic allocation out of their static memory when they need things like linked lists. But regardless, the static memory itself (the buffer) is not itself "allocated", but rather other objects are allocated out of the memory held by the buffer for this purpose. You can do this in non-embedded as well, and console games will frequently eschew the built in dynamic memory mechanisms in favor of tightly controlling the allocation process by using buffers of preset sizes for all allocations.)

    Stack variables are useful for when you know that as long as the function is in scope (on the stack somewhere), you will want the variables to remain. Stacks are nice for variables that you need for the code where they are located, but which isn't needed outside that code. They are also really nice for when you are accessing a resource, like a file, and want the resource to automatically go away when you leave that code.

    Heap allocations (dynamically allocated memory) is useful when you want to be more flexible than the above. Frequently, a function gets called to respond to an event (the user clicks the "create box" button). The proper response may require allocating a new object (a new Box object) that should stick around long after the function is exited, so it can't be on the stack. But you don't know how many boxes you would want at the start of the program, so it can't be a static.



- It's been said elaborately, just as "the short answer":

    static variable (class)
    lifetime = program runtime (1)
    visibility = determined by access modifiers (private/protected/public)

    static variable (global scope)
    lifetime = program runtime (1)
    visibility = the compilation unit it is instantiated in (2)

    heap variable
    lifetime = defined by you (new to delete)
    visibility = defined by you (whatever you assign the pointer to)

    stack variable
    visibility = from declaration until scope is exited
    lifetime = from declaration until declaring scope is exited


# 공식문서 static, fn, auto , register
- https://en.cppreference.com/w/cpp/language/storage_duration.html
