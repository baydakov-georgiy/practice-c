#include <stdio.h>
#include <assert.h>

int main() {
    int n;
    unsigned int x;
    n = scanf("%u", &x);
    assert(n == 1);

    unsigned int fcts[32];
    unsigned int fcts_size = 0;
    unsigned int fct = 1;
    while (fct <= x) {
        fcts[fcts_size++] = fct;
        fct *= (fcts_size + 1);
    }

    unsigned int fct_idx = fcts_size - 1;
    unsigned int d;
    while (x != 0) {
        putc((x / fcts[fct_idx]) + '0', stdout);
        putc('.', stdout);
        x = x % fcts[fct_idx--];
    }

    return 0;
}
