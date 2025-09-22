# Result

```bash
0 1 1
1 2 -3
2 4 9
3 8 -27
4 16 81
5 32 -243
6 64 729
7 128 -2187
8 256 6561
9 512 -19683
```

- One aspect of C functions may be unfamiliar to programmers who are used to some other languages, particulary Fortran. In C, all function arguments are passed ``by value.'' This means
that the called function is given the values of its arguments in temporary variables rather than the originals. This leads to some different properties than are seen with ``call by reference''
languages like Fortran or with var parameters in Pascal, in which the called routine has access to the original argument, not a local copy.
Call by value is an asset, however, not a liability. It usually leads to more compact programs with fewer extraneous variables, because parameters can be treated as conveniently initialized local variables in the called routine. For example, here is a version of power that makes use of this property.
  - C 함수의 한 측면은 다른 언어, 특히 포트란에 익숙한 프로그래머들에게 생소할 수 있습니다. C에서는 모든 함수 인수가 "값에 의해" 전달됩니다. 이는 다음을 의미합니다
호출된 함수는 원래 변수가 아닌 임시 변수에서 인수의 값이 주어집니다. 이는 '참조 호출'에서 볼 수 있는 것과는 다른 몇 가지 속성으로 이어집니다
포트란과 같은 언어나 파스칼에서 var 매개변수가 있는 언어로, 호출된 루틴은 로컬 복사본이 아닌 원래 인수에 접근할 수 있습니다.
그러나 가치별 호출은 부채가 아닌 자산입니다. 일반적으로 호출된 루틴에서 매개변수를 편리하게 초기화된 로컬 변수로 취급할 수 있기 때문에 외부 변수가 적은 더 간결한 프로그램으로 이어집니다. 예를 들어, 이 속성을 활용하는 파워 버전이 있습니다.


# Ref test(c23)
- https://godbolt.org/
