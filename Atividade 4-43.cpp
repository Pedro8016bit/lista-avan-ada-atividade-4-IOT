#include <stdio.h>

// Fun��o para encontrar a maior subsequ�ncia crescente
int maiorSubsequenciaCrescente(int vetor[], int tamanho) {
    int lis[tamanho]; // Array para armazenar o comprimento das subsequ�ncias
    int i, j, max = 0;

    // Inicializa todas as posi��es de lis com 1, pois a menor subsequ�ncia tem pelo menos um elemento
    for (i = 0; i < tamanho; i++) {
        lis[i] = 1;
    }

    // Calcula o comprimento da maior subsequ�ncia crescente em vetor
    for (i = 1; i < tamanho; i++) {
        for (j = 0; j < i; j++) {
            if (vetor[i] > vetor[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Encontra o valor m�ximo no array lis
    for (i = 0; i < tamanho; i++) {
        if (max < lis[i]) {
            max = lis[i];
        }
    }

    return max;
}

int main() {
    int vetor[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int resultado = maiorSubsequenciaCrescente(vetor, tamanho);
    printf("O comprimento da maior subsequ�ncia crescente �: %d\n", resultado);

    return 0;
}

