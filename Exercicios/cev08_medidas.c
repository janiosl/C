#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cm;
    int mm;
    float m;

    puts("Digite uma medida em metros:");
    scanf("%f", &m);

    cm = m * 100;
    mm = m * 1000;

    puts("--------------------------------------");

    printf("Conversão em cm: %i cm\n", cm);
    printf("Conversão em mm: %i mm\n", mm);

    puts("--------------------------------------");

    return 0;
}