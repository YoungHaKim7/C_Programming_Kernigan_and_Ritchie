#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Resource {
private:
    std::string name;
    int value;

public:
    Resource() : name("default"), value(0) {
        std::cout << "Resource " << name << " created with default constructor\n";
    }

    Resource(const std::string& n, int v) : name(n), value(v) {
        std::cout << "Resource " << name << " created\n";
    }

    ~Resource() {
        std::cout << "Resource " << name << " destroyed\n";
    }

    void doSomething() const {
        std::cout << "Resource " << name << " is doing something with value " << value << "\n";
    }

    void setValue(int v) { value = v; }
    int getValue() const { return value; }
    const std::string& getName() const { return name; }
};

class Factory {
public:
    static std::unique_ptr<Resource> createResource(const std::string& name, int value) {
        return std::make_unique<Resource>(name, value);
    }
};

void demonstrateBasicUniquePtr() {
    std::cout << "\n=== Basic unique_ptr usage ===\n";

    // Creating a unique_ptr
    std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>("basic", 42);
    ptr1->doSomething();

    // Accessing members with arrow operator
    std::cout << "Value: " << ptr1->getValue() << "\n";

    // Dereferencing with * operator
    std::cout << "Name: " << (*ptr1).getName() << "\n";

    // Check if pointer is valid
    if (ptr1) {
        std::cout << "ptr1 is valid\n";
    }

    // Reset to point to different resource
    std::cout << "Resetting ptr1...\n";
    ptr1.reset(new Resource("reset", 100));
    ptr1->doSomething();

    // Release ownership
    std::cout << "Releasing ownership...\n";
    Resource* rawPtr = ptr1.release();
    if (rawPtr) {
        std::cout << "Raw pointer: " << rawPtr->getName() << "\n";
        delete rawPtr; // Must manually delete when using release()
    }
}

void demonstrateMoveSemantics() {
    std::cout << "\n=== Move semantics ===\n";

    std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>("move_src", 200);
    std::cout << "ptr1 owns: " << (ptr1 ? ptr1->getName() : "nothing") << "\n";

    // Move ownership to ptr2
    std::unique_ptr<Resource> ptr2 = std::move(ptr1);
    std::cout << "After move:\n";
    std::cout << "ptr1 owns: " << (ptr1 ? ptr1->getName() : "nothing") << "\n";
    std::cout << "ptr2 owns: " << (ptr2 ? ptr2->getName() : "nothing") << "\n";

    // ptr2 will automatically clean up when it goes out of scope
}

void demonstrateWithContainers() {
    std::cout << "\n=== unique_ptr with containers ===\n";

    std::vector<std::unique_ptr<Resource>> resources;

    // Add resources to vector
    resources.push_back(std::make_unique<Resource>("container1", 10));
    resources.push_back(std::make_unique<Resource>("container2", 20));
    resources.push_back(std::make_unique<Resource>("container3", 30));

    // Use resources
    for (const auto& res : resources) {
        res->doSomething();
    }

    // Move a resource out of container
    std::unique_ptr<Resource> extracted = std::move(resources.back());
    resources.pop_back();
    std::cout << "Extracted resource: " << extracted->getName() << "\n";

    // All remaining resources will be automatically destroyed
}

void demonstrateCustomDeleters() {
    std::cout << "\n=== Custom deleters ===\n";

    // Using a lambda as custom deleter
    auto customDeleter = [](Resource* p) {
        std::cout << "Custom deleter called for " << p->getName() << "\n";
        delete p;
    };

    std::unique_ptr<Resource, decltype(customDeleter)> customPtr(
        new Resource("custom", 999), customDeleter
    );
    customPtr->doSomething();
}

void demonstrateFactoryPattern() {
    std::cout << "\n=== Factory pattern ===\n";

    std::unique_ptr<Resource> factoryPtr = Factory::createResource("factory", 500);
    factoryPtr->doSomething();
}

void demonstrateUniquePtrArrays() {
    std::cout << "\n=== unique_ptr with arrays ===\n";

    // unique_ptr for arrays (C++11 and later)
    std::unique_ptr<Resource[]> resourceArray = std::make_unique<Resource[]>(3);

    // Update array elements
    resourceArray[0].setValue(1);
    resourceArray[1].setValue(2);
    resourceArray[2].setValue(3);

    std::cout << "Array resources created\n";

    // Use array elements
    for (int i = 0; i < 3; ++i) {
        resourceArray[i].doSomething();
    }
}

int main() {
    std::cout << "std::unique_ptr Examples\n";
    std::cout << "========================\n";

    demonstrateBasicUniquePtr();
    demonstrateMoveSemantics();
    demonstrateWithContainers();
    demonstrateCustomDeleters();
    demonstrateFactoryPattern();
    demonstrateUniquePtrArrays();

    std::cout << "\n=== Program completed ===\n";
    std::cout << "All resources should be automatically destroyed\n";

    return 0;
}
