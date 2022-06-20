// Henrique Sousa Lauar 21.2.4104 Turma 32

#include <stdio.h>

int main () {
	int cod;
	double salario, novosalario, diferenca;
	
	printf("\nInsira o código do cargo: ");
	scanf("%d", &cod);
	printf("Insira o salário: ");
	scanf("%lf", &salario);
	
	switch(cod) {
	case 100:
		novosalario = salario * 0.03 + salario;
		diferenca = novosalario - salario;
		printf("\nSalário antigo = %.2lf\nNovo salário = %.2lf\nDiferença = %.2lf\n\n", salario, novosalario, diferenca);
	break;
	case 101:
		novosalario = salario * 0.05 + salario;
		diferenca = novosalario - salario;
		printf("\nSalário antigo = %.2lf\nNovo salário = %.2lf\nDiferença = %.2lf\n\n", salario, novosalario, diferenca);
	break;
	case 102:
		novosalario = salario * 0.075 + salario;
		diferenca = novosalario - salario;
		printf("\nSalário antigo = %.2lf\nNovo salário = %.2lf\nDiferença = %.2lf\n\n", salario, novosalario, diferenca);
	break;
	case 201:
		novosalario = salario * 0.1 + salario;
		diferenca = novosalario - salario;
		printf("\nSalário antigo = %.2lf\nNovo salário = %.2lf\nDiferença = %.2lf\n\n", salario, novosalario, diferenca);
	break;
	default:
		novosalario = salario * 0.15 + salario;
		diferenca = novosalario - salario;
		printf("\nSalário antigo = %.2lf\nNovo salário = %.2lf\nDiferença = %.2lf\n\n", salario, novosalario, diferenca);
	break;
	};


	return 0;
}
