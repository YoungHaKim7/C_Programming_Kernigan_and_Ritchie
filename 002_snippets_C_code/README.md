# snippets C

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
