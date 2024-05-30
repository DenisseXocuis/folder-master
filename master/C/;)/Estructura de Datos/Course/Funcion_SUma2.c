/* Función variádica by deniso :) */
#include<stdio.h>
#include<string.h>
#include<stdarg.h> //'standard arguments' to accept a variable number arguments, es decir, para que podamos poner los parámetros que queramos 
#include<ctype.h>

void *suma(const char *va, ...){
    //char = formats of each variable and have a count of them
    int cadena, err = 0;
    double suma = 0;
    va_list vargs;  //tipo que representa la lista de args variables
    va_start(vargs, va); //inicializa la lista con el tipo

    //now, para iterar entre los argumentos:
    for(const char *apt = va; *apt != '\0'; apt++){
        if(*apt == '%') //verifica si el primer char de la lista es un %
        {
            system("cls || clear");
            switch (*(++apt)){ //si es así, mueve apt para luego hacer referencia a su valor
                case 'd':{
                    int i = va_arg(vargs, int); //obtiene el argumento en esa posición de acuerdo al tipo 
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
                    if(!isdigit(*s)) //verifica si existe letras en el string
                    { 
                        puts("ERROR, el string contiene letras, nimodo");
                        err = 1;
                    }
                    else{
                        char *fin; //necesario para extraer el num del string
                        cadena = strtol(s, &fin, 10);  //extrae el num con base 10
                        suma += cadena;
                    }
                break;

                default:
                    printf("srry :(, formato de parametro no identificado: ");
                    putchar(*apt);
                    err = 1;
                    putchar('\n');
                break;
            }
        }
        else putchar(*apt); //si no hay un '%'

    }
    va_end(vargs); 
    if(!err)
        printf("Suma: %g\n", suma);
}
//funcionando como un printf
int main(){
    suma("%d%s", 23, "ola"); 
    return 0;
}