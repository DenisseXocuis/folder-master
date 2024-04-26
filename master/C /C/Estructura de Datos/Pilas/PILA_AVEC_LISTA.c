#include<stdlib.h>
typedef float TipoElemento;
    //estructura de nodo base ;)
    typedef struct nodo
    {   TipoElemento e;
        struct nodo *next;
    }NODO;

    //función para ver si la pila es vacía
    int vacia(NODO *P)
    {
        return P  = NULL;
    }

    //para insertar un elemento
    int push(NODO **P, NODO *dato)
    {   
        dato->next = *P;
        *P = dato;
        return 1;
    }

    int mete_p(NODO **P, TipoElemento e)
    {
        NODO *new;
    }

void imprimir_p(struct nodo **P){
    /* if(es_vacia(*P))
    {
        puts("No se puede imprimir T.T");
    }

    //struct nidi *aux= para ir vaciando pop
    NODO *aux= pop(P);
    NODO *paux = ;
    
     */
}
    NODO *pop(){

    }
    
int main(){
    NODO *apt = NULL;


    return 0;
}