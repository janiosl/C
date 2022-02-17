#include <stdio.h>
int fat(int num){
    int f;
    if (num <= 1){
        f = 1;
    } else {
        f = num * fat(num - 1);
    }
    return f;
}
int main(){
    int numero;
    int resultado;
    printf("Number: ");
    scanf("%d", &numero);
    resultado = fat(numero);
    printf("%d! = %d", numero, resultado);
    return 0;
}