#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Elem_Lista struct elem_lista
#define Elem_Cola struct elem_cola

struct elem_lista
{
    int limite;
    Elem_Cola *inicio;
    Elem_Lista *siguiente;
};

struct elem_cola
{
    int dato;
    Elem_Cola *siguiente;
};



int generar_lista(Elem_Lista **inicio, int id);
int generar_cola(Elem_Cola **inicio, int id);
Elem_Cola *bucar_dato(Elem_Lista *inicio, int dato);
Elem_Cola *buscar_dato_cola(Elem_Cola **inicio, int dato);
int borrar_cola(Elem_Cola **inicio);
int borrar_lista(Elem_Lista **inicio, int limite);

int main(){
    return 0;
}

int generar_lista(Elem_Lista **inicio, int id){
    if (!(*inicio)){
        (*inicio) = (Elem_Lista *) calloc(1, sizeof(*(*inicio)));
        if (!(*inicio))
            return 0;
        (*inicio)->limite = id;
        if (!generar_cola(&(*inicio)->inicio, id)){
            return 0;
        } 
        return 1;
    } else if ((*inicio)->limite <= id){
        if (!generar_cola(&(*inicio)->inicio, id)){
            return 0;
        }
        return 1;
    } else {
        return generar_lista(&(*inicio)->siguiente, id);
    }
}

int generar_cola(Elem_Cola **inicio, int id){
    Elem_Cola *aux=NULL;
    if (!(*inicio)){
        (*inicio) = (Elem_Cola *) calloc(1, sizeof(*(*inicio)));
        if (!(*inicio))
            return 0;
        (*inicio)->dato = id;
        return 1;
    } else if (!(*inicio)->siguiente){
        aux = (Elem_Cola *) calloc(1, sizeof(*aux));
        if (!aux)
            return 0;
        aux->dato= id;
        (*inicio)->siguiente = aux;
        return 1;
    } else {
        return generar_cola(&(*inicio)->siguiente, id);
    }
}

Elem_Cola *bucar_dato(Elem_Lista *inicio, int dato){
    if (!inicio)
        return NULL;
    if (inicio->limite <= dato){
        return buscar_dato_cola(&inicio->inicio, dato);
    } else {
        return bucar_dato(inicio->siguiente, dato);
    }
}

Elem_Cola *buscar_dato_cola(Elem_Cola **inicio, int dato){
    if (!(*inicio))
        return NULL;
    else if ((*inicio)->dato != dato)
        return buscar_dato_cola(&(*inicio)->siguiente, dato);
    else 
        return (*inicio);
}

int borrar_lista(Elem_Lista **inicio, int limite){
    Elem_Lista *aux=NULL;
    if (!(*inicio))
        return 0;
    else if ((*inicio)->limite == limite){
        while ((*inicio)->inicio)
        {
            borrar_cola(&(*inicio)->inicio);
        }
        aux = (*inicio);
        (*inicio) = (*inicio)->siguiente;
        free(aux);
        return 1;
    } else {
        return borrar_lista(&(*inicio)->siguiente, limite);
    }
}

int borrar_cola(Elem_Cola **inicio){
    Elem_Cola *aux=NULL;
    int dato;
    if (!(*inicio))
        return 0;
    aux = (*inicio);
    dato = (*inicio)->dato;
    (*inicio) = (*inicio)->siguiente;
    free(aux);
    return dato;
}