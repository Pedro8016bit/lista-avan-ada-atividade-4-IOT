#include <stdio.h>
#include <string.h>

// Função para cifrar o texto usando a cifra de César
void cifraDeCesar(char mensagem[], int deslocamento) {
    char caractere;
    for (int i = 0; mensagem[i] != '\0'; i++) {
        caractere = mensagem[i];

        // Verifica se o caractere é uma letra maiúscula
        if (caractere >= 'A' && caractere <= 'Z') {
            caractere = caractere + deslocamento;

            // Se passar de 'Z', retorna ao início do alfabeto
            if (caractere > 'Z') {
                caractere = caractere - 'Z' + 'A' - 1;
            }

            mensagem[i] = caractere;
        }
        // Verifica se o caractere é uma letra minúscula
        else if (caractere >= 'a' && caractere <= 'z') {
            caractere = caractere + deslocamento;

            // Se passar de 'z', retorna ao início do alfabeto
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

