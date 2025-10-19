#!/bin/bash

# Test script for the declaration parser
# Compile and run the program with various inputs

echo "Compiling dcl.c..."
gcc -Wall -Wextra -std=c99 -o dcl dcl.c

if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo ""
    echo "Running tests..."
    echo ""

    # Run the program
    ./dcl

    echo ""
    echo "Testing with manual input..."
    echo ""

    # Test individual cases by creating input files
    echo "int *fp()" | ./dcl
    echo ""
    echo "char (*(*x())[])()" | ./dcl
    echo ""
    echo "void (*signal(int, void (*)(int)))(int)" | ./dcl

else
    echo "Compilation failed!"
    exit 1
fi