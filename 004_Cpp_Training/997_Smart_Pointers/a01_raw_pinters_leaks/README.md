# Result

```bash
=== Raw Pointer Memory Leak Examples ===
1. processData() completed (with leak)
2. riskyOperation() threw: Something went wrong
   Memory was leaked due to exception
3. pointerReassignment() completed (with leak)
4. useLeakyData() completed (with leak)
5. nestedLeaks() completed (with leak)
6. createCircularReference() completed (with leak)
7. leakInLoop() completed (with 100 leaks)
8. wrongDelete() completed (undefined behavior)

All examples demonstrate different types of memory leaks.
Use tools like Valgrind, AddressSanitizer, or LeakSanitizer to detect these.
```
