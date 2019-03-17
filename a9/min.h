#include <algorithm>

template <typename T>
struct less {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

template <typename T, typename Compare>
// requires Compare defines a StrictWeakOrdering on T
inline
const T& min(const T& a, const T& b, Compare cmp) {
    if (cmp(b, a)) {
        return b;
    } else {
        return a;
    }
}

template <typename T>
inline
const T& min(const T&a, const T& b) {
    return min(a, b, std::less<T>());
}

/*
std::sort(a.begin(), a.end(), less<int>());
*/

template <typename T, typename Compare>
// requires T is StrictWeakOrdering
inline
void sort2(T& a, T& b) {
    if (cmp(b, a)) {
        std::swap(a, b);
    }
}

template <typename T, typename Compare>
// requires Compare defines a StrictWeakOrdering on T
inline
const T& max(const T& a, const T& b, Compare cmp) {
    if (!cmp(b, a)) {
        return a;
    } else {
        return b;
    }
}

template <typename I, typename Compare>
// requires I is ForwardIterator
// and Compare is StrictWeakOrdering on Value(I)
inline
I min_elements(I first, I last, Compare cmp) {
    if (first == last) return last;
    I min_el = first;
    ++first;
    while (first != last) {
        if (cmp(*first, *min_el)) {
            min_el = first;
        }

        ++first;
    }

    return min_el;
}

template <typename I, typename Compare>
// requires I is ForwardIterator
// and Compare is StrictWeakOrdering on Value(I)
std::pair<I, I> my_minmax_element(I first, I last, Compare cmp) {
    if (first == last) {
        return std::make_pair(last, last);
    }

    I min_el = first;
    ++first;
    I max_el = first;
    if (first == last) {
        return std::make_pair(min_el, min_el);
    }

    ++first;
    while (first != last) {
        // min_el points to current minimum
        // max_el points to current maximum
        // protential_min and protential_next point to next 2 elements
        I protential_min = first;
        I protential_max = first;
        ++first;
        if (first != last) {
            protential_max = first;
        }

        if (cmp(*protential_max, *protential_min)) {
            std::swap(protential_min, protential_max);
        }

        if (!cmp(*protential_max, *max_el)) {
            max_el = protential_max;
        }

        if (cmp(*protential_min, *min_el)) {
            min_el = protential_min;
        }
    }

    return std::make_pair(min_el, min_el);
}

//functionally
//performancer
