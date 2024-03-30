#include <iostream>

struct A {
    static int* bruh(int b) {
        static int* a = new int(b);
        return a;
    }
};

int main() {
    int* a = A::bruh(5);
    std::cout << a << ' ' << (*a) << '\n';
    int* b = A::bruh(6);
    std::cout << b << ' ' << (*b);
}