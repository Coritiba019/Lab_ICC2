#include <stdio.h>
#include <time.h>

long long int power_iterative(int n, int k) {
    long long int result = 1;
    for (int i = 0; i < k; i++) {
        result = result * n % 1000;
    }
    return result;
}

long long int power_recursive(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;
    
    long long int half = power_recursive(n, k/2);
    if (k % 2 == 0) {
        return (half * half) % 1000;
    } else {
        return (half * half * n) % 1000;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    clock_t start = clock();

    //printf("%lld\n", power_iterative(n, k));
    printf("%lld\n", power_recursive(n, k));

    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%lf\n", time_spent);

    return 0;
}

