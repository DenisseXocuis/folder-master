#include<stdio.h>
#include<stdlib.h>
//HACIENDO LO MISMO PERO SIN MOVER A P
int main(){
    int *p,n; //p es apuntador de sector de memoria, cacha lo que retorna maloc
    puts("Ingresa el tamaño del vector");
    scanf("%d", &n);
    p = (int *) malloc(n*sizeof(int)); 
    //p = malloc(n*sizeof(int)); opcional
    printf("Ingresa los %d datos del vector\n", n);

    for(int i=0; i<n; i++)
        scanf("%d", (p+i));
    //p-=n;
    puts("Los datos del vector son: ");
    getchar();
    for(int i=0; i<n; i++)
        printf("v[%d] = %d\n", i, *(p+i));
    //p-=n; se regresa para libearlo desde el inicio
    free(p); //liberamos p de la memoria
    return 0;
}