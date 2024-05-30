#include<stdio.h>
#include<stdlib.h> //apuntador tipo FILe, 

int main(){
    FILE *archivo;
    int res;
    archivo = fopen("archivo.txt","r");
    if (archivo != NULL){
        printf("Apertura correcta ");
        res = fclose(archivo);
        printf("%d\n", res);
    }
    else{
        puts("No se pudo abrir el archivo");
        puts("Suerte para la proxima");
    }

    return 0;
}