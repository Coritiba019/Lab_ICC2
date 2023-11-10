#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscaSequencial(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return 1; // Encontrado
    }
    return 0; // Não encontrado
}

int buscaBinaria(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x) return 1; // Encontrado

        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return 0; // Não encontrado
}

int compara(const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compara); // Ordena para busca binária

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);

        if (buscaSequencial(arr, n, x)) {
        // if (buscaBinaria(arr, 0, n - 1, x)) {
            printf("Presente\n");
        } else {
            printf("Ausente\n");
        }
    }

    free(arr);
    return 0;
}


