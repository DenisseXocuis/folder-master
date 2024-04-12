/* De hecho este codigo lo escribi como practica cuando empece a investigar lo de apuntadores y asignacion de memoria y ahorita que lo estoy volviendo abrir
   antes de mandarlo me salio una duda xD */
/* En la funcion donde genero a la matriz estoy declarando un doble apuntador y de ahi le asigno memoria y lo lleno antes de retornarlo, pero,
   al ser una declaracion de variable local, ¿No deberia limpiarse al terminar la funcion, retornarndo basura? ¿Es debido a que le asigne
   memoria con Calloc() que si me permite retornar los punteros?? ¿O estoy haciendo algo indebido y mas adelante me dara comportamiento indefinido??
   (0.0)??*/
/* Carlos Eduardo Espinoza Chapa */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int ** generarMatriz(size_t f, size_t c);
void imprimirMatriz(int **puntero,size_t f, size_t c);
void modificarMatriz(int **puntero, size_t f, size_t c);

int main(){
    int **matriz;
    size_t f, c;
    printf("Introduzca el numero de Filas de la Matriz:\n");
    scanf("%d", &f);
    printf("Introduzca el numero de columnas:\n");
    scanf("%d", &c);
    matriz = generarMatriz(f, c);
    imprimirMatriz(matriz, f, c);
    modificarMatriz(matriz, f, c);
    printf("\n");
    imprimirMatriz(matriz, f, c);
    return 0;
}

int ** generarMatriz(size_t f,size_t c){
    int **pp, i, j;
    srand(time(NULL));
    pp = (int **) calloc(f, sizeof(int *));
    for (i=0;i<f;i++){
        pp[i] = (int *) calloc(c, sizeof(int));
        }
    /* Empezando con el llenado */
    for (i=0;i<f;i++){
        for (j=0;j<c;j++){
            pp[i][j] = rand() % 100;
        }
    }
    return pp;
}

void imprimirMatriz(int **puntero, size_t f, size_t c){
    int i, j;
    for (i=0;i<f;i++){
        for (j=0;j<c;j++){
            printf("%d ", puntero[i][j]);
        }
        printf("\n");
    }
}

void modificarMatriz(int **puntero, size_t f, size_t c){
    int i, j;
    for (i=0;i<f;i++){
        for (j=0;j<c;j++){
            puntero[i][j] += 1;
        }
    }
}