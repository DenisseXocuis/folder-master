#include<stdio.h>
#include<stdlib.h>

typedef struct estudiante{
    char nombre[25];
    char carrera[25];
    int promedio;
} Estudiante;

void insertar(FILE *fp, Estudiante alumno);
int abrirArchivo(FILE **fp, char *nombre, char *modo);
int listar(FILE *fp);

int main(){
    FILE *fp;
    char cad[25];
    Estudiante alumno;
    scanf("%s", alumno.nombre);
    scanf("%s", alumno.carrera);
    scanf("%d", &alumno.promedio);
    //fp = fopen("ejemplo.txt", "w+");
    /*if (!fp){
        printf("Error de apertura del archivo:\n");
        return 0;
    }*/
    if (!abrirArchivo(&fp, "test.txt", "wb+")){
        return 0;
    }
    insertar(fp, alumno);
    listar(fp);
    return 0;
}

void insertar(FILE *fp, Estudiante alumno){
    fwrite(&alumno, sizeof(alumno), 1, fp);
}

int abrirArchivo(FILE **fp, char *nombre, char *modo){
    *fp = fopen(nombre, modo);
    if (!*fp){
        printf("Error de apertura del archivo:\n");
        return 0;
    }
    return 1;
}

int listar(FILE *fp){
    Estudiante alumno;
    rewind(fp);
    while (!feof(fp)){
        fread(&alumno, sizeof(alumno), 1, fp);
        if (feof(fp)){
            break;
        }
        printf("Nombre del alumno: %s\nCarrera en curso: %s\nPromedio: %d", alumno.nombre, alumno.carrera, alumno.promedio);
    }
    return 0;
}