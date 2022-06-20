// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>

int main () {
    int A[10][10], B[10][10], C[10][10], m, n, p, q;

    printf("Digite o número de linhas da matriz A: ");
    scanf("%d", &m);

    printf("Digite o número de colunas da matriz A: ");
    scanf("%d", &p);

    printf("Digite o número de linhas da matriz B: ");
    scanf("%d", &q);

    printf("Digite o número de colunas da matriz B: ");
    scanf("%d", &n);

    if (p == q) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                printf("Digite os valores A[%d][%d]: ", i+1, j+1);
                scanf("%d", &A[i][j]);
            }
        }

        for (int i = 0; i < q; i++) {
            for (int j = 0; j < n; j++) {
                printf("Digite os valores B[%d][%d]: ", i+1, j+1);
                scanf("%d", &B[i][j]);
            }
        }

       for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < p; k++) {
                    C[i][j] = (A[i][k] * B[k][j]); 
                }
            }
        }

        printf("\nMatriz C\n==========\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    else {
        printf("\nErro! Impossivel multiplicar as matrizes informadas.\n");
    }

    return 0;
}