#include<stdio.h>
#include<string.h>
#define MAX 20

int main(){
    char s1[MAX],s2[MAX],*cmp;
    puts("Ingresa una cadena");
    scanf("%s", s1);
    puts("Ingresa otra cadena");
    scanf("%s", s2);
    cmp = strstr(s1,s2);
    (cmp!=NULL) ? puts("Hay aparicion de la cadena 2 en la cadena 1") :
    puts("No hay aparicion de la cadena 2 en la cadena 1");

    return 0;
}

