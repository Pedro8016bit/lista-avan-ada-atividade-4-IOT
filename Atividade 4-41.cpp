#include <stdio.h>
#include <string.h>

// Fun��o para cifrar o texto usando a cifra de C�sar
void cifraDeCesar(char mensagem[], int deslocamento) {
    char caractere;
    for (int i = 0; mensagem[i] != '\0'; i++) {
        caractere = mensagem[i];

        // Verifica se o caractere � uma letra mai�scula
        if (caractere >= 'A' && caractere <= 'Z') {
            caractere = caractere + deslocamento;

            // Se passar de 'Z', retorna ao in�cio do alfabeto
            if (caractere > 'Z') {
                caractere = caractere - 'Z' + 'A' - 1;
            }

            mensagem[i] = caractere;
        }
        // Verifica se o caractere � uma letra min�scula
        else if (caractere >= 'a' && caractere <= 'z') {
            caractere = caractere + deslocamento;

            // Se passar de 'z', retorna ao in�cio do alfabeto
            if (caractere > 'z') {
                caractere = caractere - 'z' + 'a' - 1;
            }

            mensagem[i] = caractere;
        }
    }
}

int main() {
    char mensagem[100];
    int deslocamento;

    printf("Digite uma mensagem para cifrar: ");
    fgets(mensagem, sizeof(mensagem), stdin);
    mensagem[strcspn(mensagem, "\n")] = 0;  // Remove o '\n' lido pelo fgets

    printf("Digite o deslocamento (chave): ");
    scanf("%d", &deslocamento);

    cifraDeCesar(mensagem, deslocamento);

    printf("Mensagem cifrada: %s\n", mensagem);

    return 0;
}

