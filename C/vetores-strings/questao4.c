// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#define TAM 15

int main () {
    int vetor[TAM], n;

    for (int i = 0; i < TAM; i++) {
        printf("Digite o %dº termo do vetor: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("Digite o número de vezes que deseja rotacionar o vetor: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int aux = vetor[0];
        for (int j = 0; j < TAM; j++) {
            vetor[j] = vetor[j+1];
        }
        vetor[TAM-1] = aux;
    }

    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("[%d] ", vetor[i]);
    }

    printf("\n\n");

    return 0;
}