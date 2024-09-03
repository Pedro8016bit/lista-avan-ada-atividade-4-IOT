#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Define o tamanho máximo da fila
#define TAMANHO_MAXIMO 100

// Define a estrutura da fila
typedef struct {
    int itens[TAMANHO_MAXIMO];
    int frente;
    int tras;
} Fila;

// Função para inicializar a fila
void inicializaFila(Fila* fila) {
    fila->frente = -1;
    fila->tras = -1;
}

// Função para verificar se a fila está vazia
int isEmpty(Fila* fila) {
    return fila->frente == -1;
}

// Função para verificar se a fila está cheia
int isFull(Fila* fila) {
    return fila->tras == TAMANHO_MAXIMO - 1;
}

// Função para adicionar um elemento à fila (enqueue)
void enqueue(Fila* fila, int item) {
    if (isFull(fila)) {
        printf("Erro: Fila cheia. Não é possível adicionar o elemento %d.\n", item);
        return;
    }
    if (isEmpty(fila)) {
        fila->frente = 0;
    }
    fila->itens[++fila->tras] = item;
    printf("Elemento %d adicionado à fila.\n", item);
}

// Função para remover um elemento da fila (dequeue)
int dequeue(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Erro: Fila vazia. Não é possível remover um elemento.\n");
        return -1; // Retorna -1 como sinal de erro
    }
    int item = fila->itens[fila->frente];
    if (fila->frente == fila->tras) {
        // Fila volta ao estado vazio
        fila->frente = -1;
        fila->tras = -1;
    } else {
        fila->frente++;
    }
    return item;
}

// Função para obter o elemento da frente da fila sem removê-lo (front)
int front(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Erro: Fila vazia. Não há elementos para acessar.\n");
        return -1; // Retorna -1 como sinal de erro
    }
    return fila->itens[fila->frente];
}

// Função principal para demonstrar o uso da fila
int main() {
	setlocale(LC_ALL, "");
    Fila fila;
    inicializaFila(&fila);

    // Demonstração de uso das operações da fila
    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);

    printf("Elemento na frente da fila: %d\n", front(&fila));

    printf("Elemento removido da fila: %d\n", dequeue(&fila));
    printf("Elemento removido da fila: %d\n", dequeue(&fila));

    printf("Fila está vazia? %s\n", isEmpty(&fila) ? "Sim" : "Não");

    return 0;
}

