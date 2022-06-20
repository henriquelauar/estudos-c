// // Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>
#include <math.h>

int validaCPF (long long int cpf) {
    long long int termo, mult = 2, soma = 0, nove = cpf / 100, aux = nove;

    for (int i = 0; i < 9; i++) {
        termo = aux % 10;
        soma += termo * mult;
        mult++;
        aux /= 10;
    }

    long long int final = cpf % 100, ultimo = final % 10, penultimo = final / 10, resto = (soma * 10) % 11;
    long long int termo2, mult2 = 3, soma2 = penultimo * 2, nove2 = cpf / 100, aux2 = nove;
    
    if (resto == penultimo) {
        for (int i = 0; i < 9; i++) {
            termo2 = aux2 % 10;
            soma2 += termo2 * mult2;
            mult2++;
            aux2 /= 10;
        }

        long long int resto2 = (soma2 * 10) % 11;
        if (resto2 == 10) {
            resto2 = 0;
        }

        if (resto2 == ultimo) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main () {
    long long int cpf;
  
    printf("\nInsira os dígitos do seu CPF: ");
    scanf("%lld", &cpf);

    int func = validaCPF(cpf);

    if (func == 1) {
        printf("CPF válido\n\n");
    } else {
        printf("CPF inválido\n\n");
    }
    
    return 0;
}