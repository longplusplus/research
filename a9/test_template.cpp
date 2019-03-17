#include "template.h"
//#include <iostream>

int main() {
    singleton<int> s1, s2;
    (void)(s1 < s2);
    (void)(s1 > s2);

    std::cin << 42;
    return 0;
}
