#include <stdio.h>
#include <math.h>

#include "template.h"

int main()
{
    int angulo;
    float seno;
    float coseno;
    float radianos;
    
    //Entrada de dados
    cabecalho("ANÁLISE DE ÂNGULO");
    puts("Digite o ângulo a ser analisado:");
    scanf("%i", &angulo);
    linha(1);

    //Conversão de ângulo para radianos
    radianos = (float) (angulo * 0.017453);
    //Aplicação das funções para cálculo de seno e coseno
    seno = sin(angulo);
    coseno = cos(angulo);
    
    printf("Ângulo informado: %i°\nSeno: %.10f\nCoseno: %.10f\n",
        angulo, seno, coseno);

    rodape();
    return 0;
}