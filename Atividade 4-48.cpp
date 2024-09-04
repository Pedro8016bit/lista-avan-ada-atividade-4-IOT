#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para a função sleep()
#include <locale.h>

#define MAX_ANDARES 10 // Número máximo de andares no prédio

void simularMovimento(int andarAtual, int andarDestino) {
    if (andarAtual < andarDestino) {
        // Movendo para cima
        for (int i = andarAtual; i <= andarDestino; i++) {
            printf("Elevador no andar: %d\n", i);
            sleep(1); // Espera por 1 segundo
        }
    } else if (andarAtual > andarDestino) {
        // Movendo para baixo
        for (int i = andarAtual; i >= andarDestino; i--) {
            printf("Elevador no andar: %d\n", i);
            sleep(1); // Espera por 1 segundo
        }
    } else {
        // Se já estiver no andar desejado
        printf("Você já está no andar %d!\n", andarAtual);
    }
}

int main() {
   setlocale(LC_ALL,"");
    int andarAtual = 0; // Suponha que o elevador comece no térreo (andar 0)
    int andarDestino;

    printf("Simulação de Elevador\n");
    printf("O prédio tem %d andares (0 a %d).\n", MAX_ANDARES, MAX_ANDARES);

    while (1) {
        printf("Você está no andar %d.\n", andarAtual);
        printf("Escolha um andar de destino (0 a %d) ou -1 para sair: ", MAX_ANDARES);
        scanf("%d", &andarDestino);

        if (andarDestino == -1) {
            printf("Encerrando a simulação.\n");
            break;
        }

        if (andarDestino < 0 || andarDestino > MAX_ANDARES) {
            printf("Andar inválido. Por favor, escolha um andar entre 0 e %d.\n", MAX_ANDARES);
        } else {
            simularMovimento(andarAtual, andarDestino);
            andarAtual = andarDestino; // Atualiza o andar atual
        }
    }

    return 0;
}

