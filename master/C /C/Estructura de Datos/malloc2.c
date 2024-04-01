#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
    char *cadena;
    cadena = (char *) malloc(20* sizeof(char *));
    for(int i=0; i<=2; i++)
        scanf("%c", cadena);
    for(int i=0;i<=2; i++)
        printf("%c", cadena);
    free(cadena);

    return 0;
}