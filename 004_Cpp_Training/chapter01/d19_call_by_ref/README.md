# Result

```bash
Result: 16
After call -> base=2, n=0
```
- https://godbolt.org/

# Call by value VS Call by ref
- call by value
  - copy

- call by ref
  - ref 메모리만 참고



# (Call by Reference)`&`
- 메모리 주소를 참조한다.`&`

```asm

main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-8], 2
        mov     DWORD PTR [rbp-12], 4
        lea     rdx, [rbp-12]
        lea     rax, [rbp-8]
        mov     rsi, rdx
        mov     rdi, rax
        call    power_ref
        mov     DWORD PTR [rbp-4], eax
        mov     eax, DWORD PTR [rbp-4]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        mov     edx, DWORD PTR [rbp-12]
        mov     eax, DWORD PTR [rbp-8]
        mov     esi, eax
        mov     edi, OFFSET FLAT:.LC1
        mov     eax, 0
        call    printf
        mov     eax, 0
        leave
        ret
```

```c
#include <stdio.h>

int power(int *pbase, int *pn);
/* test power function */

// Now takes *pbase and *pn (pointers)
int power_ref(int *pbase, int *pn) {
    int p = 1;
    int base = *pbase;
    int n = *pn;

    for (; n > 0; --n)
        p = p * base;

    // Example side effect: modify *pn
    *pn = 0;  // reset exponent in caller
    return p;
}

int main(void) {
    int base = 2, n = 4;

    int result = power_ref(&base, &n);

    printf("Result: %d\n", result);
    printf("After call -> base=%d, n=%d\n", base, n);

    return 0;
}
```


# call by value

```asm

main:
        push    rbp
        mov     rbp, rsp
        push    rbx
        sub     rsp, 24
        mov     DWORD PTR [rbp-20], 0
        jmp     .L6
```

- `--std=c23`


```c
#include <stdio.h>

int power(int base, int n);
/* test power function */

/* power: raise base to n-th power; n >= 0; version 2 */
int power(int base, int n)
{
    int p;
    p = 1;
    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}

int main()
{
    int i;
    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}
```

