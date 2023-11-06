#include<stdio.h>
#define MAX 2 // cantidad de estudiantes
#define T 30
struct { //estructura para registro de datos
    char nombre[T];
    unsigned int matricula, carrera;
}datos[MAX]; // vector de 50 estructuras

struct{ //estructura de 1 miembro contador para 3 variables(3 carreras)
    int c;
}elco,mctr,inf;

int main(){
    for(int i = 0; i<=MAX ; i++){ //recolección de datos hasta el límite de estudiantes
        system("cls || clear");
        printf("Ingrese el nombre completo del estudiante %d: \n>", i+1);
        scanf("%[^\n]", datos[i].nombre); //%[^\n] permite ingresas una cadena incluyendo el espacio
        printf("Ingrese su matricula: \n>S");
        scanf("%d", &datos[i].matricula);
        printf("Ingrese su carrera: \n\t1: Electronica\n\t2: Mecatronica\n\t3: Informatica\n>");
        do{ //bucle hasta que se ingrese una opción válida
        scanf("%d", &datos[i].carrera);
            if(datos[i].carrera == 1)elco.c++; //suma cantidad por carrera
            else if(datos[i].carrera == 2) mctr.c++;
            else inf.c++;
        }while(datos[i].carrera>3 || datos[i].carrera<1);
        getchar();
    }
    system("cls || clear");
    printf("Cantidad total de estudiantes: %d\n", MAX+1);
    puts("Cantidad de estudiantes por cada carrera:");
    printf("\tElectronicos: %d\n", elco.c);
    printf("\tMecatronicos: %d\n", mctr.c);
    printf("\tInformaticos: %d\n", inf.c);

    return 0;
}


