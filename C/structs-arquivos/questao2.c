// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
typedef struct {
	double real;
	double imaginario;
} Complexo;

Complexo somaComplexo(Complexo x, Complexo y) {
	Complexo soma;
	soma.real = x.real + y.real;
	soma.imaginario = x.imaginario + y.imaginario;

	return soma;
}

Complexo subComplexo(Complexo x, Complexo y) {
	Complexo subtracao;
	
	subtracao.real = x.real - y.real;
	subtracao.imaginario = x.imaginario - y.imaginario;

	return subtracao;
}

Complexo multComplexo(Complexo x, Complexo y) {
	Complexo multiplicacao;

	multiplicacao.real = (x.real * y.real) - (x.imaginario * y.imaginario) ;
	multiplicacao.imaginario = (x.real * y.imaginario) + (x.imaginario * y.real);

	return multiplicacao;
}

int main () {
	Complexo x1, x2, soma, subtracao, multiplicacao;
	char sinal;

	printf("\nCalculadora de numeros Complexos!\n");

	printf("Digite os valores de a e b (x = a + bi): ");
	scanf("%lf %lf", &x1.real, &x1.imaginario);

	printf("Digite os valores de c e d (y = c + di): ");
	scanf("%lf %lf", &x2.real, &x2.imaginario);

	printf("Digite o operador (+, - ou *): ");
	scanf("%s", &sinal);

	switch (sinal) {
		case '+':
			soma = somaComplexo(x1,x2);
			if (soma.imaginario == 0) {
				printf ("Resultado: %.lf\n\n", soma.real);
			}
			else if (soma.imaginario == 1) {
				printf ("Resultado: %.lf + i\n\n", soma.real);
			}
			else {
				printf ("Resultado: %.lf + %.lf\n\n", soma.real, soma.imaginario);
			}
		break;
		case '-':
			subtracao = subComplexo(x1,x2);
			if (subtracao.imaginario == 0) {
				printf ("Resultado: %.lf\n\n", subtracao.real);
			}
			else if (subtracao.imaginario == 1) {
				printf ("Resultado: %.lf + i\n\n", subtracao.real);
			}
			else {
				printf ("Resultado: %.lf + %.lf\n\n", subtracao.real, subtracao.imaginario);
			}
		break;
		case '*':
			multiplicacao = multComplexo(x1,x2);
			if (multiplicacao.imaginario == 0) {
				printf("Resultado: %.lf\n\n", multiplicacao.real);
			}
			else if (multiplicacao.imaginario == 1) {
				printf("Resultado: %.lf + i\n\n", multiplicacao.real);
			}
			else {
				printf("Resultado: %.lf + %.lf\n\n", multiplicacao.real, multiplicacao.imaginario);
			}
		break;
		default:
			printf("Operador inválido\n");
	}

	return 0;
}