// Henrique Sousa Lauar 21.2.4104 Turma 32
#include <stdio.h>

int jogo () {
    int h1, m1, h2, m2, t;
    printf("\nDigite a hora e depois os minutos do ínicio do jogo: ");
    scanf("%d %d", &h1, &m1);
    
    printf("\nDigite a hora e depois os minutos do término do jogo: ");
    scanf("%d %d", &h2, &m2);
    
    if ( h1 == h2 && m1 == m2) {
        t = 1440;
    } else {
        if (m1>m2) {
            if (h1>h2) {
                t=(((h2+24) - h1) * 60) + ((m2+60) - m1);
            } else {
                t=((h2-h1) * 60) + ((m2+60) - m1);
            }
        } else {
            if (h1>h2) {
                t=(((h2+24) - h1) * 60) + (m2-m1);
            } else {
                t=((h2-h1) * 60) + (m2-m1);
            }
        }
    }

    return t;
} 

int main () {
    int partida;;
    partida = jogo();
    printf("\nTempo de jogo foi %d minutos\n\n", partida);
    return 0;
}