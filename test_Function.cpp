#include <random>
#include "Function.hpp"
#include <iostream>
#include <vector>
#include <time.h>

void test_Function(int n) {
    std::cout << n << std::endl;
}
int main()
{
    Function<void(int)> f = test_Function;
    f(5);
    Function<int(int)> g = [](int x) { return x * x; };
    std::cout << g(5) << std::endl;
    return 0;
}