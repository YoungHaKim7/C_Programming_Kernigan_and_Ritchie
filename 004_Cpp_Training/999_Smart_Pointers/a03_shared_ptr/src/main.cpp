#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>

class Resource {
private:
    std::string name;
    int value;
    static std::mutex cout_mutex;

public:
    Resource() : name("default"), value(0) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Resource " << name << " created with default constructor\n";
    }

    Resource(const std::string& n, int v) : name(n), value(v) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Resource " << name << " created\n";
    }

    ~Resource() {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Resource " << name << " destroyed\n";
    }

    void doSomething() const {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Resource " << name << " is doing something with value " << value << "\n";
    }

    void setValue(int v) { value = v; }
    int getValue() const { return value; }
    const std::string& getName() const { return name; }
};

std::mutex Resource::cout_mutex;

class Node : public std::enable_shared_from_this<Node> {
private:
    std::string name;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> parent;  // Use weak_ptr to avoid circular reference

public:
    Node(const std::string& n) : name(n) {
        std::cout << "Node " << name << " created\n";
    }

    ~Node() {
        std::cout << "Node " << name << " destroyed\n";
    }

    void setNext(std::shared_ptr<Node> n) {
        next = n;
        if (n) {
            n->parent = shared_from_this();
        }
    }

    void printChain() const {
        std::cout << "Node " << name;
        if (next) {
            std::cout << " -> ";
            next->printChain();
        } else {
            std::cout << " -> nullptr\n";
        }
    }

    std::string getName() const { return name; }
};

void demonstrateBasicSharedPtr() {
    std::cout << "\n=== Basic shared_ptr usage ===\n";

    // Creating shared_ptr with make_shared (preferred)
    std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>("basic", 42);
    ptr1->doSomething();

    std::cout << "ptr1 use_count: " << ptr1.use_count() << "\n";

    // Copy constructor - increases reference count
    {
        std::shared_ptr<Resource> ptr2 = ptr1;
        std::cout << "After copying to ptr2:\n";
        std::cout << "ptr1 use_count: " << ptr1.use_count() << "\n";
        std::cout << "ptr2 use_count: " << ptr2.use_count() << "\n";
        ptr2->setValue(100);
        std::cout << "Modified value through ptr2: " << ptr1->getValue() << "\n";
    }

    std::cout << "After ptr2 goes out of scope:\n";
    std::cout << "ptr1 use_count: " << ptr1.use_count() << "\n";

    // Assignment operator
    std::shared_ptr<Resource> ptr3;
    ptr3 = ptr1;
    std::cout << "After assigning to ptr3:\n";
    std::cout << "ptr1 use_count: " << ptr1.use_count() << "\n";
    std::cout << "ptr3 use_count: " << ptr3.use_count() << "\n";

    // Reset function
    ptr3.reset();
    std::cout << "After resetting ptr3:\n";
    std::cout << "ptr1 use_count: " << ptr1.use_count() << "\n";
}

void demonstrateWeakPtr() {
    std::cout << "\n=== Weak pointer usage ===\n";

    // Create a shared_ptr
    std::shared_ptr<Resource> shared = std::make_shared<Resource>("weak_example", 200);
    std::cout << "Initial use_count: " << shared.use_count() << "\n";

    // Create weak_ptr
    std::weak_ptr<Resource> weak = shared;
    std::cout << "After creating weak_ptr, use_count: " << shared.use_count() << "\n";

    // Use weak_ptr to access resource
    if (auto locked = weak.lock()) {
        std::cout << "Successfully locked weak_ptr\n";
        locked->doSomething();
    } else {
        std::cout << "Resource has been destroyed\n";
    }

    // Reset shared_ptr
    shared.reset();
    std::cout << "After resetting shared_ptr:\n";

    // Try to use weak_ptr after resource is destroyed
    if (auto locked = weak.lock()) {
        std::cout << "Successfully locked weak_ptr\n";
        locked->doSomething();
    } else {
        std::cout << "Resource has been destroyed - cannot lock weak_ptr\n";
    }

    std::cout << "weak_ptr expired: " << (weak.expired() ? "true" : "false") << "\n";
}

void demonstrateCircularReference() {
    std::cout << "\n=== Avoiding circular references ===\n";

    // Without weak_ptr, this would cause memory leak
    {
        auto node1 = std::make_shared<Node>("A");
        auto node2 = std::make_shared<Node>("B");

        node1->setNext(node2);
        std::cout << "Created chain: ";
        node1->printChain();
    }
    // Both nodes are properly destroyed because we used weak_ptr for parent pointer
}

void demonstrateSharedPtrWithContainers() {
    std::cout << "\n=== shared_ptr with containers ===\n";

    std::vector<std::shared_ptr<Resource>> resources;

    // Add resources to vector
    resources.push_back(std::make_shared<Resource>("container1", 10));
    resources.push_back(std::make_shared<Resource>("container2", 20));
    resources.push_back(std::make_shared<Resource>("container3", 30));

    std::cout << "Resources in container:\n";
    for (const auto& res : resources) {
        std::cout << "  ";
        res->doSomething();
        std::cout << "  use_count: " << res.use_count() << "\n";
    }

    // Create additional references
    std::shared_ptr<Resource> ref = resources[0];
    std::cout << "After creating additional reference:\n";
    std::cout << "resources[0] use_count: " << resources[0].use_count() << "\n";

    // Use weak_ptr to observe without affecting reference count
    std::weak_ptr<Resource> weak_ref = resources[1];
    std::cout << "weak_ref doesn't affect use_count: " << resources[1].use_count() << "\n";
}

void demonstrateThreading() {
    std::cout << "\n=== shared_ptr with threading ===\n";

    auto resource = std::make_shared<Resource>("thread_example", 999);
    std::atomic<int> counter{0};
    std::vector<std::thread> threads;

    std::cout << "Creating 5 threads that share the resource\n";

    // Create multiple threads that all share the same resource
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back([resource, &counter, i]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(100 * i));

            if (auto local_copy = resource) {  // Copy to thread-local shared_ptr
                local_copy->setValue(local_copy->getValue() + i);
                local_copy->doSomething();
                counter++;
            }
        });
    }

    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All threads completed. Final value: " << resource->getValue() << "\n";
    std::cout << "Final use_count: " << resource.use_count() << "\n";
}

void demonstrateCustomDeleters() {
    std::cout << "\n=== Custom deleters with shared_ptr ===\n";

    // Using a lambda as custom deleter
    auto customDeleter = [](Resource* p) {
        std::cout << "Custom deleter called for " << p->getName() << "\n";
        delete p;
    };

    std::shared_ptr<Resource> customPtr(new Resource("custom", 777), customDeleter);
    customPtr->doSomething();

    // Check that custom deleter doesn't affect reference counting
    std::shared_ptr<Resource> copy = customPtr;
    std::cout << "use_count with custom deleter: " << customPtr.use_count() << "\n";
}

void demonstrateAliasingConstructor() {
    std::cout << "\n=== Aliasing constructor ===\n";

    auto owner = std::make_shared<Resource>("owner", 100);
    std::cout << "owner use_count: " << owner.use_count() << "\n";

    // Create an alias that shares ownership but points to a different object
    int value = owner->getValue();
    std::shared_ptr<int> value_alias(owner, &value);

    std::cout << "Created alias to the value\n";
    std::cout << "owner use_count: " << owner.use_count() << "\n";
    std::cout << "value_alias use_count: " << value_alias.use_count() << "\n";
    std::cout << "Value through alias: " << *value_alias << "\n";
}

int main() {
    std::cout << "std::shared_ptr Examples\n";
    std::cout << "========================\n";

    demonstrateBasicSharedPtr();
    demonstrateWeakPtr();
    demonstrateCircularReference();
    demonstrateSharedPtrWithContainers();
    demonstrateThreading();
    demonstrateCustomDeleters();
    demonstrateAliasingConstructor();

    std::cout << "\n=== Program completed ===\n";
    std::cout << "All resources should be automatically destroyed\n";

    return 0;
}