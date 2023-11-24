#include <stdio.h>
/* Escriba una función en C llamada suma la cual debe aceptar dos ameglos del mismo tamaño, sumar los elementos correspondientes de dichos arreglos (0 con 0, 1 con 1, hastan n con n) guardar el total en un tercer arreglo y regresar un apuntador al arreglo que contiene los totales. Ponga la función en un programa en C que imprima los valores de los tres arreglos. El arreglo que contene los totales se debe imprimir tanto de modo directo como indirecto */

int* suma(const int arreglo1[], const int arreglo2[], int n) {
    int resultado[n]; // Arreglo para almacenar los resultados
    
    for (int i = 0; i < n; i++) {
        resultado[i] = arreglo1[i] + arreglo2[i];
    }

    int* punteroResultado = resultado; // Obtén un puntero al arreglo de resultados

    return punteroResultado;
}
int main(){
    int arreglo1[] = {1, 2, 3, 4, 5};
    int arreglo2[] = {6, 7, 8, 9, 10};
    int n = sizeof(arreglo1) / sizeof(arreglo1[0]);

    int* resultado = suma(arreglo1, arreglo2, n);

    printf("Arreglo 1: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo1[i]);
    }

    printf("\nArreglo 2: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo2[i]);
    }

    printf("\nArreglo de Totales (Directo): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", resultado[i]);
    }

    printf("\nArreglo de Totales (Indirecto): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(resultado + i)); // Modo indirecto
    }

    return 0;
}
