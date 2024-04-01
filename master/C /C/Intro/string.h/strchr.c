#include<stdio.h>
#include<string.h>
#define MAX 30

int main(){
    char s[MAX], c = 'e';
    system("cls || clear");
    printf("Ingresa una cadena\n");
    scanf("%s", &s);
    printf("la primera aparicion de %c es desde %s", c, strchr(s,c));

    return 0;

}

