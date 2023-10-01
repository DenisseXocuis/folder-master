#include<stdio.h>
#include<stdlib.h>
#define T 40
void menu(int p);
void pause();
void help();
void error(int err_);
void cam(float din,float pago);

typedef struct{
    int clave,cantidad;
    char nombre[30];
    float precio;
}datos;

int main(){
    int op,op2,p=0, clave2,ac,cant,err_,e=0,j=0;
    float pago,din;
    datos productos[T];
    
    do{
        system("clear||cls");
        menu(p);
        scanf("%d", &op);
        
        switch(op){
            case 1:
                for(j,op2 = 1; j<=T; j++){
                system("clear||cls");
                if(p>=T){
                    printf("\nCantidad total de productos registrados: %d\n", p);
                    error(1);
                    break;
                }
                else{
                puts("----------Alta de productos----------");
                printf("Cantidad de productos registrados: %d\n", p);
                puts("-------------------------------------");
                putchar('\n');
                puts("Ingresa la clave del producto");
                scanf("%d", &productos[j].clave);
                getchar();
                puts("Ingresa el nombre del producto");
                gets(productos[j].nombre);   
                puts("Ingresa la cantidad del producto");
                scanf("%d", &productos[j].cantidad);
                puts("Ingresa el precio del producto ($$)");
                scanf("%f", &productos[j].precio);
                p++;
                    if(p<=T){
                        while(op2){
                            puts("¿Desea agregar otro producto? (1:SI, 2:NO)");
                            scanf("%d", &op2);
                            if(op2==1 || op2==2)
                                break;
                        }
                        if(op2==2){
                            j++;
                            break;
                        }
                    }
                }
                }
            break;
                case 2:
                    e = 0;
                    system("clear||cls");
                    if(p<=0){
                        error(3);
                        break;
                    }
                    else{
                        printf("Ingresa la clave del producto a buscar\n>");
                        scanf("%d", &clave2);
                        for(int i = 0; i<=p; i++){
                        if(productos[i].clave == clave2){
                            puts("----------Mostrando el producto------------");
                            printf("Nombre del producto: \t\t%s\n", productos[i].nombre);
                            printf("Cantidad \t\t\t%d\n", productos[i].cantidad);
                            printf("Precio  \t\t\t$%g\n", productos[i].precio);
                            puts("---------------------------------------------");
                            e = 1;
                            break;
                        }
                        }
                        if(e != 1)
                            error(2);
                        else
                            pause();
                    }
            break;
            case 3:
                e = 0;
                system("clear||cls");
                if(p<=0){
                        error(3);
                        break;
                    }
                else{
                puts("----------Actualizar cantidad de productos------------");
                putchar('\n');
                puts("¿Cuanta cantidad desea agregar mas?");
                scanf("%d", &ac);
                printf("\nIngresa la clave del producto a actualizar\n>");
                scanf("%d", &clave2);
                for(int i = 0; i<=p; i++){
                    if(productos[i].clave == clave2){
                        productos[i].cantidad += ac;
                        puts("La cantidad del producto ha sido actualizada");
                        e = 1;
                        break;
                    }
                }
                if(e != 1)
                    error(2);
                else 
                    pause();
                }
            break;
            case 4:
                system("clear||cls");
                if(p<=0){
                        error(3);
                        break;
                    }
                else{
                puts("----------Mostrando información de los productos------------");
             for(int i = 0; i<p; i++){
                printf("Nombre del producto: \t\t%s\n", productos[i].nombre);
                printf("Clave: \t\t\t\t%d\n", productos[i].clave);
                printf("Cantidad \t\t\t%d\n", productos[i].cantidad);
                printf("Precio  \t\t\t$%g\n", productos[i].precio);
                puts("---------------------------------------------");
                }
                pause();
                }
            break;
            case 5:
                e = 0;
                system("clear||cls");
                if(p<=0){
                        error(3);
                        break;
                    }
                else{
                puts("----------Comprar productos------------");
                putchar('\n');
                printf("Clave del producto a comprar: \n>");
                scanf("%d", &clave2);
                for(int i = 0; i<=p; i++){
                    if(productos[i].clave == clave2){
                    puts("---------------------------------------------");
                    printf("Nombre del producto: \t\t%s\n", productos[i].nombre);
                    printf("Cantidad \t\t\t%d\n", productos[i].cantidad);
                    printf("Precio  \t\t\t$%g\n", productos[i].precio);
                    puts("---------------------------------------------");
                    e=1;
                    break;
                    }
                    }
                if(e!=0){
                    puts("Cantidad a comprar:");
                    scanf("%d", &cant);
                    
                    for(int i = 0; i<=p; i++){
                    if(productos[i].clave == clave2){
                        din = productos[i].precio * cant;
                        if(productos[i].cantidad == 0){
                            e = 3;
                            error(5);
                            break;
                        }
                        else {
                            printf("La cantidad a pagar es de: $%g, si esta de acuerdo con su compra, ingrese el dinero a pagar\n>", din);
                            break;
                        }
                    }
                    }
                    if(e!=3){
                    scanf("%f", &pago);
                    if(pago<din)
                        error(4);
                    else {
                        for(int i = 0; i<=p; i++){
                        if(productos[i].clave == clave2)
                            productos[i].cantidad -= cant;
                            if(productos[i].cantidad < 0){
                                e = 3;
                                error(5);
                                break;
                            }
                        }
                        if(e!=3)
                            cam(din,pago);
                    }}
                }
                else{
                    error(2);
                }
                }
            break;
            case 6:
                    system("clear||cls");
                    help();
                    pause();
            break;
            case 0: putchar('\n');
                    puts("Apagando maquina....");
            break;
            default:    error(0);

        }

    }while(op);

    return 0;
}

void menu(int p){
    putchar('\n');
    puts("      Maquina Expendedora v0.3");
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
    printf("\nCantidad total de productos registrados: %d\n", p);
    printf("Espacio máximo: %d\n", T);
    putchar('\n');
    puts("[1] Alta de productos");
    puts("[2] Consulta de un producto");
    puts("[3] Actualizar productos");
    puts("[4] Consulta de todos los productos");
    puts("[5] Comprar productos");
    puts("[6] Acerca de");
    puts("[0] Apagar");
    printf("Opcion \n>");
}

void pause(){
    puts("Pulse cualquier tecla para continuar....");
    getchar();
    getchar();
}
void error(int err_){
    switch (err_){
        case 1: puts("ERROR: Sin espacio disponible, se regresara al menu de opciones");
                pause();
        break;
        case 2: puts("ERROR: No se encontro ningun producto con esa clave");
                pause();
        break;
        case 3: puts("ERROR: No hay ningun producto dentro de la maquina");
                pause();
        break;
        case 4: puts("ERROR: No es dinero suficiente para pagar por el producto");
                pause();
        break;
        case 5: puts("ERROR: Sin productos disponibles para comprar"); 
                pause();
        break;
        case 0: puts("ERROR: Opcion no valida");
                pause();
        break;

    }
}
void help(){
    puts("------------------------Acerca de------------------------");
    putchar('\n');
    puts("[1] - Agregar productos de acuerdo al espacio de la maquina");
    puts("[2] - Mostrar la informacion de un producto en especifico de acuerdo a su clave");
    puts("[3] - Actualizar la cantidad de productos");
    puts("[4] - Mostrar todos los productos del inventario");
    puts("[5] - Comprar los productos");
    putchar('\n');
    puts("---------------------------------------------------------");
    puts("\t         Maquina Expendedora v0.3");
    puts("\t    by Ing. Lara Xocuis Martha Denisse");
    puts("---------------------------------------------------------");
    puts("Ingeniería Informática S22 - 1ro de Octubre del 2023");
    putchar('\n');
    
}

void cam(float din, float pago){
    float d2,c2,dos2,cen2,cambio;
    int d,c,dos,cen;

    cambio = pago - din;
    printf("\nCambio: %g peso(s)\n",cambio);
    putchar('\n');
    puts("Se le entrega a usted");
    d = cambio/10;
    d2 = cambio - (d * 10); 
    printf("\n%d monedas de 10",d);
    c = d2/5;
    c2 = d2 - (c * 5);
    printf("\n%d monedas de 5",c);
    dos = c2/2;
    dos2 = c2- (dos * 2);
    printf("\n%d monedas de 2",dos);
    cen = dos2/1;
    cen2 = dos2 - cen;
    printf("\n%d monedas de 1",cen);
    printf("\n%g centavo(s)\n",cen2);
    putchar('\n');
    puts("MUCHAS GRACIAS POR SU COMPRA");
    puts("Imprimiendo ticket......");
    putchar('\n');
    pause();
}