#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializa o gerador de n�meros aleat�rios
    srand(time(0)); // Usa o tempo atual como semente para o gerador de n�meros aleat�rios

    // Gera um n�mero aleat�rio de 1 a 100
    int numeroAleatorio = (rand() % 100) + 1;

    // Exibe o n�mero aleat�rio gerado
    printf("N�mero aleat�rio gerado: %d\n", numeroAleatorio);

    return 0;
}

