// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#include <stdlib.h>

int main () {
    int n, contador1 = 0, contador2 = 0, aux1 = 0, aux2 = 0;
    double media = 0, soma = 0;
	
	printf("Digite o tamanho do vetor[n]: ");
	scanf("%d", &n);
	printf("\n");

	int *vet1 = malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("Digite o termo vetor[%d]: ", i+1);
		scanf("%d", &vet1[i]);
	}

	for (int i = 0; i < n; i++) {
		soma += vet1[i];
	}

	media = soma / n;

	for (int i = 0; i < n; i++) {
		if (vet1[i] < media) {
			contador1++;
		} else {
			contador2++;
		}
	}

    int *vet2 = malloc(contador1 * sizeof(int));
    int *vet3 = malloc(contador2 * sizeof(int));

	for (int i = 0; i < n; i++) {
		if (vet1[i] - media >= 0) {
			vet3[aux1] = vet1[i];
			aux1++;
		} else {
			vet2[aux2] = vet1[i];
			aux2++;
		}
	}

    printf("\nVetor com os valores abaixo da média: ["); 
	for (int i = 0; i < contador1; i++) {
		printf("%2d", vet2[i]);
    }
	printf(" ]");

	printf("\n\nVetor com os valores iguais ou acima da média: [");
	for(int i = 0; i < contador2; i++) {
	    printf("%2d", vet3[i]);
    }
	printf(" ]");

	printf("\n\n");

	free(vet1);
	free(vet2);
	free(vet3);

	return 0;
}