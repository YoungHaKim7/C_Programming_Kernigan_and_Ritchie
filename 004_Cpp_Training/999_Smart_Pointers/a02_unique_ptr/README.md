# Result

```bash
std::unique_ptr Examples
========================

=== Basic unique_ptr usage ===
Resource basic created
Resource basic is doing something with value 42
Value: 42
Name: basic
ptr1 is valid
Resetting ptr1...
Resource reset created
Resource basic destroyed
Resource reset is doing something with value 100
Releasing ownership...
Raw pointer: reset
Resource reset destroyed

=== Move semantics ===
Resource move_src created
ptr1 owns: move_src
After move:
ptr1 owns: nothing
ptr2 owns: move_src
Resource move_src destroyed

=== unique_ptr with containers ===
Resource container1 created
Resource container2 created
Resource container3 created
Resource container1 is doing something with value 10
Resource container2 is doing something with value 20
Resource container3 is doing something with value 30
Extracted resource: container3
Resource container3 destroyed
Resource container1 destroyed
Resource container2 destroyed

=== Custom deleters ===
Resource custom created
Resource custom is doing something with value 999
Custom deleter called for custom
Resource custom destroyed

=== Factory pattern ===
Resource factory created
Resource factory is doing something with value 500
Resource factory destroyed

=== unique_ptr with arrays ===
Resource default created with default constructor
Resource default created with default constructor
Resource default created with default constructor
Array resources created
Resource default is doing something with value 1
Resource default is doing something with value 2
Resource default is doing something with value 3
Resource default destroyed
Resource default destroyed
Resource default destroyed

=== Program completed ===
All resources should be automatically destroyed
```
