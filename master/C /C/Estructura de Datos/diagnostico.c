#include<stdio.h>
#include<stdlib.h>
int main(){

    FILE *archivo;
    struct{
        char *nom;
        short edad;
        float peso;
    }datos[10];

    for(int i=0; i<2; i++){
        printf("datos\n");
        scanf("%s", &datos[i].nom);
        scanf("%d", &datos[i].edad);
        scanf("%f", &datos[i].peso);
    }
    archivo = fopen("Datos.csv", "w");
    fprintf(archivo, "Nombre, Edad, Peso\n");

    for(int i=0; i<2; i++){
        fprintf(archivo, "%s, %d, %f\n", datos[i].nom, datos[i].edad, datos[i].peso);
    }

    fclose(archivo);

    printf("Listo :)");

    return 0;

}