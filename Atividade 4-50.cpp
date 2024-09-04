#include <stdio.h>
#include <string.h>

// Fun��o para realizar a compress�o RLE
void compressaoRLE(char *input, char *output) {
    int len = strlen(input); // Comprimento da string de entrada
    int count, i, j = 0;

    for (i = 0; i < len; i++) {
        // Conta o n�mero de vezes que o caractere se repete
        count = 1;
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Armazena o caractere e o n�mero de repeti��es na string de sa�da
        output[j++] = input[i];
        output[j++] = count + '0'; // Convertendo o n�mero para caractere
    }
    output[j] = '\0'; // Adiciona o terminador de string
}

int main() {
    char input[100];
    char output[200]; // O tamanho m�ximo da string comprimida pode ser o dobro da original

    printf("Digite a string para compress�o RLE: ");
    scanf("%s", input);

    compressaoRLE(input, output);

    printf("String comprimida: %s\n", output);

    return 0;
}


