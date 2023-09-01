/*
   Nome: Fabio Dias da Cunha
   N USP: 11320874

   Trabalho 1 - Arquivos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_TAM 12

typedef struct {
    int id;
    char nome[NOME_TAM + 1]; // +1 para o caractere de fim de string '\0'
    int idade;
} Pessoa;

void adicionarRegistro(const char *arquivo, int id, const char *nome, int idade);
void lerPorId(const char *arquivo, int id);
void lerTodos(const char *arquivo);

int main() {
    int opcao;

    do {
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                char arquivo[100];
                int id, idade;
                char nome[NOME_TAM + 1];
                scanf("%s %d %s %d", arquivo, &id, nome, &idade);
                adicionarRegistro(arquivo, id, nome, idade);
                break;
            }
            case 2: {
                char arquivo[100];
                int id;
                scanf("%s %d", arquivo, &id);
                lerPorId(arquivo, id);
                break;
            }
            case 3: {
                char arquivo[100];
                scanf("%s", arquivo);
                lerTodos(arquivo);
                break;
            }
        }

    } while (opcao != 0);

    return 0;
}

void adicionarRegistro(const char *arquivo, int id, const char *nome, int idade) {
    FILE *fp = fopen(arquivo, "ab");

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Pessoa pessoa;
    pessoa.id = id;
    strncpy(pessoa.nome, nome, NOME_TAM);
    pessoa.nome[NOME_TAM] = '\0'; // garantir que a string esteja terminada
    pessoa.idade = idade;

    fwrite(&pessoa, sizeof(Pessoa), 1, fp);

    fclose(fp);
}

void lerPorId(const char *arquivo, int id) {
    FILE *fp = fopen(arquivo, "rb");

    if (fp == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    Pessoa pessoa;
    int encontrado = 0;

    while(fread(&pessoa, sizeof(Pessoa), 1, fp) == 1) {
        if (pessoa.id == id) {
            printf("ID: %d | NOME: %s | IDADE: %d\n", pessoa.id, pessoa.nome, pessoa.idade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Registro não encontrado.\n");
    }

    fclose(fp);
}

void lerTodos(const char *arquivo) {
    FILE *fp = fopen(arquivo, "rb");

    if (fp == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    Pessoa pessoa;

    while(fread(&pessoa, sizeof(Pessoa), 1, fp) == 1) {
        printf("ID: %d | NOME: %s | IDADE: %d\n", pessoa.id, pessoa.nome, pessoa.idade);
    }

    fclose(fp);
}
