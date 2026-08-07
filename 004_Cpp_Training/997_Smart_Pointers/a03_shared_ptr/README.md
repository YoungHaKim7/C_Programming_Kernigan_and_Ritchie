# Result

```bash

std::shared_ptr Examples
========================

=== Basic shared_ptr usage ===
Resource basic created
Resource basic is doing something with value 42
ptr1 use_count: 1
After copying to ptr2:
ptr1 use_count: 2
ptr2 use_count: 2
Modified value through ptr2: 100
After ptr2 goes out of scope:
ptr1 use_count: 1
After assigning to ptr3:
ptr1 use_count: 2
ptr3 use_count: 2
After resetting ptr3:
ptr1 use_count: 1
Resource basic destroyed

=== Weak pointer usage ===
Resource weak_example created
Initial use_count: 1
After creating weak_ptr, use_count: 1
Successfully locked weak_ptr
Resource weak_example is doing something with value 200
Resource weak_example destroyed
After resetting shared_ptr:
Resource has been destroyed - cannot lock weak_ptr
weak_ptr expired: true

=== Avoiding circular references ===
Node A created
Node B created
Created chain: Node A -> Node B -> nullptr
Node A destroyed
Node B destroyed

=== shared_ptr with containers ===
Resource container1 created
Resource container2 created
Resource container3 created
Resources in container:
  Resource container1 is doing something with value 10
  use_count: 1
  Resource container2 is doing something with value 20
  use_count: 1
  Resource container3 is doing something with value 30
  use_count: 1
After creating additional reference:
resources[0] use_count: 2
weak_ref doesn't affect use_count: 1
Resource container1 destroyed
Resource container2 destroyed
Resource container3 destroyed

=== shared_ptr with threading ===
Resource thread_example created
Creating 5 threads that share the resource
Resource thread_example is doing something with value 999
Resource thread_example is doing something with value 1000
Resource thread_example is doing something with value 1002
Resource thread_example is doing something with value 1005
Resource thread_example is doing something with value 1009
All threads completed. Final value: 1009
Final use_count: 1
Resource thread_example destroyed

=== Custom deleters with shared_ptr ===
Resource custom created
Resource custom is doing something with value 777
use_count with custom deleter: 2
Custom deleter called for custom
Resource custom destroyed

=== Aliasing constructor ===
Resource owner created
owner use_count: 1
Created alias to the value
owner use_count: 2
value_alias use_count: 2
Value through alias: 100
Resource owner destroyed

=== Program completed ===
All resources should be automatically destroyed
```
