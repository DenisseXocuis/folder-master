/*Primer programa en C

oh yeah :) */

#include<stdio.h> //directiva del preprocesador en C para antes de que se compile, stdio.h (encabezado estándar de entrada/salida)
//la función "main" inicia le ejecución del programa

int main(void)//función, la llave izquierda inicia el cuerpo de cada función, los paréntesis que aparecen después de main indican que es un bloque de construcción de programas llamado función.
{ 
    int numero; //printf indica que imprima en la pantalla la cadena de caracteres contenida entre las comillas, en ocasiones se llama mensaje o literal.
    printf("buenos dias \n"); //"\" es como carácter de escape, es decir, nueva linea.
    scanf("%i" ,&numero);

        printf("El numero ingresado es: %i \n", numero);
        printf("fin ñañaña"); //los punto y coma se conocen como finalizador de la instrucción 

    return 0;
} //finaliza la función, el par de llaves se conoce como bloque. 