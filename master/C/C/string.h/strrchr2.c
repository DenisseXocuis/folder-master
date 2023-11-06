#include <stdio.h>
#include <string.h>

int main() {
    char *str, ch, *cmp;
    system("cls || clear");
    puts("Ingrese una cadena");
    gets(str);
    puts("Ingrese un caracter");
    scanf("%c", &ch);
    cmp = strrchr(str, ch);
    (cmp!=NULL) ? printf("La ultima aparicion de '%c' está en la posición: %ld\n", ch, cmp - str) :
    puts("No se encuentra");

    return 0;
}

