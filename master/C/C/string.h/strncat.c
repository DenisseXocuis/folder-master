#include<stdio.h>
#include<string.h>
#define MAX 10

int main(){
    char s1[MAX], s2[MAX];
    system("cls || clear");
    puts("Ingresa una cadena");
    scanf("%s", s1);
    puts("Ingresa otra cadena");
    scanf("%s", s2);
    printf("Resultado: \"%s\" \n", strncat(s1,s2,4));

    return 0;
}





