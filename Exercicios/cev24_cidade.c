/*
PROGRAMA RECEBE O NOME DE UMA CIDADE
E INFORMA SE ESTE NOME É INICIADO PELA
PALAVRA SANTO
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#include "template.h"

int main()
{
    char cidade[80];
    char * palavra;
    
 
    //Entrada de dados
    cabecalho("CIDADES");
    puts("Digite o nome de uma cidade:");
    fgets(cidade, 80, stdin);
    //printf("%s\n", cidade);
    linha(1);

    puts("Palavras no nome da cidade:\n");
    palavra = strtok(cidade, " ");
    while (palavra != NULL) {
        printf("%s\n",palavra);
        palavra = strtok(NULL, " ");
    }
    linha(1);

    if (strstr(cidade, "SANTO")) {
    /*
    A checagem com a palavra funciona
    porque a função strtok mantém apenas
    a primeira palavra na variável original
    */
        puts("O nome da cidade começa com SANTO\n");
    } else {
        puts("O nome da cidade NÃO começa com SANTO\n");
    }

    rodape();
    return 0;
}