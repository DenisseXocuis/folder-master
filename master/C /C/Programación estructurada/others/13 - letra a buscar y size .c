#include<stdio.h>

#define T 60

int main(){
    int i = 0, cont = 0;
    char word[T], c;

    printf("Ingresa una palabra\n");
    scanf("%s", &word); /*s = string*/

    printf("Ingresa la letra a buscarb");
    scanf("\n %c", &c);

    while(word[i]!= '\0'){
        if(c == word[i]);
            cont++;
        i++;
    }

    if(cont == 0)
        printf("letra no encontrada \n");
    else 
        printf("la letra %c esta %d veces \n", c, cont);

    printf("EL tamanio de la palabra es de %d caracteres\n", i);

    return 0;
}