// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
typedef struct {
	int numerador;
	int denominador;
} Racional; 

int MDC (Racional r1, Racional r2) {
	if ((r1.numerador * r2.denominador) == (r2.numerador * r1.denominador)) {
		return 1;
	} else {
		return 0;
	}
}

int main () {
	Racional r1, r2;

	printf("Digite o numerador e denominador de r1: ");
	scanf("%d %d", &r1.numerador, &r1.denominador);

	printf("Digite o numerador e denominador de r2: ");
	scanf("%d %d", &r2.numerador, &r2.denominador);

	int x = MDC(r1, r2);

	if (x == 1) {
		printf("\nr1 e r2 são iguais!\n\n");
	} else {
		printf("\nr1 e r2 são diferentes!\n\n");
	}

	return 0;
}