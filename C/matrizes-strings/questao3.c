// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#include <string.h>
#define TAM 100

int main () {
    char nome[TAM], sobrenome[TAM];

    printf("Digite o nome completo: ");
    fgets(nome, TAM, stdin);

    int x = strlen(nome);

    for (int i = x - 1; nome[i] != ' '; i--) {
        int j = 0;
        sobrenome[j] = nome[i];
        j++;
    } 

    printf("\nTotal de letras: %ld\n", strlen(nome)-1);
    printf("Total de letras do último sobrenome: %ld\n\n", strlen(sobrenome));

    return 0;
}