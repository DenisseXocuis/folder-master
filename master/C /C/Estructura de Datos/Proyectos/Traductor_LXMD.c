/* INFORMATION::::
    Desarrollar  un traductor de JSON a XML y viceversa  usando el lenguaje C-99 (el visto en clase)  y estructuras de datos como  listas, colas y pilas implementados usando recursión, cada ejercicio estará guardado en un archivo de texto (archivo.xml) proporcionado por el usuario y lo devolverá en otro archivo (archivo_salida.json). Por ejemplo, el libro expresado anteriormente en XML  se representaría:

    libro.xml  -> libro.json
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

// vv control de entrada de archivo
enum _bool{FALSE, TRUE}BOOL; 

// vv para que se vea bonito ;)
void loading();
void menu();
void pause();
void about();

int main(){
    int op;
    BOOL = FALSE;  //<- no hay entrada de ningún archivo
    //loading(); 
    do{ 
            //just para verificar que se escoja una opcion de las mostradas (1,4 y 0)
            do{ menu(BOOL);
                scanf("%d", &op);
            }while(BOOL == FALSE && op != 1 && op !=4 && op != 0);

        switch(op){
            case 1: system("cls || clear");
                    FILE *archivo;
                    char name[256]; 
                    puts("Escriba el nombre del archivo");
                    printf("Sigue la estructura de: [nombre].[json/xml]\n>");
                    scanf("%s", name);
                    archivo = fopen(name, "r");
                    if(archivo != NULL){
                        BOOL = TRUE; //<- existe entrada del archivo
                        pause();
                    }
                    else{
                        puts("ERROR! No se encontro el archivo");
                        pause();
                    }  
            break;
            case 2: 
            break;
            case 3:
            break;
            case 4: about();
                    pause();
            break;
            default: puts("Au revoir");
            break;
        }
    }while(op);

    return 0;
}

void menu(enum _bool BOOL){
    system("cls || clear");
    puts("~*============={            }===============*~");
    puts("   ¡BIENVENIDO AL TRADUCTOR DE JSON A XML!");
    if(!BOOL){ //<- si no hay entrada de archivo
        puts("[1]. Subir archivo");
        puts("[4]. About");
        puts("[0]. Salir del programa");
        puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
        printf("\tOpcion: \n>");
    } 
    else{
        puts("[1]. Cambiar archivo");
        puts("[2]. JSON -> XML");
        puts("[3]. XML  -> JSON");
        puts("[4]. About");
        puts("[0]. Salir del programa");
        puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
        printf("\tOpcion: \n>");

    }
}

void loading(){
    for(int i=0;i<1; i++){
        system("cls || clear");
        printf("Loading \"Traductor_LXMD.c\"");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
        printf(".");
        fflush(stdout);
        sleep(1);
    }

    system("cls || clear");
}

void pause(){
    puts("Presione ENTER para volver al menu de opciones");
    getchar();
    getchar();
}

void about(){
    system("cls || clear");
    puts("~*============={            }===============*~");
    puts("\tTraductor de JSON a XML v0.1");
    puts("\t\t     by:");
    puts("    ©Lara Xocuis Martha Denisse. S22002213");
    puts("          Ingenieria en Informatica");
    puts("\t    \"Estructura de Datos\"");
    puts("~*==========================================*~");

}

