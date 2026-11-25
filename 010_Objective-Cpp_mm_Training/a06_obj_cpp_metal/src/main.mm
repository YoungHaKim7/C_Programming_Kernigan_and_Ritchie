#import <Foundation/Foundation.h>
#import <Metal/Metal.h>

#include <iostream>
#include <memory>

class MetalEngine {
private:
    id<MTLDevice> device;
    id<MTLCommandQueue> commandQueue;

public:
    MetalEngine() {
        device = MTLCreateSystemDefaultDevice();

        if (device) {
            commandQueue = [device newCommandQueue];
        }
    }

    void printInfo() {
        if (!device) {
            std::cout << "Metal unavailable\n";
            return;
        }

        NSLog(@"GPU: %@", device.name);

        std::cout << "Metal initialized!"
                  << std::endl;
    }
};

int main() {
    @autoreleasepool {
        MetalEngine engine;

        engine.printInfo();
    }

    return 0;
}
