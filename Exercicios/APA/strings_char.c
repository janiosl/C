#include <stdio.h>
int main(){
    char nome[] = "Belo Horizone";
    int asc;
    int n = 3;
    int i = 0;
    int h = 0;
    for(i=0; i<n; i++){
        asc = nome[i];
        printf("%c: %d\n", nome[i], asc);
        h = h + asc;
    }
    printf("Somatorio do codigo ASCII dos caractesres:%d", h);
    return 0;
}