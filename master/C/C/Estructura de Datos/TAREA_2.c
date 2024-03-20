#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define T 20

int salida(); //agregará operandos a la pila

int operacion(char *cad){
    char *apt = cad;
    long num = strtol(apt, &apt, 10);
    if(sizeof(num))
        puts("ola");
}

int jerarquia(char cad){
    /* para el algoritmo de Shunting Yard
    Se asigna un valor numérico a cada operador según su jerarquía, los de mayor tendrán valores más altos
         + -    1 
         * /    2
         ^      3
         (      4
         )     -5 (para eliminar 6-6=0)
    */
    switch(cad)
    {
        case '+':
        case '-': 
            return 1;
        break;

        case '*':
        case '/':
            return 2;
        break;

        case '^': return 3;
        break;

        case '(': return 4;
        break;

        case ')': return -4;
        break;

        default: return 0;
        break;
    }
}

void shunting_yard(char *cad){
    int prev_operator = 0, i = 0, m = 0; 
    char polish_not[T]; //expresion aritmetica en polish notation reverse
    //^ cadena reordenada a notacion polaca inversa mediante algoritmo de shunting yard
    long num; 
    for(char *apt = cad; *apt != '\0'; apt++ ,i++){
            switch (*apt)
            {
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                //valida la jerarquía y lo guarda en el vector de 
                    if(jerarquia(*apt) < prev_operator)
                        polish_not[i++] = *apt;
                    prev_operator = *apt; //se asigna como operador previo
                break;
                default: //si hay un num
                        if(isdigit(*apt))
                            polish_not[i] = *apt; 
                        //num = strtol(apt, &apt, 10); //extrae el num 
                        else 
                            puts("ERROR, hay un valor no numerico en la expresion");
                            exit(1);
                          
                break;
            }
    }
    for(int i=0; polish_not[i] != '\0'; i++)
        printf("%c",polish_not[i]);
}
int main(){ 
    char op[T] = {"a * 4 + 2"};
    printf("Q onda, ingresa algo pa: \n>");
  /*   scanf(" %[^\n]", &op); */
    shunting_yard(op);
    return 0;
}


/* 5+4 en una cadena de caracteres y
    con un metodo recursivo regresa el resultado de la ec
    mayor jerarquia***
    5 + 4/2
    (5+4) / 2
    5^2 + 4

    
*/

