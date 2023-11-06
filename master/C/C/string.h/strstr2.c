#include<stdio.h>
#include<string.h>

int main(){
    char *s1 = "Ciudad de Mexico",*s2 = "Mexico",*cmp;
    cmp = strstr(s1,s2);
    (cmp!=NULL) ? printf("\"%s\" se encuentra en \"%s\"", s2,s1) :
    puts("No hay aparicion de la cadena 2 en la cadena 1");

    return 0;
}




