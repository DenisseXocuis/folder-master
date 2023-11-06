#include<stdio.h> 
#include<string.h>
#define MAX 20

int main(){
    char s1[MAX] = "programacion estructurada", c = 'e', *s2;
    system("cls || clear");
    s2 = strchr(s1,c);
    printf("la primera aparicion de %c en la cadena \"%s\" es desde %s", c,s1,s2);

    return 0;
}

