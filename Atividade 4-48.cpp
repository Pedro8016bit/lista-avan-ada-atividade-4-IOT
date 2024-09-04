#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para a fun��o sleep()
#include <locale.h>

#define MAX_ANDARES 10 // N�mero m�ximo de andares no pr�dio

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
        // Se j� estiver no andar desejado
        printf("Voc� j� est� no andar %d!\n", andarAtual);
    }
}

int main() {
   setlocale(LC_ALL,"");
    int andarAtual = 0; // Suponha que o elevador comece no t�rreo (andar 0)
    int andarDestino;

    printf("Simula��o de Elevador\n");
    printf("O pr�dio tem %d andares (0 a %d).\n", MAX_ANDARES, MAX_ANDARES);

    while (1) {
        printf("Voc� est� no andar %d.\n", andarAtual);
        printf("Escolha um andar de destino (0 a %d) ou -1 para sair: ", MAX_ANDARES);
        scanf("%d", &andarDestino);

        if (andarDestino == -1) {
            printf("Encerrando a simula��o.\n");
            break;
        }

        if (andarDestino < 0 || andarDestino > MAX_ANDARES) {
            printf("Andar inv�lido. Por favor, escolha um andar entre 0 e %d.\n", MAX_ANDARES);
        } else {
            simularMovimento(andarAtual, andarDestino);
            andarAtual = andarDestino; // Atualiza o andar atual
        }
    }

    return 0;
}

