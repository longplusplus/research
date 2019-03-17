#include "instrumented.h"
#include <iostream>
#include <iomanip>

template<typename sorter_type>
void count_operations(std::size_t begin, std::size_t end, sorter_type sorter) {

    for (std::size_t i = instrumented_base::n; i <= instrumented_base::construction; ++i) {
        std::cout << std::setw(20) << instrumented_base::operation_numbers[i];
    }

    std::cout << std::endl;

    for (std::size_t r = begin; r < end; r <<= 1) {
        instrumented<int>* array = new instrumented<int>[r];
        instrumented<int>::initialize(r);
        sorter(array, array + r);
        for (std::size_t i = instrumented_base::n; i <= instrumented_base::construction; ++i) {
            std::cout << std::setw(20) << instrumented_base::counts[i];
        }

        std::cout << std::endl;
        delete [] array;
    }
}

struct sort {
    template<typename data_iter>
    void operator()(data_iter begin, data_iter end) const { std::sort(begin, end); }
};

struct stable_sort {
    template<typename data_iter>
    void operator()(data_iter begin, data_iter end) const { std::stable_sort(begin, end); }
};

struct heap_sort {
    template<typename data_iter>
    void operator()(data_iter begin, data_iter end) const { std::partial_sort(begin, end, end); }
};
