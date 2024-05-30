#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next_node;
}NODO;

NODO *pop(NODO **tope){
    if(!tope)
        return NULL;
    NODO *tmp = *tope;
    *tope = (*tope)->next_node;
    return tmp;
}
NODO *search(NODO *apt, int dato_buscar, NODO *apt2){
    if(apt == NULL || apt->valor == dato_buscar)
        return apt2;
    return search(apt->next_node, dato_buscar, apt); 
}
void elimina_primero(NODO **inicio){
    if(!*inicio)
        return;
    NODO *tmp = *inicio;
    *inicio = (*inicio)->next_node;
    free(tmp);
    return;
}

int elimina_x(NODO **inicio, int dato){
    NODO *temp = *inicio;
    if(temp == NULL || temp->valor == dato){
        *inicio = (*inicio)->next_node;
    }
}

int main(int argc, char **argv){
    NODO *apt_inicio = NULL, *new_node = (NODO *) malloc(sizeof(NODO));
    pop(&apt_inicio);
    pop(&apt_inicio);
    pop(&apt_inicio);
    pop(&apt_inicio);
    pop(&apt_inicio);
    NODO *anterior = search(apt_inicio, 8, apt_inicio);
    printf("Elemento anterior en la lista: %d\nDireccion del puntero: %p", anterior->valor, (*anterior).valor);

    return 0;
}

/* struct elista *pop(struct elista **tope){ //pop con listas dinámicas
    if(!*tope)
        return NULL;
    struct elista *tmp= *tope;
    *tope = (*tope)->sig;
    return tmp;
}
void elimina_primero(struct elista **inicio){
    if(!*inicio)
        return;
    struct elista *tmp= *inicio;
    *inicio = (*inicio)->sig;
    free(tmp);
    return;
}
or
{
    struct lista *tmp = pop(inicio);
    if(temp)
        free(tmp);
    return;
}

int elimina_x(struct elista **inicio, int dato){
}
 */
