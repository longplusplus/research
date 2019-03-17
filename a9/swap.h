
template<typename T>
inline
void my_swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
inline
void my_swap_xor(T& a, T& b) {
    a = a ^ b; // a ^ b, b
    b = a ^ b; // a ^ b, a
    a = a ^ b; // b, a
}
