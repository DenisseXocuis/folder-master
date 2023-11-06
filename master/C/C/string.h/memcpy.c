#include<stdio.h>
#include<string.h>
#define MAX 3

int main(){
    char s2[] = "cadena s2", *s1;
    system("cls || clear");
    printf("Antes de memcpy, la cadena s2 es: \"%s\" ", s2);
    memcpy(s1,s2,sizeof(s2));
    printf("\n Despues de memcpy, la cadena s1 es: \"%s\" \n", s1);

    return 0;
}

