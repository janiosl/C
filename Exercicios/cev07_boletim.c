#include <stdio.h>
#include <stdlib.h>

int main()
{
    float media;
    char nota1Str[10];
    char nota2Str[10];

    puts("Digite a primeira nota: ");
    fgets(nota1Str, 10, stdin);

    puts("Digite a segunda nota: ");
    fgets(nota2Str, 10, stdin);

    media = (float)(atoi(nota1Str) + atoi(nota2Str)) / 2;

    printf("Média: %.2f\n", media);

    return 0;
}