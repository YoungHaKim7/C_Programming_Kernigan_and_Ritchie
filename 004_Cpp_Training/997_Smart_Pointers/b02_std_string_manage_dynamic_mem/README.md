# Result

```bash

=== std::string Dynamic Memory Management Demo ===

1. Default constructed string:
  Content: ""
  Size: 0 characters
  Capacity: 15 characters
  Data pointer: 0x16b25a190
  Empty: Yes

2. Small string (likely SSO):
  Content: "Hello"
  Size: 5 characters
  Capacity: 15 characters
  Data pointer: 0x16b25a170
  Empty: No

3. Large string (heap allocated):
  Content: "This is a longer string that will definitely exceed the small string optimization threshold and require heap allocation for storage."
  Size: 132 characters
  Capacity: 132 characters
  Data pointer: 0x105822120
  Empty: No

4. String with reserved capacity:
  Content: ""
  Size: 0 characters
  Capacity: 100 characters
  Data pointer: 0x105822040
  Empty: Yes

5a. Initial growing string:
  Content: "Starting text"
  Size: 13 characters
  Capacity: 15 characters
  Data pointer: 0x16b25a110
  Empty: No

5b. After first append:
  Content: "Starting text - Appending more text to observe reallocation behavior"
  Size: 68 characters
  Capacity: 68 characters
  Data pointer: 0x1058221c0
  Empty: No

5c. After second append:
  Content: "Starting text - Appending more text to observe reallocation behavior - Even more text to force capacity increase and memory reallocation"
  Size: 136 characters
  Capacity: 136 characters
  Data pointer: 0x105823340
  Empty: No

6a. Source string before move:
  Content: "This string will be moved to avoid copying"
  Size: 42 characters
  Capacity: 42 characters
  Data pointer: 0x1058220b0
  Empty: No

6b. Destination string after move:
  Content: "This string will be moved to avoid copying"
  Size: 42 characters
  Capacity: 42 characters
  Data pointer: 0x1058220b0
  Empty: No

6c. Source string after move (should be empty):
  Content: ""
  Size: 0 characters
  Capacity: 15 characters
  Data pointer: 0x16b25a0f0
  Empty: Yes

Original data pointer vs moved pointer same? Yes

7a. String with over-allocation:
  Content: "Small content"
  Size: 13 characters
  Capacity: 1000 characters
  Data pointer: 0x1058233e0
  Empty: No

7b. After shrink_to_fit():
  Content: "Small content"
  Size: 13 characters
  Capacity: 15 characters
  Data pointer: 0x16b25a0b0
  Empty: No

8. Vector of strings growth:
  Vector size: 1, Capacity: 1
  Latest string added:
  Content: "String 0 with some additional content to make it longer"
  Size: 55 characters
  Capacity: 55 characters
  Data pointer: 0x1058221c0
  Empty: No

  Vector size: 2, Capacity: 2
  Latest string added:
  Content: "String 1 with some additional content to make it longer"
  Size: 55 characters
  Capacity: 55 characters
  Data pointer: 0x105822200
  Empty: No

  Vector size: 3, Capacity: 4
  Latest string added:
  Content: "String 2 with some additional content to make it longer"
  Size: 55 characters
  Capacity: 55 characters
  Data pointer: 0x105822280
  Empty: No

  Vector size: 4, Capacity: 4
  Latest string added:
  Content: "String 3 with some additional content to make it longer"
  Size: 55 characters
  Capacity: 55 characters
  Data pointer: 0x105822240
  Empty: No

  Vector size: 5, Capacity: 8
  Latest string added:
  Content: "String 4 with some additional content to make it longer"
  Size: 55 characters
  Capacity: 55 characters
  Data pointer: 0x105823460
  Empty: No

9. String managed by unique_ptr:
  Content: "Smart pointer managed string"
  Size: 28 characters
  Capacity: 28 characters
  Data pointer: 0x1058233e0
  Empty: No

=== Memory Management Summary ===
• std::string automatically manages dynamic memory
• Small String Optimization (SSO) avoids heap allocation for small strings
• Capacity grows exponentially to minimize reallocations
• Move semantics transfer ownership without copying data
• shrink_to_fit() can release excess allocated memory
• Works seamlessly with smart pointers for additional safety
```
