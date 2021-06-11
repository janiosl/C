#include <stdio.h>

void linha(int tipo)
{
    if (tipo == 2)
        puts("===========================================");
    else if (tipo == 1)
        puts("--------------------------------------------");
}

void cabecalho(char title[])
{
    linha(2);
    printf("%s\n", title);
    linha(2);
}

void rodape()
{
    linha(2);
    puts("Programa Encerrado.\nObrigado. Janio Lima");
    linha(2);
}

int main()
{
    float c;
    float f;
    char title[] = "GRAUS CELSIUS PARA FAHRENHEIT";

    cabecalho(title);

    puts("Digite a temperatura em Graus Célcius °C:");
    scanf("%f", &c);

    f = ((c * 9) / 5) + 32;

    linha(1);
    printf("A temperatura convertida é %.1f°F\n", f);

    rodape();

    return 0;
}