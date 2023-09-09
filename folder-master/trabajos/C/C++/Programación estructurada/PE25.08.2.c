#include<stdio.h>

int main(){
    int a,b;
    printf("Ingresa dos números\n"); 
    scanf("%d %d", &a, &b);

    if(a>b)
        printf("El número %d es mayor que %d", a,b); 
    else 
        if(a==b)
            printf("Los números son iguales");
        else
            printf("El número %d es mayor que %d", b,a);

    return 0;
}