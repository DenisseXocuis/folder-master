#include<stdio.h>
#include<stdlib.h>
#define T 10 //50
void menu();
/*dar de alta un producto y después agregar productos 
programa interactivo, busqueda de productos, insercion de productos, productos.

Mismo arreglo, dar de alta la N cantidad de productos,
poner inventario
productos: clave (C4 etc), consulta de productos (cuanto vale, información etc), tarjeta de credito*/
typedef struct{
    int clave,cantidad;//controlar cuanta producto n metimos 
    char nombre[30], descrip[50];
    float precio;
}datos;

int main(){
    int i,op,op2;
    datos productos[T];
    menu();
    scanf("%d", &op);
    do{
        switch(op){
            case 1: for(int i= 0; i<T; i++){
                system("clear||cls");
                puts("--------Alta de productos--------");
                putchar('\n');
                puts("Ingresa el nombre del producto");
                scanf("%s", &productos[i].nombre);
                puts("Ingresa la descripción del producto");
                scanf("%s", &productos[i].descrip);
                puts("Ingresa la clave del producto");
                scanf("%d", &productos[i].clave);
                puts("Ingresa la cantidad del producto");
                scanf("%d", &productos[i].cantidad);
                puts("Ingresa el precio del producto");
                scanf("%f", &productos[i].precio);
                puts("¿Desea agregar otro producto?. (1:SI, 2:NO)");
                scanf("%d", &op2);
            }  
            break;
            case 2:
            break;
            case 3: puts("----------Mostrando todos los productos------------");
            for(int i = 0; i<T; i++){
                printf("Nombre del producto: \t%s\n", productos[i].nombre);
                printf("Descripcion: \t%s\n", productos[i].descrip);
                printf("Clave: \t%d\n", productos[i].clave);
                printf("Cantidad \t%d\n", productos[i].cantidad);
                printf("Precio \t%d\n", productos[i].precio);
                puts("---------------------------------------------");
            }
            break;
            case 4:
            break;
            case 0: putchar('\n');
                    puts("Apagando maquina....");
            break;
            default:

        }

    }while(op);
}

void menu(){
    putchar('\n');
    puts("      Maquina Expendedora v0.1");
    putchar('\n');
    puts(" ___________________________________");
    puts("||    |    |    |    |||           ||");
    puts("|| A1 | A2 | A3 | A4 |||           ||");
    puts("||    |    |    |    |||           ||");
    puts("||-------------------|||           ||");
    puts("||    |    |    |    |||           ||");
    puts("|| B5 | B6 | B7 | B8 |||  _______  ||");
    puts("||    |    |    |    ||| |1|2|3|A| ||");
    puts("||-------------------||| |4|5|6|B| ||");
    puts("||    |    |    |    ||| |7|8|9|C| ||");
    puts("|| C9 | C0 | C1 | C2 ||| | | 0 |D| ||");
    puts("||    |    |    |    |||  ¯¯¯¯¯¯¯  ||");
    puts("||-------------------|||           ||");
    puts("||    |    |    |    |||           ||");
    puts("|| D3 | D4 | D5 | D6 |||           ||");
    puts("||    |    |    |    |||           ||");
    puts("||¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|||¯¯¯¯¯¯¯¯¯¯¯||");
    putchar('\n');
    puts("[1] Alta de productos (inventario)");
    puts("[2] Consulta de un producto");
    puts("[3] Consulta de todos los productos");
    puts("[4] Comprar productos");
    puts("[0] Apagar");
    printf("Opcion \n>");

}