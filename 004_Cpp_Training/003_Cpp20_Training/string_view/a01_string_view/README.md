# Result

```bash
=== C++20 std::string_view Examples ===

1. Basic string_view creation:
   Original string: "Hello, World!"
   String view: "Hello, World!"
   String view size: 13

2. string_view from string literal:
   Literal view: "This is a string literal"
   First word: "This"

3. Substring operations (zero-copy):
   Original: "C++20 string_view is efficient and powerful"
   Word 1 (0,5): "C++20"
   Word 2 (6,10): "string_vie"
   Word 3 (21,9): "efficient"

4. string_view as function parameter:
   Text: "Temporary string", Length: 16
   Text: "Literal", Length: 7
   Text: "Temporary", Length: 9

5. String manipulation operations:
   Original: "  C++20 Programming  "
   Trimmed: "C++20 Programming"
   Contains '20': Yes

6. string_view with STL algorithms:
   Sentence: "The quick brown fox jumps over the lazy dog"
   Word count: 9
   Words containing 'o': "brown" "fox" "over" "dog"

7. string_view comparison operations:
   sv1: "Hello"
   sv2: "Hello"
   sv3: "World"
   sv1 == sv2: true
   sv1 < sv3: true
   sv1.compare(sv3): -15

8. Working with string_view on different string parts:
   CSV data: "John,25,Engineer;Jane,30,Doctor;Bob,35,Teacher"
   Record: "John,25,Engineer"
     Name: "John", Age: "25", Profession: "Engineer"
   Record: "Jane,30,Doctor"
     Name: "Jane", Age: "30", Profession: "Doctor"
   Last record: "Bob,35,Teacher"

9. remove_prefix and remove_suffix operations:
   Full path: "/home/user/documents/file.txt"
   After remove_prefix(1): "home/user/documents/file.txt"
   After remove_suffix(4): "home/user/documents/file"
   Directory: "home/user/documents"
   Filename: "file"

10. Performance comparison (conceptual):
   Original text length: 236 characters
   First sentence: "This is a very large text string that we want to process efficiently"
   Second sentence: "Using std::string_view allows us to create substrings without copying data"
   Found word: "copyin"
   Found word: "efficiently"
   Note: All substrings above are zero-copy views!
```
