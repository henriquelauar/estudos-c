// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#include <math.h>

int calculaRaizes (float a, float b, float c, float *x1, float *x2) {
    float delta;
    delta = pow(b, 2) - 4 * a * c;

    if ( delta >= 0) { 
        *x1 = ( -b + sqrt(delta) ) / 2 * a;
        *x2 = ( -b - sqrt(delta) ) / 2 * a;
        return 1;
    } else {
        return 0;
    }
};

int main () {
    float a, b, c, x1, x2;
    int res; 

    printf("\nDigite os valores de a, b e c: ");
    scanf("%f %f %f", &a, &b, &c);

    res = calculaRaizes(a, b, c, &x1, &x2);

    if (res == 1) {
        printf("\n%.2f %.2f\n\n", x1, x2);
    } else {
        printf("Raíz menor que 0\n\n");
    }


    return 0;
}