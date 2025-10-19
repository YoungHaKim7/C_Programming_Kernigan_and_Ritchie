#include <math.h>
#include <stdio.h>
#include <string.h>

// Define a struct
struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

// Student structure
struct student {
    char name[50];
    int age;
    float gpa;
};

// Book structure
struct book {
    char title[100];
    char author[50];
    int year;
    float price;
};

// Complex number structure
struct complex {
    double real;
    double imag;
};

// Employee structure
struct employee {
    int id;
    char name[50];
    double salary;
    struct date {
        int day;
        int month;
        int year;
    } hire_date;
};

// Circle structure
struct circle {
    struct point center;
    double radius;
};

int main(void)
{
    printf("=== Structure Examples ===\n\n");

    // Example 1: Basic point structure initialization and usage
    printf("1. Basic point structure:\n");
    struct point pt = { 10, 20 };
    printf("Point pt: x=%d, y=%d\n\n", pt.x, pt.y);

    // Example 2: Rectangle using nested structures
    printf("2. Rectangle using nested point structures:\n");
    struct rect screen = { { 0, 0 }, { 320, 200 } };
    printf("Rectangle: top-left(%d,%d), bottom-right(%d,%d)\n", screen.pt1.x,
        screen.pt1.y, screen.pt2.x, screen.pt2.y);
    printf("Rectangle width: %d, height: %d\n\n", screen.pt2.x - screen.pt1.x,
        screen.pt2.y - screen.pt1.y);

    // Example 3: Structure with distance calculation
    printf("3. Distance calculation:\n");
    struct point origin = { 0, 0 };
    struct point p1 = { 3, 4 };
    double dist = sqrt((double)(p1.x - origin.x) * (p1.x - origin.x)
        + (double)(p1.y - origin.y) * (p1.y - origin.y));
    printf("Distance from (%d,%d) to origin (%d,%d): %.2f\n\n", p1.x, p1.y,
        origin.x, origin.y, dist);

    // Example 4: Student structure
    printf("4. Student structure:\n");
    struct student s1 = { "Alice Johnson", 20, 3.85 };
    struct student s2;
    strcpy(s2.name, "Bob Smith");
    s2.age = 22;
    s2.gpa = 3.65;
    printf("Student: %s, Age: %d, GPA: %.2f\n", s1.name, s1.age, s1.gpa);
    printf("Student: %s, Age: %d, GPA: %.2f\n\n", s2.name, s2.age, s2.gpa);

    // Example 5: Book structure
    printf("5. Book structure:\n");
    struct book b1
        = { "The C Programming Language", "Kernighan & Ritchie", 1978, 49.99 };
    printf("Book: \"%s\" by %s (%d), Price: $%.2f\n\n", b1.title, b1.author,
        b1.year, b1.price);

    // Example 6: Complex number operations
    printf("6. Complex number operations:\n");
    struct complex c1 = { 3.0, 4.0 };
    struct complex c2 = { 1.0, 2.0 };
    struct complex sum = { c1.real + c2.real, c1.imag + c2.imag };
    printf("(%g + %gi) + (%g + %gi) = (%g + %gi)\n\n", c1.real, c1.imag,
        c2.real, c2.imag, sum.real, sum.imag);

    // Example 7: Employee with nested date structure
    printf("7. Employee with nested date:\n");
    struct employee emp = { 1001, "John Doe", 75000.0, { 15, 6, 2023 } };
    printf("Employee ID: %d, Name: %s, Salary: $%.2f\n", emp.id, emp.name,
        emp.salary);
    printf("Hire date: %d/%d/%d\n\n", emp.hire_date.day, emp.hire_date.month,
        emp.hire_date.year);

    // Example 8: Circle structure
    printf("8. Circle structure:\n");
    struct circle c = { { 5, 5 }, 3.0 };
    printf("Circle center: (%d,%d), radius: %.1f\n", c.center.x, c.center.y,
        c.radius);
    printf("Circle area: %.2f\n\n", 3.14159 * c.radius * c.radius);

    // Example 9: Array of structures
    printf("9. Array of points:\n");
    struct point points[3] = { { 1, 1 }, { 2, 4 }, { 3, 9 } };
    for (int i = 0; i < 3; i++) {
        printf("Point %d: (%d,%d)\n", i + 1, points[i].x, points[i].y);
    }
    printf("\n");

    // Example 10: Pointer to structure
    printf("10. Pointer to structure:\n");
    struct point p = { 100, 200 };
    struct point* pp = &p;
    printf("Point via structure: (%d,%d)\n", p.x, p.y);
    printf("Point via pointer: (%d,%d)\n", pp->x, pp->y);
    printf("Modifying via pointer...\n");
    pp->x = 150;
    pp->y = 250;
    printf("Modified point: (%d,%d)\n\n", p.x, p.y);

    printf("=== All examples completed successfully! ===\n");

    return 0;
}
