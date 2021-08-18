#include <stdio.h>
float raiz(float numero){
    float precisao = 0.1;
    float b = numero, a=1;
    while ((b-a) >= precisao){
        b = (a+b)/2;
        a = numero/b;
    }
    return b;
}
int h_cidades_raiz(char *nome, int n){
    int asc;
    int i;
    int h = 0;
    //Cálculo do somatório do código ASCII
    for(i=0; i<n; i++){
        asc = nome[i];
        h = h + asc;
    }
    //Cálculo da raiz quadrada do somatório
    return raiz(h);
}
int h_cidades_div(char *nome, int n){
    int asc;
    int i;
    int h = 0;
    //Cálculo do somatório do código ASCII
    for(i=0; i<n; i++){
        asc = nome[i];
        h = h + asc;
    }
    //Cálculo do somatório dos códigos ASCII / n
    return h/n;
}
int main(){
    char cidades[25][100] = {
        "Alfenas","Araguari","Araxá","Barbacena","Belo Horizonte",
        "Betim","Bocaiúva","Bom Despacho","Caeté","Campo Belo",
        "Caratinga","Cataguases","Congonhas","Conselheiro Lafaiete",
        "Contagem","Coronel Fabriciano","Curvelo","Sabará","Santa Luzia",
        "Santos Dumont","Sete Lagoas","São Francisco","São João del Rei",
        "São Lourenço","São Sebastião do Paraíso"};
    char *nome;
    nome = cidades[0];
    int pos;
    int n = 3;
    puts("==================================");
    puts("Teste simples");
    puts("==================================");
    //Aplicação simples da primeira função hash
    printf("Hash (op. 1) para N = %d\n", n);
    puts("--------------------------");
    pos = h_cidades_raiz(nome, n);
    printf("%d : \"%s\"\n", pos, nome);
    //Aplicação simples da segunda função hash
    printf("Hash (op. 2) para N = %d\n", n);
    puts("--------------------------");
    pos = h_cidades_div(nome, n);
    printf("%d : \"%s\"\n", pos, nome);
    //Aplicação da segunda função hash para todas as cidades
    puts("==================================");
    puts("Aplicacao para todas as cidades");
    puts("==================================");
    int j;
    printf("Hash (op. 2) para N = %d\n", n);
    puts("--------------------------");
    for(j=0; j<25; j++){
        pos = h_cidades_div(cidades[j], n);
        printf("%d : \"%s\"\n", pos, cidades[j]);
    }
    return 0;
}