# Result

```bash
=== Section 6.2: Structures and Functions Examples ===

1. Using makepoint: screen.pt1=(0,0), pt2=(10,5)
2. Middle point using makepoint: (5,2)
3. Adding points (3,4) + (5,6) = (8,10)
4. Point testing:
   Point (5,2) in rect? YES
   Point (10,5) in rect? NO
   Point (11,3) in rect? NO
5. Before canonrect: pt1=(10,8), pt2=(2,3)
   After canonrect: pt1=(2,3), pt2=(10,8)
6. Using -> operator: origin is (0,0)
   Equivalent using (*pp).x: (0,0)
7. Rectangle pointer access:
   r.pt1.x = 1, rp->pt1.x = 1
   (r.pt1).x = 1, (rp->pt1).x = 1
8. Operator precedence:
   ++p->len: 6 (was 5)
   p->len: 6
9. String operations with structures:
   *p->str = W
   After *p->str++: str now points to 'World'
10. Structure operations:
    rect1: (0,0) to (10,10), area = 100
    rect2: (5,5) to (10,10), area = 25
11. Function calls with structures:
    Passing screen to area(): 50
    Returning structure from makepoint(7,9): (7,9)
12. Polygon center calculation: (2,1)

=== All examples completed successfully! ===
```

# `undefined` 해결-그지 같은 undefined behavior

```c
       128 -      printf("   ++p->len: %d (was %d)\n", ++(p->len), p->len - 1);
       128 +      int original_len = p->len;
       129 +      printf("   ++p->len: %d (was %d)\n", ++(p->len), original_len);
       130        printf("   p->len: %d\n", p->len);
       131
```

- The fix involved storing the original value of `p->len` in a separate variable before incrementing it, which eliminates the undefined behavior that occurred when both modifying and accessing the same variable in the same function call expression.
  - 수정은 `p->len`의 원래 값을 증가시키기 전에 별도의 변수에 저장하는 것을 포함했습니다. 이는 동일한 함수 호출 표현식에서 동일한 변수를 수정하거나 접근할 때 발생하는 정의되지 않은 동작을 제거합니다.
  

# Test

1. Using makepoint to initialize rectangles dynamically
2. Computing center points using makepoint
3. Adding points with addpoints
4. Testing point inclusion with ptinrect
5. Normalizing rectangles with canonrect
6. Structure pointer access using -> vs (*pp).
7. Rectangle pointer operations demonstrating equivalent access methods
8. Operator precedence examples with ++p->len
9. Complex pointer operations with strings in structures
10. Structure copying and assignment
11. Function calls with structures as parameters and return values
12. Complex calculations using multiple structure operations

- Testing Infrastructure:
  - Automated test suite (test_structures.c) with assertions to verify all functionality
  - Makefile for easy compilation and testing
  - All tests pass successfully!

- The program perfectly demonstrates the concepts from Section 6.2 and provides a solid foundation for understanding how structures work with functions in C. You can run the examples with make run and run the tests with make test.

1. 메이크포인트를 사용하여 직사각형을 동적으로 초기화하기
2. 메이크포인트를 사용하여 중심점 계산하기
3. 덧셈으로 포인트 추가하기
4. ptinrect를 사용한 테스트 포인트 포함
5. 캐논렉트로 직사각형 정규화하기
6. -> vs (*pp)를 사용한 구조 포인터 접근.
7. 동등한 접근 방법을 보여주는 직사각형 포인터 작업
8. ++p->len을 사용한 연산자 우선순위 예제
9. 구조물 내 문자열을 사용한 복잡한 포인터 연산
10. 구조 복사 및 할당
11. 구조를 매개변수로 하는 함수 호출과 반환 값
12. 여러 구조 작업을 사용한 복잡한 계산

- 테스트 인프라:
  - 모든 기능을 검증하기 위한 자동화된 테스트 스위트(test_structures.c)
  - 쉬운 컴파일 및 테스트를 위한 파일 만들기
  - 모든 테스트가 성공적으로 통과되었습니다!

- 이 프로그램은 섹션 6.2의 개념을 완벽하게 보여주며 구조가 C의 함수와 어떻게 작동하는지 이해하는 데 견고한 기초를 제공합니다. 예제를 make run으로 실행하고 make test로 테스트를 실행할 수 있습니다.
