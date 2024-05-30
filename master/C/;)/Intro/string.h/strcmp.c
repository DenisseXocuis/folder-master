#include<stdio.h>
#include<string.h>
#define MAX 20

int main(){

    char s1[MAX], s2[MAX], *cmp;
    system("cls || clear");
    puts("Ingresa una cadena");
    scanf("%s", s1);

    puts("Ingresa otra cadena");
    scanf("%s", s2);

    cmp = strcmp(s1,s2);

    if(cmp != 0)
        if(cmp > 0)
            puts("comparacion: s1 > s2");
        else
            puts("comparacion: s1 < s2");
    else
        puts("las dos cadenas son iguales");

    return 0;
}

