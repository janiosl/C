#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "template.h"

/*======================================================|
|Programa para sorteio de um aluno para apresentação de |
|trabalho em sala de aula.                              |
|======================================================*/

int main()
{
    char alunos[][80] = {"Alfred", "Wagner", "Paulo", "Cláudio"};
    int sorteado;
    int i;

    //Entrada de dados
    cabecalho("SORTEIO DE ALUNOS");
    puts("Alunos da turma:");
    for (i = 0; i < 4; i++) {
        printf("%i. %s\n", i+1, alunos[i]);
    }

    linha(1);
    
    //Plantando a semente
    srand(time(NULL));
    //Sorteio do aluno
    sorteado = rand() % 3;

    /*
    srand() inicia a rand(), gerando uma semente com base na função time
    diferente a cada execução do programa, evitando repetição dos valoress
    aleatórios gerados por rand().
    */

    printf("Aluno sorteado:\n%s\n", alunos[sorteado]);

    rodape();
    return 0;
}