#include<stdio.h>
#define T 20
//int word(char *p, char c);
int recursividad(char *p, char c);

int main(){
    char cadena[T], letra;
    int res;
    puts("Ingresa una cadena");
    gets(cadena);
    puts("Ingresa la letra a buscar");
    scanf("%c", &letra);
    res = recursividad(cadena,letra);
    if(res==0)
        puts("La letra no se encuentra");
    else
        printf("La cadena tiene %d veces la letra %c\n",recursividad(cadena,letra), letra);

    return 0;
}

/*int word(char *p, char c){ //apuntador y letra que voy a buscar
    int i=0; //contador de letra
    while(*p!='\0'){ //lo que apunte p debe ser distinto de cero, es lo mismo que *p
        if(*p == c)
            i++;
        p++;
    }
    return i;
    
}*/

int recursividad(char *p, char c){
    if(*p != '\0')
        if(*p == c)
             return (1 + recursividad(++p,c));
    else 
        return recursividad(++p,c);
}