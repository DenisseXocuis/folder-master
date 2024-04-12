#include<stdio.h> 
//LIFO -> UEPS (ultimo en entrar, primero en salir c:)
#include<stdlib.h>

struct lista{
    int valor; //it could be any type
    struct node *next;
};

/* struct elementolista{
    int dato;
    struct elementolista *sig;
};
    

int inserta_lista(struct elementolista **inicio, int dato){
    struct elementolista *nuevo = (struct elemento lista*) malloc (sizeof(struct elementolista));

    if(!nuevo)
        return 0;
    nuevo -> dato = dato;
    nuevo -> sig = *inicio;
    *inicio = nuevo;
    return 1;



} */

int main(int argc, char **argv){
    //struct elementolista *inicio = NULL; lista vacia
    struct lista *nodo;
    nodo = malloc(sizeof(struct lista));
    (*nodo).valor = 23;

    /* 
    inserta_lista(&inicio, 2);
    inserta lista(&inicio, 6);

    -create an another one



    free(nuevo);    
    */
    return 0;
}