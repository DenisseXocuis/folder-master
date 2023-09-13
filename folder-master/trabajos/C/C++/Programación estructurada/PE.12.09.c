#include<stdio.h> 
#define T 20
/*min a mayus se le resta 32*/
/*sin utilizar la librería string*/

int main(){
    char palabra[T], i = 0;
    printf("Ingrese una palabra en minuscula\n");
    scanf("%s", &palabra);

    while(palabra[i] != '\0'){
            printf("%c\t", palabra[i]-32);
            i++;
    }

    return 0;
}

/*do while es un ciclo que al menos hace una alteración*/