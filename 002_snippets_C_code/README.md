# Windows에서 c/c++ (VSCode)세팅
- https://miaow-miaow.tistory.com/126

# snippets C
- https://github.com/Harry-Ross/vscode-c-snippets

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

# santinizer Doc
- https://github.com/google/sanitizers
