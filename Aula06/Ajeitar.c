#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[12];
    int idade;
    float altura;
    int index;
} Pessoa;

int comparaPessoas(const Pessoa *a, const Pessoa *b) {
    int cmp = strcmp(a->nome, b->nome);
    if (cmp == 0) {
        cmp = a->idade - b->idade;
        if (cmp == 0) {
            return (a->altura > b->altura) - (a->altura < b->altura);
        }
        return cmp;
    }
    return cmp;
}

int partition(Pessoa arr[], int low, int high) {
    Pessoa pivot = arr[(low + high) / 2]; // pivô do meio
    int i = low - 1, j = high + 1;
    
    while (1) {
        do {
            i++;
        } while (comparaPessoas(&arr[i], &pivot) < 0);
        
        do {
            j--;
        } while (comparaPessoas(&arr[j], &pivot) > 0);
        
        if (i >= j) return j;

        Pessoa temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Quick sort
void quickSort(Pessoa arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

// Insertion sort
void insertionSort(Pessoa arr[], int n) {
    int i, j;
    Pessoa key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && comparaPessoas(&arr[j], &key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Bubble sort
void bubbleSort(Pessoa arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)     
        for (j = 0; j < n-i-1; j++)
            if (comparaPessoas(&arr[j], &arr[j + 1]) > 0) {
                Pessoa temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Shell sort
void shellSort(Pessoa arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            Pessoa temp = arr[i];
            int j;             
            for (j = i; j >= gap && comparaPessoas(&arr[j - gap], &temp) > 0; j -= gap)
                arr[j] = arr[j - gap];
             
            arr[j] = temp;
        }
    }
}

// Função principal
int main() {
    int n;
    scanf("%d", &n);

    Pessoa pessoas[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d %f", pessoas[i].nome, &pessoas[i].idade, &pessoas[i].altura);
        pessoas[i].index = i;
    }

    quickSort(pessoas, 0, n - 1);
    // insertionSort(pessoas, n);
    // bubbleSort(pessoas, n);
    // shellSort(pessoas, n);

    for (int i = 0; i < n; i++) {
        printf("%d;", pessoas[i].index);
    }

    return 0;
}