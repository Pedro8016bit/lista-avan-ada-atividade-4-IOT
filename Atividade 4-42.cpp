#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(0)); // Usa o tempo atual como semente para o gerador de números aleatórios

    // Gera um número aleatório de 1 a 100
    int numeroAleatorio = (rand() % 100) + 1;

    // Exibe o número aleatório gerado
    printf("Número aleatório gerado: %d\n", numeroAleatorio);

    return 0;
}

