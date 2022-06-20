// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>

int main() {
    int linha, coluna;

    printf("Digite a linha e a coluna em que o bispo se encontra: ");
    scanf("%d %d", &linha, &coluna);

    printf("    ");

    for(int i = 1; i <= 8; i++) {
        printf("%3d", i);
    }

    printf("\n    ");
    
    for(int i = 1; i <= 24; i++) {
        printf("-");
    }

    printf("\n");

    for(int i = 1; i <= 8; i++){
        printf("%3d|",i);

        for (int k = 1; k <= 8; k++) {
            if (i == linha && k == coluna) {
                printf("  o");
            } else if (k + i == linha+coluna || i - k == linha-coluna) {
                printf("  x");
            } else {
                printf("  -");
            }
        }
        printf("\n");
    }
    return 0;
}
