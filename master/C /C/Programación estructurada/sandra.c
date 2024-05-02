#include <stdio.h>
#include <stdlib.h>
struct salario{
	char nombre[30];
	char apellido[15];
    float sueldo;
};
struct salario empleados[100];
int i,j,personas;
float aux;

int main(){
     puts("===================================\n");
     puts("  REGISTRO DE SALARIOS\n");
     puts("===================================\n");
     printf("Numero de registros a realizar:");
     scanf("%d",&personas);
     for(i=0;i<personas;i++){
     	printf("EMPLEADO %d\n",i+1);

        printf("Ingresa tu primer nombre: \n");
        scanf("%s",empleados[i].nombre);
        printf("Ingresa tu primer apellido:\n");
        scanf("%s",empleados[i].apellido);
        printf("Sueldo: $\n");
        scanf(" %f", &empleados[i].sueldo);
        printf("\n");
	    }
	 system("cls");
	 
	for(i=0;i<personas;i++){
        for(j=0;j<personas-1;j++){
            if(empleados[j].sueldo> empleados[j+1].sueldo){
            aux = empleados[j].sueldo;
            empleados[j].sueldo=empleados[j+1].sueldo;
            empleados[j+1].sueldo = aux;

            //aquí meter algoritmo para ahora mover los nombres
            }
        }
    }
    
	 for(i=0;i<personas;i++){
	 	printf("EMPLEADO %d\n",i+1);
	 	printf("Empleado :%s",empleados[i].nombre,empleados[i].apellido);
	 	printf("\t\tSueldo: $%.2f",empleados[i].sueldo);
	 	printf("\n");
	 }
	  }