#include <stdio.h>
#include "hfcal.h"

/*
Para que o programa funcione no Linux
considerando que a biblioteca libhfcal.so está no diretório libs
dentro do diretório do programa, deve ser executado o comando a seguir
antes de rodar o programa
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:libs
*/

int main()
{
    display_calories(115.2, 11.3, 0.79);
    return 0;
}