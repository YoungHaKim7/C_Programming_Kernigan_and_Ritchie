#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Resource {
private:
    std::string name;

public:
    Resource(const std::string& n) : name(n) {
        std::cout << "Resource " << name << " created\n";
    }

    ~Resource() {
        std::cout << "Resource " << name << " destroyed\n";
    }

    void doSomething() {
        std::cout << "Resource " << name << " is doing something\n";
    }

    const std::string& getName() const {
        return name;
    }
};

int main() {
    std::cout << "=== Basic unique_ptr Usage ===\n";

    // Creating a unique_ptr with make_unique (C++14 and later)
    auto resource1 = std::make_unique<Resource>("Resource1");
    resource1->doSomething();

    // unique_ptr automatically deletes the resource when it goes out of scope
    std::cout << "resource1 will be automatically deleted when it goes out of scope\n\n";

    std::cout << "=== Move Semantics ===\n";

    // unique_ptr cannot be copied, but can be moved
    auto resource2 = std::make_unique<Resource>("Resource2");

    // This would cause a compile error:
    // auto resource3 = resource2; // ERROR: unique_ptr cannot be copied

    // But we can move ownership
    std::cout << "Moving ownership from resource2 to resource3...\n";
    auto resource3 = std::move(resource2);

    // After move, resource2 is nullptr
    if (!resource2) {
        std::cout << "resource2 is now empty (nullptr)\n";
    }

    resource3->doSomething();
    std::cout << std::endl;

    std::cout << "=== Custom Deleters ===\n";

    // unique_ptr with custom deleter
    auto customDeleter = [](Resource* r) {
        std::cout << "Custom deleter: Deleting resource " << r->getName() << "\n";
        delete r;
    };

    std::unique_ptr<Resource, decltype(customDeleter)> resource4(
        new Resource("Resource4"), customDeleter);
    resource4->doSomething();
    std::cout << std::endl;

    std::cout << "=== unique_ptr with Arrays ===\n";

    // unique_ptr for arrays
    auto resourceArray = std::make_unique<std::unique_ptr<Resource>[]>(3);

    for (int i = 0; i < 3; ++i) {
        resourceArray[i] = std::make_unique<Resource>("ArrayResource" + std::to_string(i));
        resourceArray[i]->doSomething();
    }

    std::cout << std::endl;

    std::cout << "=== Factory Function ===\n";

    // Factory function returning unique_ptr
    auto createResource = [](const std::string& name) -> std::unique_ptr<Resource> {
        return std::make_unique<Resource>(name);
    };

    auto resource5 = createResource("Resource5");
    resource5->doSomething();

    std::cout << std::endl;

    std::cout << "=== unique_ptr in Container ===\n";

    // unique_ptr in containers
    std::vector<std::unique_ptr<Resource>> resources;

    // Emplace unique_ptr into container
    resources.emplace_back(std::make_unique<Resource>("ContainerResource1"));
    resources.emplace_back(std::make_unique<Resource>("ContainerResource2"));

    for (const auto& res : resources) {
        res->doSomething();
    }

    std::cout << std::endl;

    std::cout << "=== End of main() - All resources will be automatically cleaned up ===\n";

    return 0;
}