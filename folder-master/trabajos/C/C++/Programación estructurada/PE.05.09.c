#include<stdio.h>

int main(){
    /*Imprima en un rango de 1 a n, solo los numeros que sean multiplos de m*/
    int r,m;
    printf("Ingrese dos numeros, uno para el rango y otro para calcular sus multiplos\n>");
    while(r>=1){
        scanf("%d %d", &r, &m);
        if(r>=1)
            for(int i = 1 ; i <= r; i++){
                if(m % i == 0)
                    printf("El num %d es multiplo de %d\n", i, m);
            }
        else 
            printf("ERROR: El rango no puede ser menor de 1");
    }

    return 0;
}