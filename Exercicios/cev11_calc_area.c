#include <stdio.h>

void linha()
{
    puts("===========================================");
}

int main()
{
    float base;
    float altura;
    float area;
    float rendimento = 2.0;
    float litros;

    linha();
    puts("CALCULADORA DE ÁREA - VERSÃO 1.0");
    linha();

    //Entrada das dimensões da parede
    puts("Digite o comprimento da base em metros:");
    scanf("%f", &base);
    puts("Digite o comprimento da altura em metros:");
    scanf("%f", &altura);
    linha();

    //Cálculo e exibição da área
    area = base * altura;
    printf("Área da parede: %.1f metros\n", area);

    //Cálculo da quantidade de litros de tinta
    litros = area / rendimento;
    printf("Serão necessários %.1f litros de tinta\npara pintar este parede\n", litros);

    linha();
    puts("Programa encerrado. Obrigado!\nJanio Lima");
    linha();
    return 0;
}