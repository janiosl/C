#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    Lista* lst;          /*Cria uma variável com o tipo personalizado*/
    lst = lst_cria();    /*Cria uma lista vazia*/
    
    puts("==================================================");
    puts("Lista Encadeada");
    puts("==================================================\n");
    
    /*Uso da função de verifica de lista vaiza antes da inserção de elementos*/
    puts("Verificar lista vazia:\n1 = Lista vazia; 0 = Lista com elementos");
    int verifica;
    verifica = lst_vazia(lst);
    printf("Vazia? %i\n\n", verifica);
    
    
    /*Insere diversos elementos*/
    puts("==================================================\n");
    puts("Inserindo elementos na lista...\n");
    
    
    lst = lst_insere(lst, 23);
    lst = lst_insere(lst, 45);
    lst = lst_insere(lst, 33);
    lst = lst_insere(lst, 7);
    
    puts("Visualizar itens da lista\n");
    lst_imprime(lst);
    
    /*Uso da função de verifica de lista vaiza depois da inserção de elementos*/
    puts("Verificar lista vazia:\n1 = Lista vazia; 0 = Lista com elementos");
    verifica = lst_vazia(lst);
    printf("Vazia? %i\n", verifica);

    
    /*Busca de um elemento da lista*/
    puts("==================================================\n");
    
    int elem = 25; /*Valor procurado na lista*/
    Lista* elem_busca;
    elem_busca = lst_busca(lst, elem); /*Execução da busca*/
    
    /*Exibição do resultado da busca*/
    puts("\nBuscar elemento na lista");
    
    if (elem_busca != NULL) {
        printf("Elemento %i encontrado\n",  elem);
    } else
        printf("Elemento %i inexistente na lista\n", elem);
    
    /*Busca de um elemento da lista*/
    elem = 23; /*Valor procurado na lista*/
    elem_busca = lst_busca(lst, elem); /*Execução da busca*/
    
    /*Exibição do resultado da busca*/
    puts("\nBusca de elemento na lista");
    
    if (elem_busca != NULL) {
        printf("Elemento %i encontrado\n",  elem);
    } else
        printf("Elemento %i inexistente na lista\n", elem);
    
    
    /*Aplicação da função para remoção de um elemento*/
    puts("==================================================\n");
    
    elem = 45;
    printf("Remover elemento %i\n", elem);
    lst = lst_retira(lst, elem);
    
    puts("Visualizar itens da lista atualizada\n");
    lst_imprime(lst);

    elem = 7;
    printf("Remover elemento %i\n", elem);
    lst = lst_retira(lst, elem);
    
    puts("Visualizar itens da lista atualizada\n");
    lst_imprime(lst);
    
    /*Aplicação da função para liberar lista da memória*/
    puts("==================================================\n");
    
    puts("Liberando lista...\n");
    lst_libera(lst);
    
    return 0;
}