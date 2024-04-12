#include<stdio.h>
#include<stdlib.h>
#define Elem_Lista struct elem_lista
#define Lista struct lista_doble
// no se me ocurre un nombre original para los elem
struct elem_lista
{
    int dato; // no supe que poner de dato
    Elem_Lista *siguiente;
};
// lista doble pk si
struct lista_doble
{
    Elem_Lista *inicio;
    Elem_Lista *final;
} lista_default = {NULL, NULL};

int generarLista(Lista **lista);
int insertarI(Lista *lista, int dato);
int insertarF(Lista *lista, int dato);
int eliminar_Elem(Lista *lista);
void imprimir(Lista *lista);
int eliminar_Dato(Lista *lista, int dato);

int main(){
    Lista *lista;
    generarLista(&lista);
    if (!lista){
        return 0;
    }
    insertarI(lista, 8);
    insertarI(lista, 5);
    insertarI(lista, 3);
    insertarI(lista, 1);
    imprimir(lista);
    eliminar_Dato(lista, 5);
    printf("Nueva lista:\n");
    imprimir(lista);
    if (!lista->inicio){
        printf("Lista vacia\n");
    }
    return 0;
}
// aloja la memoria e inicializa con null las listas
int generarLista(Lista **lista){
    *lista = (Lista *) calloc(1, sizeof(*lista));
    if (!lista){
        printf("No se pudo alojar la memoria:\n");
        return 0;
    }
    //**lista = lista_default; //Creo que es innecesario pk calloc ya inicializa la memoria en 0s
    return 1;
}
//para la cracion de pilas
int insertarI(Lista *lista, int dato){
    Elem_Lista *temp = (Elem_Lista *) malloc(sizeof(Elem_Lista));
    if (!temp){
        printf("No se pudo alojar la memoria del elemento\n");
        return 0;
    }
    temp->dato = dato;
    temp->siguiente = NULL;
    if (!lista->inicio && !lista->final){
        lista->inicio = temp;
        lista->final = temp;
    } else {
        temp->siguiente = lista->inicio;
        lista->inicio = temp;
    }
    return 1;
}
//para la creacion de colas
int insertarF(Lista *lista, int dato){
    Elem_Lista *temp = (Elem_Lista *) malloc(sizeof(Elem_Lista));
    if (!temp){
        printf("No se pudo alojar la memoria del elemento\n");
        return 0;
    }
    temp->dato = dato;
    temp->siguiente = NULL;
    if (!lista->inicio && !lista->final){
        lista->inicio = temp;
        lista->final = temp;
    } else {
        lista->final->siguiente = temp;
        lista->final = temp;
    }
    return 1;
}
// visualizar los datos insertados
void imprimir(Lista *lista){
    Elem_Lista *temp = lista->inicio;
    int i=0;

    while (temp != NULL){
        printf("Elemento Numero [%d] de la lista\n%d\n", i, temp->dato);
        i++;
        temp = temp->siguiente;
    }
    return;
}

int eliminar_Elem(Lista *lista){
    Elem_Lista *temp = lista->inicio;
    int dato = temp->dato;
    lista->inicio = lista->inicio->siguiente;
    free(temp);
    return dato;
}

int eliminar_Dato(Lista *lista, int dato){
    Elem_Lista *temp=lista->inicio, *ant=NULL;
    if (!temp){
        printf("test");
        return 0;
    }

    while (temp != NULL)
    {
        if (temp->dato == dato){
            if (temp == lista->inicio){
                lista->inicio = lista->inicio->siguiente;
                temp->siguiente = NULL;
            } else if (temp == lista->final){
                lista->final = ant;
                lista->final->siguiente = NULL;
            } else {
                ant->siguiente = temp->siguiente;
                temp->siguiente = NULL;
            }
            free(temp);
            return 1;
        }
        ant = temp;
        temp = temp->siguiente;
    }
    printf("Elemento no encontrado:\n");
    return 1;
}