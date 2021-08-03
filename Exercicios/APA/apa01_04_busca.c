#include <stdio.h>

int buscaBinaria(int A[], int inicio, int final, int itemProcurado){
    while (inicio <= final){
        /*Aplicação da estratégia de divisão e conquista*/
        int i = (inicio + final) / 2;

        /*Retorno do índice do item procurado*/
        if (A[i] == itemProcurado){
            return i;
        }

        /*Aplicação da condição para chamar levar o laço para cada metade do vetor de itens*/
        if (A[i] < itemProcurado){
            /*Segue buscando depois do meio*/
            inicio = i + 1;
        } else {
            /*Segue buscando antes do meio*/
            final = i;
        }
    }
    /*Resultado se o item não for localizado*/
    return -1;
}

int main(){
    int A[] = {1,2,3,4,5};                    /*Vetor de itens*/
    int inicio = 0;                           /*Início do vetor*/
    int tamanho = sizeof(A)/sizeof(A[0]);     /*Tamanho do vetor*/
    int final = tamanho - 1;                  /*Final = Tamanho - 1 para controlar o final do laço*/
    int result;                               /*Índice de localização do item procurado*/

    /*Aplicação da função*/
    int itemProcurado = 5;
    result = buscaBinaria(A, inicio, final, itemProcurado);
    
    /*Exibição do resultado na tela*/
    printf("Item procurado: %i\n", itemProcurado);
    if (result == -1){
        puts("Item nao localizado\n");
    } else {
        printf("Indice do item procurado no vetor de itens: %i\n", result);
    }
    return 0;
}