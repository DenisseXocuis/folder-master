#include <stdio.h>
void menu();
enum tamano{
    PEQUENO=1,MEDIANO,GRANDE,EXTRA_GRANDE
}t;

int main(){
    double precio;
    menu();
    scanf("%d", &t);

    switch (t) {
        case 1:
            precio = 2.50;
            break;
        case 2:
            precio = 3.00;
            break;
        case 3:
            precio = 3.50;
            break;
        case 4:
            precio = 4.00;
            break;
        default:
            puts("ERROR: El tamaño de la bebida no es válido");
            return 1;
    }

    printf("El precio de la bebida del tamaño seleccionado es: $%.2lf\n", precio);

    return 0;
}

void menu(){
    puts("Elige el tamaño de la bebida:");
    puts("1. Pequeño");
    puts("2. Mediano");
    puts("3. Grande");
    puts("4. Extra grande");
    printf("Opción: \n>");
}


