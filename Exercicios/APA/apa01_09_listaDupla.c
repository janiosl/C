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

/*===================================================*/
/*Função inserção ordenada: Insere elemento em ordem */
/*===================================================*/
ListaDE* lst_insere_ordenado(ListaDE* lst, int val)
{
    /*Elemento novo*/
    ListaDE* novo;
    
    /*Ponteiros auxiliares*/
    ListaDE* ant = NULL;
    ListaDE* p = lst;
    
    /*Procura posição da inserção*/
    while (p != NULL && p->info < val)
    {
        ant = p;
        p = p->prox;
    }
    
    /*Cria novo elemento*/
    novo = (ListaDE*) malloc(sizeof(ListaDE));
    novo->info = val;
    
    /*Encadeia elemento*/
    if (ant == NULL)
    {
        /*Insere elemento no início da lista*/
        novo->prox = lst;
        lst = novo;
    } else
    {
        /*Insere elemento no meio da lista*/
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return lst;
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
/*==================================================*/
/*Função de impressão: imprime valores dos elementos*/
/*==================================================*/
ListaDE* concatena(ListaDE* lst1, ListaDE* lst2){
    ListaDE* ct = (ListaDE*)malloc(sizeof(ListaDE));
    ct = listaDE_cria();
    ListaDE* p; /*Ponteiro para percorrer elementos da lista*/
    for (p = lst1; p != NULL; p = p->prox){
        ct = listaDE_insere(ct, p->info);
    }
    for (p = lst2; p != NULL; p = p->prox){
        ct = listaDE_insere(ct, p->info);
    }
    return ct;
}
/*==================================================*/
/*Função de cópia: copia a lista para uma lista nova*/
/*==================================================*/
ListaDE* copiar(ListaDE* lst){
    ListaDE* copia = (ListaDE*)malloc(sizeof(ListaDE));
    copia = listaDE_cria();
    ListaDE* p; /*Ponteiro para percorrer elementos da lista*/
    for (p = lst; p != NULL; p = p->prox){
        copia = lst_insere_ordenado(copia, p->info);
    }
    return copia;
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
    ListaDE* listaOrd;
    listaOrd = listaDE_cria();
    /*Inserção de elementos*/
    puts("==================================================");
    puts("Lista Ordenada");
    puts("==================================================\n");
    listaOrd = lst_insere_ordenado(listaOrd, 7);
    listaOrd = lst_insere_ordenado(listaOrd, 72);
    listaOrd = lst_insere_ordenado(listaOrd, 33);
    /*Visualizando a lista completa*/
    listaDE_imprime(listaOrd);
    /*Concatenção de listas*/
    puts("==================================================");
    puts("Concatenando as duas listas");
    puts("==================================================\n");
    ListaDE* listaCT;
    listaCT = listaDE_cria();
    listaCT = concatena(lista, listaOrd);
    /*Visualizando a lista completa*/
    listaDE_imprime(listaCT);
    puts("==================================================");
    puts("Copiando uma lista");
    puts("==================================================\n");
    puts("Lista ORIGINAL");
    listaDE_imprime(listaOrd);
    ListaDE* listaCP;
    listaCP = listaDE_cria();
    listaCP = copiar(listaOrd);
    /*Visualizando a lista completa*/
    puts("Lista COPIADA");
    listaDE_imprime(listaOrd);
    return 0;
}