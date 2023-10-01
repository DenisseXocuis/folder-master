#include<stdio.h>
#include<stdlib.h>
#define T 50
void menu();
void pausa();
void salir();
void info();
void error();

typedef struct{
    int clave;
    char nombre[T];
    char descripcion[T];
    float precio;
    int cantidad;
} datos;

int main(){
    datos productos[T];
    int i, opc, p=0;

	
	do{
		menu();
		scanf("%d", &opc);
		switch(opc){
			case 1:
				printf("Ingresa la clave\n");
				scanf("%d", &productos[p].clave);
				printf("Ingresa el nombre\n");
				scanf("%s", &productos[p].nombre);
				printf("Ingresa el precio\n");
				scanf("%f", &productos[p].precio);
				printf("Ingresa la cantidad\n");
				scanf("%d", &productos[p].cantidad);
				p++;
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 9:
				info();
			case 0:
				salir();
			default:
				error();
		}
	} while(opc);
	return 0;
    
}

void menu(){
    system("clear||cls");
    puts("---------------------------");
    puts("ACTIVIDAD CLASE 25 SEP 2023");
    puts("---------------------------");
    puts("[1] Alta de productos");
    puts("[2] Actualizar productos");
    puts("[3] Consulta de un producto");
    puts("[4] Mostrar todos los productos");
    puts("[5] Comprar productos");
    puts("[9] Acerca de...");
    puts("[0] Salir...");
    puts("Seleccione una opción... \n>");
}

void pausa(){
    printf("Presione cualquier tecla para continuar . . . ");
    fflush(stdin);
    getchar();
}

void salir(){
    puts("\n-----------------");
    puts("CERRANDO PROGRAMA");
    puts("-----------------");
}

void info(){
    system("clear||cls");
    puts("---------------------------");
    puts("ACTIVIDAD CLASE 25 SEP 2023");
    puts("---------------------------");
    puts("C. Ing. Guillermo Fco. Themsel Montes");
    puts("Ingeniería Informatica");
    puts("© 2023\n");
    pausa();
}

void error(){
    puts("\n-----------------");
    puts("OPCION NO VALIDA");
    puts("-----------------");
}
