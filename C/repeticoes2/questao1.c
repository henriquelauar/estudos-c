// // Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#include <math.h>

double calculo (int termos) {
    double S = 0;
    int sinal = 1;
    int denominador = 1;

    for (int i = 0; i < termos; i++) {
        S += sinal * 1.0 / pow(denominador, 3);
        sinal *= -1;
        denominador = denominador + 2;
    }

    return cbrt(S * 32);
}

int main () {
    int termos;
    double piAprox;

    printf("\nDigite o número de termos: ");
    scanf("%d", &termos);

    piAprox = calculo(termos);

    printf("%f\n\n", piAprox);

    return 0;
}