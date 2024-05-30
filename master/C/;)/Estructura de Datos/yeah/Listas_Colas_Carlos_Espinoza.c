#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define Coches struct coches
#define Lista struct lista_doble
#define Elem_Lista struct elem_lista

struct coches
{
    char marca[20];
    char modelo[20];
    int anio;
    float precio;
};

struct elem_lista
{
    Coches vehiculo;
    Elem_Lista *siguiente;
};

struct lista_doble
{
    Elem_Lista *inicio;
    Elem_Lista *final;
    Lista *siguiente;
};

int insertar(Lista **lista, Coches *coche);
Lista* insertar_Lista(Lista **lista, Coches *coche);
Elem_Lista* insertar_FCola(Elem_Lista *final, Coches *coche);
int rellena_Coche(Coches *coches);
int listar(Lista *lista, char *marca);
int listar_coches(Elem_Lista *inicio);


int main(){
    Lista *lista=NULL;
    Coches coche, coche2;

    rellena_Coche(&coche);
    rellena_Coche(&coche2);
    insertar(&lista, &coche);
    insertar(&lista, &coche2);
    listar(lista, coche.marca);
    return 0;
}

int insertar(Lista **lista, Coches *coche){
    Elem_Lista *temp;
    if (!(*lista)){
        if (insertar_Lista(lista, coche))
            return 1;
        return 0;
    }
    else if (!strcmp(coche->marca, (*lista)->inicio->vehiculo.marca)){
        temp = insertar_FCola((*lista)->final, coche);
        if (temp){
            (*lista)->final = temp;
            return 1;
        }
        return 0;
    }
    else if (!(*lista)->siguiente){
        (*lista)->siguiente = insertar_Lista(&(*lista)->siguiente, coche);
        if ((*lista)->siguiente){
            return 1;
        }
        return 0;
    }
    else {
        return insertar(&(*lista)->siguiente, coche);
    }
}

Lista* insertar_Lista(Lista **lista, Coches *coche){
    if (!(*lista)){
        *lista = (Lista *) calloc(1, sizeof(Lista));
        if (!(*lista)){
            return NULL;
        }
        Elem_Lista *nodo = (Elem_Lista *) calloc(1, sizeof(Elem_Lista));
        if (!nodo){
            free(*lista);
            return NULL;
        }
        nodo->vehiculo = *coche;
        nodo->siguiente = NULL;
        (*lista)->inicio = nodo;
        (*lista)->final = nodo;
        (*lista)->siguiente = NULL;
        return *lista;
    }
    else {
        return insertar_Lista(&(*lista)->siguiente, coche);
    }
}

Elem_Lista* insertar_FCola(Elem_Lista *final, Coches *coche){
    Elem_Lista *temp = (Elem_Lista *) calloc(1, sizeof(Elem_Lista));
    if (!temp){
        return NULL;
    }
    temp->vehiculo = *coche;
    temp->siguiente = NULL;
    if (!final){
        return temp;
    }
    else {
        final->siguiente = temp;
        return temp;
    }
}

int rellena_Coche(Coches *coches){
    fflush(stdin);
    printf("Ingrese la marca del coche:\n");
    scanf("%19[^\n]", coches->marca);
    fflush(stdin);
    printf("Ingrese el modelo del coche:\n");
    scanf("%19[^\n]", coches->modelo);
    fflush(stdin);
    printf("Ingrese el anio del coche:\n");
    scanf("%d", &coches->anio);
    fflush(stdin);
    printf("Ingrese el precio del coche:\n");
    scanf("%f", &coches->precio);
    fflush(stdin);
    return 1;
}

int listar(Lista *lista, char *marca){
    Elem_Lista temp;
    if (!lista){
        printf("No se encontro la marca en el registro:\n");
        return 0;
    }
    else if (!strcmp(marca, lista->final->vehiculo.marca)){
        listar_coches(lista->inicio);
        return 1;
    }
    else if (!lista->siguiente){
        return 0;
    }
    printf("Siguiente");
    return listar(lista->siguiente, marca);
}

int listar_coches(Elem_Lista *inicio){
    if (!inicio){
        return 1;
    }
    printf("Marca: %s\n", inicio->vehiculo.marca);
    printf("Modelo: %s\n", inicio->vehiculo.modelo);
    printf("Fecha Lanzamiento: %d\n", inicio->vehiculo.anio);
    printf("Precio Sugerido: %.2f\n", inicio->vehiculo.precio);
    if (!inicio->siguiente){
        return 1;
    }
    listar_coches(inicio->siguiente);
}