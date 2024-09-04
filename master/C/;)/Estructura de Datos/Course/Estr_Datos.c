#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 3

typedef struct Datos{
    char nombre[65], numero[11], correo[60];
}datos;

void mostrar_menu();
void agregar_contactos(datos contactos[], int p);
void buscar_contactos(datos contactos[], int p, char nombre[]);

int main(){
    datos contactos[T];
    int p=0, op;
    char nombre[65];

    do{
    system("clear");
    mostrar_menu();
    scanf("%d", &op);
    switch (op)
    {
    case 1: agregar_contactos(contactos, p);
        break;
    case 2: printf("Ingrese nombre a buscar\n");
            scanf("%s", &nombre);
            buscar_contactos(contactos, p, nombre);
            getchar();
            getchar();

        break;
    case 3: while(p<T){
            printf("%s\n", contactos[p].nombre);
            printf("%s\n", contactos[p].numero);
            printf("%s\n", contactos[p].correo);
            p++;
            printf("\n");
            }   
            getchar();
            getchar();
            break;
    default: puts("Saliendo del programa");
            getchar();
        break;
    }
    }while(op);
}


void mostrar_menu(){
    puts("Programa Agenda de Contactos");
    puts("1) Agregar contactos");
    puts("2) Buscar por nombre");
    puts("3) Mostrar todos los contactos");
    puts("0) Salir del programa");
}

void agregar_contactos(datos contactos[], int p){
    int op;
    printf("Contacto: %d\n", p+1);
    printf("Ingresa el nombre del contacto: ");
    scanf("%s", &contactos[p].nombre);
    printf("Ingresa el numero del contacto: ");
    scanf("%s", &contactos[p].numero);
    printf("Ingresa el correo del contacto: ");
    scanf("%s", &contactos[p].correo);
    p++;
    printf("\n");
    if(p<T)
        agregar_contactos(contactos,p);
}

void buscar_contactos(datos contactos[], int p, char nombre[]){
    if(strcmp(nombre, contactos[p].nombre) == 0){
        puts("Se ha encontrado el contacto: ");
        printf("%s\n", contactos[p].nombre);
        printf("%s\n", contactos[p].numero);
        printf("%s\n", contactos[p].correo);
    }
    else if(p<T){
        p++;
        buscar_contactos(contactos,p,nombre);
    }
    else puts("No se ha registrado el usuario");
}
