#import <Foundation/Foundation.h>

#include <iostream>
#include <memory>

class Renderer {
public:
    void draw() {
        std::cout << "Rendering frame..." << std::endl;
    }

    ~Renderer() {
        std::cout << "Renderer destroyed" << std::endl;
    }
};

@interface GraphicsController : NSObject {
    std::unique_ptr<Renderer> _renderer;
}

- (void)renderFrame;

@end

@implementation GraphicsController

- (instancetype)init {
    self = [super init];

    if (self) {
        _renderer = std::make_unique<Renderer>();
    }

    return self;
}

- (void)renderFrame {
    _renderer->draw();
}

@end

int main() {
    @autoreleasepool {
        GraphicsController *controller =
            [[GraphicsController alloc] init];

        [controller renderFrame];
    }

    return 0;
}
