#include <stdio.h>

struct circulo{
    int radio;
}cir;

struct cuadrado{
    int lado;
}cua;

struct triangulo{
    int base, altura;
}t;

union {
    struct circulo cir;
    struct cuadrado cua;
    struct triangulo t;
}figura1,figura2,figura3;


int main(){

    figura1.cir.radio = 3;
    figura2.t.base = 2;
    figura2.t.altura = 2;
    figura3.cua.lado = 6;

    puts("Figura 1: ");
    printf("Circulo con radio de %d cm\n", figura1.cir.radio);
    putchar('\n');
    puts("Figura 2: "); 
    printf("Triangulo con base %d cm y altura de %d cm\n", figura2.t.base, figura2.t.altura);
    putchar('\n');
    puts("Figura 3: ");
    printf("Cuadrado con lado de: %d cm\n", figura3.cua.lado);


    return 0;
}


