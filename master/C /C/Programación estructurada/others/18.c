#include<stdio.h>
#define T 200 
#define M 20 

int main(){

    int i = 0, F = 0;
    char pa[T], k[M];

    printf("Ingresa la palabra\n>");
    gets(pa);

    scanf("");
    printf("Ingrese la palabra llave\n>");
    scanf("%s", &k);

    scanf("%[^\n]", &pa); //gets(palabra)
    while(k[i]){
        F += k[i];
        i++;
    }

     F /= 10;

    i = 0;
    printf("Factor = %d \n", F); /*universidad fiee 118*/

    while(pa[i] != '\0'){
        pa[i] += F;
        i++;
    }

    printf("La palabra encriptada es %s \n", pa);
    i = 0;
                    while(pa[i]){
                        pa[i] -= F;
                        i++;
                    }

                    printf("La palabra desencriptada es %s \n", pa);
}