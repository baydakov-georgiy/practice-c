#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long i64;

i64 gcd(i64 a, i64 b) {
    i64 q;
    a = llabs(a);
    b = llabs(b);
    while (q != 0) {
        q = a % b;
        a = b;
        b = q;
    }
    return a;
}

int main() {
    i64 x = 0, y = 0, g;
    i64 res;
    res = scanf("%lld %lld", &x, &y);
    assert(res == 2);
    g = gcd(x, y);
    printf("%lld\n", g);
    return 0;
}
