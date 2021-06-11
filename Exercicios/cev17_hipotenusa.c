#include <stdio.h>
#include <math.h>
#include "template.h"

float hipo(float adj, float opo)
{
    /*Função para cálculo da hipotenusa
    Teorema de Pitágoras: h² = adj² + opo²*/
    float h2;
    float h;

    h2 = (pow(adj, 2) + pow(opo, 2));
    h = sqrt(h2);

    return h;
}

int main()
{
    float cateto_a;
    float cateto_o;
    float hipotenusa;

    cabecalho("CALCULADORA DE HIPOTENUSA");
    //Entradas de dados pelo usuário
    puts("Digite a medida do cateto adjascente:");
    scanf("%f", &cateto_a);
    puts("Digite a medida do cateto oposto:");
    scanf("%f", &cateto_o);

    linha(1);
    hipotenusa = hipo(cateto_a, cateto_o);
    printf("Hipotenusa: %.4f\n", hipotenusa);

    rodape();
    return 0;
}