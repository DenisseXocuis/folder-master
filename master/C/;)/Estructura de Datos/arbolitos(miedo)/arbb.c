#include <stdlib.h>
#include <stdio.h>

typedef struct elista{
    struct nodo* hijo;
    struct elista* sig;
}elista;

typedef struct nodo{
    char dato;
    struct elista* hijos;
}nodo;

elista* inserta_lista(elista **inicio, char dato){
    if (!*inicio) {
        elista* nuevo = (elista*)malloc(sizeof(elista));
        if(!nuevo){
            return NULL;
        }
        nuevo->hijo = (nodo*) malloc(sizeof(nodo));
        nuevo->sig=NULL;
        if (!nuevo->hijo) {
            free(nuevo);
            return NULL;
        }
        nuevo->hijo->dato = dato;
        nuevo->hijo->hijos = NULL;
        *inicio = nuevo;
        return *inicio;
    }
    elista* elem;
    if (elem = buscar_elem(*inicio, dato)) {
        return elem;
    }
    //return inserta_lista(&(*inicio)->sig, dato);

}

int inserta_nodo(nodo** raiz, char dato){
    if(!*raiz){
        nodo* nuevo=(nodo*)malloc(sizeof(nodo));
        if(!nuevo){
            return 0;
        }

        nuevo->dato = '*';
        nuevo->hijos = NULL;
        *raiz=nuevo;
    } else if ((*raiz)->dato == '*') {
        if (inserta_lista(&((*raiz)->hijos), dato)) {
            return 1;
        }
        return 0;
    }
}

int main(){
    return 0;
}