#include<stdio.h>
#include<string.h>
#define T 10

int main(){
    char s1[T], s2[T], letras[T];
    system("cls || clear");
    puts("Ingresa una cadena");
    gets(s1);
    puts("Ingresa los caracteres a buscar");
    gets(letras);

    if((strpbrk(s1,letras) != '\0'))
        printf("Hay caracteres en comun");
    else 
        printf("No hay caracteres en comun");

    return 0;
}
