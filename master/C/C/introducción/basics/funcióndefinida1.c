#include<stdio.h>

/*Funciones universales*/
int cuadrado(int z); /*int dentro del PARÉNTESIS informa que la función espera recibir un valor entero, el int a la izquierda del bombre indica que la función devuelve un resultado entero*/

int main(){
    for (int x = 1; x <= 10; x++)
    {
        printf("%d ", cuadrado(x)); /*llamada a la función*/
    }

    return 0;
}
/*definición de la función cuadrado, devuelve el cuadrado del parámetro, "z" es una copia del argumento para la función*/
int cuadrado (int z)
{
    return z * z; /*recibe una copia del valor de x en z y hace el cuadrado y regresa a la función main*/
}