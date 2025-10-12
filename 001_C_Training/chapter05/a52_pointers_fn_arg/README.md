# Result

```bash
Before swap: a = 5, b = 10
After swap: a = 10, b = 5
Before increment: x = 7
After increment: x = 8
Before doubling: y = 8
After doubling: y = 16
Before reset: z = 42
After reset: z = 0
Before square: num = 6
After square: num = 36
Before addition: first = 15, second = 7
After addition: first = 22, second = 7
Before char swap: c1 = A, c2 = Z
After char swap: c1 = Z, c2 = A
Before setting flag: flag = 0
After setting flag: flag = 1
Before absolute: neg_num = -25
After absolute: neg_num = 25
Before max: max_val = 12, compare_val = 18
After max: max_val = 18, compare_val = 18

```
- Fixed! I implemented the missing getch and ungetch functions that were causing the linker errors. These
  functions provide character input buffering:
  - `getch()` returns characters from a buffer if available, otherwise calls getchar()
  - `ungetch()` pushes characters back into the buffer for future reads

- The build now completes successfully without any errors.
