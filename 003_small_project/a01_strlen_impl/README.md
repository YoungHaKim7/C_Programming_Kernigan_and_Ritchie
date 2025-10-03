# Result

```bash
Test 1: ""
  strlen_simple = 0
  strlen_glibc  = 0
  strlen(builtin) = 0
  ✅ Match
--------------------------------------------------
Test 2: "a"
  strlen_simple = 1
  strlen_glibc  = 1
  strlen(builtin) = 1
  ✅ Match
--------------------------------------------------
Test 3: "Hello"
  strlen_simple = 5
  strlen_glibc  = 8
  strlen(builtin) = 5
  ❌ Mismatch!
--------------------------------------------------
Test 4: "This is a test"
  strlen_simple = 14
  strlen_glibc  = 16
  strlen(builtin) = 14
  ❌ Mismatch!
--------------------------------------------------
Test 5: "1234567890"
  strlen_simple = 10
  strlen_glibc  = 10
  strlen(builtin) = 10
  ✅ Match
--------------------------------------------------
Test 6: "Longer string for test!"
  strlen_simple = 23
  strlen_glibc  = 24
  strlen(builtin) = 23
  ❌ Mismatch!
--------------------------------------------------
Test 7: "With
newline"
  strlen_simple = 12
  strlen_glibc  = 16
  strlen(builtin) = 12
  ❌ Mismatch!
--------------------------------------------------
Test 8: "Embedded"
  strlen_simple = 8
  strlen_glibc  = 8
  strlen(builtin) = 8
  ✅ Match
--------------------------------------------------
Test 9: "Spaces   inside"
  strlen_simple = 15
  strlen_glibc  = 16
  strlen(builtin) = 15
  ❌ Mismatch!
--------------------------------------------------
Test 10: "abcdefghijklmnopqrstuvwxyz"
  strlen_simple = 26
  strlen_glibc  = 26
  strlen(builtin) = 26
  ✅ Match
```
