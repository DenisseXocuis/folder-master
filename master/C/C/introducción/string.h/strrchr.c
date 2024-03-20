#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Agua de limon";
    char ch = 'e', *cmp;
    cmp = strrchr(str, ch);
    system("cls || clear");
    (cmp!=NULL) ? printf("La ultima aparicion de '%c' está en la posición: %ld\n", ch, cmp - str) :
    puts("No se encuentra");

    return 0;
}


