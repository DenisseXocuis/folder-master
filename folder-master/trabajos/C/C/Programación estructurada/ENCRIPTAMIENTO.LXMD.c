#include<stdio.h>
/*pedir una palabra y palabra clave, encriptar */
#define T 200
#define T 300

//nums ascii de la palabra div entre 10//
int main(){

    int i = 0, F = 0, op, F2;/*F = factor o llave*/
    char pa[T], pclave[T], pclave2[T];

    do{
    system("clear||cls");
    puts("\n---------------------------------------------"); /*flujo de caracter y salto de linea automatico*/
    puts("----------PROGRAMA DE ENCRIPTAMIENTO---------");
    puts("---------------------------------------------");
    puts("[1] Encriptar");
    puts("[2] Desencriptar");
    puts("[3] Desencriptar manualmente");
    puts("[4] About");
    puts("[0] Salir");

    printf("Opcion: >");
    scanf("%d", &op);

    switch(op)
        {
            case 1: fflush(stdin);
                    system("clear||cls");
                    printf("Ingresar una palabra\n>");
                    scanf("%s", &pa);
                    printf("Ingresa una palabra clave\n>");
                    scanf("%s", &pclave);

                    /*calculando el factor*/
                    while(pclave[i]){
                        F += pclave[i];
                        i++;
                    }
    
                    F /= 10;
                    i = 0;

                    printf("Factor = %d \n", F);

                    while(pa[i]){
                        pa[i] += F;
                        i++;
                    }

                    printf("La palabra encriptada es %s \n", pa);

                    puts("Ingrese cualquier tecla para continuar");
                    getchar();
                    getchar();

            break;   
            case 2: fflush(stdin);
                    system("clear||cls");
                    puts("Ingrese la palabra clave de la palabra encriptada");
                    scanf("%s", &pclave2);
                    i = 0;
                    while(pclave2[i]){
                        F2 += pclave2[i];
                        i++;
                    }   
                    F2 /=10; 
                    if(F2 == F){
                        i = 0;
                        printf("Factor = %d \n", F);

                        while(pa[i]){
                            pa[i] -= F;
                            i++;
                        }
                        printf("La palabra desencriptada es %s \n", pa);
                        puts("Ingrese cualquier tecla para continuar");
                        getchar();
                        getchar();
                    }
                    else if(F==0){
                            puts("ERROR: No hubo un encriptamiento antes");
                            puts("Ingrese cualquier tecla para continuar");
                            getchar();
                            getchar();
                        } 
                        else{
                            puts("ERROR: Palabra clave incorrecta");
                            puts("Ingrese cualquier tecla para continuar");
                            getchar();
                            getchar();
                        }
            break;
            case 3: system("clear||cls");
                    fflush(stdin);
                    printf("Ingresar la palabra encriptada\n>");
                    scanf("%s", &pa);
                    printf("Ingresa una palabra clave\n>");
                    scanf("%s", &pclave);

                    while(pclave[i]){
                        F += pclave[i];
                        i++;
                    }
    
                    F /= 10;
                    i = 0;

                    printf("Factor = %d \n", F);

                        while(pa[i]){
                            pa[i] -= F;
                            i++;
                        }
                    printf("La palabra desencriptada es %s \n", pa);

                    puts("Ingrese cualquier tecla para continuar");
                    getchar();
                    getchar();
            break;
            case 4: system("clear||cls");
                     puts("\n---------------------------------------------");   
                    puts("----------PROGRAMA DE ENCRIPTAMIENTO---------");
                    puts("---------------------------------------------");
                    puts("Lara Xocuis Martha Denisse");
                    puts("Ingeniería Informática");
                    putchar('\n');
                    puts("Ingrese cualquier tecla para continuar");
                    getchar();
                    getchar();
            break; 
            case 0: puts("Saliendo.....");

            break; 
            default: puts("ERROR: opcion no valida");
                     puts("Ingrese cualquier tecla para continuar");
                     getchar();
                     getchar();
        }
    
    }while(op);


    return 0;
}