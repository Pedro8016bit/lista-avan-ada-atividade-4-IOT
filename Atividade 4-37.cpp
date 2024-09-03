#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Define o tamanho m�ximo da fila
#define TAMANHO_MAXIMO 100

// Define a estrutura da fila
typedef struct {
    int itens[TAMANHO_MAXIMO];
    int frente;
    int tras;
} Fila;

// Fun��o para inicializar a fila
void inicializaFila(Fila* fila) {
    fila->frente = -1;
    fila->tras = -1;
}

// Fun��o para verificar se a fila est� vazia
int isEmpty(Fila* fila) {
    return fila->frente == -1;
}

// Fun��o para verificar se a fila est� cheia
int isFull(Fila* fila) {
    return fila->tras == TAMANHO_MAXIMO - 1;
}

// Fun��o para adicionar um elemento � fila (enqueue)
void enqueue(Fila* fila, int item) {
    if (isFull(fila)) {
        printf("Erro: Fila cheia. N�o � poss�vel adicionar o elemento %d.\n", item);
        return;
    }
    if (isEmpty(fila)) {
        fila->frente = 0;
    }
    fila->itens[++fila->tras] = item;
    printf("Elemento %d adicionado � fila.\n", item);
}

// Fun��o para remover um elemento da fila (dequeue)
int dequeue(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Erro: Fila vazia. N�o � poss�vel remover um elemento.\n");
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

// Fun��o para obter o elemento da frente da fila sem remov�-lo (front)
int front(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Erro: Fila vazia. N�o h� elementos para acessar.\n");
        return -1; // Retorna -1 como sinal de erro
    }
    return fila->itens[fila->frente];
}

// Fun��o principal para demonstrar o uso da fila
int main() {
	setlocale(LC_ALL, "");
    Fila fila;
    inicializaFila(&fila);

    // Demonstra��o de uso das opera��es da fila
    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);

    printf("Elemento na frente da fila: %d\n", front(&fila));

    printf("Elemento removido da fila: %d\n", dequeue(&fila));
    printf("Elemento removido da fila: %d\n", dequeue(&fila));

    printf("Fila est� vazia? %s\n", isEmpty(&fila) ? "Sim" : "N�o");

    return 0;
}

