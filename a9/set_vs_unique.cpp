#include <iostream>
#include <set>
#include <algorithm>

int main() {
    int rounds = 1000000;
    for (int i = 0; i < rounds; ++i) {
        int a[] = {1, 3, 1, 4, 1, 5, 1, 6};
        std::sort(a, a + 6);
        std::unique(a, a + 6);
    }

    int a[] = {1, 3, 1, 4, 1, 5, 1, 6};
    for (int i = 0; i < rounds; ++i) {
        std::set<int> set_of_int(a, a + 6);
    }

    std::cout << std::unique(a, a + 6) - a << std::endl;
    return 0;
}
