#import <Foundation/Foundation.h>
#include <iostream>

// C++ class
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int multiply(int a, int b) {
        return a * b;
    }
};

// Objective-C class
@interface MyObject : NSObject

- (void)printMessage;

@end

@implementation MyObject

- (void)printMessage {
    NSLog(@"Hello from Objective-C class!");
}

@end

int main() {
    @autoreleasepool {
        Calculator calc;

        std::cout << "Addition: "
                  << calc.add(10, 20) << std::endl;

        std::cout << "Multiplication: "
                  << calc.multiply(10, 20) << std::endl;

        MyObject *obj = [[MyObject alloc] init];

        [obj printMessage];
    }

    return 0;
}
