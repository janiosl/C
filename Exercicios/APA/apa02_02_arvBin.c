#include <stdio.h>
#include <stdlib.h>
/*------------------
TAD - Árvore Binária
------------------*/
struct arv{
    char info;
    struct arv* esq;
    struct arv* dir;
};typedef struct arv Arv;
/*----------------------------------------
Funções para manipulação da Árvore Binária
----------------------------------------*/
Arv* arv_criavazia(void){
    //Cria a árvore vazia
    return NULL;
}
int arv_vazia(Arv* a){
    //Verifica se a árvore é vazia
    return a==NULL;
}
Arv* arv_cria(char c, Arv* sae, Arv* sad){
    /*Cria a árvore com um nós
    e as sub-árvores sae e sad*/
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}
Arv* arv_libera(Arv* a){
    //Libera a árvore da memória
    if (!arv_vazia(a)){
        arv_libera(a->esq); /* libera sae */
        arv_libera(a->dir); /* libera sad */
        free(a);            /* libera raiz */
    }
    return NULL;
}
/*----------------------------------------
Funções análise da Árvore Binária
----------------------------------------*/
void arv_imprime (Arv* a){
    //Imprime as informações da árvore
    printf("<");
    if (!arv_vazia(a)){
        printf("%c ", a->info); /* mostra raiz */
        arv_imprime(a->esq);    /* mostra sae */
        arv_imprime(a->dir);    /* mostra sad */
    }
    printf(">");
}
int arv_conta_nos(Arv* a){
    //Conta a quantidade de nós da árvore
	if(!a)
		return 0;
	else
		return 1+ arv_conta_nos(a->esq)+arv_conta_nos(a->dir);
}
int arv_num_folhas(Arv *a){
    //Conta quantidade de folhas
    int nf;
    nf = 0;
    //Verifica se a arvore é vazia
    if(!arv_vazia(a)){
        if(arv_vazia(a->esq) && arv_vazia(a->dir)){
            nf ++;
        } else{
            nf = nf + arv_num_folhas(a->esq);
            nf = nf + arv_num_folhas(a->dir);
        }
        return nf;
    }
    return 0;
}
int arv_filhos_direita(Arv *a){
    //Conta quantidade de filhos à direita
    return 0;
}
int arv_altura(Arv *a){
    //Calcula a altura da árvore
    return 0;
}
/*------------------
Programa principal
------------------*/
int main(){
    /* sub-árvore 'd' */
    Arv* a1= arv_cria('d',arv_criavazia(),arv_criavazia());
    /* sub-árvore 'b' */
    Arv* a2= arv_cria('b',arv_criavazia(),a1);
    /* sub-árvore 'e' */
    Arv* a3= arv_cria('e',arv_criavazia(),arv_criavazia());
    /* sub-árvore 'f' */
    Arv* a4= arv_cria('f',arv_criavazia(),arv_criavazia());
    /* sub-árvore 'c' */
    Arv* a5= arv_cria('c',a3,a4);
    /* árvore 'a' */
    Arv* a = arv_cria('a',a2,a5);
    /*Analisando arvore completa*/
    puts("Visualizacao da arvore a:");
    puts("-----------------------------------------");
    arv_imprime(a);
    puts("\n=========================================");
    int nos;
    int folhas;
    nos = arv_conta_nos(a);
    folhas = arv_num_folhas(a);
    printf("Nos: %d\nFolhas: %d\n\n", nos, folhas);
    /*Analisando a subárvore arvore c*/
    puts("Visualizacao da arvore c:");
    puts("-----------------------------------------");
    arv_imprime(a5);
    puts("\n=========================================");
    nos = arv_conta_nos(a5);
    folhas = arv_num_folhas(a5);
    printf("Nos: %d\nFolhas: %d\n\n", nos, folhas);
    /*Analisando uma árvore vazia*/
    Arv* vazia = arv_criavazia();
    puts("Visualizacao da arvore vazia:");
    puts("-----------------------------------------");
    nos = arv_conta_nos(vazia);
    arv_imprime(vazia);
    puts("\n=========================================");
    folhas = arv_num_folhas(vazia);
    printf("Nos: %d\nFolhas: %d\n\n", nos, folhas);
    return 0;
}