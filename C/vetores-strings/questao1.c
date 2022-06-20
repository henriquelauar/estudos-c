// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#define TAM 10

int main () {
    int vetor[TAM];

    vetor[0] = 1;
    vetor[1] = 1;

    for (int i = 2; i < TAM; i++) {
        vetor[i] = vetor[i - 1] + vetor[i - 2];
    }
    
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}