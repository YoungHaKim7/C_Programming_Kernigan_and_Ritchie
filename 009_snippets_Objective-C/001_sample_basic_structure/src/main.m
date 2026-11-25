#import <Foundation/Foundation.h>

@interface Person : NSObject
- (void)sayHello;
@end

@implementation Person
- (void)sayHello {
    NSLog(@"Hello, Objective-C!");
}
@end

int main(void) {
    Person *p = [[Person alloc] init];
    [p sayHello];
    return 0;
}
