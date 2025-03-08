// Nível Novato

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

// Nível Aventureiro 

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
