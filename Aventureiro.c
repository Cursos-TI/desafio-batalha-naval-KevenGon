#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

void inicializar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int posicionar_navio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < NAVIO; i++) {
        int l = linha + (diagonal ? i : (direcao ? i : 0));
        int c = coluna + (diagonal ? i : (direcao ? 0 : i));
        
        if (l >= TAMANHO || c >= TAMANHO || tabuleiro[l][c] == NAVIO) {
            return 0; // posição inválida ou sobreposição
        }
    }

    for (int i = 0; i < NAVIO; i++) {
        int l = linha + (diagonal ? i : (direcao ? i : 0));
        int c = coluna + (diagonal ? i : (direcao ? 0 : i));
        tabuleiro[l][c] = NAVIO;
    }

    return 1;
}

void imprimir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    inicializar_tabuleiro(tabuleiro);

    // Posicionar navios horizontais/verticais
    posicionar_navio(tabuleiro, 0, 0, 1, 0); // navio horizontal
    posicionar_navio(tabuleiro, 3, 0, 0, 0); // navio vertical

    // Posicionar navios diagonais
    posicionar_navio(tabuleiro, 5, 5, 0, 1); // navio diagonal crescente
    posicionar_navio(tabuleiro, 9, 0, 0, 2); // navio diagonal decrescente

    imprimir_tabuleiro(tabuleiro);

    return 0;
}