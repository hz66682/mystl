#include <iostream>
#include <cstdio>
using namespace std;

// typedef void (*func)();

void printhello() {
    cout << "Hello" << endl;
}
void printworld() {
    cout << "World" << endl;
}
struct func {
    void operator()(int i) const {
        printf("%d Hello x = %d, y = %d \n", i, x, y);
    }
    int &x;
    int &y;
};
template <typename F>
void repeat(F const f) {
    f(1);
    f(2);
}
int main()
{
    int x = 1, y = 2;
    // cin >> x >> y;
    func a{x, y};
    // a.x = 1;
    // a.y = 2;
    repeat(a);
    repeat([&x, &y](int i) {
        printf("%d Hello x = %d, y = %d \n", i, x, y);
    });
    return 0;
}