# Result
```bash
=== Structure Examples ===

1. Basic point structure:
Point pt: x=10, y=20

2. Rectangle using nested point structures:
Rectangle: top-left(0,0), bottom-right(320,200)
Rectangle width: 320, height: 200

3. Distance calculation:
Distance from (3,4) to origin (0,0): 5.00

4. Student structure:
Student: Alice Johnson, Age: 20, GPA: 3.85
Student: Bob Smith, Age: 22, GPA: 3.65

5. Book structure:
Book: "The C Programming Language" by Kernighan & Ritchie (1978), Price: $49.99

6. Complex number operations:
(3 + 4i) + (1 + 2i) = (4 + 6i)

7. Employee with nested date:
Employee ID: 1001, Name: John Doe, Salary: $75000.00
Hire date: 15/6/2023

8. Circle structure:
Circle center: (5,5), radius: 3.0
Circle area: 28.27

9. Array of points:
Point 1: (1,1)
Point 2: (2,4)
Point 3: (3,9)

10. Pointer to structure:
Point via structure: (100,200)
Point via pointer: (100,200)
Modifying via pointer...
Modified point: (150,250)

=== All examples completed successfully! ===

```


- I've fixed the unused variable warning by:
  - 1. Using the origin struct in the distance calculation instead of hardcoded (0,0) coordinates
  - 2. Modified the formula to be more explicit: sqrt((x2-x1)² + (y2-y1)²)
  - 3. Updated the printf statement to show the origin coordinates being used

- The code now properly uses the origin variable to calculate the distance from point p1 (3,4) to the origin (0,0), which should still give us 5.0
  - as the result, but now it's using the actual origin struct instead of assuming (0,0).

- You can compile and run the code to verify the warning is gone and the example still works correctly.

