#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Hello world C lang " << std::endl;
    int i;
    
    for (i=0; i < argc; i++) {
        printf("%s", argv[i]);
    }
    return 0;
}
