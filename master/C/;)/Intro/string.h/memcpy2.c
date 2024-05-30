#include<stdio.h>
#include<string.h>
#define MAX 80

int main(){
    char s2[MAX]={"Esta es la cadena de origen"}, s1[MAX] = {"Esta es la cadena de destino"};
    system("cls || clear");
    printf("Cadena s1: \"%s\" \n", s1);
    printf("Cadena s2: \"%s\" \n", s2);
    memcpy(s1,s2,MAX);
    printf("s2 a s1 por memcpy:  \"%s\" \n",s1);
    

    return 0;
}

