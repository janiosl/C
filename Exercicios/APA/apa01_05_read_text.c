#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find_vogais(char texto[]){
    /*
    Função realiza a contagem de vogais em um texto recebido
    */
    char vg[10] = "AaEeIiOoUu";
    int q = 0;
    int i, j;

    /*Para cada letra do texto até seu final \0*/
    for (i = 0; texto[i] != '\0'; i++){
        /*Para cada vogal*/
        for (j = 0; vg[j] != '\0'; j++){
            /*Se a vogal for igual à letra adiciona 1 a q*/
            if (vg[j] == texto[i]) {
                q ++;
                break;
            }
        }
    }
    return q;
}

int main(){
    /*
    Para receber texto via arquivo o programa deve ser executado com a sintaxe:
    read_text < [arquivo.txt]
    * read_text é o nome sugerido para o programa compilado
    * [arquivo.txt] deve ser substituído pelo arquivo contendo o texto para análise
    ---------------------------------------------------------------------------------
    A saída exibirá o texto contido no arquivo e a quantidade de vogais identificadas
    Se o arquivo não for passado o programa aguardará a digitação pelo usuário.
    */

    /*Variáveis para receber texto e gravar resultado*/
    char texto[100];
    int resultado;

    /*Leitura do texto*/
    scanf("%99[^\n]", texto);
    
    /*Execução da função e exibição do resultado*/
    resultado = find_vogais(texto);
    printf("Texto recebido:\n%s\nVogais identificadas: %i\n", texto, resultado);

    return 0;
}