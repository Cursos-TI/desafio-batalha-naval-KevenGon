#include <stdio.h>

// Define o tamanho do tabuleiro
#define TAMANHO 10

// Função para inicializar o tabuleiro com zeros
void inicializaTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para posicionar navio horizontalmente
void posicionaNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha][coluna + i] = 3; // 3 representa navio
    }
}

// Função para posicionar navio verticalmente
void posicionaNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha + i][coluna] = 3; // 3 representa navio
    }
}

// Função para imprimir o tabuleiro
void imprimeTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define o tabuleiro
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro
    inicializaTabuleiro(tabuleiro);

    // Define o tamanho dos navios
    int tamanhoNavio = 3;

    // Posiciona os navios
    // Navio horizontal na posição (2, 3)
    posicionaNavioHorizontal(tabuleiro, 2, 3, tamanhoNavio);

    // Navio vertical na posição (5, 7)
    posicionaNavioVertical(tabuleiro, 5, 7, tamanhoNavio);

    // Imprime o tabuleiro
    imprimeTabuleiro(tabuleiro);

    return 0;
}