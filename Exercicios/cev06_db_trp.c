#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Com a inclusão da biblioteca math.h a compilação deve seguir o padrão abaixo:
gcc programa.c -lm -o programa
*/

int main()
{
    char numeroStr[10];
    int numero;
    int db;
    int trp;
    int raiz;

    puts("Digite um número: ");
    fgets(numeroStr, 10, stdin);
    numero = atoi(numeroStr);

    db = numero * 2;
    trp = numero * 3;
    raiz = sqrt(numero);

    puts("----------------------------------------------");
    printf("Número digitado: %i\nDobro: %i\nTriplo: %i\nRaiz quadrada: %i\n",
        atoi(numeroStr), db, trp, raiz);
    puts("----------------------------------------------");

    return 0;
}