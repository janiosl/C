#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_v(char text[]){
    /*
    Função realiza a contagem de vogais em um texto recebido
    */
    char v[10] = "AaEeIiOoUu";
    int c = 0;
    int i, j;

    /*Para cada letra do texto até seu final \0*/
    for (i = 0; text[i] != '\0'; i++){
        /*Para cada vogal*/
        for (j = 0; v[j] != '\0'; j++){
            /*Se a vogal for igual à letra adiciona 1 a q*/
            if (v[j] == text[i]) {
                c ++;
                break;
            }
        }
    }
    return c;
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
    char text[100];
    int result;

    /*Leitura do texto*/
    scanf("%99[^\n]", text);
    
    /*Execução da função e exibição do resultado*/
    result = count_v(text);
    printf("Texto recebido:\n%s\nVogais identificadas: %i\n", text, result);

    return 0;
}