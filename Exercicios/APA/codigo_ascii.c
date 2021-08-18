#include <stdio.h>
int main(){
    int asc;
    char caractere;
    puts("Identificar codigo ASCII");
    puts("=====================================");
    printf("Digite o caractere desejado: ");
    scanf("%c", &caractere);
    //Identificação do código ascii do caractere desejado
    asc = caractere;
    //Exibição do resultado
    printf("Codigo ASCII para caractere \"%c\": %d\n", caractere, asc);
    puts("=====================================");
    return 0;
}