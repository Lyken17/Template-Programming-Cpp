#include <iostream>
#include <cmath>


int module_exponential_iterative(int n, int b) {
    int res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * n;

        b = b >> 1;
        n = n * n;
    }

    return res;
}

int module_exponential_recursive(int n, int b) {
    if (b == 0) return 1;

    int remain = b % 2;
    int res = module_exponential_recursive(n, (b - remain) / 2);


    if (remain == 0) {
        return res * res;
    } else {
        return n * res * res;
    }
}


template <int n, int b>
struct fast_exp {
    enum {
        remain = b % 2,
        s = fast_exp<n, (b - remain) / 2>::value,
        res = s * s % (1000000007),
        extra = remain > 0 ? n : 1,
        value = extra * res % (1000000007),
        depth = fast_exp<n, (b - remain) / 2>::depth + 1
    };
};

template <int n>
struct fast_exp<n, 0> {
    enum {
        value = 1,
        depth = 1
  };
};

using namespace std;

#define N 5
#define E 100000000

int main(int argc, char const *argv[]) {
    cout << fast_exp<N, E>::value << endl;
    cout << fast_exp<N, E>::depth << endl;
    return 0;
}
