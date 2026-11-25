# Result

```bash
The largest number is 100
The largest char is y
p3.x = 5, p3.y = c
Success is ok: true
Error is ok: false
Success value: 42
Comparison result: -1
Printed twice: Hello, World! Hello, World!
Comparing 42 and 3.141592653589793
42 is not smaller
Comparing hello and world
hello is smaller
Excerpt: ImportantExcerpt { part: "Call me Ishmael", data: 42 }
Level: 3
Attention please: Important excerpt follows!
Returned part: Call me Ishmael
Part field: Call me Ishmael
Data field: 42
Even numbers: [2, 4, 6, 8, 10]
Squared numbers: [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
Wrapped is some: true
Empty is some: false
Wrapped value: 42
Empty value: 100
Tree preorder traversal: [10, 5, 3, 7, 15, 12, 18]
```


# I've successfully created 10 generic Rust code examples outside the main function. Here's what I've implemented:

  1. Generic Function: largest - finds the largest item in a slice
  2. Generic Struct: Point - coordinates with any types and methods to mix points
  3. Generic Enum: MyResult - a Result-like type for success/error values
  4. Generic Trait: Comparable - defines comparison behavior
  5. Generic Implementation: MyDisplay - adds methods to any Display type
  6. Multiple Type Parameters: compare_and_print - function with multiple generic types
  7. Lifetime + Generics: ImportantExcerpt - struct with lifetime and generic data
  8. Generic Operations: filter and map - functional programming utilities
  9. Generic Wrapper: Wrapper - optional value wrapper
  10. Generic Tree: TreeNode - binary search tree with generic values

- Each example demonstrates different aspects of Rust's generic programming features, including traits, structs, enums, functions, lifetimes, and bounds.
  1. Line 229: Changed MyResult<T, E> to MyResult<i32, &str> to specify concrete types
  2. Line 230: Added explicit type annotation MyResult<i32, &str> to the error variable

  The issue was that generic type parameters T and E can only be used within generic function signatures, struct definitions, or enum definitions.
   In the main function, you need to use concrete types when creating instances. I chose i32 for the success value type and &str for the error
  type based on the values being stored (42 and "Something went wrong" respectively).
