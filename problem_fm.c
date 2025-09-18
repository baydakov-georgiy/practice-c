#include <stdio.h>
#include <assert.h>

typedef long long i64;

i64 fib(i64 x, i64 m) {
    if (x == 0) return 0;
    i64 f = 0 % m;
    i64 s = 1 % m;
    i64 tmp;
    for (i64 i = 1; i < x; i++) {
        tmp = s;
        s = (f + s) % m;
        f = tmp;
    }
    return s;
}

int main() {
#if 0
    for (i64 i = 0; i < 40; i++) {
        printf("%lld\n", fib(i, 1000000));
    }
    return 0;
#endif
    i64 x, m;
    int res = scanf("%lld %lld", &x, &m);
    assert(res == 2);
    printf("%lld", fib(x, m));
    return 0;
}
