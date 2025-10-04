# Result

```bash
Example 1: push 'A' and getch() it back
  Output: A

Example 2: push 'B' and 'C', then read twice
  Output 1: C
  Output 2: B

Example 3: push then overwrite (check LIFO)
  Expected order: Z, Y, X
  Output: X Y Z

Example 4: getch() with no push — type something manually:
a
  You typed: a

Example 5: simulate string input using ungetch
  Reading characters back: olleH

Example 6: push numeric chars '1','2','3'
  Output: 1 2 3

Example 7: push space and punctuation
  Output: ! ?

Example 8: fill buffer and test overflow message
ungetch: too many characters
  (Should print overflow warning once)

Example 9: mix push and typed input
ungetch: too many characters
  You will type one char:
  getch() gives: x, then typed:


Example 10: verify buffer is empty after all reads
  Buffer still has 99 chars ❌
```
