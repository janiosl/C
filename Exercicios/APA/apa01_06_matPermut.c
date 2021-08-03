#include <stdio.h>
#define N 3
/*===================================================*/
/*Função verifica se a matriz passada é de permutação*/
/*===================================================*/
int verifMatPerm(int matriz[N][N], int tamanho){
    int i, j;
    i = 0;
    j = 0;
    int somaGeral = 0;
    int somaLinha, somaColuna;
    for (i=0; i<tamanho; i++){
        somaLinha = 0;
        for(j=0; j<tamanho; j++){
            if(matriz[i][j] == 1){
                somaLinha ++;
                somaGeral ++;
            }
        }
        /*Checagem da linha*/
        if(somaLinha != 1){
            return 0;
        }
    }
    for (j=0; j<tamanho; j++){
        somaColuna = 0;
        for(i=0; i<tamanho; i++){
            if(matriz[i][j] == 1){
                somaColuna ++;
            }
        }
        /*Checagem da coluna*/
        if(somaColuna != 1){
            return 0;
        }
    }
    /*Checagem geral*/
    /*Esta checagem geral garante a integridade geral,
    mas com as checagens anteriores se torna desnecessária,
    por isso está inativa*/
    /*
    if(somaGeral/tamanho == 1){
        return 1;
    } else {
        return 0;
    }*/
    /*A função chegará no retorno verdadeiro (1) apenas
    se não for terminado antecipadamente pela reprovação
    nas checagens das regras de definição da matriz de permutação
    =============================================================*/
    return 1;
}
/*=================*/
/*Programa principal*/
/*=================*/
int main(){
    int i, j;
    int result;
    /*Criação das matrizes para teste*/
    /*===============================*/
    int A[N][N];
    /*Criando uma matriz que NÃO atende aos requisitos*/
    /*=================================================*/
    for (i=0; i<N; i++){
        for(j=0; j<N; j++){
            A[i][j] = 0;
        }
    }
    /*A matriz abaixo é de permutação*/
    /*===============================*/
    int B[N][N] = {1,0,0,0,1,0,0,0,1};
    /*O exemplo abaixo NÃO é uma matriz de permutação, mas se a lógica
    estiver errada será interpretada equivocadamente*/
    /*==================================================================*/
    int C[N][N] = {1,0,0,1,0,0,1,0,0};
    /*Visualizando as matrizes*/
    /*========================*/
    puts("Matriz A:");
    for ( i=0; i<N; i++ ) {
        for ( j=0; j<N; j++ ){
            printf ("%d", A[ i ][ j ]);
        }
        puts("");
    }
    /*Testando a primeira matriz*/
    result = verifMatPerm(A, N);
    if (result == 1){
        puts("Matriz de permutacao: Verdadeiro\n");
    } else {
        puts("Matriz de permutacao: Falso\n");
    }
    puts("Matriz B:");
        for ( i=0; i<3; i++ ) {
            for ( j=0; j<3; j++ ){
                printf ("%d", B[ i ][ j ]);
            }
            puts("");
        }
    /*Testando a segunda matriz*/
    result = verifMatPerm(B, N);
    if (result == 1){
        puts("Matriz de permutacao: Verdadeiro\n");
    } else {
        puts("Matriz de permutacao: Falso\n");
    }
    puts("Matriz C:");
    for ( i=0; i<3; i++ ) {
        for ( j=0; j<3; j++ ){
            printf ("%d", C[ i ][ j ]);
        }
        puts("");
    }
    /*Testando a terceira matriz*/
    result = verifMatPerm(C, N);
    if (result == 1){
        puts("Matriz de permutacao: Verdadeiro\n");
    } else {
        puts("Matriz de permutacao: Falso\n");
    }
    return 0;
}