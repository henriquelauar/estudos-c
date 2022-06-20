// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#define TAM 6

int main () {
    int temp[TAM], soma, cont1 = 0, cont2 = 0;
    double tempMedia;

    for (int i = 0; i < TAM; i++) {
        printf("Digite a temperatura do %dº dia: ", i+1);
        scanf("%d", &temp[i]);
        soma += temp[i];
    }

    tempMedia = soma / TAM;

    for (int i = 0; i < TAM; i++) {
        if (temp[i] >= tempMedia) {
            cont1++;
        } else if (temp[i] < tempMedia) {
            cont2++;
        }
    }

    printf("\nDias com temperatura maior que a média: %d\n", cont1);
    printf("\nDias com temperatura menor que a média: %d\n", cont2);

    return 0;
}