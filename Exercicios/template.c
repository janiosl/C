#include <stdio.h>
#include "template.h"

void linha(int tipo)
{
    /*---------------------------------------------------
    Função: linha
    Parâmetros: int tipo: quantidade de traços (1 ou 2)
    Retorno: A função não retorna valores
    Descrição: gera uma linha com 1 ou 2 traços para
    auxiliar na organização de conteúdo na tela.
    -----------------------------------------------------*/
    if (tipo == 2)
        puts("===========================================");
    else if (tipo == 1)
        puts("--------------------------------------------");
}

void cabecalho(char title[])
{
    /*---------------------------------------------------
    Função: cabecalho
    Parâmetros: char title: título do programa
    Retorno: A função não retorna valores
    Descrição: gera um cabeçalho com o título do programa
    organizado entre duas linhas de dois traços.
    -----------------------------------------------------*/
    linha(2);
    printf("%s\n", title);
    linha(2);
}

void rodape()
{
    /*---------------------------------------------------
    Função: rodape
    Parâmetros: sem parâmetros
    Retorno: A função não retorna valores
    Descrição: gera um rodapé informado concluusao
    do programa
    -----------------------------------------------------*/
    linha(2);
    puts("Programa Encerrado.\nObrigado. Janio Lima");
    linha(2);
}