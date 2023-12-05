//copia el contenido de un archivo binario a otro
#include<stdio.h>
#include<stdlib.h>
#define T 50 //multiproceso

int main(){
    //fgets y fputs
    FILE *archivo, *archivo2; //se requiere apuntador file
    char texto[T];
    int BytesLeidos;
    archivo = fopen("archivo.bin", "rb"); //leer un binario rb, si no es, manda un NULL, manda un apuntador
    archivo2 = fopen("archivocp.bin", "wb");
    if(archivo != NULL){
        //puts("Apertura correcta");
        fread(texto, sizeof(char), T, archivo);
        printf("%s \n", texto);
    } else{
        puts("Error al abrir el archivo");
        exit(1); //para salir normalmente
    }
    if(archivo2 != NULL){
        fwrite(texto, sizeof(char), T, archivo2);
        printf("Archivo copiado\n");
    }
    else{
        puts("Error al abrir el archivo");
        exit(1); //para salir normalmente
    }
    fclose(archivo);
    fclose(archivo2);

    return 0;
}
//que el archivo exista o q no exista, guardar lo del usuario
//guardar los numeros en el binario, promedio, num más alto
