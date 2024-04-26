#include<stdio.h>
#include<stdlib.h>

void recurPrintf(int *arreglo, int obj, int tam);

int main(){
    int *arr, n, i, obj;
    printf("Ingrese el tamanio del arreglo:\n");
    scanf("%d", &n);
    arr = (int *) calloc(n, sizeof(int));
    for (i=0;i<n;i++){
        printf("Ingresando el elemento[%d] del arreglos:\n", i);
        scanf("%d", &arr[i]);
    }
    printf("Ingrese el numero que se desea encontrar:\n");
    scanf("%d", &obj);
    recurPrintf(arr, obj, n);
    free(arr);
    return 0;
}

void recurPrintf(int *arreglo, int obj, int tam){
    if (tam <= 0){
        printf("No se encontro el numero;\n");
        return;
    } else if (*arreglo == obj){
        printf("%d\n", *arreglo);
        printf("Se logro encontrar el numero en el arreglo:\n");
        return;
    }
    printf("%d ", *arreglo);
    recurPrintf(++arreglo, obj, --tam);
}