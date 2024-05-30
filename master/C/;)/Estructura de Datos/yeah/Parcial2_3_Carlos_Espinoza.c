#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Elem_Lista struct elem_lista
#define Circular struct lista

struct elem_lista
{
    int dato;
    Elem_Lista *siguiente;
    Elem_Lista *anterior;
} elem_default={0,NULL,NULL};

struct lista
{//Siento que se puede prescindir de esta estructura, pero para ayudar a la separacion y claridad del codigo la dejare declarada
    Elem_Lista *inicio;
} lista_default={NULL};

int insertar(Elem_Lista **lista, int dato);
void imprimir(Circular *lista);
int eliminar_Elem(Circular *lista);
int eliminar_Dato(Circular *lista, int dato);

int main(){
    Circular *lista= (Circular *) calloc(1, sizeof(*lista));;
    insertar(lista, 1);
    insertar(lista, 2);
    insertar(lista, 3);
    insertar(lista, 4);
    imprimir(lista);
    eliminar_Dato(lista, 4);
    imprimir(lista);
    return 0;
}

int insertar(Elem_Lista **lista, int dato){
    Elem_Lista *temp=(Elem_Lista *) calloc(1, sizeof(*temp));
    if (!temp){
        return 0;
    }
    temp->dato= dato;
    temp->siguiente=temp->anterior=NULL;
    if (!(*lista)){
        temp->siguiente = temp;
        temp->anterior = temp;
        (*lista) = temp;
    } else if ((*lista)->dato >= dato){
        if ((*lista)->anterior->dato >= dato){
            return insertar(&(*lista)->anterior, dato);
        }
        temp->siguiente = (*lista);
        temp->anterior = (*lista)->anterior;
        (*lista)->anterior->siguiente = temp;
        (*lista)->inicio->anterior = temp;
    } else if ((*lista)->dato <= dato){
        if ((*lista)->siguiente->dato >= dato){
            return insertar(&(*lista)->siguiente, dato);
        }
        temp->anterior = (*lista);
        temp->siguiente = (*lista)->siguiente;
        (*lista)->siguiente->anterior = temp;
        (*lista)->siguiente = temp;
    }
    return 1;
}

void imprimir(Circular *lista){
    Elem_Lista *temp=(Elem_Lista *) calloc(1, sizeof(*temp));
    if (!temp){
        return;
    }
    temp = lista->inicio;
    do
    {
        printf("%d\n", temp->dato);
        temp= temp->anterior;
    } while (temp != lista->inicio);
    return;
}

int eliminar_Elem(Circular *lista){
    int dato;
    Elem_Lista *temp=(Elem_Lista *) calloc(1, sizeof(*temp));
    if (!temp){
        return 0;
    }
    temp = lista->inicio;
    dato = temp->dato;
    if(temp->siguiente == temp && temp->anterior == temp){
        temp->siguiente=temp->anterior=NULL;
        lista->inicio = NULL;
    } else {
        temp->anterior->siguiente = temp->siguiente;
        temp->siguiente->anterior = temp->anterior;
        lista->inicio = temp->anterior;
        temp->siguiente=temp->anterior=NULL;
    }
    free(temp);
    return dato;
}

int eliminar_Dato(Circular *lista, int dato){
    Elem_Lista *temp=(Elem_Lista *) calloc(1, sizeof(*temp));
    if (!temp){
        return 0;
    }
    temp=lista->inicio;
    do
    {
        if (temp->dato == dato){
            if (temp->anterior == temp && temp->siguiente == temp){
                temp->anterior=temp->siguiente=NULL;
                lista->inicio = NULL;
            } else if (temp == lista->inicio){
                temp->anterior->siguiente = temp->siguiente;
                temp->siguiente->anterior = temp->anterior;
                lista->inicio = temp->anterior;
            } else {
                temp->anterior->siguiente = temp->siguiente;
                temp->siguiente->anterior = temp->anterior;
            }
            free(temp);
            return 1;
        }
        temp = temp->anterior;
    } while (temp != lista->inicio);
    
    printf("No se encontro el elemento en la lista:\n");
    return 0;
}