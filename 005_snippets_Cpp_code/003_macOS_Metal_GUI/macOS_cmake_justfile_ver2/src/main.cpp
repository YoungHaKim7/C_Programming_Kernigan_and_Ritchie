// #include <Metal/Metal.hpp>

// #include <iostream>

// // int main(int argc, const char *argv[]) {
// int main() {

//     // insert code here...

//     MTL::Device *metalDevice = MTL::CreateSystemDefaultDevice();

//     std::cout << "Hello, World from Metal-CPP!\n";
//     return 0;
// }
#include <Metal/Metal.hpp>

#include <cstdio>
#include <iostream>

int main() {
    NS::AutoreleasePool *pool = NS::AutoreleasePool::alloc()->init();

    MTL::Device *metalDevice = MTL::CreateSystemDefaultDevice();
    if (!metalDevice) {
        std::puts("no Metal device");
        return 1;
    }

    std::printf("GPU: %s\n", metalDevice->name()->utf8String());
    std::cout << "Hello, World from Metal-CPP!\n";

    metalDevice->release();
    pool->release();
    return 0;
}
