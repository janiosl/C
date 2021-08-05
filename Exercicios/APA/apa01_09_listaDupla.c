#include <stdio.h>
#include <stdlib.h>
/*=========================*/
/*Cria a estrutura da lista*/
/*=========================*/
struct listaDE{
    int info;              /*Elemento da lista*/
    struct listaDE* ant;   /*Ponteiro para o item anterior*/
    struct listaDE* prox;  /*Ponteiro para o próximo item*/
}; typedef struct listaDE ListaDE;
/*==================================*/
/*Função Criar: cria uma lista vazia*/
/*==================================*/
ListaDE* listaDE_cria(void){
    return NULL;
}
/*====================================*/
/*Função Inserir: insere item na lista*/
/*====================================*/
ListaDE* listaDE_insere(ListaDE* lst, int val){
    ListaDE* novo = (ListaDE*)malloc(sizeof(ListaDE));
    novo->info = val;
    novo->prox = lst;
    novo->ant = NULL;
    if(lst != NULL){
        lst->ant = novo;
    }
    return novo;
}
/*=====================================*/
/*Função Buscar: busca um item na lista*/
/*=====================================*/
ListaDE* listaDE_busca(ListaDE* lst, int val){
    ListaDE* p; /*Variável temporária para percorrer a lista*/
    /*Laço passa por cada elemento da lista*/
    for (p=lst; p!=NULL; p=p->prox){
        /*Condição verifica se o campo info contém o valor procurado*/
        if(p->info == val){
            puts("Elemento encontrado");
            return p;
        }
    }
    /*Ação final ao não encontrar o item na lista*/
    puts("Elemento nao encontrado");
    return NULL;
}
/*==================================================*/
/*Função de impressão: imprime valores dos elementos*/
/*==================================================*/
void listaDE_imprime(ListaDE* lst)
{
    ListaDE* p; /*Ponteiro para percorrer elementos da lista*/
    for (p = lst; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}
/*==================*/
/*Programa Principal*/
/*==================*/
int main(){
    /*Criação da lista*/
    ListaDE* lista;
    lista = listaDE_cria();
    /*Inserção de elementos*/
    lista = listaDE_insere(lista, 7);
    lista = listaDE_insere(lista, 9);
    lista = listaDE_insere(lista, 33);
    /*Busca de elementos na lista*/
    int val_desejado;
    val_desejado = 9;
    printf("Verificando se valor %i esta na lista\n", val_desejado);
    listaDE_busca(lista, val_desejado);
    val_desejado = 12;
    printf("Verificando se valor %i esta na lista\n", val_desejado);
    listaDE_busca(lista, val_desejado);
    /*Visualizando a lista completa*/
    listaDE_imprime(lista);
    return 0;
}