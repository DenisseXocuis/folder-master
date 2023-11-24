//MATRIZ CON ARITMÉTICA APUNTADOR
#include<stdio.h>
#define F 2
#define C 2 //reserva de memoria para una matriz de la cantidad que quiera el usuario, punteros dobles
int main(){
    int **matriz,n;
    //llenamos y mostramos
    puts("Llenado de la matriz");
     do{ 
    printf("Ingresa el tamaño de la matriz nxn\n>"); scanf("%d", &n);
    }while(n<=0);
    matriz = (int **)malloc(n * sizeof(int*)); 

    for(int f=0; f<F;f++)
        for(int c=0; c<C; c++){
            scanf("%d", &matriz[f][c]); //llenando la matriz
            matriz[f] = (int *)malloc(n * sizeof(int));
    }
    putchar('\n');
    
    for(int f=0; f<F;f++){
        for(int c=0;c<C; c++)
            printf("[%d][%d] = %d", f,c, *(*(matriz+f)+c));
        putchar('\n');
    }

    return 0;
}