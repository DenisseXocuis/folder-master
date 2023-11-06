#include<stdio.h>
#include<math.h>
#include<locale.h>

int main(){
    setlocale(LC_CTYPE, "");
    /* Programa de ejemplo */
    int tamañoA = 0;
    printf("Programa que guarda datos en un arreglo dependiendo el tamaño que se le establezca\nIngrese el tamaño del arreglo\n>");
    scanf("%i", &tamañoA);
    
    int age[tamañoA];

    for (int i = 0; i < tamañoA; i++)
    {
        printf("Ingresa el valor %i \n>", i+1);
        scanf("%i", &age[i]);
    }

    printf("Los valores del arreglo son:\n");
    for(int i=0; i < tamañoA; i++)
    {
        printf("%i", age[i]);
    }

    return 0;

};