#include <stdio.h>

// Função para realizar o algoritmo de Insertion Sort
void insertionSort(int arr[], int n) {
    int i, j, chave;

    // Percorre o array a partir do segundo elemento
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insere a chave na posição correta
        arr[j + 1] = chave;
    }
}

// Função para imprimir o array
void imprimeArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Pergunta ao usuário o tamanho do array
    printf("Digite o número de elementos no array: ");
    scanf("%d", &n);

    int arr[n]; // Define o array com o tamanho especificado pelo usuário

    // Lê os elementos do array a partir da entrada do usuário
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array original:\n");
    imprimeArray(arr, n);

    // Ordena o array usando Insertion Sort
    insertionSort(arr, n);

    printf("Array ordenado:\n");
    imprimeArray(arr, n);

    return 0;
}

