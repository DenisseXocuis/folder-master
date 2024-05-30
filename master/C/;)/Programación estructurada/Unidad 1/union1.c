#include <stdio.h>

union variables {
    int entero;
    float flotante;
    char caracter;
};

int main() {
    union variables u;
    
    u.entero = 42;
    printf("Valor entero: %d\n", u.entero);
    
    u.flotante = 3.14;
    printf("Valor flotante: %f\n", u.flotante);
    
    u.caracter = 'A'; 
    printf("Valor caracter: %c\n", u.caracter);
    return 0;
}


