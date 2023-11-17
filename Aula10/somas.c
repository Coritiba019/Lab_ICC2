#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 200000

// Estrutura para Hashing
typedef struct HashNode {
    int key;
    struct HashNode *next;
} HashNode;

HashNode *hashTable[TABLE_SIZE];

// Função de hash aprimorada
int hash(int key) {
    return (key & 0x7fffffff) % TABLE_SIZE;
}

// Inserir com encadeamento
void insert(int key) {
    int i = hash(key);
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->next = hashTable[i];
    hashTable[i] = newNode;
}

// Busca com encadeamento
int search(int key) {
    int i = hash(key);
    HashNode *node = hashTable[i];
    while (node) {
        if (node->key == key) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

// Limpar a tabela de hash
void clearHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode *node = hashTable[i];
        while (node) {
            HashNode *temp = node;
            node = node->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

// Função de comparação para qsort
int compare(const void *a, const void *b) {
    int num1 = *(const int *)a;
    int num2 = *(const int *)b;
    if (num1 > num2) return 1;
    if (num1 < num2) return -1;
    return 0;
}

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) 
            return 1; 
        if (arr[m] < x) 
            l = m + 1; 
        else
            r = m - 1; 
    }
    return 0;
}

int twoSumBinarySearch(int arr[], int n, int k) {
    // A ordenação já foi feita anteriormente
    for (int i = 0; i < n - 1; i++) {
        if (binarySearch(arr, i + 1, n - 1, k - arr[i])) 
            return 1;
    }
    return 0;
}

int twoSumHashing(int *arr, int n, int k) {
    // A tabela de hash já foi preenchida anteriormente
    for (int i = 0; i < n; i++) {
        if (search(k - arr[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, q, k;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Ordena o array para a busca binária
    qsort(arr, n, sizeof(int), compare);

    // Preenche a tabela de hash
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }

    scanf("%d", &q);
    while (q--) {
        scanf("%d", &k);
        // printf("%s\n", twoSumBinarySearch(arr, n, k) ? "S" : "N");
        printf("%s\n", twoSumHashing(arr, n, k) ? "S" : "N");
    }

    free(arr);
    clearHashTable();
    return 0;
}
