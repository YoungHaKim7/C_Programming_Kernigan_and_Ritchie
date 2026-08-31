#include <stdio.h>
#include <string.h>

// Define a structure type
struct Student {
    char name[50];
    int age;
    float height;
};

int main(void) {
    // Create a variable of type struct Student
    struct Student student;

    // Assign values to the members
    strcpy(student.name, "Young");
    student.age = 30;
    student.height = 175.5f;

    // Access and print the members
    printf("Name   : %s\n", student.name);
    printf("Age    : %d\n", student.age);
    printf("Height : %.1f cm\n", student.height);

    return 0;
}
