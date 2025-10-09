# Result

```bash

=== std::vector Dynamic Memory Management Demo ===

1. Creating a vector of integers:
Initial capacity: 0
Added 0, size: 1, capacity: 1
Added 100, size: 2, capacity: 2
Added 200, size: 3, capacity: 4
Added 300, size: 4, capacity: 4
Added 400, size: 5, capacity: 8
Added 500, size: 6, capacity: 8
Added 600, size: 7, capacity: 8
Added 700, size: 8, capacity: 8
Added 800, size: 9, capacity: 16
Added 900, size: 10, capacity: 16
Vector 'numbers' automatically destroyed and memory freed

2. Vector with custom objects:
Creating objects and adding to vector...
Reserved capacity: 3
Constructor called for Object1
Constructor called for Object2
Constructor called for Object3

Displaying objects:
MyClass Object1: 0 10 20 30 40
MyClass Object2: 0 10 20 30 40
MyClass Object3: 0 10 20 30 40
Destructor called for Object1
Destructor called for Object2
Destructor called for Object3
Vector 'objects' automatically destroyed, all MyClass destructors called

3. Vector of raw pointers (requires manual cleanup):
Constructor called for PtrObject1
Constructor called for PtrObject2
Constructor called for PtrObject3
Displaying pointer objects:
MyClass PtrObject1: 0 10 20 30 40
MyClass PtrObject2: 0 10 20 30 40
MyClass PtrObject3: 0 10 20 30 40
Manually deleting objects...
Destructor called for PtrObject1
Destructor called for PtrObject2
Destructor called for PtrObject3
Vector 'pointerObjects' destroyed, but we manually deleted objects

4. Vector of smart pointers (recommended approach):
Constructor called for SmartObject1
Constructor called for SmartObject2
Constructor called for SmartObject3
Displaying smart pointer objects:
MyClass SmartObject1: 0 10 20 30 40
MyClass SmartObject2: 0 10 20 30 40
MyClass SmartObject3: 0 10 20 30 40
Destructor called for SmartObject1
Destructor called for SmartObject2
Destructor called for SmartObject3
Vector 'smartObjects' destroyed, unique_ptr automatically deletes objects

5. Vector resizing and reallocation:
Initial vector:
Hello World C++
Size: 3, Capacity: 4

After resize(6, "New"):
Hello World C++ New New New
Size: 6, Capacity: 6

After resize(2):
Hello World
Size: 2, Capacity: 6
Vector 'words' destroyed, all string objects automatically cleaned up
```
