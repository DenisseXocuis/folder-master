#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define T 30
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
        case '+': return 1;
        break;

        case '-': return 2;
        break;

        case '*': return 3;
        break;

        case '/': return 4;
        break;

        case '^': return 5;
        break;

        case '(': return 6;
        break;

        case ')': return -6;
        break;

        default: return 0;
        break;
    }
}
int ascii(int num){
    switch(num){
        case 1: return 43;
        break;

        case 2: return 45;
        break;

        case 3: return 42;
        break;

        case 4: return 47;
        break;

        case 5: return 94;

        default: return 0;
        break;
    }
}
char *shunting_yard(char *cad, char *polish_not){
    int prev_operator = 0, i = 0; 
     //expresion aritmetica en polish notation reverse
    //^ cadena reordenada a notacion polaca inversa mediante algoritmo de shunting yard
    for(char *apt = cad; *apt != '\0'; apt++){
            if (!isspace(*apt)){
                switch (*apt)
                {
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '^':
                    //valida la jerarquía y lo guarda en el vector de
                        if(jerarquia(*apt) < prev_operator) // 1<3
                            polish_not[i++] = ascii(prev_operator);
                        else if(jerarquia(*apt) == 6)
                            printf("%d", jerarquia(*apt));
                        prev_operator = jerarquia(*apt); //se asigna como operador previo
                    break;
                    default: //si hay un num
                            if(isdigit(*apt)){
                                polish_not[i++] = *apt;
                            }
                            else if(jerarquia(*apt) == 0){
                                puts("ERROR, hay un valor no numerico en la expresion");
                                return 0;
                            }
                    break;
                    //num = strtol(apt, &apt, 10); //extrae el num
                }
            }
    }
    if (prev_operator != 0) {
        polish_not[i] = ascii(prev_operator);
    }
    polish_not[i+1] = '\0';
    return polish_not;
}
int operacion(char *polish_not){
    long num = 0;
    int op1,op2; 
    char *apt = polish_not;
    if(*apt == '\0')
        return 0; //caso base 
    else if (isspace(*apt))
        apt++;
    else if (isdigit(*apt))
        num = strtol(apt, &apt, 10);
    switch (*apt)
    {
        case '+':   
        case '-':
        case '*':
            //op1 = strtol(apt, &apt,10);
            return 1;
        case '/':
        default: // si es num
            return operacion(apt++);
    }
}
int main(){
    char op[T] = "5 * 2 + 1", polish[T];
    printf("Ingresa una expresion aritmetica \n>");
    /* scanf(" %[^\n]", &op); */
    shunting_yard(op, polish);

    printf("Conversion a notacion polaca inversa: ");
    for(int j =0; polish[j] != '\0'; j++)
        printf("%c ", polish[j]);

    //printf ("\nResultado: %d", operacion(polish, i));
    return 0;
}