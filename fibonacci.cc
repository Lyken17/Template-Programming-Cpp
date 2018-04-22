#include <iostream>
#include <cmath>

// get nth item in fibonacci array
int normal_iterative_fibo(int n) {
    if ( n == 1 || n == 2) return 1;

    int a = 1, b = 1, res = a + b;
    for (int i = 3; i < n; i ++) {
        res = a + b;
        a = b;
        b = res;
    }

    return res;
}

// get nth item in fibonacci array
int normal_recursive_fibo(int n) {
    if ( n == 1 || n == 2) return 1;

    // TODO: can be optimized with memorization
    return normal_recursive_fibo(n - 1) +
           normal_recursive_fibo(n - 2);
}

template <int n>
struct fibonacci {
	enum {
        a = fibonacci<n - 1>::value,
        b = fibonacci<n - 2>::value,
        value = a + b
    };
};

template <>
struct fibonacci<1> {
	enum { value = 1 };
};

template <>
struct fibonacci<2> {
	enum { value = 1 };
};
