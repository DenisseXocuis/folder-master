#include<stdio.h>
#include<string.h>
#define MAX 10

int main(){
    char s2[MAX], *s1;
    system("cls || clear");
    puts("Ingrese una cadena para copiarla a otra cadena");
    scanf("%s", s2);

    printf("\ns1 ahora contiene: \"%s\"\n", strcpy(s1,s2));

    return 0;

}