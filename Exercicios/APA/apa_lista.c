#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void)
{
    Lista* lst;                /*Declaração da lista não iniciada*/
    lst=lst_cria();            /*Cria a lista vazia*/
                               /*Insere diversos elementos*/
    lst=lst_insere(lst,23);
    lst=lst_insere(lst,45);
    lst=lst_insere(lst,56);
    lst=lst_insere(lst,78);
    lst_imprime(lst);           /*Imprime elementos da lisa*/
    puts("----------");
    lst=lst_retira(lst,78);     /*Remove elemento 78*/
    lst_imprime(lst);           /*Imprime elementos da lisa*/
    puts("----------");
    lst=lst_retira(lst,45);     /*Remove elemento 78*/
    lst_imprime(lst);           /*Imprime elementos da lisa*/
    puts("----------");
    lst_libera(lst);
    return 0;
}