#import <Foundation/Foundation.h>
#include <iostream>

// C++ engine
class Engine {
public:
    void start() {
        std::cout << "Engine started!" << std::endl;
    }

    int calculate(int a, int b) {
        return a * b;
    }
};

// Objective-C interface
@interface AppController : NSObject {
    Engine *_engine;
}

- (void)run;

@end

@implementation AppController

- (instancetype)init {
    self = [super init];

    if (self) {
        _engine = new Engine();
    }

    return self;
}

- (void)run {
    _engine->start();

    int result = _engine->calculate(100, 200);

    NSLog(@"Result: %d", result);
}

- (void)dealloc {
    delete _engine;
}

@end

int main() {
    @autoreleasepool {
        AppController *app =
            [[AppController alloc] init];

        [app run];
    }

    return 0;
}
