#include <stdio.h>

#define TAM 10
#define NAV 3
#define MAR 0
#define TEM_NAVIO 3

//tabuleiro 
void mostrarTabuleiro(int tab[TAM][TAM]) {
    printf("Aqui ta o tabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}
int main() {

    int tabuleiro[TAM][TAM] = {0};

    // navio deitado
    int linhah = 7;
    int colunah = 1;

    //navio em pé
    int linhav = 0;
    int colunav = 6;


    if (colunah + NAV > TAM) {
        printf("ihh... o navio deitado ta muito grande\n");
        return 1;
    }

    if (linhav + NAV > TAM) {
        printf("erro: navio em pé nao cabe ali\n");
        return 1;
    }

    int bateu = 0;
    for (int i = 0; i < NAV; i++) {
        if (tabuleiro[linhah][colunah + i] != MAR || tabuleiro[linhav + i][colunav] != MAR) {
            bateu = 1;
            break;
        }
    }

    if (bateu) {
        printf("erro: os navios tão colidindo!\n");
        return 1;
    }

    //navio deitado.
    for (int i = 0; i < NAV; i++) {
        tabuleiro[linhah][colunah + i] = TEM_NAVIO;
    }

    //navio em pé.
    for (int i = 0; i < NAV; i++) {
        tabuleiro[linhav + i][colunav] = TEM_NAVIO;
    }
    mostrarTabuleiro(tabuleiro);

    return 0;
}



