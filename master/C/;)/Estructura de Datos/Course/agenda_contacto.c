//librerias
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define T 20 //numero maximo de contactos en la agenda

typedef struct{
	char nombre[65];
	char numero[11];
	char correo[60];
	
}datos;  //definicion de la estructura

//prototipos de funciones
void menu();
void agregar_contacto(datos contactos[],int *p);
void buscar_contacto(datos contactos[],int p);
void mostrar_contacto(datos contactos[],int p);


int main(){
	datos contactos[T];
	int p=0; //contador de contactos
	int op;
	
	do{
	system("clear"); // Limpiar la pantalla
		menu();
		scanf("%d",&op);
		getchar(); // Consumir el salto de l�nea
		
		switch(op){
			case 1: agregar_contacto(contactos, &p);
			        break;
			case 2: buscar_contacto(contactos, p);
			        break;
			case 3: mostrar_contacto(contactos, p);
					getchar();
			        break;
			case 0: puts("Saliendo...");
					break;
			default: puts("Opcion no valida..");
					break;
		}
		
	}while (op!=0);
	return 0;
}

void agregar_contacto(datos contactos[], int *p){
	int op;
	if (*p >= T) {
        printf("La agenda esta llena. No se pueden agregar mas contactos.\n");
        return;
	}
	
	printf("Ingresa el nombre del contacto: ");
	scanf("%s",&contactos[*p].nombre);
	printf("Ingresa el numero telefonico:");
	scanf("%s",&contactos[*p].numero);
	printf("Ingresa el correo electronico:");
	scanf("%s",&contactos[*p].correo);
	p++;
	printf("CONTACTO AGREGADO CON EXITO\n");
	
	printf("\nDesea anadir otro contacto");
	printf("0) No");
	printf("1) Si");
	scanf("%d",&op);
	if(op!= 1 && op !=0)
	puts("Opcion no valida...");	
}

void buscar_contacto(datos contactos[], int p){
	int i;
	char nombreBusqueda[65];
    printf("Ingrese el nombre del contacto a buscar: ");
    scanf("%s", nombreBusqueda);
    for (i= 0;i<p;i++) {
        if (strcmp(contactos[i].nombre, nombreBusqueda) == 0) {
            printf("Contacto encontrado:\n");
            printf("Nombre: %s\n", contactos[i].nombre);
            printf("N�mero: %s\n", contactos[i].numero);
            printf("Correo: %s\n", contactos[i].correo);
            printf("-----------------------------------------------\n");
            return;
        }
    }
    printf("Contacto no encontrado.\n");	
}

void mostrar_contacto(datos contactos[], int p){
	    if (p == 0) {
        printf("No hay contactos en la agenda.\n");
        return;
    }

	int i;
    for (i = 0; i < p; i++) {
        printf("Contacto %d:\n", i + 1);
        printf("Nombre: %s\n", contactos[i].nombre);
        printf("N�mero: %s\n", contactos[i].numero);
        printf("Correo: %s\n", contactos[i].correo);
        printf("----------------------------\n");
    }
	
}


void menu(){
	puts("------------------------------------");
	puts("--------AGENDA DE CONTACTOS--------");
	puts("------------------------------------");
	puts("[1]  Resgistrar contacto");
	puts("[2]  Buscar contacto");
	puts("[3]  Mostrar todos los contactos");
	puts("[0]  Salir");
	puts("\nSeleccione una opcion: ");	

}


