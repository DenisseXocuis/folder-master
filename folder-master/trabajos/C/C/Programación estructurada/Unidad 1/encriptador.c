#include<stdio.h>
#include<stdlib.h>
#define T 250
int main(){
        int i, opc, factor;
        char palabra[T], clave[T];
        FILE *crypt;

        do{
        system("clear"); //Borra pantalla, en Windows se debe cambiar a "cls"
        
        //Menú de selección
        printf("---------------------------------\n");
        printf("ENCRIPTADOR Y DESENCRIPTADOR v0.3\n");
        printf("---------------------------------\n");
        printf("[1] Encriptar\n");
        printf("[2] Desencriptar\n");
        printf("[3] Acerca de...\n");
        printf("[0] Salir del programa...\n");
        printf("Opción: ");
        scanf("%d", &opc);

    switch(opc){
        case 1: 
        system("clear");
        printf("------------\n");
        printf("ENCRIPTACIÓN\n");
        printf("------------\n");

        printf("\nIngrese una palabra a encriptar\n");
        scanf("%s", &palabra);
        printf("Ingrese una palabra clave para encriptar\n");
        scanf("%s", &clave);

        //Calcula el factor sumando los valores ASCII de la clave
        while(clave[i]){
                factor+=clave[i];
                i++;
        }
        factor/=10;
        i=0;

        //Suma los valores ASCII a la palabra para desfazarla
        while(palabra[i]){
                palabra[i]+=factor;
                i++;
        }
        i=0;

        //Suma los valores ASCII a la clave para desfazarla
        while(clave[i]){
                clave[i]+=factor;
                i++;
        }
        i=0;
        factor=0;

        //Crear archivo crypt.thm y escribir palabra encriptada
        crypt=fopen ("crypt.thm", "w");
        fprintf(crypt,"%s", palabra);
        fclose(crypt);

        printf("Texto encriptado guardado en crypt.thm\n");
        printf("Presione cualquier tecla para continuar... \n");
        system("read -s"); //Hace pausa, en windows se debe cambiar a pause
break;
        case 2: 
        system("clear");
        printf("---------------\n");
        printf("DESENCRIPTACIÓN\n");
        printf("---------------\n");

        printf("\nIngrese palabra clave \n");
        scanf("%s", clave);

        //Abrir crypt.thm y leer su contenido
        crypt=fopen ("crypt.thm", "r");
        fscanf(crypt,"%s", palabra);
        fclose(crypt);

        //Calcula el factor sumando los valores ASCII de la clave
        while(clave[i]){
                factor+=clave[i];
                i++;
        }
        factor/=10;
        i=0;

        //Resta los valores ASCII para resfazar la palabra 
        while(palabra[i]){
                palabra[i]-=factor;
                i++;
        }
        i=0;
        factor=0;

        printf("La palabra desencriptada es: %s \n", palabra);

        printf("Presione cualquier tecla para continuar... \n");
        system("read -s"); //En windows se debe cambiar a pause
break;
        case 3:
        system("clear");
        printf("---------------------------------\n");
        printf("ENCRIPTADOR Y DESENCRIPTADOR v0.3\n");
        printf("---------------------------------\n");
        printf("C. Ing. Guillermo Fco. Themsel Montes\n");
        printf("Ingeniería Informatica\n");
        printf("© 2023\n \n");
        printf("Presione cualquier tecla para continuar... \n");
        system("read -s"); //En windows se debe cambiar a pause
break;
        case 0:
        printf("\n-----------------\n");
        printf("CERRANDO PROGRAMA\n");
        printf("-----------------\n");
break;
        default: 
        printf("\n----------------\n");
        printf("OPCIÓN INVALIDA\n");
        printf("----------------\n");
        printf("Presione cualquier tecla para continuar... \n");
        system("read -s"); //En windows se debe cambiar a pause
    }
    }   while(opc);
    return 0;

}