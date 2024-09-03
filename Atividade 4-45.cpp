#include <stdio.h>
#include <stdbool.h>

#define N 9

// Função para imprimir o tabuleiro de Sudoku
void imprimirTabuleiro(int tabuleiro[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d ", tabuleiro[row][col]);
        }
        printf("\n");
    }
}

// Função para verificar se é seguro colocar o número em uma célula específica
bool isSeguro(int tabuleiro[N][N], int row, int col, int num) {
    // Verifica se o número já está na linha
    for (int x = 0; x < N; x++) {
        if (tabuleiro[row][x] == num) {
            return false;
        }
    }

    // Verifica se o número já está na coluna
    for (int x = 0; x < N; x++) {
        if (tabuleiro[x][col] == num) {
            return false;
        }
    }

    // Verifica se o número já está na subgrade 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Função principal de resolução usando backtracking
bool resolverSudoku(int tabuleiro[N][N]) {
    int row, col;
    bool vazio = false;

    // Encontra uma célula vazia (denotada por 0)
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (tabuleiro[row][col] == 0) {
                vazio = true;
                break;
            }
        }
        if (vazio) {
            break;
        }
    }

    // Se não há células vazias, o Sudoku está resolvido
    if (!vazio) {
        return true;
    }

    // Tenta números de 1 a 9 na célula vazia
    for (int num = 1; num <= 9; num++) {
        if (isSeguro(tabuleiro, row, col, num)) {
            tabuleiro[row][col] = num;

            // Recursivamente tenta preencher o tabuleiro
            if (resolverSudoku(tabuleiro)) {
                return true;
            }

            // Se falhar, desfaz a jogada (backtrack)
            tabuleiro[row][col] = 0;
        }
    }

    return false; // Retorna false se não puder ser resolvido
}

int main() {
    // Exemplo de Sudoku incompleto (0 representa células vazias)
    int tabuleiro[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (resolverSudoku(tabuleiro)) {
        imprimirTabuleiro(tabuleiro);
    } else {
        printf("Não existe uma solução para o Sudoku fornecido.\n");
    }

    return 0;
}

