#include <stdio.h>
#include <stdlib.h>

int main()
{
    char numeroStr[10];
    int suc;
    int ant;

    puts("Digite um número: ");
    fgets(numeroStr, 10, stdin);

    suc = atoi(numeroStr) + 1;
    ant = atoi(numeroStr) - 1;

    puts("----------------------------------------------");

    printf("Número digitado: %i\nSucessor: %i\nAntecessor: %i\n", atoi(numeroStr), suc, ant);

    puts("----------------------------------------------");

    return 0;
}