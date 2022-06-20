#include <stdio.h>
#include <stdlib.h>

int multiplicaMatrizes(int ***R, int **A, int n, int m, int **B, int p, int q) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                *R[i][j] = A[i][k] * B[k][j]; 
            }
        }
    }

    printf("\nMatriz R\n==========\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%ls ", R[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 1;
}

int main () {
    int n, m, p, q;
    int **A, **B, **R;

    printf("Digite o tamanho da matriz A: ");
    scanf("%d", &n);
    scanf("%d", &m);

	A = malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		A[i] = malloc(n * sizeof(int));
	}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Digite o valor da posição A[%d][%d]: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }

	B = malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		B[i] = malloc(n * sizeof(int));
	}

    printf("Digite o tamanho da matriz B: ");
    scanf("%d", &p);
    scanf("%d", &q);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Digite o valor da posição B[%d][%d]: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }

    R = malloc(m * sizeof(int*));
    multiplicaMatrizes(&R, A, n, m, B, p, q);


    free(A);
    free(B);
    free(R);

    return 0;
}