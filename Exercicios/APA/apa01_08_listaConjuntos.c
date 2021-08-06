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
            printf("Elemento %i pertence ao conjunto\n", val);
            return p;
        }
    }
    /*Ação final ao não encontrar o item na lista*/
    printf("Elemento %i nao pertence ao conjunto\n", val);
    return NULL;
}
/*==================================================*/
/*Função de impressão: imprime valores dos elementos*/
/*==================================================*/
void listaDE_imprime(ListaDE* lst)
{
    ListaDE* p; /*Ponteiro para percorrer elementos da lista*/
    printf("(");
    for (p = lst; p != NULL; p = p->prox)
        printf(" %d ", p->info);
    printf(")\n");
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
    ListaDE* A;
    ListaDE* B;
    ListaDE* C;
    A = listaDE_cria();
    B = listaDE_cria();
    C = listaDE_cria();
    /*Inserção de elementos Conjunto A*/
    A = listaDE_insere(A, 1);
    A = listaDE_insere(A, 2);
    A = listaDE_insere(A, 3);
    /*Visualizando a lista completa*/
    puts("\n====================================");
    puts("Conjunto A");
    puts("====================================");
    listaDE_imprime(A);
    /*Busca de elementos na lista*/
    int val_desejado;
    val_desejado = 9;
    puts("\n====================================");
    puts("Pertinencia ao Conjunto A");
    puts("====================================");
    listaDE_busca(A, val_desejado);
    val_desejado = 2;
    listaDE_busca(A, val_desejado);
    /*Inserção de elementos Conjunto B*/
    B = listaDE_insere(B, 3);
    B = listaDE_insere(B, 5);
    B = listaDE_insere(B, 7);
    /*Visualizando a lista completa*/
    puts("\n====================================");
    puts("Conjunto B");
    puts("====================================");
    listaDE_imprime(B);
    /*União entre conjuntos*/
    C = concatena(A, B);
    puts("\n====================================");
    puts("Uniao de conjunto A e B");
    puts("Conjunto C");
    puts("====================================");
    listaDE_imprime(C);
    /*Intersecção entre os conjuntos*/
    ListaDE* C_inter;
    C_inter = listaDE_cria();
    puts("\n====================================");
    puts("Interseccao de conjunto A e B");
    puts("Conjunto C");
    puts("====================================");
    puts("Funcionalidade em desenvolvimento...");
    ListaDE* C_dif;
    C_dif = listaDE_cria();
    puts("\n====================================");
    puts("Diferença de conjunto A e B");
    puts("Conjunto C");
    puts("====================================");
    puts("Funcionalidade em desenvolvimento...");
    return 0;
}