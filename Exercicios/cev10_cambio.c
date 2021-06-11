#include <stdio.h>

void linha()
{
    /*Cria uma linha na tela para organização das saídas*/
    puts("==============================================");
}

int main()
{
    float brl;
    float usd;
    float cambio;
    int tipo;

    linha();
    puts("CONVERSÃO DE MOEDAS - JANIO LIMA");
    linha();

    puts("Digite a taxa de câmbio atual:\nUSD $1.00 = R$: ");
    scanf("%f", &cambio);
    linha();

    puts("OPERAÇÕES DISPONÍVEIS: \n1. Real para Dólar (R$ -> USD)\n2. Dólar para Real (USD -> R$)");
    puts("Escolha o tipo de operação: ");
    scanf("%i", &tipo);
    linha();

    if (tipo == 1) {
        puts("Digite o valor em Reais: R$");
        scanf("%f", &brl);
        usd = (float) (brl / cambio);

        printf("Valor convertido: USD $%.2f\n", usd);

    }
    else if (tipo == 2) {
        puts("Digite o valor em Dólar: USD $");
        scanf("%f", &usd);
        brl = (float) (usd * cambio);

        printf("Valor convertido:  R$%.2f\n", brl);
    }
    else
        puts("Opção inválida");
    
    linha();
    puts("Programa concluído. Obrigado!");
    linha();

    return 0;
}