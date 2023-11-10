#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    short int dia;
    short int mes;
    short int ano;
} Data;

long long pares_fora_de_ordem = 0;

int comparaData(Data a, Data b) {
    if (a.ano < b.ano) return -1;
    if (a.ano > b.ano) return 1;
    if (a.mes < b.mes) return -1;
    if (a.mes > b.mes) return 1;
    if (a.dia < b.dia) return -1;
    if (a.dia > b.dia) return 1;
    return 0;
}

// force brute  O(n^2)
long long paresForaDeOrdem(Data arr[], int n) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (comparaData(arr[i], arr[j]) == 1) {
                count++;
            }
        }
    }
    return count;
}

void merge(Data arr[], Data aux[], int l, int m, int r) {
    int i, j, k;
    
    for (i = l; i <= r; i++) {
        aux[i] = arr[i];
    }

    i = l;
    j = m + 1;
    k = l;

    while (i <= m && j <= r) {
        if (comparaData(aux[i], aux[j]) <= 0) {
            arr[k++] = aux[i++];
        } else {
            arr[k++] = aux[j++];
            pares_fora_de_ordem += (m - i + 1);
        }
    }

    while (i <= m) {
        arr[k++] = aux[i++];
    }

    while (j <= r) {
        arr[k++] = aux[j++];
    }
}

// mergeSort O(n log n)
void mergeSort(Data arr[], Data aux[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        mergeSort(arr, aux, l, m);
        mergeSort(arr, aux, m + 1, r);

        merge(arr, aux, l, m, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Data *datas = (Data *)malloc(n * sizeof(Data));
    Data *aux = (Data *)malloc(n * sizeof(Data));

    for (int i = 0; i < n; i++) {
        scanf("%hd %hd %hd", &datas[i].dia, &datas[i].mes, &datas[i].ano);
    }

    //clock_t start = clock();
    
    // Chama a função mergeSort
    //mergeSort(datas, aux, 0, n - 1);
    //printf("%lld\n", pares_fora_de_ordem);

    pares_fora_de_ordem = paresForaDeOrdem(datas, n);
    printf("%lld\n", pares_fora_de_ordem);

    //clock_t end = clock();

    //double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    //printf("%lf\n", time_spent);

    free(datas);
    free(aux);

    return 0;
}