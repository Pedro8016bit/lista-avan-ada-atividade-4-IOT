#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define o tamanho máximo para a expressão
#define TAMANHO_MAXIMO 100

// Estrutura para a pilha
typedef struct {
    int topo;
    char itens[TAMANHO_MAXIMO];
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
void push(Pilha* pilha, char item) {
    if (isFull(pilha)) {
        printf("Erro: Pilha cheia. Não é possível adicionar o elemento '%c'.\n", item);
        return;
    }
    pilha->itens[++pilha->topo] = item;
}

// Função para remover um elemento da pilha (pop)
char pop(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: Pilha vazia. Não é possível remover um elemento.\n");
        return '\0'; // Retorna '\0' como sinal de erro
    }
    return pilha->itens[pilha->topo--];
}

// Função para obter o elemento no topo da pilha sem removê-lo (peek)
char peek(Pilha* pilha) {
    if (isEmpty(pilha)) {
        return '\0';
    }
    return pilha->itens[pilha->topo];
}

// Função para verificar se um caractere é um operador
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Função para determinar a precedência dos operadores
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Função para converter a expressão infixa para pós-fixa
void infixParaPosfixa(char* infix, char* posfixa) {
    Pilha pilha;
    inicializaPilha(&pilha);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // Se o caractere é um operando, adicione à expressão pós-fixa
        if (isalnum(c)) {
            posfixa[j++] = c;
        }
        // Se o caractere é '(', empilhe-o
        else if (c == '(') {
            push(&pilha, c);
        }
        // Se o caractere é ')', desempilhe até encontrar '('
        else if (c == ')') {
            while (!isEmpty(&pilha) && peek(&pilha) != '(') {
                posfixa[j++] = pop(&pilha);
            }
            pop(&pilha); // Remove '(' da pilha
        }
        // Se o caractere é um operador
        else if (isOperator(c)) {
            while (!isEmpty(&pilha) && precedence(peek(&pilha)) >= precedence(c)) {
                posfixa[j++] = pop(&pilha);
            }
            push(&pilha, c);
        }
    }

    // Desempilha todos os operadores restantes na pilha
    while (!isEmpty(&pilha)) {
        posfixa[j++] = pop(&pilha);
    }

    posfixa[j] = '\0'; // Termina a string pós-fixa
}

int main() {
    char infix[TAMANHO_MAXIMO], posfixa[TAMANHO_MAXIMO];

    // Entrada da expressão infixa
    printf("Digite a expressão infixa: ");
    scanf("%s", infix);

    // Converter infixa para pós-fixa
    infixParaPosfixa(infix, posfixa);

    // Saída da expressão pós-fixa
    printf("Expressão pós-fixa: %s\n", posfixa);

    return 0;
}

