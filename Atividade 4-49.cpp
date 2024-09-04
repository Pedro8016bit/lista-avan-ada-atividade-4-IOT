#include <stdio.h>
#include <stdbool.h>

bool reconhecerPadrao(int vetor[], int n, int padrao[], int m) {
    // Percorre o vetor principal até a posição onde a subsequência pode caber
    for (int i = 0; i <= n - m; i++) {
        bool encontrado = true;

        // Verifica se o padrão começa na posição atual do vetor
        for (int j = 0; j < m; j++) {
            if (vetor[i + j] != padrao[j]) {
                encontrado = false;
                break;
            }
        }

        // Se o padrão foi encontrado, retorna true
        if (encontrado) {
            return true;
        }
    }

    // Se o loop terminar sem encontrar o padrão, retorna false
    return false;
}

int main() {
    int vetor[] = {1, 3, 9, 7, 3, 4, 1, 5, 3, 7};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    int padrao[] = {3, 4, 1};
    int m = sizeof(padrao) / sizeof(padrao[0]);

    if (reconhecerPadrao(vetor, n, padrao, m)) {
        printf("Padrão encontrado no vetor.\n");
    } else {
        printf("Padrão não encontrado no vetor.\n");
    }

    return 0;
}

