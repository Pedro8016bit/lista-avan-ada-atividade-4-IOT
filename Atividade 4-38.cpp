#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define o tamanho m�ximo para a express�o
#define TAMANHO_MAXIMO 100

// Estrutura para a pilha
typedef struct {
    int topo;
    char itens[TAMANHO_MAXIMO];
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
void push(Pilha* pilha, char item) {
    if (isFull(pilha)) {
        printf("Erro: Pilha cheia. N�o � poss�vel adicionar o elemento '%c'.\n", item);
        return;
    }
    pilha->itens[++pilha->topo] = item;
}

// Fun��o para remover um elemento da pilha (pop)
char pop(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: Pilha vazia. N�o � poss�vel remover um elemento.\n");
        return '\0'; // Retorna '\0' como sinal de erro
    }
    return pilha->itens[pilha->topo--];
}

// Fun��o para obter o elemento no topo da pilha sem remov�-lo (peek)
char peek(Pilha* pilha) {
    if (isEmpty(pilha)) {
        return '\0';
    }
    return pilha->itens[pilha->topo];
}

// Fun��o para verificar se um caractere � um operador
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Fun��o para determinar a preced�ncia dos operadores
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

// Fun��o para converter a express�o infixa para p�s-fixa
void infixParaPosfixa(char* infix, char* posfixa) {
    Pilha pilha;
    inicializaPilha(&pilha);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // Se o caractere � um operando, adicione � express�o p�s-fixa
        if (isalnum(c)) {
            posfixa[j++] = c;
        }
        // Se o caractere � '(', empilhe-o
        else if (c == '(') {
            push(&pilha, c);
        }
        // Se o caractere � ')', desempilhe at� encontrar '('
        else if (c == ')') {
            while (!isEmpty(&pilha) && peek(&pilha) != '(') {
                posfixa[j++] = pop(&pilha);
            }
            pop(&pilha); // Remove '(' da pilha
        }
        // Se o caractere � um operador
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

    posfixa[j] = '\0'; // Termina a string p�s-fixa
}

int main() {
    char infix[TAMANHO_MAXIMO], posfixa[TAMANHO_MAXIMO];

    // Entrada da express�o infixa
    printf("Digite a express�o infixa: ");
    scanf("%s", infix);

    // Converter infixa para p�s-fixa
    infixParaPosfixa(infix, posfixa);

    // Sa�da da express�o p�s-fixa
    printf("Express�o p�s-fixa: %s\n", posfixa);

    return 0;
}

