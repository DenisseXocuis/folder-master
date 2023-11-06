#include<stdio.h>
#include<string.h>
#define T 20

int main(){
    char s1[T], letras[T];
    system("cls || clear");
    puts("Ingresa una cadena");
    gets(s1);
    puts("Ingresa los caracteres a buscar");
    gets(letras);
    if((strpbrk(s1,letras)) != '\0') printf("Los caracteres %s aparecen desde %s", letras,strpbrk(s1,letras));
    else puts("No hay caracteres en comun");

    return 0;
}

