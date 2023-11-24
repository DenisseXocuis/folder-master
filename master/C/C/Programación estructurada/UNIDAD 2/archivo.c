#include<stdio.h>
#include<stdlib.h>
#define T 50

int main(){
    //fgets y fputs
    FILE *archivo; //se requiere apuntador file
    char texto[T];
    archivo = fopen("archivo.txt", "r+"); //fopen para abrir
    if(archivo != NULL){
        puts("Apertura correcta");
        while(feof(archivo) == 0){ //eof END OF FILE, revisa linea por linea, SI EOF == 0 QUIERE DECIR Q NO HA LLEGADO A FIN DE ARCHIVO
            fscanf(archivo, "%s", texto);
            printf("%s \n", texto);
        }    
        //fclose(archivo);
    } else{
        puts("Error al abrir el archivo");
        exit(1); //para salir normalmente
    }
    printf("Ingresa un texto");
    gets(texto);
    fputs(texto, archivo);

    return 0;
}

