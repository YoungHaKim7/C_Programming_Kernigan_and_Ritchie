#import <Foundation/Foundation.h>

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main() {
    @autoreleasepool {

        // C++ STL
        std::vector<int> numbers = {
            10, 20, 30, 40, 50
        };

        int total = std::accumulate(
            numbers.begin(),
            numbers.end(),
            0
        );

        std::cout << "Total: " << total << '\n';

        // Convert C++ string to NSString
        std::string cpp_string = "Hello C++";

        NSString *objc_string =
            [NSString stringWithUTF8String:cpp_string.c_str()];

        NSLog(@"NSString: %@", objc_string);
    }

    return 0;
}
