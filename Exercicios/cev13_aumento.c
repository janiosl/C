#include <stdio.h>

void linha()
{
    puts("===========================================");
}

int main()
{
    float salario;
    float aumento = 0.15;
    float salario_novo;

    linha();
    puts("CALCULADORA DE AUMENTO SALARIAL");
    linha();

    puts("Digite o salário atual do empregado:");
    scanf("%f", &salario);

    salario_novo = salario + (salario * aumento);
    printf("O empregado recebeu um aumento de %.2f\nSeu novo salário é %.2f\n",
        salario * aumento, salario_novo);
    
    linha();
    puts("Programa encerrado.\nObrigado. Janio Lima");
    linha();

    return 0;
}