#include <iostream>
#include <vector>
#include <string>
#include <memory>

class MyClass {
private:
    std::string name;
    int* data;

public:
    MyClass(const std::string& n, int size) : name(n) {
        std::cout << "Constructor called for " << name << std::endl;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = i * 10;
        }
    }

    ~MyClass() {
        std::cout << "Destructor called for " << name << std::endl;
        delete[] data;
    }

    MyClass(const MyClass& other) : name(other.name + "_copy") {
        std::cout << "Copy constructor called for " << other.name << std::endl;
        int size = 5; // Assuming size 5 for simplicity
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    MyClass& operator=(const MyClass& other) {
        std::cout << "Assignment operator called for " << other.name << std::endl;
        if (this != &other) {
            delete[] data;
            name = other.name + "_assigned";
            int size = 5;
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    MyClass(MyClass&& other) noexcept : name(std::move(other.name)), data(other.data) {
        std::cout << "Move constructor called for " << name << std::endl;
        other.data = nullptr;
    }

    MyClass& operator=(MyClass&& other) noexcept {
        std::cout << "Move assignment called for " << other.name << std::endl;
        if (this != &other) {
            delete[] data;
            name = std::move(other.name);
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    void display() const {
        std::cout << "MyClass " << name << ": ";
        for (int i = 0; i < 5; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

void demonstrateVectorMemoryManagement() {
    std::cout << "=== std::vector Dynamic Memory Management Demo ===" << std::endl;
    std::cout << std::endl;

    // 1. Basic vector creation and automatic memory management
    std::cout << "1. Creating a vector of integers:" << std::endl;
    {
        std::vector<int> numbers;
        std::cout << "Initial capacity: " << numbers.capacity() << std::endl;

        // Add elements - vector automatically manages memory
        for (int i = 0; i < 10; ++i) {
            numbers.push_back(i * 100);
            std::cout << "Added " << i * 100 << ", size: " << numbers.size()
                      << ", capacity: " << numbers.capacity() << std::endl;
        }
    }
    std::cout << "Vector 'numbers' automatically destroyed and memory freed" << std::endl;
    std::cout << std::endl;

    // 2. Vector with custom objects
    std::cout << "2. Vector with custom objects:" << std::endl;
    {
        std::vector<MyClass> objects;
        std::cout << "Creating objects and adding to vector..." << std::endl;

        // Reserve capacity to avoid multiple reallocations
        objects.reserve(3);
        std::cout << "Reserved capacity: " << objects.capacity() << std::endl;

        // Add objects - vector manages their lifetime
        objects.emplace_back("Object1", 5);
        objects.emplace_back("Object2", 5);
        objects.emplace_back("Object3", 5);

        std::cout << "\nDisplaying objects:" << std::endl;
        for (const auto& obj : objects) {
            obj.display();
        }
    }
    std::cout << "Vector 'objects' automatically destroyed, all MyClass destructors called" << std::endl;
    std::cout << std::endl;

    // 3. Vector of pointers (manual memory management needed)
    std::cout << "3. Vector of raw pointers (requires manual cleanup):" << std::endl;
    {
        std::vector<MyClass*> pointerObjects;

        // Create objects on heap
        for (int i = 1; i <= 3; ++i) {
            pointerObjects.push_back(new MyClass("PtrObject" + std::to_string(i), 5));
        }

        std::cout << "Displaying pointer objects:" << std::endl;
        for (const auto* ptr : pointerObjects) {
            ptr->display();
        }

        // Must manually delete each object
        std::cout << "Manually deleting objects..." << std::endl;
        for (auto* ptr : pointerObjects) {
            delete ptr;
        }
    }
    std::cout << "Vector 'pointerObjects' destroyed, but we manually deleted objects" << std::endl;
    std::cout << std::endl;

    // 4. Vector of smart pointers (automatic memory management)
    std::cout << "4. Vector of smart pointers (recommended approach):" << std::endl;
    {
        std::vector<std::unique_ptr<MyClass>> smartObjects;

        // Create unique_ptr objects
        for (int i = 1; i <= 3; ++i) {
            smartObjects.push_back(std::make_unique<MyClass>("SmartObject" + std::to_string(i), 5));
        }

        std::cout << "Displaying smart pointer objects:" << std::endl;
        for (const auto& ptr : smartObjects) {
            ptr->display();
        }
    }
    std::cout << "Vector 'smartObjects' destroyed, unique_ptr automatically deletes objects" << std::endl;
    std::cout << std::endl;

    // 5. Vector resizing and reallocation
    std::cout << "5. Vector resizing and reallocation:" << std::endl;
    {
        std::vector<std::string> words;
        words.push_back("Hello");
        words.push_back("World");
        words.push_back("C++");

        std::cout << "Initial vector:" << std::endl;
        for (const auto& word : words) {
            std::cout << word << " ";
        }
        std::cout << "\nSize: " << words.size() << ", Capacity: " << words.capacity() << std::endl;

        // Resize larger - adds default-constructed elements
        words.resize(6, "New");
        std::cout << "\nAfter resize(6, \"New\"):" << std::endl;
        for (const auto& word : words) {
            std::cout << word << " ";
        }
        std::cout << "\nSize: " << words.size() << ", Capacity: " << words.capacity() << std::endl;

        // Resize smaller - removes elements
        words.resize(2);
        std::cout << "\nAfter resize(2):" << std::endl;
        for (const auto& word : words) {
            std::cout << word << " ";
        }
        std::cout << "\nSize: " << words.size() << ", Capacity: " << words.capacity() << std::endl;
    }
    std::cout << "Vector 'words' destroyed, all string objects automatically cleaned up" << std::endl;
    std::cout << std::endl;
}

int main() {
    demonstrateVectorMemoryManagement();
    return 0;
}
