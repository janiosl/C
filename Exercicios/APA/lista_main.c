#include <stdio.h>
#include <stdlib.h>
#include <locale.h> /*Biblioteca para usar acentuação nas impressões*/
#include "lista.h"

int main() {
    setlocale(LC_ALL,"Portuguese"); /*Configuração de idioma dos caracteres*/
    
    Lista* lst;          /*Cria uma variável com o tipo personalizado*/
    lst = lst_cria();    /*Cria uma lista vazia*/
    
    
    /*Uso da função de verifica de lista vaiza antes da inserção de elementos*/
    puts("Verificar se a lista está vazia:\n1 = Vazia; 0 = Não vazia");
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
    
    puts("Impressão de itens da lista\n");
    lst_imprime(lst);
    puts("Lista concluída\n");
    
    /*Uso da função de verifica de lista vaiza depois da inserção de elementos*/
    puts("Verificar se a lista está vazia:\n1 = Vazia; 0 = Não vazia");
    verifica = lst_vazia(lst);
    printf("Vazia? %i\n", verifica);

    
    /*Busca de um elemento da lista*/
    puts("==================================================\n");
    
    int elem = 25; /*Valor procurado na lista*/
    Lista* elem_busca;
    elem_busca = lst_busca(lst, elem); /*Execução da busca*/
    
    /*Exibição do resultado da busca*/
    puts("\nBusca de elemento na lista");
    
    if (elem_busca != NULL) {
        printf("Elemento encontrado: %i\n",  elem);
    } else
        printf("Elemento %i inexistente na lista\n", elem);
    
    /*Busca de um elemento da lista*/
    elem = 23; /*Valor procurado na lista*/
    elem_busca = lst_busca(lst, elem); /*Execução da busca*/
    
    /*Exibição do resultado da busca*/
    puts("\nBusca de elemento na lista");
    
    if (elem_busca != NULL) {
        printf("Elemento encontrado: %i\n",  elem);
    } else
        printf("Elemento %i inexistente na lista\n", elem);
    
    
    /*Aplicação da função para remoção de um elemento*/
    puts("==================================================\n");
    
    elem = 45;
    printf("Remoção do elemento %i\n", elem);
    lst_retira(lst, elem);
    
    puts("Impressão de itens da lista atualizada\n");
    lst_imprime(lst);
    puts("Lista concluída\n");
    
    
    /*Aplicação da função para liberar lista da memória*/
    puts("==================================================\n");
    
    puts("Liberando lista da memória...\n");
    lst_libera(lst);
    
    return 0;
}