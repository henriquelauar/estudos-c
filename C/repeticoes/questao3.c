// // Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>

int main() {
  int x, y;

  printf("Digite os valores de x e y: ");
  scanf("%d %d", &x, &y);

  while (x % 2 != 0 || y % 2 != 0 || x >= y) {
    if (x >= y) {
      printf("Erro: x deve ser menor que y");
      printf("Digite os valores de x e y: ");
      scanf("%d %d", &x, &y);
    }
  }

  printf("\n");

  int i = x, espaco = (y - i) / 2;

  while (i < y) {
    int asterisco = i, espaco2 = espaco;

    while (espaco2 > 0) {
      printf(" ");
      espaco2--;
    }

    while (asterisco > 0) {
      printf("*");
      asterisco--;
    }

    i = i + 2;
    espaco--;

    printf("\n\n");
  }

  return 0;
}