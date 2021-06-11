#include <stdio.h>

void linha()
{
    puts("===========================================");
}


int main()
{
    float preco;
    float desconto = 0.05;
    float preco_novo;

    linha();
    puts("CALCULADORA DE DESCONTOS");
    linha();

    puts("Digite o preço do produto: ");
    scanf("%f", &preco);
    preco_novo = preco - (preco * desconto);
    printf("O produto recebeu um desconto de %.2f\nO novo preço é %.2f\n", preco * desconto, preco_novo);

    linha();
    puts("Programa Encerrado\nObrigado. Janio Lima");
    linha();
    
    return 0;
}