#include <stdlib.h>
//buscar en una lista, buscar en el elemento y regresar la dirección del puntero siguiente al elemento q encuentre
typedef struct node{
    int valor;
    struct node *next_node;
}NODO; //nodo es sinónimo de struct node

int puts_elem(NODO **inicio, int dato){
    NODO *new_node = (NODO *) malloc(sizeof(NODO));
    if(!new_node)
        return 0;
    new_node-> valor = dato;
    new_node-> next_node = *inicio;
    *inicio = new_node;
    return 1;
}
/* int elimina_x(NODO **inicio, int dato){
    if(*inicio)
} */

NODO **search(NODO **apt, int dato_buscar){
    if(!apt) return NULL;
    else if(!*apt) return NULL;
    else if((*apt)->valor == dato_buscar)
        return apt;
    return search(&(*apt)->next_node, dato_buscar);
}

int main(int argc, char **argv){
    NODO *apt_inicio = NULL; //lista vacia, no tiene elementos
    puts_elem(&apt_inicio,1);
    puts_elem(&apt_inicio,2);
    puts_elem(&apt_inicio,3);
    puts_elem(&apt_inicio,4);
    puts_elem(&apt_inicio,8);
    NODO *anterior = search(&apt_inicio, 3);
    printf("Elemento anterior en la lista: %d\nDireccion del puntero: %p",anterior->valor);
    elimina_x(&apt_inicio, 3);

    return 0;
}
