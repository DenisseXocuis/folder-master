#include<stdio.h>
#include<string.h>
#define MAX 20

int main(){
    char s1[MAX], s2[MAX];
    system("cls || clear");
    puts("Ingresa una cadena");
    scanf("%s", s1);
    puts("Ingresa los caracteres para devolver la cadena ingresada previamente sin uno de estos");
    scanf("%s", s2);

    printf("la cadena \"%s\" hasta encontrar \"%s\" es : \"%d\" \n", s1,s2, strcspn(s1,s2));

    return 0;

}

