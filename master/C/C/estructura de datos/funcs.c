/* Función variádica by deniso :) */
#include<stdio.h>
#include<string.h>
#include<stdarg.h> //'standard arguments' to accept a variable number arguments, es decir, para que podamos poner los parámetros que queramos 

void *suma(const char *va, ...){
    //char = formats of each variable and have a count of them :)
    int cadena, err = 1;
    double suma = 0;
    va_list vargs;  //tipo que representa la lista de args variables
    va_start(vargs, va); //inicializa la lista
    //iterar entre los argumentos c:
    for(const char *apt = va; *apt != '\0'; apt++){
        if(*apt == '%') //verifica si el primer char es un %
        {
            switch (*(++apt)){ //si es así, 
                case 'd':{
                    int i = va_arg(vargs, int);
                    suma += i;
                }
                break;
                
                case 'f':
                    double f = va_arg(vargs, double);
                    suma += f;
                
                break;
                
                case 's':
                    char *s = va_arg(vargs, char *);
                    //cadena = atoi(s);
                    char *fin;
                    cadena = strtol(s, &fin, 10);
                    suma += cadena;
                break;

                default:
                    printf("srry :(, formato de parametro no identificado: ");
                    putchar(*apt);
                    err = 0;
                    putchar('\n');
                break;
            }
        }
        else putchar(*apt); //si no hay un '%'

    }
    va_end(vargs); 
    if(err)
        printf("Suma: %g", suma);
}
//funcionando como un printf
int main(){
    suma("%s %d", "25.6", 5); 
    return 0;
}