#include<stdio.h>
#include<stdlib.h>
#define T 50 //multiproceso

int main(){
    //fgets y fputs
    FILE *archivo; //se requiere apuntador file
    char texto[T];
    int BytesLeidos;
    archivo = fopen("archivo.bin", "rb"); //leer un binario rb, si no es, manda un NULL, manda un apuntador
    if(archivo != NULL){
        puts("Apertura correcta");
        fread(texto, sizeof(char), T, archivo);
        printf("%s \n", texto);
    } else{
        puts("Error al abrir el archivo");
        exit(1); //para salir normalmente
    }
    fclose(archivo);
    return 0;
}
