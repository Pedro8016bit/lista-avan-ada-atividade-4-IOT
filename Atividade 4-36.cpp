#include <stdio.h>
#include <stdlib.h>

// Define o tamanho máximo da pilha
#define TAMANHO_MAXIMO 100

// Define a estrutura da pilha
typedef struct {
    int topo;
    int itens[TAMANHO_MAXIMO];
} Pilha;

// Função para inicializar a pilha
void inicializaPilha(Pilha* pilha) {
    pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
int isEmpty(Pilha* pilha) {
    return pilha->topo == -1;
}

// Função para verificar se a pilha está cheia
int isFull(Pilha* pilha) {
    return pilha->topo == TAMANHO_MAXIMO - 1;
}

// Função para adicionar um elemento à pilha (push)
void push(Pilha* pilha, int item) {
    if (isFull(pilha)) {
        printf("Erro: Pilha cheia. Não é possível adicionar o elemento %d.\n", item);
        return;
    }
    pilha->itens[++pilha->topo] = item;
    printf("Elemento %d adicionado à pilha.\n", item);
}

// Função para remover um elemento da pilha (pop)
int pop(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: Pilha vazia. Não é possível remover um elemento.\n");
        return -1; // Retorna -1 como sinal de erro
    }
    return pilha->itens[pilha->topo--];
}

// Função para observar o elemento no topo da pilha (peek)
int peek(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: Pilha vazia. Não há elementos para observar.\n");
        return -1; // Retorna -1 como sinal de erro
    }
    return pilha->itens[pilha->topo];
}

int main() {
    Pilha pilha;
    inicializaPilha(&pilha);

    // Demonstração de uso das operações da pilha
    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    printf("Elemento no topo da pilha: %d\n", peek(&pilha));

    printf("Elemento removido da pilha: %d\n", pop(&pilha));
    printf("Elemento removido da pilha: %d\n", pop(&pilha));

    printf("Pilha está vazia? %s\n", isEmpty(&pilha) ? "Sim" : "Não");

    return 0;
}

