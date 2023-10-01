#include<stdio.h>
#include<stdlib.h>
#define T 30

void menu(int pos);
void pausa();
void salir();
void info();
void error(int opc_error);
void cambio(float opc_dinero);

typedef struct{
    int clave;
    char nombre[T];
    float precio;
    int cantidad;
} datos;

int main(){
    datos productos[T];
    int i, opc, pos=1, opc_prod, opc_cantidad;
    float opc_dinero;

	
	do{
		menu(pos);
		scanf("%d", &opc);

		switch(opc){
			case 1:
                system("clear||cls");
                puts("----------------------");
                puts("---ALTA DE PRODUCTO---");
                puts("----------------------");
                if(pos>115)
                    error(4);
                    else{
                        printf("Cantidad de productos registrados: %d\n", pos-1);
                        printf("Ingresa la clave\n");
                        scanf("%d", &productos[pos].clave);
                        printf("Ingresa el nombre\n");
                        scanf("%s", &productos[pos].nombre);
                        printf("Ingresa el precio\n");
                        scanf("%f", &productos[pos].precio);
                        printf("Ingresa la cantidad\n");
                        scanf("%d", &productos[pos].cantidad);
                        printf("Producto guardado en la posición: %d\n", pos);
                        pos++;
                    }
                pausa();
				break;
			case 2:
                system("clear||cls");
                puts("-------------------------------");
                puts("---ACTUALIZACIÓN DE PRODUCTO---");
                puts("-------------------------------");

                if(pos>1){
                printf("Ingrese el número del producto a actualizar\n");
                scanf("%d", &opc_prod);
                    if(opc_prod<1)
                        error(0);
                        else if(opc_prod<pos){
                            printf("Cantidad de productos registrados: %d\n", pos-1);
                            printf("Ingresa la clave\n");
                            scanf("%d", &productos[opc_prod].clave);
                            printf("Ingresa el nombre\n");
                            scanf("%s", &productos[opc_prod].nombre);
                            printf("Ingresa el precio\n");
                            scanf("%f", &productos[opc_prod].precio);
                            printf("Ingresa la cantidad\n");
                            scanf("%d", &productos[opc_prod].cantidad);
                        }
                            else if(opc_prod>115)
                                error(3);
                                else
                                    error(2);
                }
                else
                    error(1);
                pausa();
                break;
			case 3:
                system("clear||cls");
                puts("--------------------------");
                puts("---CONSULTA DE PRODUCTO---");
                puts("--------------------------");
                
                if(pos>1){
                printf("Cantidad de productos registrados: %d\n", pos-1);
                printf("Ingrese el número del producto a consultar\n");
                scanf("%d", &opc_prod);
                    if(opc_prod<1)
                        error(0);
                        else if(opc_prod<pos){
                            printf("Clave: %d\n", productos[opc_prod].clave);
                            printf("Nombre: %s\n", productos[opc_prod].nombre);
                            printf("Precio: $%g\n", productos[opc_prod].precio);
                            printf("Cantidad disponible: %d\n", productos[opc_prod].cantidad);
                        }
                            else if(opc_prod>115)
                                error(3);
                                else
                                    error(2);
                }
                else
                    error(1);
                pausa();
                break;
			case 4:
                system("clear||cls");
                puts("-------------------------");
                puts("---LISTADO DE PRODUCTO---");
                puts("-------------------------");
        
                if(pos>1){
                    printf("Cantidad de productos registrados: %d\n", pos-1);
                    for(i=1; i<pos; i++){
                        printf("Clave: %d\n", productos[i].clave);
                        printf("Nombre: %s\n", productos[i].nombre);
                        printf("Precio: $%g\n", productos[i].precio);
                        printf("Cantidad disponible: %d\n", productos[i].cantidad);
                        printf("-------------------------\n");
                    }
                }
                else
                    error(1);
                pausa();
                break;
			case 5:
                system("clear||cls");
                puts("------------------------");
                puts("---COMPRA DE PRODUCTO---");
                puts("------------------------");

                if(pos>1){
                printf("Ingrese el número del producto a comprar\n");
                scanf("%d", &opc_prod);
                    if(opc_prod<1)
                        error(0);
                        else if(opc_prod<pos){
                            if(productos[opc_prod].cantidad>0){
                            puts("Producto a comprar:");
                            printf("Clave: %d\n", productos[opc_prod].clave);
                            printf("Nombre: %s\n", productos[opc_prod].nombre);
                            printf("Precio: $%g\n", productos[opc_prod].precio);
                            printf("Cantidad disponible: %d\n\n", productos[opc_prod].cantidad);
                            puts("Ingrese la cantidad a comprar");
                            scanf("%d", &opc_cantidad);
                            if(opc_cantidad<=productos[opc_prod].cantidad){
                                printf("Cantidad a pagar: %g\n", productos[opc_prod].precio*opc_cantidad);
                                puts("Ingrese la cantidad con la que pagará");
                                scanf("%f", &opc_dinero);
                                if (opc_dinero>=productos[opc_prod].precio*opc_cantidad){
                                    productos[opc_prod].cantidad=productos[opc_prod].cantidad-opc_cantidad;
                                    printf("Su cambio es: %g\n", opc_dinero-productos[opc_prod].precio*opc_cantidad);
                                    cambio(opc_dinero-productos[opc_prod].precio*opc_cantidad);
                                } 
                                    else   
                                        error(6);
                            }
                            else
                            error(7);
                                }
                                else   
                                error(5);
                        }
                            else if(opc_prod>115)
                                error(3);
                                else
                                    error(2);
                }
                else
                    error(1);
                pausa();
                break;
			case 9:
				info();
                break;
			case 0:
				salir();
                break;
			default:
				error(0);
                pausa();
                break;
		}
	} while(opc);
	return 0;
    
}

void menu(int pos){
    system("clear||cls");
    puts("-------------------------------------");
    puts("---EJERCICIO 2 MAQUINA EXPENDEDORA---");
    puts("-------------------------------------");
    if(pos>1){
        printf("Cantidad de productos registrados: %d\n", pos-1);
        puts("[1] Alta de productos");
        puts("[2] Actualizar productos");
        puts("[3] Consulta de un producto");
        puts("[4] Mostrar todos los productos");
        puts("[5] Comprar productos");
    }
    else{
        puts("[1] Alta de productos");
    }
    puts("[9] Acerca de...");
    puts("[0] Salir...");
    printf("Seleccione una opción... \n>");
}

void info(){
    system("clear||cls");
    puts("-------------------------------------");
    puts("---EJERCICIO 2 MAQUINA EXPENDEDORA---");
    puts("-------------------------------------");
    puts("C. Ing. Guillermo Fco. Themsel Montes");
    puts("Ingeniería Informatica");
    puts("© 2023\n");
    puts("Programa creado y probado en sistema tipo UNIX");
    puts("En caso de existir problemas, contactar al desarrollador");
    pausa();
}

void salir(){
    puts("-----------------------");
    puts("---CERRANDO PROGRAMA---");
    puts("-----------------------");
}

void pausa(){
    printf("Presione cualquier tecla para continuar . . . ");
    fflush(stdin);
    getchar();
    getchar();
}

void error(int opc_error){
    const char* err_txt;
    switch (opc_error){
    case 0:
        err_txt="Opción no valida";
        break;
    case 1:
        err_txt="Productos no existentes, dé de alta uno";
        break;
    case 2:
        err_txt="Opción no valida, producto no existente";
        break;
    case 3:
        err_txt="Opción no valida, valor muy grande";
        break;
    case 4:
        err_txt="Cantidad máxima de productos alcanzada";
        break;
    case 5:
        err_txt="Producto fuera de existencia";
        break;
    case 6:
        err_txt="Cantidad no suficiente";
        break;
    case 7:
        err_txt="No hay suficiente producto";
        break;
    default:
        err_txt="Error no identificado, contacte al desarrollador";
        break;
    }
    printf("ERROR %d: %s\n", opc_error, err_txt);
}

void cambio(float cantidad){
  int monedas_10 = 0, monedas_5 = 0, monedas_2 = 0, monedas_1 = 0;
  float cambio_restante = 0;
  while (cantidad >= 10) {
    monedas_10++;
    cantidad -= 10;
  }
  while (cantidad >= 5) {
    monedas_5++;
    cantidad -= 5;
  }
  while (cantidad >= 2) {
    monedas_2++;
    cantidad -= 2;
  }
  monedas_1 = (int)cantidad;
  cambio_restante = cantidad - monedas_1;
  printf("Monedas de 10 pesos: %d\n", monedas_10);
  printf("Monedas de 5 pesos: %d\n", monedas_5);
  printf("Monedas de 2 pesos: %d\n", monedas_2);
  printf("Monedas de 1 peso: %d\n", monedas_1);
  printf("Cambio restante: %.1f\n", cambio_restante);

}