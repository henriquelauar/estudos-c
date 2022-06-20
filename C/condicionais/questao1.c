// Henrique Sousa Lauar 21.2.4104 Turma 32

#include <stdio.h>

int main () {
    int ano;
    
    printf("Digite um ano: ");
    scanf("%d", &ano);

    if ( ano % 4 == 0 && ano % 100 != 0 ) {
        printf("O ano é bissexto\n");
    } else if ( ano % 400 == 0 ) {
        printf ("O ano é bissexto\n");
    } else {
    printf("O ano não é bissexto\n");
    }
    return 0;
}
