# Result

```bash
=== Chapter 5.5: Character Pointers and Functions ===

1. String Constants and Character Pointers:
   Pointer assignment: pmessage = "now is the time"
   printf with string constant: hello, world

2. Array vs Pointer Declaration:
   amessage[]: "now is the time"
  Address: 0x16dc4a4a0
  Length: 15
  Characters: 'n'(0x6e) 'o'(0x6f) 'w'(0x77) ' '(0x20) 'i'(0x69) 's'(0x73) ' '(0x20) 't'(0x74) 'h'(0x68) 'e'(0x65) ' '(0x20) 't'(0x74) 'i'(0x69) 'm'(0x6d) 'e'(0x65) '\0'(0x00)

   *pmessage2: "now is the time"
  Address: 0x1021b5400
  Length: 15
  Characters: 'n'(0x6e) 'o'(0x6f) 'w'(0x77) ' '(0x20) 'i'(0x69) 's'(0x73) ' '(0x20) 't'(0x74) 'h'(0x68) 'e'(0x65) ' '(0x20) 't'(0x74) 'i'(0x69) 'm'(0x6d) 'e'(0x65) '\0'(0x00)

3. Modifying Array vs Pointer:
   Modified amessage: "Now is the time"
   Reassigned pmessage2: "new string"

4. Testing strcpy Functions:
   strcpy_array_version: "Hello, C Programming!"
   strcpy_pointer_version1: "Hello, C Programming!"
   strcpy_pointer_version2: "Hello, C Programming!"
   strcpy_pointer_version3: "Hello, C Programming!"

5. Testing strcmp Functions:
   Comparing "apple" and "banana":
     strcmp_array_version: -1
     strcmp_pointer_version: -1
   Comparing "apple" and "apple":
     strcmp_array_version: 0
     strcmp_pointer_version: 0
   Comparing "banana" and "apple":
     strcmp_array_version: 1
     strcmp_pointer_version: 1

6. Multiple String Constants:
   messages[0]: "First message" (at 0x1021b58c8)
   messages[1]: "Second message" (at 0x1021b58d8)
   messages[2]: "Third message" (at 0x1021b58e8)
   messages[3]: "Last message" (at 0x1021b58f8)

7. String Manipulation with Pointers:
   Original: "Pointers are powerful"
   Character by character: Pointers are powerful

8. Manual String Length Calculation:
   String: "Calculate my length"
   Manual length: 19
   strlen() result: 19

9. String Concatenation:
   Result: "Hello, World!"

10. Standard Library vs Custom Functions:
    Standard strcpy: "Testing comparison"
    Custom strcpy: "Testing comparison"
    strcmp results: 0 (standard) vs 0 (custom)
```
