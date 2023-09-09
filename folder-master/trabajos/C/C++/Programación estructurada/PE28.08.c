#include<stdio.h>
/*programa que imprime números de forma ascendente*/
int main(){
    int a,b;
    printf("Ingrese dos números\n");
    scanf("%d %d", &a,&b);    
    if(a>b)
        printf("\n %d \n %d", b,a);
    else
        if(b>a)
            printf("\n %d \n %d", a,b);
        else 
            printf("Los dos numeros son iguales");

    return 0;
}