#include <print>
#include <vector>
#include <stdexcept>

// Leak Example 1: Early return from function
void processData()
{
    int* data = new int[1000];
    bool errorCondition = true;  // Declare the variable

    if (errorCondition) {
        return; // LEAK! Forgot delete[]
    }

    delete[] data;
}

// Leak Example 2: Exception thrown before delete
void riskyOperation()
{
    int* buffer = new int[500];

    // Simulate an exception that could occur
    if (true) { // Always throw for demo purposes
        throw std::runtime_error("Something went wrong"); // LEAK! Exception skips delete
    }

    delete[] buffer; // Never reached
}

// Leak Example 3: Reassigning pointer without deleting previous memory
void pointerReassignment()
{
    int* ptr = new int(42);
    ptr = new int(100); // LEAK! Lost access to first allocated memory

    delete ptr; // Only deletes the second allocation
}

// Leak Example 4: Function returning allocated memory without proper ownership transfer
int* createLeakyData()
{
    return new int[200]; // Caller might forget to delete[]
}

void useLeakyData()
{
    int* data = createLeakyData();
    // Do some work with data...
    // LEAK! Forgot delete[] before function ends
}

// Leak Example 5: Nested allocations with early exit
void nestedLeaks()
{
    int* level1 = new int[100];
    int* level2 = new int[200];
    int* level3 = new int[300];

    bool problem = true;
    if (problem) {
        delete[] level1; // Only clean first level
        return; // LEAK! level2 and level3 not freed
    }

    delete[] level1;
    delete[] level2;
    delete[] level3;
}

// Leak Example 6: Circular reference with raw pointers
struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

void createCircularReference()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);

    node1->next = node2;
    node2->next = node1; // Creates circular reference

    // LEAK! Both nodes reference each other, neither can be properly deleted
    // In this simple case we could break the cycle, but in complex scenarios
    // this becomes a serious memory management issue
}

// Leak Example 7: Memory leak in loop
void leakInLoop()
{
    for (int i = 0; i < 100; ++i) {
        int* temp = new int[i]; // Allocate memory in each iteration
        // LEAK! No delete[] in loop - 100 allocations leaked
    }
}

// Leak Example 8: Forgotten array deletion
void wrongDelete()
{
    int* array = new int[50];
    delete array; // WRONG! Should be delete[] for arrays
    // This is undefined behavior and may leak memory
}

int main(void)
{
    std::print("=== Raw Pointer Memory Leak Examples ===\n");

    try {
        processData();
        std::print("1. processData() completed (with leak)\n");
    } catch (...) {
        std::print("1. processData() threw exception\n");
    }

    try {
        riskyOperation();
    } catch (const std::exception& e) {
        std::print("2. riskyOperation() threw: {}\n", e.what());
        std::print("   Memory was leaked due to exception\n");
    }

    pointerReassignment();
    std::print("3. pointerReassignment() completed (with leak)\n");

    useLeakyData();
    std::print("4. useLeakyData() completed (with leak)\n");

    nestedLeaks();
    std::print("5. nestedLeaks() completed (with leak)\n");

    createCircularReference();
    std::print("6. createCircularReference() completed (with leak)\n");

    leakInLoop();
    std::print("7. leakInLoop() completed (with 100 leaks)\n");

    wrongDelete();
    std::print("8. wrongDelete() completed (undefined behavior)\n");

    std::print("\nAll examples demonstrate different types of memory leaks.\n");
    std::print("Use tools like Valgrind, AddressSanitizer, or LeakSanitizer to detect these.\n");

    return 0;
}
