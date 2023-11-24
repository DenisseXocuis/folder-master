#include<stdio.h>
#include<stdlib.h>
void menu();
void pause();
void llenar(int **, int *, int);
void mostrar(int **, int *, int);

int main(){
    int op,**ap, e=1,n;
    do{
        system("cls || clear");
        menu();
        scanf("%d", &op);

        switch(op){
            case 1:
                    if(e == 1){
                        do{ 
                        printf("Ingresa el tamaño de la matriz nxn\n>"); scanf("%d", &n);
                        }while(n<=0);
                        ap = (int **)malloc(n * sizeof(int*)); //creando espacio en el puntero dependiendo del tamaño deseado del arreglo 
                        for(int i=0; i<n; i++){
                            for(int j=0; j<n; j++){ 
                                ap[i] = (int *)malloc(n * sizeof(int)); //creando espacio en la memoria para la fila num 1 y la que corresponde 
                            }
                        }
                        llenar(ap, &e,n);
                    }
                    else{
                    ap = (int **)malloc(n * sizeof(int*)); //creando espacio en el puntero dependiendo del tamaño deseado del arreglo 
                    for(int i=0; i<n; i++){
                            for(int j=0; j<n; j++){ 
                                ap[i] = (int *)malloc(n * sizeof(int)); //creando espacio en la memoria para la fila num 1 y la que corresponde 
                        }
                    }
                    llenar(ap, &e,n);
                    }
            break;
            case 2: mostrar(ap, &e, n);
            break;
            case 3: if(e == 1){
                    puts("ERROR! Cree una matriz desde la opcion 1 del menu");
                    pause();
                     }
                    else{
                        do{ system("cls || clear");
                        printf("Ingresa el nuevo tamaño de la matriz nxn\n>"); scanf("%d", &n);
                        }while(n<=0);
                        for(int i=0; i<n; i++){
                                free(ap[i]);
                        }
                        puts("LISTO!, la matriz ha sido redimensionada");
                        pause();
                    }
        }
    }while(op);

    return 0;
}

void menu(){
    puts("---------------------------");
    puts("Matriz con memoria dinamica");
    puts("---------------------------");
    puts("1: Llenar la matriz");
    puts("2: Mostrar la matriz");
    puts("3: Redimensionar la matriz");
    puts("0: Salir");
    printf("Opcion: \n>");
}

void pause(){
    puts("Pulse \"ENTER\" para continuar...");
    getchar();
    getchar();
}

void llenar(int **ap, int *error, int n){
    system("cls || clear");
    printf("EXCELENTE!, es hora de llenar la matriz %dx%d\n\n", n,n);
    for(int i=0; i<n; i++){ //llenado de matriz, fila
        for(int j=0; j<n; j++){ //llenado de matriz, columna
            printf("Llenado de elemento para la posicion %dx%d\n", i+1,j+1);
            scanf("%d", &ap[i][j]);
            putchar('\n');
        }
    }
    puts("LISTO!, ha llenado su matriz correctamente");
    *error = 0;
    pause();
}

void mostrar(int **ap, int *error, int n){
    if(*error==1){
        puts("ERROR! Cree una matriz desde la opcion 1 del menu");
        pause();
    }
    else{ system("cls || clear");
        printf("Mostrando la matriz %dx%d\n",n,n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("|%d|", ap[i][j]);
            }
            putchar('\n');
        }
        pause();
    }
}