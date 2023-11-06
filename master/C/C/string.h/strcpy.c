#include<stdio.h>
#include<string.h>
#define T 10

int main(){
    char s1[T], s2[T];
    system("cls || clear");
    puts("Ingresa una cadena");
    gets(s1);
    puts("Ingresa otra cadena");
    gets(s2);

    printf("Cadena 1: \"%s\" \n", s1);
    printf("Cadena 2: \"%s\" \n", s2);
    printf("Copiando cadena 2 a cadena 1: \"%s\"", strcpy(s1,s2));

    return 0;
}

