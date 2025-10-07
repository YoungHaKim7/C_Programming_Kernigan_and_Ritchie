#include <algorithm>
#include <iostream>
#include <iterator>
#include <print>
#include <vector>

template <typename C>
void reverse_sort(C& c)
{
    sort(begin(c), end(c), [](auto x, auto y) { return x > y; });
}

int main(int argc, char** argv)
{
    std::print("Hello world C++ reverse sort ");

    std::vector<int> v = { 3, 7, 2, 9 };

    std::sort(begin(v), end(v));
    std::copy(cbegin(v), cend(v), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    // sort(begin(v), end(v), [](auto x, auto y){ return x > y; });
    reverse_sort(v);
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
    std::cout << "number of arguments: " << argc << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <name>" << std::endl;
        return 1;
    }

    std::cout << "Hello, " << argv[1] << "!" << std::endl;

    return 0;
}
