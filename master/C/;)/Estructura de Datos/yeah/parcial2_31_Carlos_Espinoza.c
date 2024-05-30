#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Elem_Lista struct elem_lista
#define Circular struct lista

struct elem_lista
{
    int dato;
    Elem_Lista *siguiente;
    Elem_Lista *anterior;
} elem_default = {0, NULL, NULL};

int insertar(Elem_Lista **lista, int dato);

int main()
{
    return 0;
}

int insertar(Elem_Lista **lista, int dato)
{
    Elem_Lista *temp = NULL;
    if (!(*lista))
    {
        temp->siguiente = temp;
        temp->anterior = temp;
        (*lista) = temp;
    }
    else if ((*lista)->dato >= dato)
    {
        if ((*lista)->anterior->dato >= dato)
        {
            return insertar(&(*lista)->anterior, dato);
        }
        temp = (Elem_Lista *)calloc(1, sizeof(*temp));
        if (!temp)
        {
            return 0;
        }
        temp->dato = dato;
        temp->siguiente = temp->anterior = NULL;
        temp->siguiente = (*lista);
        temp->anterior = (*lista)->anterior;
        (*lista)->anterior->siguiente = temp;
        (*lista)->anterior = temp;
    }
    else if ((*lista)->dato <= dato)
    {
        if ((*lista)->siguiente->dato >= dato)
        {
            return insertar(&(*lista)->siguiente, dato);
        }
        temp = (Elem_Lista *)calloc(1, sizeof(*temp));
        if (!temp)
        {
            return 0;
        }
        temp->dato = dato;
        temp->siguiente = temp->anterior = NULL;
        temp->anterior = (*lista);
        temp->siguiente = (*lista)->siguiente;
        (*lista)->siguiente->anterior = temp;
        (*lista)->siguiente = temp;
    }
    return 1;
}