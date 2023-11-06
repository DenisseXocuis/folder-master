#include<stdio.h>
#include<string.h>
#define MAX 20

int main(){

    char s1[MAX], s2[MAX], *cmp;
    int num,n;
    system("cls || clear");
    puts("Ingresa una cadena");
    scanf("%s", s1);

    puts("Ingresa otra cadena");
    scanf("%s", s2);

    puts("ingresa la longitud a comparar");
    scanf("%d", &num);
    cmp = strncmp(s1,s2,num);
    n = (!cmp);
    (!n) ? printf("son diferentes") : printf("son iguales");
    return 0;
}


//strcomp tira 0 si son iguales
// n = (!cmp) tira 1 si se cumple
// !n 

