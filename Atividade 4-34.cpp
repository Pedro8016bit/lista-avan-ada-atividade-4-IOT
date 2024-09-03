#include <stdio.h>

// Fun��o para mesclar dois sub-arrays
void merge(int arr[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Arrays tempor�rios
    int L[n1], R[n2];

    // Copia os dados para os arrays tempor�rios L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[esquerda + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    // Mescla os arrays tempor�rios de volta em arr[]
    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fun��o recursiva para o algoritmo de Merge Sort
void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        // Mescla as duas metades
        merge(arr, esquerda, meio, direita);
    }
}

// Fun��o para imprimir o array
void imprimeArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Pergunta ao usu�rio o tamanho do array
    printf("Digite o n�mero de elementos no array: ");
    scanf("%d", &n);

    int arr[n]; // Define o array com o tamanho especificado pelo usu�rio

    // L� os elementos do array a partir da entrada do usu�rio
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array original:\n");
    imprimeArray(arr, n);

    // Ordena o array usando Merge Sort
    mergeSort(arr, 0, n - 1);

    printf("Array ordenado:\n");
    imprimeArray(arr, n);

    return 0;
}

