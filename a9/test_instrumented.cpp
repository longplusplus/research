#include "functorized.h"
#include "swap.h"
#include <vector>

int main() {
    /*
    instrumented<int> i1;
    instrumented<int> i2;
    i1 = i2;
    for (std::size_t i = instrumented_base::n; i <= instrumented_base::construction; ++i) {
        std::cout << i1.counts[i] << " ";
    }
    */

    count_operations(16, 16 * 1024, sort());
    count_operations(16, 16 * 1024, stable_sort());

    //std::vector<int> a(100000, 0);
    //std::vector<int> b(100000, 0);
    int a = 16;
    int b = 2010;
    my_swap_xor(a, b);
    std::cout << "a = " << a << ", b = " << b;

    return 0;
}
