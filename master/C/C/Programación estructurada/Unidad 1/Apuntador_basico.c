#include<stdio.h>

void cubo(int *n);

int main(){

    int valor = 3;
    int *apuntador = &valor;

    printf("%d\n", *apuntador);

    *apuntador = 80;

    printf("%d\n", valor);
    //%p ubicacion de memoria como entero hexadecimal


    return 0;
}
