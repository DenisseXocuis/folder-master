#include<stdio.h>

int main(){
    int i;
    float *p, arr[11]; // Este es un arreglo de de floats de tamaño 11
    for (i=0;i<10;i++){
        printf("Ingrese el valor[%d] del vector:\n", i+1);
        scanf("%f", &arr[i]); //Voy introduciendo valores al arreglo (Guardando cosas en la direcciones de memoria)
        }
    p = &arr[0]; // El operador & es para obtener la direccion de memoria, es necesario porque cuando llamas a un arreglo como arr[4] lo estas desreferenciando al mismo tiempo
                 // Osea estas obteniendo el valor y no la direccion de memoria
    for (i=0;i<10;i++){
        printf("Modificando el elemento[%d] del vector:\n", i+1);
        scanf("%f", (p+i));
    }
    printf("Imprimiendo vector final:\n");
    for (i=0;i<10;i++){
        printf("%.2f ", *(p+i));
    }
    return 0;
}


/*int main(){
    int i;
    float *p, vector[11];
    for (i=0;i<10;i++){
        printf("Ingrese el valor[%d] del vector:\n", i+1);
        scanf("%f", vector[i]);
        }
    p = &vector[0];
    for (i=0;i<10;i++){
        printf("Modificando el elemento[%d] del vector:\n", i+1);
        scanf("%f", (p+i));
    }
    printf("Imprimiendo vector final:\n");
    for (i=0;i<10;i++){
        printf("%.2f ", *(p+i));
    }
    return 0;
}*/