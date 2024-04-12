/* Estoy jugando con la memoria dinamica para hacer mas desafiantes los programas, ahora solo me falta ver
   como deasignar la memoria :D*/
/* No supe que datos agregar al registro si que espero que este correcto */
/* Creo que el codigo original ya cumple con los requisitos de asi que lo reenvio sin cambios (•̀ᴗ•́)و ̑̑* */
/* Carlos Eduardo Espinoza Chapa */

#include<stdio.h>
#include<stdlib.h>
#define Alumno struct Alumnos
/* puse todo en char pk no espero operar con ningun dato, asi como deje implicitos los demas parametros pk
   no es el objetivo de la tarea */
struct Alumnos{
    char Nombre[100];
    char Edad[100];
    char Promedio[100];
    /* etc, etc... */
};

Alumno generarFicha();
void visualizarReg(Alumno *alumno);

int main(){
    Alumno *alumno;
    size_t i, j, n;
    printf("Ingrese el numero de registros a ingresar:\n");
    scanf("%d", &n);
    fflush(stdin);
    alumno=(Alumno *) calloc(n, sizeof(Alumno));
    for (i=0;i<n;i++){
        alumno[i] = generarFicha();
    }
    for (i=0;i<n;i++){
        printf("Mostrando el Registro %d:\n", (i+1));
        visualizarReg(alumno+i);
    }
    return 0;
}

Alumno generarFicha(){
    Alumno alumno;
    printf("Ingrese el nombre del alumno:\n");
    fgets(alumno.Nombre , 100, stdin);
    printf("Ingrese la edad del estudiante::\n");
    fgets(alumno.Edad, 100, stdin);
    printf("Ingrese el promedio del estudiante:\n");
    fgets(alumno.Promedio, 100, stdin);
    return alumno;
}

void visualizarReg(Alumno *alumno){
    int i;
    printf("%s\n", alumno->Nombre);
    printf("%s\n", alumno->Edad);
    printf("%s\n", alumno->Promedio);
}