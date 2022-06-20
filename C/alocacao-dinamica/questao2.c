// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#include <stdlib.h>

double** transposta (double **matriz, int m, int n);
double** criaMatriz(int m, int n);
void liberaMatriz(double **matriz, int m);

int main () {
	int m, n;

	printf("Digite as dimensões da matriz matriz[m][n]: ");
	scanf("%d", &m);
	scanf("%d", &n);

	criaMatriz(m, n);

	return 0;
}

double** criaMatriz(int m, int n) {
	double **matriz;

	matriz = malloc(m * sizeof(int*));

	for (int i = 0; i < m; i++) {
		matriz[i] = malloc(n * sizeof(int));
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("Digite o componente de matriz[%d][%d]: ", i+1, j+1);
			scanf("%lf", &matriz[i][j]);
		}
	}
	
	printf("\n");

 	for (int i = 0; i < m; i++) {
 		printf("|");
 		for (int j = 0; j < n; j++) {
 			printf("  %.0lf  ", matriz[i][j]);
 		}
 		printf("|");
 		printf("\n");
	}	

	transposta(matriz, m, n);
	liberaMatriz(matriz, m);

	return matriz;
}

void liberaMatriz (double **matriz, int m) {
	for (int i = 0; i < m; i++) {
		free(matriz[i]);
	}

	free(matriz);
}


double** transposta (double **matriz, int m, int n) {
	double **matrizTransposta;
	matrizTransposta = malloc(n * sizeof(int*));

	for(int i=0; i<n; i++) {
		matrizTransposta[i] = malloc(m * sizeof(int));
	}

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			matrizTransposta[i][j] = matriz[i][j];
		}
	}

	printf("\n");
 	for (int i = 0; i < n; i++) {
 		printf("|");
 		for (int j = 0; j < m; j++) {
 			printf("  %.0lf  ", matrizTransposta[j][i]);
 		}
 		printf("|");
 		printf("\n");
	}	

	for (int i = 0; i < n; i++) {
 		free(matrizTransposta[i]);
	}
 
 	free(matrizTransposta);

	return matrizTransposta;
}

