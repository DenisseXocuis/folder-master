#include<stdio.h>
#include<stdlib.h>

typedef struct persona{
    char nombre[25];
    char edad[3];
    char sexo[15];
    char direccion[60];
} Persona;

int abrirArchivo(FILE **fp, char *nombre, char *modo);
int transcripcion(FILE *binario, FILE *csv);

int main(){
    FILE *binario, *csv;
    if (!abrirArchivo(&binario, "Placeholder.dat", "wb+")){
        return 0;
    }
    if (!abrirArchivo(&csv, "ejemplo.csv", "wb+")){
        return 0;
    }
    transcripcion(binario, csv);
    return 0;
}


int abrirArchivo(FILE **fp, char *nombre, char *modo){
    *fp = fopen(nombre, modo);
    if (!*fp){
        printf("Error de apertura del archivo:\n");
        return 0;
    }
    return 1;
}

int transcripcion(FILE *binario, FILE *csv){
    Persona persona;
    while (!feof(binario)){
        fread(&persona, sizeof(persona), 1, binario);
        if (feof(binario)){
            break;
        }
        fprintf(csv, "%s, %s, %s, %s\n", persona.nombre, persona.edad, persona.sexo, persona.direccion);
    }
    return 1;
}