#include <string>
#include <vector>
#include "Tuple.hpp"
#include <iostream>
int main()
{
    tuple<int, std::string> t(21, "ygg");
    std::vector<tuple<int, int, double>> vec;
    for (int i = 1; i <= 10; i++)
    {
        vec.push_back({i, i, 1.0 / i});
    }
    for (auto &x : vec)
    {
        std::cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << std::endl;
        get<0>(x)++, get<1>(x)++;
        std::cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << std::endl;
    }
}