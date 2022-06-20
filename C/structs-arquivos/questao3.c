// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>

typedef struct {
	char nome[50];
	float nota;
	float frequencia;	
} Aluno;

int main () {
	Aluno NOME[50], NOTA, FREQUENCIA;
	int numAlunos;

	printf("\nEscreva o número de alunos da turma: ");
	scanf("%d", &numAlunos);

	FILE *arquivo = fopen("alunos.txt", "w");

	fprintf(arquivo, "%d\n", numAlunos);
	printf("\n");

	for (int i = 0; i < numAlunos; i++) {
		printf("Digite o nome do aluno %d: ", i+1);
		scanf("%s", NOME[i].nome);
		fprintf(arquivo, "\n%s\n", NOME[i].nome);
		
		do {
			printf("Digite a nota do aluno %d: ", i+1);
			scanf("%f", &NOTA.nota);
			if (NOTA.nota < 0 || NOTA.nota > 10) {
				printf("Nota inválida.\n\n");		
			}
		} while (NOTA.nota < 0 || NOTA.nota > 10);
	
		fprintf(arquivo, "\n%.2f\n", NOTA.nota);

		do {
			printf("Digite a frequência do aluno %d: ", i+1);
			scanf("%f", &FREQUENCIA.frequencia);
			printf("\n");
			if (FREQUENCIA.frequencia < 0 || FREQUENCIA.frequencia > 100) {
				printf("Frequência inválida.\n\n");
			}
		} while (FREQUENCIA.frequencia < 0 || FREQUENCIA.frequencia > 100);
		
		fprintf(arquivo, "\n%.2f\n", FREQUENCIA.frequencia);
		}

	fclose(arquivo);
	
	return 0;
}