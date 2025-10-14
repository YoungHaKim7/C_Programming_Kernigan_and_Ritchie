# Result

```bash
1d array( 1d matrix)
Matrix 1d: 1 2 3 4 5 6

~~~~~~~~~~~~~~~~~~~2d array( 2d matrix)
Matrix (2x3) initialized with indices:
 0  1  2
 3  4  5

Matrix 3x3 (all zeros):
 0  0  0
 0  0  0
 0  0  0

Matrix 2x3 (initializer):
 0  1  2
 3  4  5


~~~~~~~~~~~~~~~~~~~3d array( 3d matrix)
3d matrix sampleMatrix 3D (2x3x2):
Layer 0:
 0  1
 2  3
 4  5

Layer 1:
 6  7
 8  9
10 11

Matrix 3D (5x3x2):
Layer 0:
 0  1
 2  3
 4  5

Layer 1:
 6  7
 8  9
10 11

Layer 2:
12 13
14 15
16 17

Layer 3:
18 19
20 21
22 23

Layer 4:
24 25
26 27
28 29
```


# Changes Made:

- 1. Headers: Replaced #include <stdio.h> with C++ headers:
  - `#include <iostream>` for `std::cout`
  - `#include <vector>` for `std::vector`
  - `#include <format>` for `std::format` (C++26)
  2. `I/O`: Converted all `printf()` calls to `std::cout` with `std::format()` for formatted output
  3. Variable Length Arrays: Replaced VLAs (not supported in C++) with `std::vector<std::vector<int>>:`
    - `int matrix02[rows][cols]` → `std::vector<std::vector<int>> matrix02(rows, std::vector<int>(cols))`
    - `int matrix03[rows02][cols02]` → `std::vector<std::vector<int>> matrix03(rows02, std::vector<int>(cols02, 0))`
  4. Duplicate Variables: Renamed `matrix_3d[2][3][2]` to `matrix_3d_small` to avoid naming conflict
  5. Function Signature: Changed `int main(void)` to `int main()` (C++ style)
