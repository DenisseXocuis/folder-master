/*MÁQUINA DESPACHADORA*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void menu();
void pause();
void help();
void error(int);
void cam(float,float);

struct datos{ //datos de cada producto
    int clave,cantidad,tipo,vendidos;
    char nombre[30];
    float precio;
};
struct m{ //estructura de matriz
    struct datos **ap;
}matriz;

void csvProducto(struct datos **, int); //guardar archivo csv
void guardarRegistroCompras(struct datos **, int, float, float, float);
void guardarTicket(struct datos **, int);

int main(){
    int op,p=0,CLAVE,ac,cant,e=0,n,i,j,m=0,ticket; 
    float pago,din,totalDinero, totalBotanas, totalRefrescos;

        /*                    GUÍA DE VARIABLES
            op = variable de opciones para menu interactivo
            p = contador de productos registrados
            CLAVE = clave a buscar por producto
            ac = cantidad a actualizar
            cant = cantidad a comprar
            e = variable de control de las sentencias condicionales, determina si se encontró la información con éxito
            n = para el tamaño de matriz nxn
            i,j = variables de control
            m = variable de control para llenar matriz
            i_t, j_t= variables de control temporales
        */
    do{
        system("clear||cls");
        puts("Maquina Expendedora v0.4");
        printf("\nCantidad total de productos registrados: %d\n", p);
        putchar('\n');
        if(m == 1) //si m=1, existe una matriz creada
            menu();
        else{
            puts("[1] Crear matriz");
            puts("[8] Acerca de");
            puts("[0] Apagar");
        }
        printf("Opcion \n>");
        scanf("%d", &op);
        
        switch(op){
            case 1: /*CREACIÓN DE MATRIZ*/
                system("cls || clear");
                /*verificando e ingresando el valor de la matriz nxn*/
                do{printf("Ingresa el tamaño de la matriz nxn\n>"); scanf("%d", &n);
                }while(n<=0);
                /*generando espacio en la memoria dependiendo del tamaño deseado de la matriz*/
                matriz.ap = (struct datos**)malloc(n * sizeof(struct datos*));

                for(i=0; i<n; i++){
                    for(j=0; j<n; j++){ 
                        /*creando espacio en la memoria para la filas que correspondan*/
                        matriz.ap[i] = (struct datos*)malloc(n * sizeof(struct datos));
                    }
                }
                putchar('\n');
                printf("LISTO! Ha creado su matriz de %dx%d correctamente\n", n,n);
                m = 1; //matriz creada
                pause();
            break;
            /*ALTA DE PRODUCTOS*/
            case 2:
                if(p>=n*n){ //si el límite de productos registrados se sobrepasa, no se podrán agregar más productos
                    printf("\nCantidad total de productos registrados: %d\n", p);
                    error(1); //imprime el error 1 (sin espacio disponible)
                    break;
                }   
                for(i=0; i<n; i++){
                    for(j=0; j<n; j++){
                        //AGREGANDO PRODUCTOS EN LA MATRIZ
                        system("clear||cls");
                        puts("----------Alta de productos----------");
                        printf("Cantidad de productos registrados: %d\n", p);
                        printf("Posicion: %dx%d\n", i+1,j+1);
                        puts("-------------------------------------");
                        putchar('\n');
                        puts("Ingresa la clave del producto");
                        scanf("%d", &matriz.ap[i][j].clave);
                        getchar();
                        puts("Ingresa el nombre del producto");
                        gets(matriz.ap[i][j].nombre);
                        puts("Ingresa la cantidad del producto");
                        scanf("%d", &matriz.ap[i][j].cantidad);
                        printf("Ingresa el precio del producto ($$)\n");
                        scanf("%f", &matriz.ap[i][j].precio);
                        printf("Ingrese el tipo de producto (1:Refresco, 2:Botana)\n");
                        scanf("%d", &matriz.ap[i][j].tipo);
                        p++;
                        }
                    }
                    
            break;
            /*CONSULTA DE UN PRODUCTO*/
            case 3:
                e = 0;  //se inicializa e=0 porque esta variable se usa para cada caso, cambia a 1 si no hay ningun error con el proceso
                system("clear||cls");
                if(p<=0){ //si no hay productos registrados, imprime el error 3 (sin productos)
                    error(3);
                    break;
                }
                else{
                    printf("Ingresa la clave del producto a buscar\n>");
                    scanf("%d", &CLAVE);
                    for(i=0; i<n; i++){
                        for(j=0; j<n; j++){
                            if(matriz.ap[i][j].clave == CLAVE){ //si la clave es correcta y existe, imprime el producto
                                puts("----------Mostrando el producto------------");
                                printf("Nombre del producto: \t\t%s\n", matriz.ap[i][j].nombre);
                                printf("Cantidad \t\t\t%d\n", matriz.ap[i][j].cantidad);
                                printf("Precio  \t\t\t$%g\n", matriz.ap[i][j].precio);
                                printf("Tipo de producto \t\t");
                                if(matriz.ap[i][j].tipo==1) printf("Refresco\n");
                                else printf("Botana\n");
                                puts("---------------------------------------------");
                                e = 1; //si el producto fue encontrado devuelve "e" como 1 y rompe el ciclo
                                break;
                            }
                        }
                    }
                    if(e != 1) //si NO encuentra el producto (e=0), imprime error 2(no se encontró nada)
                        error(2);
                    else
                        pause();
                }
            break;
            /*ACTUALIZAR UN PRODUCTO*/
            case 4:
                e = 0;
                system("clear||cls");
                if(p<=0){ //si no hay productos registrados, imprime el error 3 (sin productos)
                        error(3);
                        break;
                    }
                else{
                    puts("----------Actualizar cantidad de productos------------");
                    putchar('\n');
                    puts("¿Cuanta cantidad desea agregar mas?");
                    scanf("%d", &ac);
                    printf("\nIngresa la clave del producto a actualizar\n>");
                    scanf("%d", &CLAVE);
                    /*busca el producto por medio de la clave*/
                    for(i=0; i<n; i++){
                        for(j=0; j<n; j++){
                            if(matriz.ap[i][j].clave == CLAVE){ //si encuentra la clave, actualiza la cantidad del producto
                                matriz.ap[i][j].cantidad += ac;
                                puts("La cantidad del producto ha sido actualizada");
                                e = 1; //si el producto fue encontrado devuelve "e" como 1 y rompe el ciclo
                                break;
                            }
                        }
                    }
                    if(e != 1) //si NO encuentra el producto (e=0), imprime error 2(no se encontró nada)
                        error(2);
                    else 
                        pause();
                }
            break;
            case 5: /*CONSULTA DE TODOS LOS PRODUCTOS*/
                system("clear||cls");
                if(p<=0){ //si no hay productos registrados, imprime el error 3 (sin productos)
                        error(3);
                        break;
                    }
                else{
                    puts("----------Mostrando información de los productos------------");

                     for(i = 0; i<n; i++){
                        for(j = 0; j<n; j++){
                            printf("Nombre del producto: \t\t%s\n", matriz.ap[i][j].nombre);
                            printf("Clave: \t\t\t\t%d\n", matriz.ap[i][j].clave);
                            printf("Cantidad \t\t\t%d\n", matriz.ap[i][j].cantidad);
                            printf("Precio  \t\t\t$%g\n", matriz.ap[i][j].precio);
                            printf("Tipo de producto \t\t");
                                if(matriz.ap[i][j].tipo==1) printf("Refresco\n");
                                else printf("Botana\n");
                            puts("---------------------------------------------");
                        }
                    }
                    int opcionGuardar;
                    printf("¿Desea guardar la información en un archivo? (1:Si, 2:No)\n>");
                    scanf("%d", &opcionGuardar);
                    if (opcionGuardar == 1)
                        csvProducto(matriz.ap, n);
                    pause();
                }
            break;
            case 6:
                e = 0;
                int i_t,j_t; //variables temporales
                system("clear||cls");
                if(p<=0){ //si no hay productos registrados, imprime el error 3 (sin productos)
                        error(3);
                        break;
                    }
                else{
                    puts("----------Comprar productos------------");
                    putchar('\n');
                    printf("Clave del producto a comprar: \n>");
                    scanf("%d", &CLAVE); //busca el producto e imprime su información
                    for(i = 0; i<n; i++){
                        for(j = 0; j<n; j++){
                            if(matriz.ap[i][j].clave == CLAVE){
                                puts("---------------------------------------------");
                                printf("Nombre del producto: \t\t%s\n", matriz.ap[i][j].nombre);
                                printf("Cantidad \t\t\t%d\n", matriz.ap[i][j].cantidad);
                                printf("Precio  \t\t\t$%g\n", matriz.ap[i][j].precio);
                                printf("Tipo de producto \t\t");
                                if(matriz.ap[i][j].tipo==1) printf("Refresco\n");
                                else printf("Botana\n");
                                puts("---------------------------------------------");
                                e = 1; //encontró el producto con éxito
                                break;
                            }
                        }
                    } //si hay éxito en la búsqueda, puede proceder con la compra
                    if(e!=0){
                        do{
                            printf("Cantidad a comprar:\n>");
                            scanf("%d", &cant); //ingresa cantidad a comprar
                        }while(cant<=0); //verifica si es positivo

                        for(i = 0; i<n; i++){
                            for(j=0; j<n; j++){
                                if(matriz.ap[i][j].clave == CLAVE){ //vuelve a posicionarse en el producto a comprar
                                    i_t=i; //fija la posición en variables temporales
                                    j_t=j;
                                    //si no hay productos disponibles a comprar o si la cantidad a comprar es mayor que la existente, imprime un error 
                                    if(matriz.ap[i][j].cantidad <= 0 || cant>matriz.ap[i][j].cantidad){
                                        e = 3; // no hay productos o excedio la cantidad del producto
                                        error(6); //imprime error 6 y rompe el ciclo
                                        break;
                                    }
                                    else {
                                        din = matriz.ap[i][j].precio * cant; //busca el valor del precio y multiplica por la cantidad a comprar
                                        printf("La cantidad a pagar es de: $%g, si esta de acuerdo con su compra, ingrese el dinero a pagar\n>", din);
                                        break; 
                                    }
                                }
                            }
                        }
                        if(e!=3){ //si hay productos disponibles
                            scanf("%f", &pago); //ingresa dinero a pagar
                            if(pago<din) //si el dinero no es suficiente imprime error 4
                                error(4); //No es dinero suficiente para pagar por el producto
                            else{ //si el dinero SI es suficiente:
                                    matriz.ap[i_t][j_t].cantidad -= cant; //resta la cantidad de productos que hay por la que se va a comprar
                                    matriz.ap[i_t][j_t].vendidos += cant; //acumula la cantidad de vendidos en esa posición
                                    cam(din, pago); //calcula el cambio
                                    totalDinero+=din; //acumula dinero recaudado

                                    //acumula lo recaudado por botanas o refrescos
                                    if (matriz.ap[i_t][j_t].tipo==1) totalRefrescos+=din;
                                    else totalBotanas+=din;
                                    printf("¿Desea guardar su ticket? (1:Si, 2:No)\n>");
                                    scanf("%d", &ticket);
                                    if (ticket == 1)
                                        guardarTicket(matriz.ap, n);
                                }
                        }
                    }
                    else{ //si no hay exito con la busqueda, imprime error 2
                        error(2); //No se encontro ningun producto con esa clave
                    }
                }
            break;
            case 7:
                system("clear||cls");
                if(p<=0){ //si no hay productos registrados, imprime el error 3 (sin productos)
                        error(3);
                        break;
                    }
                else{
                    guardarRegistroCompras(matriz.ap, n, totalDinero, totalRefrescos, totalBotanas);
                    // llama a la función para guardar el registro de compras sin dinero ni pago
                    pause();
                }
            break;
            case 8:
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

void menu(){
    puts("[2] Alta de productos");
    puts("[3] Consulta de un producto");
    puts("[4] Actualizar productos");
    puts("[5] Consulta de todos los productos");
    puts("[6] Comprar productos");
    puts("[7] Guardar registro de compras");
    puts("[8] Acerca de");
    puts("[0] Apagar");
    
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
        case 6: puts("ERROR: no hay productos o excedio la cantidad del producto");
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
    puts("[2] - Agregar productos de acuerdo al espacio de la maquina");
    puts("[3] - Mostrar la informacion de un producto en especifico");
    puts("[4] - Actualizar la cantidad de productos");
    puts("[5] - Mostrar todos los productos del inventario");
    puts("[6] - Comprar los productos");
    puts("[7] - Guardar en un archivo todas las compras realizadas");
    putchar('\n');
    puts("---------------------------------------------------------");
    puts("\t         Maquina Expendedora v0.4");
    puts("\t                   by");
    puts("\t    Ing. Themsel Montes Guillermo Francisco");
    puts("\t    Ing. Lara Xocuis Martha Denisse");
    puts("---------------------------------------------------------");
    puts("Ingeniería Informática S22 - 14 de diciembre del 2023");
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

void csvProducto(struct datos **ap, int n){
    int i,j;
    FILE *archivo;
    archivo = fopen("Productos.csv", "w"); //crea el archivo productos.csv =excel

    //escribe encabezados en el archivo .csv
    fprintf(archivo, "Clave,Nombre,Cantidad,Precio ($MXN),Tipo (1: Refresco 2:Botana)\n");

    for (i = 0; i<n; i++) {
        for (j = 0; j<n; j++) {
            fprintf(archivo, "%d,%s,%d,%.2f,%d\n", ap[i][j].clave, ap[i][j].nombre, ap[i][j].cantidad, ap[i][j].precio, ap[i][j].tipo);
        }
    }
    fclose(archivo);
    printf("Datos guardados en el archivo 'Productos.csv'\n");
}

void guardarTicket(struct datos **ap, int n){
    FILE *archivo;
    archivo = fopen("Ticket.txt", "w");

    fprintf(archivo, "COMPRA\n, ola");
}

void guardarRegistroCompras(struct datos **ap, int n, float din, float totalRefrescos, float totalBotanas) {
    FILE *archivo;
    archivo = fopen("RegistroCompras.csv", "a");

    fprintf(archivo, "Clave,Nombre,Cantidad Vendida,Precio ($MXN),Tipo (1: Refresco 2:Botana)\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fprintf(archivo, "%d,%s,%d,%.2f,%d\n", ap[i][j].clave, ap[i][j].nombre, ap[i][j].vendidos,
                    ap[i][j].precio, ap[i][j].tipo);
        }
    }
    fprintf(archivo, "Total recabado:,$%.2f\n", din);
    fprintf(archivo, "Total recabado refrescos:,$%.2f\n", totalRefrescos);
    fprintf(archivo, "Total recabado botanas:,$%.2f\n", totalBotanas);
    fclose(archivo);
    printf("Registro de compras guardado en el archivo 'RegistroCompras.csv'\n");
}