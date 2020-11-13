#include <stdio.h>
#include <string.h>

char tracks[][80] = {
    "I let my heart in Havard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing with a Dork",
    "From here to maternity",
    "The girl from Iwo Jima"
};

void find_track(char search_for[]) {
    int i;
    for (i = 0; i < 5; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

int main() {
    char search_for[80];
    printf("Search for: ");
    //fgets(search_for, 80, stdin);
    /*O uso da entrada de dados com fgets não está funcionando*/
    scanf("%79[^\n]", search_for);
    /*Ao usar a entrada de dados com scanf está funcionando,
    mas é pouco prático por aceitar apenas uma string sem espaços
    PROBLEMA SOLUCIONADO USANDO O PADRÃO ACIMA QUE ACEITA ESPAÇOS NO scanf*/
    find_track(search_for);
    return 0;
}