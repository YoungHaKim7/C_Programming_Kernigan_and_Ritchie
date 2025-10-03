# Chapter 4 - Functions and Program Structure
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
