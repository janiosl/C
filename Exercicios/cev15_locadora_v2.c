#include <stdio.h>
#include "template.h"

int main()
{
    int km;
    int dias;
    float total_dias;
    float total_km;
    float custo_total;

    //VALORES PARA BASE DE CÁLCULO
    #define TAXA_DIA 60.00;
    #define TAXA_KM 0.15;

    cabecalho("LOCADORA J S/A");

    puts("Informe a quantidade de dias da locação:");
    scanf("%i", &dias);
    puts("Informe a quantidade de quilômetros rodados:");
    scanf("%i", &km);

    linha(1);

    total_dias = dias * TAXA_DIA;
    total_km = km * TAXA_KM;

    printf("R$%10.2f - Custo diárias\nR$%10.2f - Custo quilometragem\n",
        total_dias,
        total_km);
    linha(1);

    custo_total = total_dias + total_km;
    printf("R$%10.2f - TOTAL A PAGAR\n", custo_total);

    rodape();

    return 0;
}