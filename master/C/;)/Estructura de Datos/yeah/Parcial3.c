#include<stdio.h>
#include<stdlib.h>

int intercambio(int *arr1, int *arr2, int tam);

int main(){
    int arr[10], Arr2[10], tam;
    // va el llenado pero el tiempo me gana el tiempoD:
    //intercambio(arr, Arr2, tam);
    return 0;
}

int int intercambio(int *arr1, int *arr2, int tam){
    int i = 0;
    while (i < tam)
    { // creo que asi va para intercambiar valores sin hacer uso de una variable temp, pero no puedo comprobar por el tiempo si no me equivoque xD
        arr1[i] += arr2[i];
        arr2[i] = arr1[i] - arr2[i];
        arr1[i] -= arr2[i]
        i++;
    }
    return 1
}