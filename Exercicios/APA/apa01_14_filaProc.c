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
    return(f->qtd_itens == 0);
}
/*====================================================*/
/*Função de inserção: insere elemento no final da fila*/
/*====================================================*/
void fila_insere(Fila *f, int item){
    if(f->qtd_itens == f->tamanho){
        puts("Fila cheia.");
        printf("Processo %i ficou fora da fila\n", item);
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
        puts("Nao ha mais processos para execucao.");
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
    if(fila_vazia(f)){
        return;
    }
    int cont, i;
    puts("Fila de processos aguardando execucao:");
    printf("Sistema");
	for (cont=0, i=f->inicio; cont<f->qtd_itens; cont++){
        printf(" < id:%i ",f->info[i++]);
		if (i == f->tamanho){
            i=0;
        }
	}
    printf(" < Entrada na fila < Novos processos\n");
}
int main(){
    /*Cria uma pilha vazia*/
    puts("Iniciando a fila de processos...");
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    int elementos = 5;
    fila_cria(fila, elementos);
    /*Processos: variáveis simulam a identificação de cada processo*/
    puts("Adicionando processos...");
    int id_p1 = 8;
    int id_p2 = 5;
    int id_p3 = 3;
    int id_p4 = 1;
    int id_p5 = 0;
    /*Adicionando elementos*/
    fila_insere(fila, id_p1);
    fila_insere(fila, id_p2);
    fila_insere(fila, id_p3);
    fila_insere(fila, id_p4);
    fila_insere(fila, id_p5);
    /*Exibir o conteúdo da fila*/
    fila_imprime(fila);
    /*Excluir elemento da fila*/
    puts("\n-------------------------------");
    puts("Rotina de execucao de processos");
    puts("-------------------------------\n");
    int i = 0;
    while(i < elementos++){
        /*Loop forçado a exceder o limite da fila para checar
        a trava embutida na função de exclusão*/
        int e;
        e = fila_exclui(fila);
        printf("Transferindo processo id:%i da fila para execucao...\n\n", e);
        fila_imprime(fila);
        i++;
    }
    return 0;
}