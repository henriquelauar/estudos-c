// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#include <stdlib.h>

int verificaMatriz (int **m, int n) {
    int i = 0, j = 0, soma1 = 0, soma2 = 0;
    
    for (i=0; i<n; i++) {
        soma1 += m[i][i];
        soma2 += m[i][n - 1 - i];
    }

    if (soma1 != soma2) {
        return 0;
    }
        
    for (i = 0; i < n; i++) { 
        int lS = 0, cS = 0;   
        for (j = 0; j < n; j++) {
            lS += m[i][j];
            cS += m[j][i];
        }
        
        if (lS != cS || cS != soma1)
            return 0;
    }
   return 1;
}

int main(){
    int n;
    
    printf("\nDigite o valor de n: ");
    scanf("%d", &n);
    
    int **matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
        matriz[i] = malloc(n * sizeof(int));
    }
    
    printf("Digite os valores da matriz n x n:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
            
    if (verificaMatriz(matriz, n)) {
        printf("\nEsta matriz é um quadrado mágico!\n");
    } else {
        printf("\nEsta matriz não é um quadrado mágico!\n");
    }
    
    free(matriz);
    
    return 0;
}
