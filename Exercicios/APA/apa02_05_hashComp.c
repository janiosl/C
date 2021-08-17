#include <stdio.h>
#include <stdlib.h>
/*--------------------------------------------------------------------------
  Função identifica a ordem alfabética de uma letra
  Argumentos:
      str char => Letra a ser analisada
  Retorno:
      int ord => Posição da letra no alfabeto (começando em 1)
--------------------------------------------------------------------------*/
int ordem(char letra){
    int ord;
    switch( letra ){
        case 'A':
            ord = 1;
            break;
        case 'B':
            ord = 2;
            break;
        case 'C':
            ord = 3;
            break;
        case 'D':
            ord = 4;
            break;
        case 'E':
            ord = 5;
            break;
        case 'F':
            ord = 6;
            break;
        case 'G':
            ord = 7;
            break;
        case 'H':
            ord = 8;
            break;
        case 'I':
            ord = 9;
            break;
        case 'J':
            ord = 10;
            break;
        case 'K':
            ord = 11;
            break;
        case 'L':
            ord = 12;
            break;
        case 'M':
            ord = 13;
            break;                                                                                                                                                                                                                        
        //alfa = 'NOPQRSTUVWXYZ'
        //Este trecho é temporário. Enquanto não digito as outras letras
        default:
            puts("Ordem no alfabeto: ");
            scanf("%d", &ord);
    }
    return ord;
}
/*--------------------------------------------------------------------------
Função Calcula a função hash para definir a posição da letra na tabela
Argumentos:
    int ord => Ordem da letra no alfabeto
Retorno:
    int pos => Calculada baseada na função h(char) = (ordem alfabética)%5
--------------------------------------------------------------------------*/
int h(int ord){
    int pos;
    pos = ord % 5;
    return pos;
}
/*--------------------------------------------------------------------------
Programa Principal
--------------------------------------------------------------------------*/
int main(){
    char letra;
    puts("Letra: ");
    scanf("%c", &letra);
    int ord;
    ord = ordem(letra);
    int pos;
    pos = h(ord);
    puts("----------------------");
    puts("Letra : Pos Hash Table");
    printf("  %c   :       ", letra);
    printf("%d\n", pos);
    puts("----------------------");
    return 0;
}