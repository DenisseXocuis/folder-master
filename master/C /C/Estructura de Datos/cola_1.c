/* Cola con una lista enlazada 
    Permite ajustarse al núm de elementos de la cola, utiliza dos punteros para acceder a la lista 
    Al ser una estructura dinámica puede crecer y decrecer según las necesidades (el límite está en la memoria libre del computador) */
#include <stdlib.h>
//estructura cola con punteros frente y final
typedef struct cola{
    struct ecola *frente;
    struct ecola *final; //si está vacia, si es el mismo elemento
}COLA;

//se declara la estructura del nodo de la lista enlazada
typedef struct{
    int valor;
    COLA *next_node;
}NODO;

//crea un nodo, regresa una estructura
NODO *crear(int x){
    NODO *new = NULL;
    new= (NODO *)malloc(sizeof(NODO));
    new->valor = x;
    new->next_node=NULL;
}                       
int push(COLA *cola, int x){
    NODO *a;
    if(cola->frente == NULL && cola->final==NULL){ //primer valor
        a = crear(x);
        cola->frente = a;
        cola->final = a;
    } //if (función llena)
    cola->final=x;

    //(*apt)->new_node= (*apt)->final;


    return 1;
} //if frente a null, if frente y a final apunta al mismo valor

int main(int argc, char **argv){
    //so the first step is to declarate two variables (in this case they're struct type 'cause we don't use dinamic memory c:)
    COLA c = {NULL, NULL};
    push(&c,2); //<< this one 

    return 0;
}