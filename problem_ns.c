#include <stdio.h>
#include <assert.h>

int main() {
    int n;
    unsigned int x, y;
    n = scanf("%u %u", &x, &y);
    assert(n == 2);
    assert(y > 1 && y < 11 && x > 0);

    unsigned char res[256];
    unsigned int res_size = 0;
    while (x != 0) {
        res[res_size++] = (x % y) + '0';
        x /= y;
    }

    for (int i = res_size - 1; i >= 0; i--) {
        putc(res[i], stdout);
    }
    return 0;
}
