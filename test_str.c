#include <stdio.h>
#include <string.h>
int main() {
    char palavra[50] = "Palavra procurada";
    char frase[50] = "Palavra procurada na frase";
    //printf("Digite a palavra procurada: ");
    //fgets(palavra, 50, stdin);
    //scanf("%50s", &palavra);
    if (strstr(frase, palavra)) {
        printf("Palavra '%s' encontrada na frase\n'%s'", palavra, frase);
    }
    else {
        printf("Palavra '%s' não encontrada na frase\n'%s'", palavra, frase);
    }
    return 0;
}