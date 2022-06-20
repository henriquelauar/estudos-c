// Henrique Sousa Lauar 21.2.4104 Turma 32

#include <stdio.h>

int main () {
	double peso, altura, IMC;
	
	printf("Insira seu peso e altura: ");
	scanf("%lf %lf", &peso, &altura);
	IMC = peso / (altura * altura);
	
	if (IMC < 18.5) {
		printf("\nAbaixo do peso\n");
	} else if ( IMC >= 18.5 && IMC < 25 ) {
		printf("\nPeso normal\n");
	} else if ( IMC >= 25 && IMC < 30 ) {
		printf("\nAcima do peso\n");
	} else if ( IMC > 30 ) {
		printf("\nObeso\n");
	} else {
		printf("\nPeso ou Altura inválido\n");
	}
	
	return 0;
}
