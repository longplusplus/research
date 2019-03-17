#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T>
// T is 
struct singleton {
    T value;

    //semiregular, default constructor, copy constructor, assignment, destructor
    singleton(const singleton& x) : value(x.value) {}
    // could be implicitly declared
    singleton() {}
    ~singleton() {}
    singleton& operator=(const singleton& x) {
        value = x.value;
        return *this;
    }

    //regular
    friend
    bool operator==(const singleton& x, const singleton& y) {
        return x.value == y.value;
    }

    friend
    bool operator!=(const singleton& x, const singleton& y) {
        return !(x == y);
    }

    //totally ordered
    friend
    bool operator<(const singleton& x, const singleton& y) {
        return x.value < y.value;
    }

    friend
    bool operator>(const singleton& x, const singleton& y) {
        return x.value > y.value;
    }

    friend
    bool operator<=(const singleton& x, const singleton& y) {
        return !(y < x);
    }

    friend
    bool operator>=(const singleton& x, const singleton& y) {
        return !(y < x);
    }

    //conversion
};

#endif  // end of
