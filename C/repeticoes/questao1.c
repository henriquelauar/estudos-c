// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>

long long fat ( int n ) {
    int i = 1, fatorial = 1;
    while ( i <= n ) {
        fatorial = fatorial * i;
        i++;
    }
    return fatorial;
}

int main () {
    int n;
    long long func;

    printf("\nDigite um número: ");
    scanf("%d", &n);

    func = fat(n);
    printf("\n%d! = %lld\n\n", n, func);

    return 0;
}