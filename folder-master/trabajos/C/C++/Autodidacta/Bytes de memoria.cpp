#include<stdio.h>
#include<conio.h>

int main(){

    printf("La variable del tipo entero ocupa %d bytes de memoria \n", sizeof(int));
    printf("La variable de tipo entero corto ocupa %d bytes de memoria \n", sizeof(short int));
    printf("La variable del tipo entero largo ocupa %d bytes de memoria \n", sizeof(long int));
    printf("La variable del tipo flotante ocupan %d bytes de memoria \n", sizeof(float));
    printf("Los enteros con decimal ocupan %d bytes de memoria \n", sizeof(double));
    printf("Los enteros largos con decimal ocupan %d bytes de memoria \n", sizeof(long double));
    printf("Las variables del tipo char ocupan %d bytes de memoria", sizeof(char));

    return 0;
}