#include<stdio.h>
#include<string.h>
#define MAX 10
int main(){
    char s1[MAX], *s2;
    puts("Ingresa una cadena");
    gets(s1);
    s2 = &s1; 
    printf("La cadena tiene una longitud de: %d", strlen(s2));

    return 0;
}

