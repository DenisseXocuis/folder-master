#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Matriz struct matriz

struct matriz{
    int **pp;
    size_t f;
    size_t c;
};

Matriz generarMatriz();
Matriz multiMatriz(Matriz a, Matriz b);

int main(){
    Matriz a, b, r;
    a = generarMatriz();
    b = generarMatriz();
    if (a.c != b.f){
        printf("Multiplicacion imposible:\n");
        return 0;
    }
    r = multiMatriz(a, b);
    return 0;
}

Matriz generarMatriz(){
    Matriz m1;
    size_t i, j;
    printf("Introduzca el numero de Filas de la Matriz:\n");
    scanf("%d", &m1.f);
    printf("Introduzca el numero de Columnas de la Matriz:\n");
    scanf("%d", &m1.c);
    m1.pp = (int **) calloc(m1.f, sizeof(int *));
    for (i=0;i<m1.c;i++){
        m1.pp[i] = (int *) calloc(m1.c, sizeof(int));
    }
    for (i=0;i<m1.f;i++){
        for (j=0;j<m1.c;j++){
            printf("Ingresando el elemento [%d][%d] de la Matriz:\n", i,j);
            scanf("%d", &m1.pp[i][j]);
        }
    }
    return m1;
}

Matriz multiMatriz(Matriz a, Matriz b){
    int i, j, k;
    Matriz r = generarMatriz(); // Solo para darle tamanio, en realidad debo modificar la funcion de generar matriz pero no hay tiempo
    for(i=0;i<b.c;i++){
        for(j=0;j<a.f;j++){
            r.pp[i][j]=0;
            for(k=0;k<a.c;k++)
                r.pp[i][j]+=a.pp[i][k]*b.pp[k][j];

        }
    }
}