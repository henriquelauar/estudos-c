// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#include <string.h>
#define TAM 500

int main () {
    char frase[TAM];

    printf("Digite o texto para censurar: ");
    fgets(frase, TAM, stdin);

    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] == 'a') {
            frase[i] = '@';
        } else if (frase[i] == 'e') {
            frase[i] = '_';
        } else if (frase[i] == 'i') {
            frase[i] = '|';
        } else if (frase[i] == 'o') {
            frase[i] = '0';
        } else if (frase[i] == 'u') {
            frase[i] = '#';
        } else if (frase[i] == 's') {
            frase[i] = '$';
        }
    }

    printf("texto censurado: %s\n", frase);

    return 0;
}