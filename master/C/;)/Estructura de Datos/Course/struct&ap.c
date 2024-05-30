#include<stdio.h>
#include<string.h>
//comunmente los ap se inicializan con NULL
int main(int argc, char **argv){
    struct persona{
        short edad;
        char *nombre;
        float peso;
    };
    struct persona per;
    struct persona *aper;
    struct persona **aaper;
    struct persona per2;
    /* char cadena[10] = "Hola Mundo";
    char cad2[10]; */
    per.nombre;
    per.edad = 22;
    per.peso;
    per2.edad = 24;

    //con apuntadores
    printf("per: %d\n", per.edad);
    aper = &per;
    //aper -> edad = 22;
    aaper = &aper;
    (*aaper)->edad = 48;
    printf("con aaper: %d\n", (*aaper)->edad);
    printf("con per: %d\n", per.edad);
    printf("con aper: %d\n", aper->edad);
    putchar('\n');
    //aper apuntando a otra cosa :)
    *aaper = &per2;
    printf("per2: %d\n", per2.edad);
    printf("aaper apuntando a per2: %d\n", aper->edad);
    printf("aper: %d\n", aper->edad);

    /* cadena[4] = '\0'; */

    /* for(int i=0; i<10; i++){
        printf("%c\n", cadena[i]);
    }
    printf("-- %s --\n", cadena); detecta fin de cadena */

    return 0;
}