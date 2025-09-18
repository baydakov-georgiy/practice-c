#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void con_frac(long long a, long long b) {
    if (a < b) printf("0 ");
    unsigned long long x = llabs(a);
    unsigned long long y = llabs(b);
    unsigned long long max, min, q;
    if (x > y) {
        max = x;
        min = y;
    } else {
        max = y;
        min = x;
    }
    for (;;) {
        printf("%llu ", max / min);
        q = max % min;
        if (q == 0) {
            return;
        }
        max = min;
        min = q;
    }
}

int main() {
    long long x = 0, y = 0, g;
    int res;

    res = scanf("%lld %lld", &x, &y);
    assert(res == 2);
    con_frac(x, y);
    //printf("%llu\n", g);

    return 0;
}
