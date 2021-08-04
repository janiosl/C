#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int len;
/*=========================*/
/*Cria a estrutura da pilha*/
/*=========================*/
struct pilha {
    int info;
    struct pilha* prox;
};
typedef struct pilha Pilha;
/*==========================================*/
/*Função de criação: retorna uma pilha vazia*/
/*==========================================*/
void pilha_cria(Pilha *plh){
    plh->prox = NULL;
    len=0;
}
/*======================================*/
/*Função verifica se a pilha está vazia*/
/*======================================*/
int pilha_vazia(Pilha *plh){
    if(plh->prox == NULL){
        return 1;
    } else {
        return 0;
    }
}
/*========================================*/
/*Função de inserção de elementos à pilha*/
/*========================================*/
void pilha_insere(Pilha* plh, int item){
    /*Alocação da memória*/
    /*Incluir stdlib.h para usar malloc*/
    Pilha *novo=(Pilha*)malloc(sizeof(Pilha));
    /*Inserção do item novo*/
    if(!novo){
        puts("Sem memoria\n");
        exit(1);
    }else{
        novo->info = item;
    }
    novo->prox = NULL;
    if(pilha_vazia(plh)){
        plh->prox = novo;
    } else{
        Pilha *t = plh->prox;
        while(t->prox != NULL){
            t = t->prox;
        }
        t->prox = novo;
    }
    len ++;
}
/*========================================*/
/*Função de exclusão de elementos da pilha*/
/*========================================*/
Pilha* pilha_exclui(Pilha* plh){
    if(plh->prox == NULL){
        puts("Pilha vazia!");
        return NULL;
    } else{
        /*Variáveis de apoio para percorrer pilha*/
        Pilha *u = plh->prox; /*Último item*/
        Pilha *pu = plh;      /*Penúlmtimo item*/
        /*Lógica para ajustar posição dos itens*/
        while(u->prox != NULL){
            pu = u;
            u = u->prox;
        }
        pu->prox = NULL;
        len --;
        printf("%i\n", u->info);
        return u;
    }
}
/*==================================================*/
/*Função de impressão: imprime valores dos elementos*/
/*==================================================*/
void pilha_imprime(Pilha *plh){
    puts("Visualizar itens da pilha:");
    if(pilha_vazia(plh)){
        puts("Pilha vazia!");
        return;
    }
    Pilha *p, *t; /*p = próximo; t = tual*/
    t = plh->prox;
    while(t != NULL){
        p = t->prox;
        printf("%i\n", t->info);
        t = p;
    }
}
/*==================================================*/
/*Função libera: libera a pilha completa da memória */
/*==================================================*/
void pilha_liberar(Pilha *plh){
    /*Executa a lógica apenas se a pilha não estiver vazia*/
    if(!pilha_vazia(plh)){
        /*Variáveis auxiliares para percorrer a pilha*/
        Pilha *p, *t; /* p = Próximo; t = Atual*/
        t = plh->prox;
        while(t != NULL){
            p = t->prox;
            free(t);
            t = p;
        }
    }
}
/*======================================*/
/*Função de identificação do fator primo*/
/*======================================*/
Pilha* fatPrimo(int n){
    printf("Fatores primos para %i\n", n);
    /*Cria uma pilha para manipular os fatores*/
    Pilha *fatores = (Pilha*)malloc(sizeof(Pilha));
    pilha_cria(fatores);
    /*Aplica o cálculo dos fatores*/
    int d = 2; /*Inicia pelo menor fator (2)*/
    /*Lógica para cálculo*/
    while(d * d <= n){
        /*Verifica se o resto da divisão é zero*/
        while(n % d == 0){
            n = n / d;
            /*Adiciona cada fator à pilha*/
            pilha_insere(fatores, d);
        }
        d++;
    }
    /*Evita a inclusão do 1 na pilha de fatores*/
    if(n>1){
        assert(d <= n);
        pilha_insere(fatores, n);
    }
    /*Exibe os fatores calculados*/
    /*pilha_imprime(fatores);*/
    return fatores;
}
/*==================*/
/*Programa principal*/
/*==================*/
int main(){
    /*Cria uma pilha vazia*/
    puts("Iniciando a pilha...");
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha_cria(pilha);
    /*Teste a lógica de exclusão e verifica se a pilha está vazia*/
    printf("Removendo da pilha item: ");
    pilha_exclui(pilha);
    puts("Verificar pilha vazia:\n1 = Vazia; 0 = Com elementos");
    int verifica;
    verifica = pilha_vazia(pilha);
    printf("Vazia? %i\n\n", verifica);
    pilha_imprime(pilha);
    /*Insere itens na pilha*/
    puts("Inserindo itens na pilha...");
    pilha_insere(pilha, 12);
    pilha_insere(pilha, 24);
    pilha_insere(pilha, 36);
    pilha_insere(pilha, 72);
    /*Teste a lógica de exclusão e verifica se a pilha está vazia*/
    puts("Verificar pilha vazia:\n1 = Vazia; 0 = Com elementos");
    verifica = pilha_vazia(pilha);
    printf("Vazia? %i\n\n", verifica);
    pilha_imprime(pilha);
    /*Teste a lógica de exclusão na pilha com elementos*/
    printf("Removendo da pilha item: ");
    pilha_exclui(pilha);
    pilha_imprime(pilha);
    /*Libera a memória*/
    pilha_liberar(pilha);
    printf("Vazia? %i\n\n", verifica);
    /*--------------------------------------
    ATENÇÃO: As etapas anteriores foram usadas
    para testar o funcionamento da TAD pilha
    *** A seguir é usada esta TAD junto com a
    função fatPrimo para realizar a identificação
    do fator primo de um numero qualquer.
    ----------------------------------------*/
    int n;
    puts("-----------------------");
    puts("Identificar fator primo");
    puts("-----------------------");
    printf("Digite um numero: ");
    scanf("%i", &n);
    Pilha* fp;
    fp = fatPrimo(n);
    /*Eliminação dos elementos e exibição na tela*/
    /*Como a eliminaçaõ é feita na ordem inversa
    do topo da pilha até o final, conseguimos 
    visualizar a ordem correta (inversa) dos itens*/
    while (fp->prox != NULL){
        pilha_exclui(fp);
    }
    pilha_liberar(fp);
    return 0;
}