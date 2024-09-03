#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Define o tamanho m�ximo da pilha
#define TAMANHO_MAXIMO 100

// Estrutura para a pilha
typedef struct {
    int topo;
    double itens[TAMANHO_MAXIMO];
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
void push(Pilha* pilha, double item) {
    if (isFull(pilha)) {
        printf("Erro: Pilha cheia. N�o � poss�vel adicionar o elemento %lf.\n", item);
        return;
    }
    pilha->itens[++pilha->topo] = item;
}

// Fun��o para remover um elemento da pilha (pop)
double pop(Pilha* pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: Pilha vazia. N�o � poss�vel remover um elemento.\n");
        return -1; // Retorna -1 como sinal de erro
    }
    return pilha->itens[pilha->topo--];
}

// Fun��o para avaliar a express�o p�s-fixa
double avaliaPosfixa(char* expr) {
    Pilha pilha;
    inicializaPilha(&pilha);

    for (int i = 0; expr[i] != '\0'; i++) {
        // Se o caractere � um espa�o, continue para o pr�ximo
        if (isspace(expr[i])) continue;

        // Se o caractere � um operando, empilhe-o
        if (isdigit(expr[i])) {
            double num = 0;
            // Converte o caractere para n�mero
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--; // Corrige a posi��o de i ap�s sair do loop
            push(&pilha, num);
        }
        // Se o caractere � um operador, aplique-o
        else {
            double val2 = pop(&pilha);
            double val1 = pop(&pilha);

            switch (expr[i]) {
                case '+': push(&pilha, val1 + val2); break;
                case '-': push(&pilha, val1 - val2); break;
                case '*': push(&pilha, val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Erro: Divis�o por zero.\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&pilha, val1 / val2);
                    break;
                case '^': push(&pilha, pow(val1, val2)); break;
                default: 
                    printf("Erro: Operador inv�lido '%c'.\n", expr[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    // O resultado final deve estar no topo da pilha
    return pop(&pilha);
}

int main() {
    char expr[TAMANHO_MAXIMO];

    // Entrada da express�o p�s-fixa
    printf("Digite a express�o p�s-fixa: ");
    fgets(expr, TAMANHO_MAXIMO, stdin);

    // Avalia a express�o p�s-fixa
    double resultado = avaliaPosfixa(expr);

    // Sa�da do resultado
    printf("Resultado da express�o: %.2lf\n", resultado);

    return 0;
}

