#include "functorized.h"
#include "swap.h"
#include "min.h"
#include <cstdlib>
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
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::vector<int> int_arr;
    srand(time(NULL));
    for (std::size_t i = 0; i < 10; ++i) {
        int_arr.push_back(rand());
        std::cout << int_arr.back() << " ";
    }

    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> res =
        my_minmax_element(int_arr.begin(), int_arr.end(), std::less<int>());

    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> res_std =
        minmax_element(int_arr.begin(), int_arr.end(), std::less<int>());

    std::cout << std::endl;
    std::cout << "my_res:" << *res.first << "," << *res.second << std::endl;
    std::cout << "std_res:" << *res_std.first << "," << *res_std.second << std::endl;
    std::cout << std::distance(int_arr.begin(), res.first) << "," << std::distance(int_arr.begin(), res.second) << std::endl;
    return 0;
}
