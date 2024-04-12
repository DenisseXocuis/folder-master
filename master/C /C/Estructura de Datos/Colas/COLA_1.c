/* Cola con una lista enlazada 
    Permite ajustarse al núm de elementos de la cola, utiliza dos punteros para acceder a la lista 
    Al ser una estructura dinámica puede crecer y decrecer según las necesidades (el límite está en la memoria libre del computador) */
#include <stdlib.h>
//se declara la estructura del nodo de la lista enlazada
typedef struct nodo{
    int valor;
    struct nodo *next;
}NODO;

//estructura de punteros al nodo, son de tipo estructura porque apuntan a otra estructura
typedef struct cola{
    struct nodo *frente;
    struct nodo *final; //si está vacia, si es el mismo elemento
}COLA;

//crea un nodo, regresa una estructura
NODO *crear_nodo(int x){
    NODO *new;
    new= (NODO *)malloc(sizeof(NODO));
    if(!new){
        puts("ERROR, no hay memoria suficiente :c");
        exit(1);
    }
    new-> valor = x;
    new-> next =NULL;
    return new; //regresa el nodo con x y el puntero siguiente a null
}                       
int insertar(COLA *cola, int x){
    NODO *a;
    a = crear_nodo(x);
    if(cola->frente == NULL){ //primer valor, frente == NULL it means cola vacía
        cola->frente = a;
        cola->final = a;
        return 1;
    }
    cola->final-> next= a; 
    cola->final = a;
    return 1;
}
int main(){
    //inicializando los punteros frente y final en NULL
    COLA c = {NULL, NULL};
    insertar(&c,2);

    return 0;
}