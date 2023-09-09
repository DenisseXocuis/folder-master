#include<stdio.h> 

int main(){
    int n;
    printf("Programa que identifica si el número ingresaro es positivo o negativo\n");
    printf("Ingrese un numero\n>");
    scanf("%d", &n);

    if(n >= 0)
        if(n == 0)
            printf("El número es neutro");
        else 
            printf("El número es positivo");
    
    else 
        printf("El número ingresado es negativo");

    return 0;
}