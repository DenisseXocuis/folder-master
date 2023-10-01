#include<stdio.h>
/*MAYOR A MENOR*/
int main(){
    int a,b,c;
    printf("Ingresa 3 numeros");
    scanf("%d %d %d", &a,&b,&c);

    if(a>c && a>b)
        if(c>b)
            printf("\n %d %d %d", a,c,b);
        else 
            printf("\n %d %d %d", a,b,c);
    if(c>a && c>b)
        if(a>b)
            printf("\n %d %d %d", c,a,b);
        else
            printf("\n %d %d %d", c,b,a);
    if(b>a && b>c)
        if(a>c)
            printf("\n %d %d %d", b,a,c);
        else 
            printf("\n %d %d %d", b,c,a);
    if(a==b && a==c)
        if(b==c)
            printf("Los números son iguales");
    return 0;
}