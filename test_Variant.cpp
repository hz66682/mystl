#include "Variant.hpp"
#include <iostream>
using std::cout, std::endl;

int main() {
    Variant<int, std::string, double, bool> v;
    v = 1;
    cout << v.get<0>() << endl;
    v = 312.12;
    cout << v.get<2>() << endl;
    std::string s = "hello";
    v = std::move(s);
    cout << v.get<1>() << endl;
}