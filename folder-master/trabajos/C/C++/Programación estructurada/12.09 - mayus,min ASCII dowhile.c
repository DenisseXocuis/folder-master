#include<stdio.h>
#define T 30


int main(){
    int i = 0, op;
    char palabra[T];

    do{ /*va a esperar que le de la opción*/
    printf("-------------------------\n");
    printf("Bienvenido a mi programa \n");
    printf("-------------------------\n");
    printf("[1] Cambiar de minusculas a mayusculas \n");
    printf("[2] Cambiar de mayusculas a minusculas \n");
    printf("[0] Salir\n");

    printf("Opcion: >");
    scanf("%d", &op);

    switch(op)
        {
            case 1: printf("Ingresa una palabra en minuscula\n");
            scanf("%s", &palabra);
            while(palabra[i]){
                printf("%c", palabra[i] - 32);
                i++;
            }

            break;

            case 2: printf("Ingresa una palabra en mayuscula\n");
            scanf("%s", &palabra);
            while(palabra[i]){
                printf("%c", palabra[i] + 32);
                i++;
            }

            break; 

            case 0: printf("Saliendo......\n");

            break; 

            default: printf("ERROR: opcion no valida\n");
        }
    }while(op); /*este while si lleva punto y coma*/


    return 0;
}