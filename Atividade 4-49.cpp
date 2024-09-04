#include <stdio.h>
#include <stdbool.h>

bool reconhecerPadrao(int vetor[], int n, int padrao[], int m) {
    // Percorre o vetor principal at� a posi��o onde a subsequ�ncia pode caber
    for (int i = 0; i <= n - m; i++) {
        bool encontrado = true;

        // Verifica se o padr�o come�a na posi��o atual do vetor
        for (int j = 0; j < m; j++) {
            if (vetor[i + j] != padrao[j]) {
                encontrado = false;
                break;
            }
        }

        // Se o padr�o foi encontrado, retorna true
        if (encontrado) {
            return true;
        }
    }

    // Se o loop terminar sem encontrar o padr�o, retorna false
    return false;
}

int main() {
    int vetor[] = {1, 3, 9, 7, 3, 4, 1, 5, 3, 7};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    int padrao[] = {3, 4, 1};
    int m = sizeof(padrao) / sizeof(padrao[0]);

    if (reconhecerPadrao(vetor, n, padrao, m)) {
        printf("Padr�o encontrado no vetor.\n");
    } else {
        printf("Padr�o n�o encontrado no vetor.\n");
    }

    return 0;
}

