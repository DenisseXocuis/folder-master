#include<stdio.h>
/*#define T 6*/
#define T 6

int main(){
    /*const int T = 6;*/
    int v[T], i, suma = 0;
    float prom = 0; 
    printf("Ingrese los del vector\n");
    for(i = 0; i < T; i++)
        scanf("%d", &v[i]);
    printf("-------------------------\n");
    printf("Recorrido del vector\n"); 
    printf("-------------------------\n");

    for(i = 0; i < T; i++){
        printf("vector [%d] = %d \n", i, v[i]);
    printf("-------------------------\n");
    suma += v[i];
    }
    prom = (float) suma / T;
    printf("-------------------------\n");
    printf("La suma del vector es %d \n", suma);
    printf("promedio %g", prom);
    return 0;
}