// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char nome[50];
    float nota;
    float frequencia;
} Aluno;

int main () {
    char nome[30];

    printf("\nDigite o nome do arquivo: ");
    fgets(nome, 30, stdin);

    int tamanho = strlen(nome);
    nome[tamanho-1] = '\0';

    if (strcmp(nome, "alunos.txt") != 0) {
        printf("Arquivo com os dados tem outro nome!\n\n");
    } else {
        FILE *arquivo = fopen(nome, "r");

        Aluno aluno[30];
        int n;
        float nota, frequencia, aprovados;

        FILE *binario, *binario2;
        
        binario2 = fopen("alunos.dat", "wb");

        fscanf(arquivo, "%d ", &n);

        for (int i = 0; i < n; i++) {
            fscanf(arquivo, "%s %f %f", aluno[i].nome, &aluno[i].nota, &aluno[i].frequencia);
        }

        fwrite(&aluno, sizeof(Aluno), n, binario2);
        fclose(binario2);
        fclose(arquivo);

        binario = fopen("alunos.dat", "rb");

        fwrite(&n, sizeof(int), 1, binario);
        fread(&aluno, sizeof(Aluno), n, binario);

        for (int i = 0; i < n; i++) {
            nota += aluno[i].nota;
            frequencia += aluno[i].frequencia;
            if (aluno[i].nota >= 6.0) {
                aprovados++;
            }
        }

        printf("\nNota média: %.1f", nota / n);
        printf("\nFrequência média: %.0f%%", frequencia / n);
        printf("\nPercentual de aprovação: %.0f%%\n", ((double)aprovados / n) * 100);
        
        printf("\nNome dos alunos com nota acima da nota media: \n");
        for (int i = 0; i < n; i++){
            if(aluno[i].nota > (nota/n))
                printf("%s\n", aluno[i].nome);
        }

        printf("\nAlunos aprovados: \n");
        for (int i = 0; i < n; i++) {
            if (aluno[i].nota >= 6.0) {
                printf("%s, N = %.1f, F = %.0f%%\n", aluno[i].nome, aluno[i].nota, aluno[i].frequencia);
            }
        }

        printf("\nAlunos reprovados: \n");
        for (int i = 0; i < n; i++) {
            if (aluno[i].nota < 6.0) {
                printf("%s, N = %.1f, F = %.0f%%\n", aluno[i].nome, aluno[i].nota, aluno[i].frequencia);
            }
        }
        fclose(binario);
    }

	printf("\n");

    return 0;
}