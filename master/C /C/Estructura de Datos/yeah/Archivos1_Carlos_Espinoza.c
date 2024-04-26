#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define cant 100
#define Persona struct persona

struct persona{
    char Nombre[cant];
    int Edad;
    char Estudio[25];
/* etc, etc */
};

void insertar(int cantidad, FILE *archivos);
void listar(FILE *archivos);
void buscarAlumno(char *nombre, FILE *archivos);
void modificarDatos(char *nombre, FILE *archivos);

int main(){
    FILE *archivo;
    int c=0, cantidad=0;
    char *nombre;
    if (!(archivo = fopen("ejemplo.dat", "ab+"))){// ab+ zpara la creacion del archivo en caso de que sea la primera vez que corre el programa 
        printf("Error al abrir el archivo.\n");
        return 0;
    } fseek(archivo, 0, SEEK_SET);
    while (1){ // Iba a hacer todo esto en una funcion de control para no sobrecargar el main(), pero me dio flojera xD, tengo que limpiar el codigo 
        printf("Ingrese la operacion deseada:\n");
        printf("Ingrese 1 para ingresar nuevos registros\n");
        printf("Ingrese 2 para visualizar los registros existentes\n");
        printf("Ingrese 3 para visualizar los registros de 1 alumno en especifico\n");
        printf("Ingrese 4 para modificar los datos de un alumno en especifico\n");
        printf("Ingrese 0 para salir del programa\n");
        scanf("%d", &c);
        if (c == 1){
            printf("Ingrese la cantidad\n");
            scanf("%d", &cantidad);
            insertar(cantidad, archivo);
            continue;
        } else if (c == 2){
            listar(archivo);
            continue;
        } else if (c == 3){
            nombre = (char *) calloc(cant, sizeof(char));
            printf("Ingrese el nombre que se va a buscar:\n");
            scanf("%s", nombre);
            buscarAlumno(nombre, archivo);
            free(nombre);
            continue;
        } else if (c == 4){
            fclose(archivo);
            if (!(archivo = fopen("ejemplo.dat", "rb+"))){
                printf("Error al abrir el archivo para modificarlos. \n");
                return 0;
            }
            nombre = (char *) calloc(cant, sizeof(char));
            printf("Ingrese el nombre del estudiante cuyo registro quiere modificar:\n");
            scanf("%s", nombre);
            modificarDatos(nombre, archivo);
            free(nombre);
            fclose(archivo);
            if (!(archivo = fopen("ejemplo.dat", "ab+"))){ // para volver a la forma inicial del archivo pk soy flojo y no quiero normalizar lo demas para estandarizar xD
                printf("Error al reabrir el archivo.\n");
                return 0;
            }
            continue;
        } else {
            fclose(archivo);
            printf("El progrma ha finalizado:\n");
            return 0;
        }
    }
    return 0;
}

void insertar(int cantidad, FILE *archivos){
    Persona alumno;
    //fseek(archivos, 0, SEEK_END); // comentado para mantener la compatibilidad de la funcion cuando voy a modificar el registro
    for(int i=0;i < cantidad; i++){  // originalmente lo tenia de esta forma par asegurarme de agregar datos al final, pero ya que estoy abriendolo con append
                                        //siento que es redundante, aunque encontre informacion contradictoria y discusiones sobre iso C y ansi C
        printf("Ingrese el nombre del alumno:\n");
        scanf("%s", alumno.Nombre);
        printf("Ingrese la edad del alumno:\n");
        scanf("%d", &alumno.Edad);
        printf("Ingrese la carrera en curso del alumno:\n");
        scanf("%s", alumno.Estudio);
        printf("\n");
        fwrite(&alumno, sizeof(Persona), 1, archivos);
    }
}

void listar(FILE *archivos){
    Persona alumno;
    int i=0;
    fseek(archivos, 0, SEEK_SET);
    while (!feof(archivos)){
        fread(&alumno, sizeof(Persona), 1, archivos);
        if (feof(archivos)){
            printf("Final del archivo actual:\n");
            break;
        }
        printf("Registro[%d]\n", ++i);
        printf("Nombre:\n%s\nEdad:\n%d\nCarrera:\n%s\n", alumno.Nombre, alumno.Edad, alumno.Estudio);
    }
}

void buscarAlumno(char *nombre, FILE *archivos){
    Persona alumno;
    int i=0;
    fseek(archivos, 0, SEEK_SET);
    while (!feof(archivos)){
        fread(&alumno, sizeof(Persona), 1, archivos);
        ++i;
        if (feof(archivos)){
            printf("Final del archivo actual:\n");
            break;
        }
        if ((strcmp(nombre, alumno.Nombre)) != 0){
            continue;
        }
        printf("Registro[%d]\n", i);
        printf("Nombre:\n%s\nEdad:\n%d\nCarrera:\n%s\n", alumno.Nombre, alumno.Edad, alumno.Estudio);
    }
}

void modificarDatos(char *nombre, FILE *archivos){
    Persona alumno;
    int i=0;
    fseek(archivos, 0, SEEK_SET);
    while (!feof(archivos)){
        fread(&alumno, sizeof(Persona), 1, archivos);
        ++i;
        if (feof(archivos)){
            printf("Final del archivo actual:\n");
            printf("No se encontro el Registro especificado:\n");
            return;
            break;
        }
        if ((strcmp(nombre, alumno.Nombre)) != 0){
            continue;
        } else {
            printf("Registro[%d]\n", i);
            printf("Nombre:\n%s\nEdad:\n%d\nCarrera:\n%s\n", alumno.Nombre, alumno.Edad, alumno.Estudio);
            fseek(archivos, -sizeof(Persona), SEEK_CUR);
            insertar(1, archivos);
            printf("Se ha modificado el registro:\n");
            return;
        }
    }
}


