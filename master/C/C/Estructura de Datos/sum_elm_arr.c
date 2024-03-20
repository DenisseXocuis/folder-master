#include <stdio.h>
int suma(int *arreglo, int i){
    if(i==0)
        return 0;
    else
        return arreglo[i] + suma(arreglo[i], i-1);
}

int main(){
    int v[] = {1,1,1,1,1};
    printf(" %d", suma(&v, 5));
    return 0;
}

/* 5+4 en una cadena de caracteres y
    con un metodo recursivo regresa el resultado de la ec
    mayor jerarquia***
    5 + 4/2
    (5+4) / 2
    5^2 + 4


    +
    -
    *
    /
    ^
    (
    )
*/