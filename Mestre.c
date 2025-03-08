#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar navio no tabuleiro
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

// Função para imprimir o tabuleiro
void imprimir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para sobrepor uma matriz de habilidade no tabuleiro
void aplicar_habilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[5][5], int origem_linha, int origem_coluna) {
    int offset = 2; // O centro da matriz de habilidade 5x5 é (2,2)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int l = origem_linha + i - offset;
            int c = origem_coluna + j - offset;
            if (l >= 0 && l < TAMANHO && c >= 0 && c < TAMANHO && habilidade[i][j] == 1) {
                tabuleiro[l][c] = HABILIDADE;
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de cone
void criar_matriz_cone(int habilidade[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de cruz
void criar_matriz_cruz(int habilidade[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de octaedro
void criar_matriz_octaedro(int habilidade[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
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

    // Criar e aplicar habilidades
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    criar_matriz_cone(cone);
    criar_matriz_cruz(cruz);
    criar_matriz_octaedro(octaedro);

    aplicar_habilidade(tabuleiro, cone, 2, 2); // Aplicar cone centrado em (2,2)
    aplicar_habilidade(tabuleiro, cruz, 7, 7); // Aplicar cruz centrado em (7,7)
    aplicar_habilidade(tabuleiro, octaedro, 5, 5); // Aplicar octaedro centrado em (5,5)

    imprimir_tabuleiro(tabuleiro);

    return 0;
}