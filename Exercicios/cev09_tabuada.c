#include <stdio.h>

int main()
{
    int numero;
    int k;

    puts("========================================");
    puts("TABUADA");
    puts("========================================");

    puts("Digite um número para saber a tabuada:");
    scanf("%i", &numero);
    puts("========================================");

    for (k = 1; k < 11; k++) {
        printf("%2i x %2i = %2i\n", numero, k, numero * k);
    }

    return 0;
}