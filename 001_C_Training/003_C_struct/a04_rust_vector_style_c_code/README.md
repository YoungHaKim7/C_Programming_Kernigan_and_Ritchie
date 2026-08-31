# Result

```bash
--- Pushing to Stack ---
Value: 10 | Address: 0x55afd739a010
Value: 20 | Address: 0x55afd739a014
Value: 30 | Address: 0x55afd739a018

--- Popping from Stack ---
Popped 30 <- Memory Address: 0x55afd739a018
Returned value: 30
Popped 20 <- Memory Address: 0x55afd739a014
Returned value: 20
```

# C언어에는 러스트 벡터가 없어서 비슷한게 흉내낸 코드

- 이런 패턴이 많다.
  - `malloc(sizeof(int) * capacity);`

```c
// Similar to Vec::with_capacity(capacity)
Stack stack_new(size_t capacity) {
    Stack stack;

    stack.data = malloc(sizeof(int) * capacity);

    if (stack.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    stack.len = 0;
    stack.capacity = capacity;

    return stack;
}
```
