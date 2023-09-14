#include<stdio.h>
/*pedir una palabra y palabra clave, encriptar */
#define T 200
#define T 300

//nums ascii de la palabra div entre 10//
int main(){

    int i = 0, F = 0, op;/*F = factor o llave*/
    char pa[T], pclave[T];

    do{
    puts("---------------------------------------------"); /*flujo de caracter y salto de linea automatico*/
    puts("Bienvenido a el programa sobre encriptamiento");
    puts("---------------------------------------------");
    puts("[1] Encriptar");
    puts("[2] Desencriptar");
    puts("[3] About");
    puts("[0] Salir");

    printf("Opcion: >");
    scanf("%d", &op);

    switch(op)
        {
            case 1: 
                    printf("Ingresar una palabra\n>");
                    scanf("%[^\n]", &pa);
                    printf("Ingresa una palabra clave\n>");
                    scanf("%s", &pclave);


                    /*calculando el factor*/
                    while(pa[i] != '\0'){
                        F += pa[i];
                        i++;
                    }
    
                        F /= 10;

                    i = 0;
                    printf("Factor = %d \n", F); /*universidad fiee 118*/

                    while(pa[i] != '\0'){
                        pa[i] += F;
                        i++;
                    }

                    printf("La palabra encriptada es %s \n", pa);
            break; 
                    
            case 2: /*universidad, bebé*/
                    printf("Ingresar una palabra\n>");
                    scanf("%s", &pa);
                    printf("Ingresa una palabra clave\n>");
                    scanf("%s", &pclave);

                    /*calculando el factor*/
                    while(pclave[i]){
                        F += pclave[i];
                        i++;
                    }
                    i = 0;
                    printf("Factor = %d \n", F);

                    while(pa[i]){
                        pa[i] -= F;
                        i++;
                    }

                    printf("La palabra desencriptada es %s \n", pa);
            break;

            case 3: puts("Lara Xocuis Martha Denisse");
                    puts("Ingenieria Informatica :) ");


            break; 


            case 0: 
                    puts("Saliendo.....");

            break; 

            default: puts("ERROR: opcion no valida");
        }
    

   

    while(pa[i] != '0'){
        printf("%c ", pa[i] - F);
        i++;
    }


    }while(op);


    return 0;
}