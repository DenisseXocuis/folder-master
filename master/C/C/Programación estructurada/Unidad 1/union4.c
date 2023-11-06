#include <stdio.h>
#include<string.h>


union info {
    int edad;
    float altura;
    char nombre[50];
};

struct person{
    char tipo;
    union info datos;
};

int main() {
    struct person persona1, persona2;

    persona1.tipo = 'e';
    persona1.datos.edad = 30;

    persona2.tipo = 'n';
    strcpy(persona2.datos.nombre, "Juan Pérez");

    printf("Persona 1: ");
    if (persona1.tipo == 'e')
        printf("Edad: %d años\n", persona1.datos.edad);
    else if (persona1.tipo == 'a')
        printf("Altura: %.2f metros\n", persona1.datos.altura);
    else if (persona1.tipo == 'n')
        printf("Nombre: %s\n", persona1.datos.nombre);

    printf("Persona 2: ");
    if (persona2.tipo == 'e')
        printf("Edad: %d años\n", persona2.datos.edad);
    else if (persona2.tipo == 'a')
        printf("Altura: %.2f metros\n", persona2.datos.altura);
    else if (persona2.tipo == 'n')
        printf("Nombre: %s\n", persona2.datos.nombre);

    return 0;
}

