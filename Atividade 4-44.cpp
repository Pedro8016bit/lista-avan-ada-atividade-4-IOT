#include <stdio.h>
#include <stdbool.h>

#define N 8

// Movimentos possíveis do cavalo no tabuleiro de xadrez
int movimentosX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int movimentosY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Função para verificar se a próxima posição é válida
bool isValido(int x, int y, int tabuleiro[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && tabuleiro[x][y] == -1);
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            printf(" %2d ", tabuleiro[x][y]);
        }
        printf("\n");
    }
}

// Função recursiva para resolver o problema do Passeio do Cavalo
bool resolverPasseioDoCavalo(int xAtual, int yAtual, int movimentoCount, int tabuleiro[N][N]) {
    int proxX, proxY;

    if (movimentoCount == N * N) {
        return true;
    }

    // Testa todos os próximos movimentos possíveis a partir da posição atual
    for (int i = 0; i < 8; i++) {
        proxX = xAtual + movimentosX[i];
        proxY = yAtual + movimentosY[i];

        if (isValido(proxX, proxY, tabuleiro)) {
            tabuleiro[proxX][proxY] = movimentoCount;

            if (resolverPasseioDoCavalo(proxX, proxY, movimentoCount + 1, tabuleiro)) {
                return true;
            } else {
                // Backtracking
                tabuleiro[proxX][proxY] = -1;
            }
        }
    }
    return false;
}

// Função principal
int main() {
    int tabuleiro[N][N];

    // Inicializa o tabuleiro com -1
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            tabuleiro[x][y] = -1;
        }
    }

    // Posição inicial do cavalo
    int xInicial = 0, yInicial = 0;
    tabuleiro[xInicial][yInicial] = 0;

    // Resolve o problema do Passeio do Cavalo
    if (resolverPasseioDoCavalo(xInicial, yInicial, 1, tabuleiro)) {
        imprimirTabuleiro(tabuleiro);
    } else {
        printf("Não existe uma solução.\n");
    }

    return 0;
}

