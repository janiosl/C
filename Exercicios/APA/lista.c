#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*Cria a estrutura da lista*/
struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista Lista;


/*==========================================*/
/*Função de criação: retorna uma lista vazia*/
/*==========================================*/
Lista* lst_cria (void)
{
    return NULL;
}


/*========================================================*/
/*Função de inserção no início: retorna a lista atualizada*/
/*========================================================*/
Lista* lst_insere(Lista* lst, int val)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista)); /*Incluir stdlib.h para usar malloc*/
    novo->info = val;
    novo->prox = lst;
    return novo;
}


/*==================================================*/
/*Função de impressão: imprime valores dos elementos*/
/*==================================================*/
void lst_imprime(Lista* lst)
{
    Lista* p; /*Ponteiro para percorrer elementos da lista*/
    for (p = lst; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}


/*==================================================*/
/*Função lista vazia: confere se a lista está vazia */
/*==================================================*/
int lst_vazia(Lista* lst)
{
    return (lst == NULL);
}


/*==================================================*/
/*Função busca: busca um elemento na lista          */
/*==================================================*/
Lista* lst_busca(Lista* lst, int v)
{
    Lista* p;
    for (p = lst; p != NULL; p = p->prox)
    {
        if (p->info == v)
            return p;
    }
    return NULL;
}


/*==================================================*/
/*Função remover: remove um elemento na lista       */
/*==================================================*/
Lista* lst_retira(Lista* lst, int val)
{
    Lista* ant = NULL; /*Ponteiro para elemento anterior*/
    Lista* p = lst;    /*Ponteiro para percorrer a lista*/
    
    /*Proucra elemento na lista, guardando anterior*/
    while (p != NULL && p->info != val)
    {
        /*Se o p é diferente de nulo e p->info diferente do valor procurado*/
        /*Atualiza o valor anterior e atual e refaz a checagem*/
        ant = p;
        p = p->prox;
    }
    
    /*O laço será encerrado se uma das condições for atendida*/
    /*Então, inicia a verificação se encontrou elemento desejado*/
    if (p == NULL)
        return lst; /*Não encontrou: retorna a lista original e sai da função*/
    
    /*A função continuará se a condição anterior não acionar o retorno da lista original */
    /*Remoção do elemento desejado*/
    if (ant == NULL)
    {
        /*Remove elemento do início da lista*/
        lst = p->prox;
    } else
    {
        /*Remove elemento do meio da lista*/
        ant->prox = p->prox;
    }
    
    free(p);
    return lst;
}


/*==================================================*/
/*Função libera: libera a lista completa da memória */
/*==================================================*/
void lst_libera(Lista* lst)
{
    Lista* p = lst;
    while (p != NULL)
    {
        Lista* t = p->prox;   /*Guarda referência para próximo elemento*/
        free(p);              /*Libera memória do elemento atual*/
        p = t;                /*Aponta para o próximo elemento para continuar o loop*/
    }
}