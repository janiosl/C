#include <stdio.h>

int buscaBinariaRec(int A[], int inicio, int final, int itemProcurado){
    /*Aplicação da estratégia de divisão e conquista*/
    int i = (inicio + final) / 2;
    
    /*Resultado se o item não for localizado*/
    if (inicio > final){
        return -1;
    }

    /*Retorno do índice do item procurado*/
    if (A[i] == itemProcurado){
        return i;
    }

    /*Aplicação da recursividade para chamar a função para cada metade do vetor de itens*/

    if (A[i] < itemProcurado){
        /*Segue buscando depois do meio*/
        return buscaBinariaRec(A, i + 1, final, itemProcurado);
    } else {
        /*Segue buscando antes do meio*/
        return buscaBinariaRec(A, inicio,  i - 1, itemProcurado);
    }
}

int main(){
    int A[] = {1,2,3,4,5};                  /*Vetor de itens*/
    int inicio = 0;                         /*Início do vetor*/
    int final = sizeof(A)/sizeof(A[0]);     /*Tamanho do vetor*/
    int result;                             /*Índice de localização do item procurado*/

    /*Aplicação da função*/
    int itemProcurado = 5;
    result = buscaBinariaRec(A, inicio, final, itemProcurado);
    
    /*Exibição do resultado na tela*/
    printf("Item procurado: %i\n", itemProcurado);
    if (result == -1){
        puts("Item nao localizado\n");
    } else {
        printf("Indice do item procurado no vetor de itens: %i\n", result);
    }
    
    return 0;
}