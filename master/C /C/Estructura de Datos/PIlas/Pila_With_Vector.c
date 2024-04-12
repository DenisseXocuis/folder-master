#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef int TipoPila;
enum Bool{FALSE, TRUE}BOOL;

//saber si la pila está llena o vacía
int p(TipoPila TOPE){
    if(TOPE) BOOL = FALSE;
    else if(TOPE==MAX-1) BOOL= TRUE; //desbordamiento
    return BOOL;
}
//meter dato en la pila
int push(TipoPila *pila, TipoPila dato, TipoPila TOPE){
    if(p(TOPE)){
        puts("ERROR, u have an overflow :c");
        return 1;
    }
    pila[TOPE+1] = dato; 
    return *pila;
}
int main(){
    TipoPila pila[MAX], dato, tope=0;
    push(pila, 2, tope);
    push(pila, 5, tope);
    push(pila, 8, tope);

    return 0;
}