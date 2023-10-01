#include<stdio.h>
#include<stdlib.h>
#define T 2 //10, 5, 2 y 1|
void menu();
void pause();
/*dar de alta un producto y después agregar productos 
programa interactivo, busqueda de productos, insercion de productos, productos.

Mismo arreglo, dar de alta la N cantidad de productos,
poner inventario
productos: clave (C4 etc), consulta de productos (cuanto vale, información etc), tarjeta de credito*/
typedef struct{
    int clave,cantidad;//controlar cuanta producto n metimos 
    char nombre[35];
    float precio;
}datos;

int main(){
    int i,op,p=0;
    datos productos[T];
    
    do{
        system("clear||cls");
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:
                fflush(stdin);
                puts("--------Alta de productos--------");
                putchar('\n');
                for(int i = 0, op2 = 0; i<T; i++){
                system("clear||cls");
                puts("Ingresa la clave del producto");
                scanf("%d", &productos[i].clave);
                getchar();
                puts("Ingresa el nombre del producto");
                gets(productos[i].nombre);   
                puts("Ingresa la cantidad del producto");
                scanf("%d", &productos[i].cantidad);
                puts("Ingresa el precio del producto");
                scanf("%f", &productos[i].precio);
                p++; //pivote
                if((p+1)<=T){
                    puts("¿Desea agregar otro producto? (1:SI, 2:NO)");
                    scanf("%d", &op2);
                    if(op2==2)
                        break;
                    else if(op2!=1){
                        puts("ERROR: Introdujo una opcion invalida, se regresara al menu de opciones");
                        pause();
                        break;
                    }
                }
                else{
                    puts("Ya no hay espacio disponible para otro articulo, se regresara al menu de opciones");
                    pause();
                }
                }
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
                system("clear||cls");
                puts("----------Mostrando todos los productos------------");
                putchar('\n');
             for(int i = 0; i<p; i++){
                printf("Nombre del producto: \t%s\n", productos[i].nombre);
                printf("Clave: \t\t\t%d\n", productos[i].clave);
                printf("Cantidad \t\t\t%d\n", productos[i].cantidad);
                printf("Precio \t\t\t%d\n", productos[i].precio);
                puts("---------------------------------------------");
            }
            pause();
            break;
            case 5:
            break;
            case 0: putchar('\n');
                    puts("Apagando maquina....");
            break;
            default:

        }

    }while(op);

    return 0;
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
    puts("[3] Actualizar productos"); //cantidad
    puts("[4] Consulta de todos los productos");
    puts("[5] Comprar productos");
    puts("[6] Ayuda");
    puts("[0] Apagar");
    printf("Opcion \n>");

}

void pause(){
    puts("Pulse cualquier tecla para salir....");
    getchar();
    getchar();
}