#include <stdio.h>

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Função para verificar se houve um vencedor
char verificarVencedor(char tabuleiro[3][3]) {
    // Verifica linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return tabuleiro[i][0];
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return tabuleiro[0][i];
        }
    }

    // Verifica diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return tabuleiro[0][0];
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return tabuleiro[0][2];
    }

    // Verifica empate
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return ' '; // Ainda há jogadas possíveis
            }
        }
    }

    return 'E'; // Empate
}

// Função principal
int main() {
    char tabuleiro[3][3];
    int linha, coluna;
    char jogadorAtual = 'X';
    char vencedor = ' ';

    inicializarTabuleiro(tabuleiro);

    printf("Bem-vindo ao Jogo da Velha!\n");

    while (vencedor == ' ') {
        imprimirTabuleiro(tabuleiro);
        printf("Jogador %c, digite a linha e coluna (0, 1 ou 2): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        vencedor = verificarVencedor(tabuleiro);

        // Alterna jogadores
        if (vencedor == ' ') {
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
        }
    }

    imprimirTabuleiro(tabuleiro);

    if (vencedor == 'E') {
        printf("O jogo terminou em empate!\n");
    } else {
        printf("Parabéns! Jogador %c venceu!\n", vencedor);
    }

    return 0;
}

