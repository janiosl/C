#include <stdio.h>
#include <math.h>
#include "template.h"

int main()
{
    float numero;
    int truncado;

    cabecalho("EXIBIR PORÇÃO INTEIRA DE UM NÚMERO");

    puts("Digite um número com casas decimais:");
    scanf("%f", &numero);
    linha(1);

    truncado = trunc(numero);
    printf("A porção inteira de %f é %i\n", numero, truncado);

    rodape();
    return 0;
}