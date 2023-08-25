/*
   Nome: Fabio Dias da Cunha
   N USP: 11320874

   Trabalho 1 - Palíndromos

   Objetivo:
   Determinar se uma string é palíndroma, considerando somente caracteres alfanuméricos.
   Letras maiúsculas e minúsculas são tratadas como iguais.

   Lógica:
   1. Comparar o primeiro e o último caractere da string.
   2. Se forem iguais, verificar se o restante da string (sem esses caracteres) também é palíndroma.

   Saída:
   O programa imprime "Sim" se a string for palíndroma e "Não" caso contrário.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Função para verificar se um caractere é alfanumérico
bool is_alphanumeric(char character) {
    return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || 
           (character >= '0' && character <= '9');
}

// Função para converter um caractere maiúsculo para minúsculo
char convert_to_lowercase(char character) {
    if(character >= 'A' && character <= 'Z') {
        return character + ('a' - 'A');
    }
    return character;
}

// Função principal para verificar se a string dada é palíndroma
bool is_string_palindrome(const char *input_string) {
    int start_index = 0;
    int end_index = strlen(input_string) - 1; // Encontrando o último índice válido da string

    // Loop para comparar caracteres nas posições iniciais e finais da string
    while(start_index < end_index) {
        // Ignorando caracteres não alfanuméricos no início da string
        while(start_index < end_index && !is_alphanumeric(input_string[start_index])) {
            start_index++;
        }
        // Ignorando caracteres não alfanuméricos no final da string
        while(start_index < end_index && !is_alphanumeric(input_string[end_index])) {
            end_index--;
        }
        
        // Comparando caracteres nas posições atuais. Se diferentes, a string não é palíndroma.
        if(convert_to_lowercase(input_string[start_index]) != convert_to_lowercase(input_string[end_index])) {
            return false;
        }

        start_index++;
        end_index--;
    }
    return true; // Se saiu do loop sem retornar falso, a string é palíndroma.
}

int main(void) {
    char user_input[1000]; // Definindo o tamanho máximo para a entrada do usuário

    fgets(user_input, sizeof(user_input), stdin);

    // Verifica e imprime o resultado
    if (is_string_palindrome(user_input)) {
        printf("Sim\n");
    } else {
        printf("Não\n");
    }

    return 0;
}
