#include <stdio.h>
#include <time.h>

typedef long long lli;

lli mdc_iterativo(lli m, lli n) { 
    lli menor = (m < n) ? m : n;
    for (lli i = menor; i > 0; i--) {
        if (m % i == 0 && n % i == 0) {
            return i;
        }
    }
    return 1;
}

lli mdc_recursivo(lli m, lli n) {
    if (n == 0) {
        return m;
    } else {
        return mdc_recursivo(n, m % n);
    }
}

int main() {
    lli m, n;

    scanf("%lld %lld", &m, &n);

    clock_t start = clock();

    //printf("%lld\n", mdc_iterativo(m, n));
    printf("%lld\n", mdc_recursivo(m, n));

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%f\n", time_spent);

    return 0;
}
