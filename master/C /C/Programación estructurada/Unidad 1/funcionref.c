#include<stdio.h>
void intercambio(int *,int*);

int main(){
    int a = 2, b = 3;
    printf("%d y %d \n", a,b);
    intercambio(&a,&b);
    printf("usando funcion de referencia: %d y %d", a,b);

    return 0;
}

void intercambio(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

