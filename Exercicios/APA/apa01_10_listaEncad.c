#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
int main(){
    /*Criação da lista ordenada*/
    /*-------------------------*/
    /*Cria uma variável com o tipo personalizado*/
    Lista* lst_ord;
    /*Cria uma lista vazia*/
    lst_ord = lst_cria();
    puts("==================================================");
    puts("Lista Encadeada Ordenada");
    puts("==================================================\n");
    /*Insere diversos elementos*/
    /*-------------------------*/
    puts("Inserindo elementos na lista...\n");
    lst_ord = lst_insere_ordenado(lst_ord, 23);
    lst_ord = lst_insere_ordenado(lst_ord, 45);
    lst_ord = lst_insere_ordenado(lst_ord, 33);
    lst_ord = lst_insere_ordenado(lst_ord, 70);
    /*Visualiza elementos*/
    /*-------------------*/
    puts("Visualizar itens da lista ORIGINAL\n");
    lst_imprime(lst_ord);
    /*Realizando inversão da lista*/
    /*----------------------------*/
    puts("==================================================");
    puts("Invertendo Lista Encadeada");
    puts("==================================================\n");
    Lista* invertida;
    invertida = lst_inv(lst_ord);
    puts("Visualizar itens da lista INVERTIDA\n");
    lst_imprime(invertida);
    puts("Liberando lista...\n");
    lst_libera(lst_ord);
    lst_libera(invertida);
    return 0;
}   