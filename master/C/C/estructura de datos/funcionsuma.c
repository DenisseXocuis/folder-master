/* Función variádica :) */
#include<stdio.h>
#include<string.h>
//'standard arguments' to accept a variable number arguments
#include<stdarg.h> 

void *suma(const char *va, ...){
//char = formats of each variable and have a count of them :)
    va_list vargs;  //tipo que representa la lista de argumts variables
    va_start(vargs, va); //inicializa la lista
    //iterar entre los argumentos c:
    for(const char *apt = va; *apt != '\0'; apt++){
        if(*apt == '%')
        {
            switch (*(++apt)){
                case 'd':{
                    int i = va_arg(vargs, int);
                }
                break;
                
                case 'f':
                    double f = va_arg(vargs, double);
                
                break;
                
                case 's':
                    char *s = va_arg(vargs, char *);
                    char *fin;
                    int num = strtol(s, &fin, 10);

                break;

                default:
                    printf("Formato de parametro no identificado: ");
                    putchar(*apt); 
                    putchar('\n');
                break;
            
            }
        }
        else putchar(*apt); //si no hay un '%'
    }
    va_end(vargs); 
}

int main(){
    suma("%d %d", 23, 3); //funcionando como un printf
    return 0;
}