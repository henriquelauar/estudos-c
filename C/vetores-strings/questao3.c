// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#include <stdlib.h>
#define TAM 500

void repeticao (int A[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("O número %d foi repetido %d vezes\n", i, A[i]);
    }
}

int main () {
    int vetor[100000], A[TAM], n;

    do {
        printf("Digite um número menor ou igual a 500: ");
        scanf("%d", &n);
    } while (n > 500);

    for (int i = 0; i < n; i++) {
        A[i] = 0;
    }

    for (int i = 0; i < 100000; i++) {
        vetor[i] = 1 + rand() % n;
        A[vetor[i]]++;
    }

    repeticao(A, n);

    return 0;
}