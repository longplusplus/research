#include <iostream>
#include <typeinfo>

template<typename T>
class TD {};

int main() {
    const int x = 100;
    auto rx = x;
    auto px = &x;
    TD<decltype(rx)> xType;
    TD<decltype(px)> yType;

    std::cout << typeid(rx).name() << "\n";
    std::cout << typeid(px).name() << "\n";

    std::cout << typeid(xType).name() << "\n";
    std::cout << typeid(yType).name() << "\n";

    return 0; 
}
