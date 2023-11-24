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
            fgets(texto, T, archivo);
            printf("%s", texto);
        }    
        fclose(archivo);
    } else{
        puts("Error al abrir el archivo");
        exit(1); //para salir normalmente
    }

    return 0;
}

