#ifndef INSTRUMENTED_H
#define INSTRUMENTED_H

#include <stddef.h>

struct instrumented_base {
    enum operations {
        n, copy, assignment, destructor, default_constructor, equality, comparison, construction
    };

    static const size_t number_ops = 8;
    static double counts[number_ops];
    static const char* operation_numbers[number_ops];
    static void initialize(size_t);
};

template<typename T>
// T is 
struct instrumented : instrumented_base {
    T value;

    //semiregular, default constructor, copy constructor, assignment, destructor
    instrumented(const instrumented& x) : value(x.value) {
        ++counts[copy];
    }

    instrumented() { ++counts[default_constructor]; }

    ~instrumented() { ++counts[destructor]; }
    instrumented& operator=(const instrumented& x) {
        ++counts[assignment];
        value = x.value;
        return *this;
    }

    //regular
    friend
    bool operator==(const instrumented& x, const instrumented& y) {
        ++counts[equality];
        return x.value == y.value;
    }

    friend
    bool operator!=(const instrumented& x, const instrumented& y) {
        return !(x == y);
    }

    //totally ordered
    friend
    bool operator<(const instrumented& x, const instrumented& y) {
        ++counts[comparison];
        return x.value < y.value;
    }

    friend
    bool operator>(const instrumented& x, const instrumented& y) {
        ++counts[comparison];
        return x.value > y.value;
    }

    friend
    bool operator<=(const instrumented& x, const instrumented& y) {
        return !(y < x);
    }

    friend
    bool operator>=(const instrumented& x, const instrumented& y) {
        return !(y < x);
    }

    //conversion
};

#endif  // end of
