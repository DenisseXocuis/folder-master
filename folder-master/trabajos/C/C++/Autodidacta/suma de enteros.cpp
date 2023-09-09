#include<stdio.h>
/* la función main inicia la ejecución del programa*/
int main ()
//programa de suma
{
int entero1; /*definir a la variable como entero, primer núm a introducir*/
int entero2; /*definir a la variable como entero, segundo num a introducir*/
int suma; /*variable a la que se almacenará la suma*/

/*las variables también se pudieron haber agrupado: int entero1, entero2, suma;*/

printf("Introduzca el primer entero \n"); /*imprime en pantalla*/
scanf("%d", &entero1); /*lee un entero*/

/*scanf tiene dos argumentos, el primero es la cadena de control de formato, indica el tipo de dato que debe introducir el usuario. El especificador de conversión, &d, indica que el dato debe ser un entero.

El segundo argumento comienza con amperson (&) conocido como operador de dirección seguido del nombre de una variable, el amperson le indica a scanf la ubicación en memoria de la variable para ubicar el valor de entero en esa ubicación.*/

printf("Introduzca el segundo entero\n"); /*imprime en pantalla*/
scanf("%d", &entero2); /*lee un entero*/

suma = entero1 + entero2; /*suma los dos enteros*/

printf("La suma es %d\n", suma); /*imprime la suma, el primer argumeno es la cadena de control de formato y contiene el especificador de conversión %d que indica que se imprimirá un entero*/

return 0;   
}