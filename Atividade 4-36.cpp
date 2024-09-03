#include <stdio.h>
#include <stdlib.h>

// Define o tamanho m�ximo da pilha
#define TAMANHO_MAXIMO 100

// Define a estrutura da pilha
typedef struct {
    int topo;
    int itens[TAMANHO_MAXIMO];
} Pilha;

// Fun��o para inicializar a pilha
void inicializaPilha(Pilha* pilha) {
    pilha->topo = -1;
}

// Fun��o para verificar se a pilha est� vazia
int isEmpty(Pilha* pilha) {
    return pilha->topo == -1;
}

// Fun��o para verificar se a pilha est� cheia
int isFull(Pilha* pilha) {
    return pilha->topo == TAMANHO_MAXIMO - 1;
}

// Fun��o para adicionar um elemento � pilha (push)
void push(Pilha* pilha, int item) {
    if (isFull(pilha)) {
        printf("Erro: Pilha cheia. N�o � poss�vel adicionar o elemento %d.\n", item);
        return;
    }
    pilha->itens[++pilha->topo] = item;
    printf("Elemento %d adicionado � pilha.\n", item);
}

// Fun��o para remover um elemento da pilha (pop)
int pop(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: Pilha vazia. N�o � poss�vel remover um elemento.\n");
        return -1; // Retorna -1 como sinal de erro
    }
    return pilha->itens[pilha->topo--];
}

// Fun��o para observar o elemento no topo da pilha (peek)
int peek(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: Pilha vazia. N�o h� elementos para observar.\n");
        return -1; // Retorna -1 como sinal de erro
    }
    return pilha->itens[pilha->topo];
}

int main() {
    Pilha pilha;
    inicializaPilha(&pilha);

    // Demonstra��o de uso das opera��es da pilha
    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    printf("Elemento no topo da pilha: %d\n", peek(&pilha));

    printf("Elemento removido da pilha: %d\n", pop(&pilha));
    printf("Elemento removido da pilha: %d\n", pop(&pilha));

    printf("Pilha est� vazia? %s\n", isEmpty(&pilha) ? "Sim" : "N�o");

    return 0;
}

