// Henrique Sousa Lauar 21.2.4104 turma 32
#include <stdio.h>

int primo (int n) {
    int cont, i = 1;

    while (i <= n) {
        if ((n % i) == 0) {
            cont++;
        }
        i++;
    }

    if (cont == 2) {
        return 1;
    } else {
        return 0;
    }
}

int main () {
    int n, func;

    printf("\nDigite um número: ");
    scanf("%d", &n);
    func = primo(n);

    if (func == 1) {
        printf("\n%d é um número primo\n\n", n);
    } else {
        printf("\n%d não é um número primo\n\n", n);
    }

    return 0;
}