#import <Foundation/Foundation.h>
#include <iostream>

int main() {
    @autoreleasepool {
        // Objective-C
        NSString *message = @"Hello from Objective-C++!";
        NSLog(@"%@", message);

        // C++
        std::cout << "Hello from C++!" << std::endl;
    }

    return 0;
}
