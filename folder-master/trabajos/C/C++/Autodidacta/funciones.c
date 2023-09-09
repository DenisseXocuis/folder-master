#include<stdio.h>
#include<math.h>
#include<string.h>
/*
    strlen (str)---> cantidad de caracteres, devuelve un entero sin contar el nulo

    strcpy (destino, origen) ----> copia cadena de caracteres de origen con la cadena de destino

    strcat (destino, origen) ----> (concatenación) concatena dos cadenas de caracteres

    strcmp (string1, string2) --> string compare, compara dos string, si son iguales el resultado es 0. Los compara lexicográficamente, es decir, compara el tamaño(parte gráfica) por caracter por caracter (lexico)

    strstr(string1, string2) ---> busca la cadena2 dentro de la cadena1 y nos devuelve NULL sino aparece

    strcspn(string1, string2) ---> posición donde se encuentra cad2 dentro de cad1 a partir de tal posición


*/



int main(){

    char cadena[10];

    printf("Ingrese una palabra o frase: \n");
    fgets(cadena,10,stdin);
    scanf("%s", &cadena);

    printf("\n%s", cadena);

    return 0;
}