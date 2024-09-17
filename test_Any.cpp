#include "Any.hpp"

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<Any> v = {1, 2, 1.321, std::string("Hello"), 'A', true};
    for (auto& a : v) {
        std::cout << a << std::endl;
    }
    return 0;
}