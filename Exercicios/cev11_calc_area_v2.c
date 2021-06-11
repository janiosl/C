#include <stdio.h>

void linha()
{
    puts("===========================================");
}

float calc_area(float base, float altura)
{
    //Cálculo e exibição da área
    float area;
    area = base * altura;
    printf("Área calculada: %.1f metros\n", area);
    return area;
}

float calc_tinta(float area, float rendimento)
{
    //Cálculo da quantidade de litros de tinta
    float litros;
    litros = area / rendimento;
    printf("Serão necessários %.1f litros de tinta\npara pintar esta superfície\n", litros);
    return litros;
}

int main()
{
    float base;
    float altura;
    float area;
    float rendimento = 2.0;
    float litros;

    linha();
    puts("CALCULADORA DE ÁREA - VERSÃO 2.0");
    linha();

    //Entrada das dimensões da parede
    puts("Digite o comprimento da base em metros:");
    scanf("%f", &base);
    puts("Digite o comprimento da altura em metros:");
    scanf("%f", &altura);
    linha();

    area = calc_area(base, altura);
    litros = calc_tinta(area, rendimento);

    linha();
    puts("Programa encerrado. Obrigado!\nJanio Lima");
    linha();
    return 0;
}