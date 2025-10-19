# (목차) Chapter 6 - Structures.

```bash
Chapter 6 - Structures.
  6.1 Basics of Structures.
  6.2 Structures and Functions.
  6.3 Arrays of Structures.
  6.4 Pointers to Structures.
  6.5 Self-referential Structures.
  6.6 Table Lookup.
  6.7 Typedef.
  6.8 Unions.
  6.9 Bit-fields
```

# struct 기본 개념

- A structure is a collection of one or more variables, possibly of different types, grouped together under a single name for convenient handling. (Structures are called ``records'' in some languages, notably Pascal.) Structures help to organize complicated data, particularly in large programs, because they permit a group of related variables to be treated as a unit instead of as separate entities.
- One traditional example of a structure is the payroll record: an employee is described by a set of attributes such as name, address, social security number, salary, etc. Some of these in turn could be structures: a name has several components, as does an address and even a salary. Another example, more typical for C, comes from graphics: a point is a pair of coordinate, a rectangle is a pair of points, and so on.
- The main change made by the ANSI standard is to define structure assignment - structures may be copied and assigned to, passed to functions, and returned by functions. This has been supported by most compilers for many years, but the properties are now precisely defined. Automatic structures and arrays may now also be initialized.

- 구조는 다양한 유형의 하나 이상의 변수가 그룹화된 집합입니다 편리한 취급을 위해 하나의 이름으로 함께 사용합니다. (일부에서는 구조를 '기록'이라고 부릅니다.) 언어, 특히 파스칼.) 구조는 특히 복잡한 데이터를 정리하는 데 도움이 됩니다
- 프로그램은 관련 변수 그룹을 다음과 같은 단위가 아닌 단위로 취급할 수 있도록 허용하기 때문입니다 별도의 엔티티.
- 구조의 전통적인 예 중 하나는 급여 기록입니다: 직원은 집합으로 설명됩니다 이름, 주소, 주민등록번호, 급여 등과 같은 속성에 대해. 이 중 일부는 차례로 구조일 수 있습니다: 이름에는 주소와 급여와 마찬가지로 여러 구성 요소가 있습니다. 또 다른 예로, C에 더 일반적인 것은 그래픽에서 비롯됩니다: 점은 좌표 쌍, 즉 a입니다 직사각형은 점들의 쌍입니다.
- ANSI 표준에 의해 이루어진 주요 변경 사항은 구조 할당을 정의하는 것입니다. 구조는 다음과 같습니다 복사하여 할당하고, 함수에 전달하고, 함수에 의해 반환합니다. 이것은 다음과 같습니다 수년 동안 대부분의 컴파일러가 지원했지만 이제는 속성이 정확하게 정의되었습니다. 자동 구조 및 배열도 이제 초기화할 수 있습니다.
