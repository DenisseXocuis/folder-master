#include <stdlib.h>
/* we have 2 structures types */
typedef struct cola{
    struct ecola *frente;
    struct ecola *final; //si está vacia, si es el mismo elemento
}COLA;

typedef struct ecola{
    int valor;
    struct ecola *next_node;
}ecola;

int push(COLA *cola, int x){
    ecola *new = NULL;
    new = (ecola *)malloc(sizeof(ecola));
    if(cola->frente == NULL && cola->final==NULL){ //primer valor
        new->valor = x;
        new->next_node=NULL;
        cola->frente = new;
        cola->final = new;
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