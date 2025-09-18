#include <stdio.h>
#include <assert.h>

typedef long long i64;

int sgn(i64 x) {
    return x < 0 ? -1 : 1;
}


void extended_gcd(i64 m, i64 n) {
    i64 x, y, a_prev, b_prev, a, b, q, d, tmp;
    x = m * sgn(m);
    y = n * sgn(n);

    a_prev = 1;
    b_prev = 0;
    a = 0;
    b = 1;

    while (y != 0) {
        d = x / y;

        tmp = a;
        a = a_prev - d * a;
        a_prev = tmp;

        tmp = b;
        b = b_prev - d * b;
        b_prev = tmp;

        q = x % y;
        x = y;
        y = q;

    }

    printf("%lld %lld %lld\n", sgn(m) * a_prev, sgn(n) * b_prev, x);
}

int main() {
    int res;
    i64 x, y;
    res = scanf("%lld %lld", &x, &y);
    assert(res == 2);
    extended_gcd(x, y);
    return 0;
}
