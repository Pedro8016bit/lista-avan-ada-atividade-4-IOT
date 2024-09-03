#include <stdio.h>

// Função para encontrar a maior subsequência crescente
int maiorSubsequenciaCrescente(int vetor[], int tamanho) {
    int lis[tamanho]; // Array para armazenar o comprimento das subsequências
    int i, j, max = 0;

    // Inicializa todas as posições de lis com 1, pois a menor subsequência tem pelo menos um elemento
    for (i = 0; i < tamanho; i++) {
        lis[i] = 1;
    }

    // Calcula o comprimento da maior subsequência crescente em vetor
    for (i = 1; i < tamanho; i++) {
        for (j = 0; j < i; j++) {
            if (vetor[i] > vetor[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Encontra o valor máximo no array lis
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
    printf("O comprimento da maior subsequência crescente é: %d\n", resultado);

    return 0;
}

