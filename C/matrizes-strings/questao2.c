// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#include <string.h>
#define TAM 50

int main () {
	char palavra[TAM];
	char reflexo[TAM];
	char fim[] = "FIM";

	printf("Digite uma palavra para verificar, para sair digite FIM: ");

	while(strcmp(palavra, fim) != 0) {
		scanf("%s", palavra);

        int j = 0;

        for (int i = strlen(palavra) - 1; i >= 0; i--) {
            reflexo[j] = palavra[i];
            j++;
        }

         reflexo[j] = '\0';
        
		if (strcmp(palavra, reflexo) == 0){
			printf("A palavra %s é um palindromo de %s\n\n", reflexo, palavra);
        } else {
            printf("A palavra %s não é um palindromo de %s\n\n", reflexo, palavra);
        }
			
	    printf("Digite mais um nome ou escreva FIM: ");
	}

	return 0;
}