// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#define TAM 5

int main () {
    int nota1[TAM], nota2[TAM];
    float media;

    for (int i = 0; i < TAM; i++) {
        printf("Digite a nota da 1ª prova do %dº aluno: ", i+1);
        scanf("%d", &nota1[i]);
    }

    for (int i = 0; i < TAM; i++) {
        printf("Digite a nota da 2ª prova do %dº aluno: ", i+1);
        scanf("%d", &nota2[i]);
    }

    printf("\n");

    for (int i = 0; i < TAM; i++) {
        int soma = nota1[i] + nota2[i];
        media = soma / 2;

        if (media >= 60) {
            printf("Aluno %d aprovado!\n", i+1);
        } else if (media < 60) {
            printf("Aluno %d reprovado!\n", i+1);
        }
    }
    
    return 0;
}