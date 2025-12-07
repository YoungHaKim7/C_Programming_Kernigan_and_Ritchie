# Windows에서 c/c++ (VSCode)세팅
- https://miaow-miaow.tistory.com/126

# snippets C
- https://github.com/Harry-Ross/vscode-c-snippets
- https://github.com/one-harsh/vscode-cpp-snippets

- array print패턴
  - [c01 test c code 참고](./c01_test_c_code)

```c
void print_array(const char *msg, int v[], int n) {
    printf("%s", msg);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
```

# sanitizers Doc(Google에서 만듬)
- https://github.com/google/sanitizers


# (251206)Increasing code performance with LTO | Keifer
- https://youtu.be/fPGodf5hNoo?si=yXmOUFj54_RxaxCm

- 추가함.

```cmake
# LTO
set_property(TARGET ${ProjectId} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
```
