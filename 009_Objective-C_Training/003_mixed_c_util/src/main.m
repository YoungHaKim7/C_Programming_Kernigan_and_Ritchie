#include "my_util.h" // 👈 Import C header
#import <Foundation/Foundation.h>

@interface Calculator : NSObject
- (void)run;
@end

@implementation Calculator
- (void)run {
    int result = my_add(3, 4); // 👈 Call C function
    NSLog(@"Result from C: %d", result);
}
@end

int main(void) {
    Calculator *calc = [[Calculator alloc] init];
    [calc run];
    return 0;
}
