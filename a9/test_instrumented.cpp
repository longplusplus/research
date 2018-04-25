#include "instrumented.h"
#include <iostream>

int main() {
    instrumented<int> i1;
    instrumented<int> i2;
    i1 = i2;
    for (std::size_t i = instrumented_base::n; i <= instrumented_base::construction; ++i) {
        std::cout << i1.counts[i] << " ";
    }

    std::cout << std::endl;
    instrumented<int> array[10241];

    for (std::size_t r = 16; r < 10240; r <<= 1) {
        instrumented<int>::initialize(r);
        std::sort(array, array + r);
        for (std::size_t i = instrumented_base::n; i <= instrumented_base::construction; ++i) {
            std::cout << i1.counts[i] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
