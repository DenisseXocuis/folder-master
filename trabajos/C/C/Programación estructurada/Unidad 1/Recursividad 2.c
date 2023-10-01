#include<stdio.h> //funcion parametro por valor, parametro por referencia
int pow(int b, int e);

int main(){
    int b,e;
    printf("Ingresa una base y un exponente\n");
    scanf("%d %d", &b, &e);
    printf("%d ^ %d = %d", b,e,potencia(e,b));

    return 0;
}

int potencia(int e,int b){
    if(e == 0)
       return 1;
    else
        return b * potencia(e-1, b);
}