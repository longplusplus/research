#include <algorithm>
#include <vector>
#include <iostream>

template<typename T>
class TD {};

int main() {
    std::vector<int> vi;
    vi.push_back(1983);
    vi.push_back(1988);
    vi.push_back(1998);
    auto iter = std::find(vi.cbegin(), vi.cend(), 1988);
    TD<decltype(iter)> td;

    std::cout << typeid(iter).name() << "\n";
    std::cout << typeid(td).name() << "\n";
    
    //vi.insert(iter, 2002);
    return 0;
}
