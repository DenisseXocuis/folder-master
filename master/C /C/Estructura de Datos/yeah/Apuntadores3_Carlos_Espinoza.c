#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int ** generarMatriz(int f, int c);
void imprimirMatriz(int **puntero,int f, int c);
void modificarMatriz(int **puntero, int f, int c);

int main(){
    int **matriz, f, c;
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

int ** generarMatriz(int f, int c){
    int **pp, i, j;
    srand(time(NULL));
    pp = (int **) calloc(f * sizeof(int *));
    for (i=0;i<f;i++){
        pp[i] = (int *) calloc(c * sizeof(int));
        }
    /* Empezando con el llenado */
    for (i=0;i<f;i++){
        for (j=0;j<c;j++){
            pp[i][j] = rand() % 100;
        }
    }
    return pp;
}

void imprimirMatriz(int **puntero, int f, int c){
    int i, j;
    for (i=0;i<f;i++){
        for (j=0;j<c;j++){
            printf("%d ", puntero[i][j]);
        }
        printf("\n");
    }
}

void modificarMatriz(int **puntero, int f, int c){
    int i, j;
    for (i=0;i<f;i++){
        for (j=0;j<c;j++){
            puntero[i][j] += 1;
        }
    }
}