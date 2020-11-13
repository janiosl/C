#include <stdio.h>
#include "encrypt.h"
#include "linha.h"

int main() {
    char msg[80];
    puts("Digite a mensagem para ser codificada: ");
    fgets(msg, 80, stdin);

    encrypt(msg);
    printf("\nResultado:\n%s\n", msg);
    printf("Feito com make\n");
    linha();
    
    return 0;
}