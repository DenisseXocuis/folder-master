#include<stdio.h>
#include<string.h>
#define MAX 20

int main(){
    char array[MAX];
    system("cls || clear");
    puts("Ingresa una cadena:");
    gets(array);
    printf("La longitud de la cadena es de: %d", strlen(array));

    return 0;
}


