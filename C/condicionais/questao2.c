// Henrique Sousa Lauar 21.2.4104 Turma 32

#include <stdio.h>

int main () {
	int A, B, C, maior, intermediario, menor;
	
	printf("Digite 3 números inteiros: ");
	scanf("%d %d %d", &A, &B, &C);
	
	if ((A >= B) && (A >= C) && (B >= C)) {
		maior = A;
		intermediario = B;
		menor = C;
	} else if ((A >= B) && (A >= C) && (C >= B)) {
		maior = A;
		intermediario = C;
		menor = C;
	} else if ((B >= A) && (B >= A) && (A >= C)) {
		maior = B;
		intermediario = A;
		menor = C;
	} else if ((B >= A) && (B >= A) && (C >= A)) {
		maior = B;
		intermediario = C;
		menor = A;
	} else if ((C >= A) && (C >= B) && (B >= A)) {
		maior = C;
		intermediario = B;
		menor = A;
	} else if ((C >= A) && (C >= B) && (A >= B)) {
		maior = C;
		intermediario = A;
		menor = B;
	}
	
	printf("\nMenor: %d", menor);
	printf("\nIntermediário: %d", intermediario);
	printf("\nMaior: %d\n\n", maior);

	return 0;
}
