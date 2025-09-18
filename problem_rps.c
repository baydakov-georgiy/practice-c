#include <stdio.h>
#include <assert.h>

typedef long long i64;

// Функция Эйлера
i64 euler_phi(i64 n) {
    i64 result = n;
    for (i64 i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// n^k mod m
i64 pow_mod(i64 n, i64 k, i64 m) {
    if (m == 1) return 0;
    i64 res = 1;
    n = n % m;
    while (k > 0) {
        if (k & 1)
            res = (res * n) % m;
        k = k >> 1;
        n = (n * n) % m;
    }
    return res;
}

// n^^k mod m с использованием теоремы Эйлера
i64 superpow_mod(i64 n, i64 k, i64 m) {
    if (m == 1) return 0;
    if (k == 0) return 1 % m;
    if (k == 1) return n % m;
    
    i64 phi = euler_phi(m);
    i64 exponent = superpow_mod(n, k - 1, phi);
    
    // Используем теорему Эйлера: a^b ≡ a^(b mod φ(m) + φ(m)) mod m при b ≥ φ(m)
    return pow_mod(n, exponent + phi, m);
}

int main() {
    i64 a, b, n;
    int res = scanf("%lld %lld %lld", &a, &b, &n);
    assert(res == 3);
    printf("%lld\n", superpow_mod(a, b, n));
    return 0;
}
