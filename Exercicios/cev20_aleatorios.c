#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "template.h"

int main()
{
    char alunos[][80] = {"Alfred", "Wagner", "Paulo", "Cláudio"};
    int sorteados[4];
    int sorteado;
    int i;

    //Entrada de dados
    cabecalho("APRESENTAÇÃO DE TRABALHOS");
    puts("Alunos da turma:");
    for (i = 0; i < 4; i++) {
        printf("%i. %s\n", i+1, alunos[i]);
    }

    linha(1);
    
    
    //Plantando a semente
    srand(time(NULL));

    puts("Ordem de apresentações:");
    for (i = 0; i < 4; i++) {
        //Sorteio do aluno
        sorteado = rand() % 3;
        sorteados[i] = sorteado;
    }

    linha(1);
    for (i = 0; i < 4; i++)
        printf("%iº Aluno: %i - %s\n", i+1, sorteados[i]+1, alunos[sorteados[i]]);
    
    /*
    srand() inicia a rand(), gerando uma semente com base na função time
    diferente a cada execução do programa, evitando repetição dos valoress
    aleatórios gerados por rand().
    */

    rodape();
    return 0;
}