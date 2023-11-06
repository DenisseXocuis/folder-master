#include<stdio.h>
#include<stdlib.h>
#define MAX 1
#define T 80
void menu();
void pause();

struct {
    char titulo[T], autor[T], editorial[T];
    unsigned int anyo, ejempl;
    float precio;
}libro[MAX];

int main(){
    unsigned int op,anio;
    do{
        system("cls || clear");
        menu();
        scanf("%d", &op);
        getchar();
    switch(op){
        case 1: 
            for(int i=0; i<=MAX; i++){
                system("cls || clear");
                printf("Ingrese el titulo del libro %d: \n>",i+1);
                fgets(libro[i].titulo, sizeof(libro[i].titulo), stdin);
                printf("Ingrese el autor: \n>");
                fgets(libro[i].autor, sizeof(libro[i].autor), stdin);
                printf("Ingrese la editorial: \n>");
                fgets(libro[i].editorial, sizeof(libro[i].editorial), stdin);
                printf("Ingrese el año de la publicacion: \n>");
                scanf("%d", &libro[i].anyo);
                printf("Ingrese el precio: \n>$");
                scanf("%f", &libro[i].precio);
                printf("Ingrese el numero de ejemplares: \n>");
                scanf("%d", &libro[i].ejempl);
                getchar();
            }
        break;

        case 2:
            if(libro[0].anyo == 0){
                puts("ERROR: No hay registros de ningun libro");
                pause();
            }
            else{
                system("cls || clear");
                puts("Ingrese el anio");
                scanf("%d", &anio);
                puts("Libros encontrados:");
                putchar('\n');
                for(int i=0; i<=MAX;i++){
                    if(anio == libro[i].anyo){
                        puts("-------------------------------");
                        printf("Titulo: %s\n", libro[i].titulo);
                        printf("Autor: %s\n", libro[i].autor);
                        printf("Editorial: %s\n", libro[i].editorial);
                        printf("Precio: $%g\n", libro[i].precio);
                        printf("Ejemplares: %d\n", libro[i].ejempl);
                    }
                    else{
                        puts("ERROR: No hay libros con ese año o el numero ingresado fue incorrecto");
                        break;
                    }
                }
            pause();
            getchar();
            }

        break;
        case 3:     
            if(libro[0].anyo == 0){
                puts("ERROR: No hay registros de ningun libro");
                pause();
            }
            else if(libro[0].ejempl < 2){
                
                pause();
            }
            else{
                system("cls || clear");
                puts("Libros con al menos 2 ejemplares disponibles:");
                for(int i=0; i<=MAX;i++){
                    if(libro[i].ejempl>=2){
                        puts("-------------------------------");
                        printf("Titulo: %s\n", libro[i].titulo);
                        printf("Autor: %s\n", libro[i].autor);
                        printf("Editorial: %s\n", libro[i].editorial);
                        printf("Precio: $%g\n", libro[i].precio);
                        printf("Ejemplares: %d\n", libro[i].ejempl);
                        }
                    }
                pause();
            }
        break;
        case 0: printf("\nSaliendo.....\n");
        break;
        default:puts("ERROR: Opcion no valida");
                pause();
        }

    }while(op);

}

void menu(){
    puts("1: Registrar libros");
    puts("2: Buscar por anio");
    puts("3: Libros con ejemplares disponibles");
    puts("0: Salir");
    printf("Opcion: \n>");
}

void pause(){
    printf("\nPulse ENTER para continuar....");
    getchar();
}