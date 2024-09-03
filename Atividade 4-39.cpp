#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Define o tamanho máximo da pilha
#define TAMANHO_MAXIMO 100

// Estrutura para a pilha
typedef struct {
    int topo;
    double itens[TAMANHO_MAXIMO];
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
void push(Pilha* pilha, double item) {
    if (isFull(pilha)) {
        printf("Erro: Pilha cheia. Não é possível adicionar o elemento %lf.\n", item);
        return;
    }
    pilha->itens[++pilha->topo] = item;
}

// Função para remover um elemento da pilha (pop)
double pop(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: Pilha vazia. Não é possível remover um elemento.\n");
        return -1; // Retorna -1 como sinal de erro
    }
    return pilha->itens[pilha->topo--];
}

// Função para avaliar a expressão pós-fixa
double avaliaPosfixa(char* expr) {
    Pilha pilha;
    inicializaPilha(&pilha);

    for (int i = 0; expr[i] != '\0'; i++) {
        // Se o caractere é um espaço, continue para o próximo
        if (isspace(expr[i])) continue;

        // Se o caractere é um operando, empilhe-o
        if (isdigit(expr[i])) {
            double num = 0;
            // Converte o caractere para número
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--; // Corrige a posição de i após sair do loop
            push(&pilha, num);
        }
        // Se o caractere é um operador, aplique-o
        else {
            double val2 = pop(&pilha);
            double val1 = pop(&pilha);

            switch (expr[i]) {
                case '+': push(&pilha, val1 + val2); break;
                case '-': push(&pilha, val1 - val2); break;
                case '*': push(&pilha, val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Erro: Divisão por zero.\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&pilha, val1 / val2);
                    break;
                case '^': push(&pilha, pow(val1, val2)); break;
                default: 
                    printf("Erro: Operador inválido '%c'.\n", expr[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    // O resultado final deve estar no topo da pilha
    return pop(&pilha);
}

int main() {
    char expr[TAMANHO_MAXIMO];

    // Entrada da expressão pós-fixa
    printf("Digite a expressão pós-fixa: ");
    fgets(expr, TAMANHO_MAXIMO, stdin);

    // Avalia a expressão pós-fixa
    double resultado = avaliaPosfixa(expr);

    // Saída do resultado
    printf("Resultado da expressão: %.2lf\n", resultado);

    return 0;
}

