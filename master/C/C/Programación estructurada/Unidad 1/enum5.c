#include <stdio.h>
void menu();
enum color{ ROJO=1, VERDE, AZUL, AMARILLO, ROSA
}c;
int main(){
    int r, g, b;
    menu();
    scanf("%d", &c);
    switch (c) {
        case ROJO:
            r = 255;
            g = 0;
            b = 0;
            break;
        case VERDE:
            r = 0;
            g = 255;
            b = 0;
            break;
        case AZUL:
            r = 0;
            g = 0;
            b = 255;
            break;
        case AMARILLO:
            r = 255;
            g = 255;
            b = 0;
            break;
        case ROSA:
            r = 255;
            g = 0;
            b = 255;
            break;
        default:
            puts("ERROR: Color no válido");
            return 1;
    }
    printf("RGB del color: (%d, %d, %d).\n", r, g, b);
    return 0;
}
void menu(){

    puts("Elige un color:");
    puts("1. Rojo");
    puts("2. Verde");
    puts("3. Azul");
    puts("4. Amarillo");
    puts("5. Rosa");
    printf("Opción: \n>");
}


