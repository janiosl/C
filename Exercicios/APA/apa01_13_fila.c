#include <stdio.h>
#include <stdlib.h>
/*========================*/
/*Cria a estrutura da fila*/
/*========================*/
struct fila {
    int tamanho;
    int *info;
    int inicio;
    int final;
    int qtd_itens;
};typedef struct fila Fila;
/*=========================================*/
/*Função de criação: retorna uma fila vazia*/
/*=========================================*/
void fila_cria(Fila *f, int t){
    f->tamanho = t;
    /*Reserva o espaço de memória de acordo com o tamanho da fila*/
    f->info = (int*)malloc(f->tamanho * sizeof(int));
    f->inicio = 0;
    f->final = -1;
    f->qtd_itens = 0;
}
/*==============================================*/
/*Função de vazia: Verifica se a fila está vazia*/
/*==============================================*/
int fila_vazia(Fila *f){
        if(f->qtd_itens == 0){
        puts("Fila vazia");
        return 1;
    } else{
        puts("Elementos na fila");
        return 0;
    }
}
/*====================================================*/
/*Função de inserção: insere elemento no final da fila*/
/*====================================================*/
void fila_insere(Fila *f, int item){
    if(f->qtd_itens == f->tamanho){
        puts("Fila cheia.");
        printf("Elemento %i ficou fora da fila\n", item);
        return;
    }
    if(f->final == f->tamanho-1){
        f->final = -1;
    }
    f->final++;
    f->info[f->final] = item;
    f->qtd_itens++;
}
/*=====================================================*/
/*Função de exclusão: retira elemento no início da fila*/
/*=====================================================*/
int fila_exclui(Fila *f){
    if(fila_vazia(f)){
        exit(1);
    }
    int t = f->info[f->inicio++];
    if(f->inicio == f->tamanho){
        f->inicio = 0;
    }
    f->qtd_itens--;
    return t;
}
/*=============================================*/
/*Função de exibição: Exibe o conteúdo da fila*/
/*============================================*/
void fila_imprime(Fila *f){
    int cont, i;
	for (cont=0, i=f->inicio; cont<f->qtd_itens; cont++){
        printf("%i\n",f->info[i++]);
		if (i == f->tamanho){
            i=0;
        }
	}
}
int main(){
    /*Cria uma pilha vazia*/
    puts("Iniciando a fila...");
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    int elementos = 5;
    fila_cria(fila, elementos);
    /*Adicionando elementos*/
    fila_insere(fila, 0);
    fila_insere(fila, 1);
    fila_insere(fila, 1);
    fila_insere(fila, 3);
    fila_insere(fila, 5);
    fila_insere(fila, 8);
    /*Exibir o conteúdo da fila*/
    puts("Elementos da fila:");
    fila_imprime(fila);
    /*Excluir elemento da fila*/
    puts("Removendo elementos da fila:");
    int i = 0;
    while(i < elementos++){
        /*Loop forçado a exceder o limite da fila para checar
        a trava embutida na função de exclusão*/
        fila_exclui(fila);
        fila_imprime(fila);
        i++;
    }
    return 0;
}