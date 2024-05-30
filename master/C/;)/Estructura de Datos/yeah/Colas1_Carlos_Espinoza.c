#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Elem_Lista struct Coca_Cola
#define Lista struct lista

struct Coca_Cola
{
    char producto[25];
    float litros;
    float precio;
    Elem_Lista *siguiente;
    // etc, etc
};

struct lista
{
    Elem_Lista *inicio;
    Elem_Lista *final;
} lista_default={NULL, NULL};

int insertarF(Lista *lista);
void rellenar_Coca(Elem_Lista *producto);
void imprimir(Lista *lista);
int Eliminar_Elem(Lista *lista, Elem_Lista *salida);
int eliminar_Dato(Lista *lista, char *producto);
int generarLista(Lista **lista);

int main(){
    Lista *lista;
    Elem_Lista elem;
    generarLista(&lista);

    return 0;
}

int insertarF(Lista *lista){
    Elem_Lista *temp;
    temp= (Elem_Lista *) calloc(1,sizeof(*temp));
    if (!temp){
        printf("Error de memoria:\n");
        return 0;
    }
    rellenar_Coca(temp);
    if (!lista->inicio && !lista->final){
        lista->inicio = temp;
        lista->final = temp;
    } else {
        lista->final->siguiente = temp;
        lista->final = temp;
    }
    return 1;
}

void rellenar_Coca(Elem_Lista *producto){
    printf("Ingrese el nombre del producto:\n");
    fflush(stdin);
    scanf("%24[^\n]", producto->producto);
    printf("Ingrese la cantidad de litros:\n");
    fflush(stdin);
    scanf("%f", &producto->litros);
    printf("Ingrese el precio sugerido:\n");
    fflush(stdin);
    scanf("%f", &producto->precio);
    producto->siguiente = NULL;
    return;
}

void imprimir(Lista *lista){
    Elem_Lista *temp;
    int i=0;
    temp = (Elem_Lista *) calloc(1, sizeof(*temp));
    if (!temp){
        printf("Error de memoria:\n");
        return 0;
    }
    temp = lista->inicio;
    while (temp)
    {
        printf("Elemento Numero [%d] de la lista:\n", i);
        printf("Nombre del producto: %s\n", temp->producto);
        printf("Volumen en litro: %.2f\n", temp->litros);
        printf("Precio sugerido: %.2f\n", temp->precio);
        i++;
        temp = temp->siguiente;
    }
    return;
}

int Eliminar_Elem(Lista *lista, Elem_Lista *salida){
    Elem_Lista *temp= lista->inicio;
    Elem_Lista aux = *temp;
    lista->inicio = lista->inicio->siguiente;
    temp->siguiente = NULL;
    *salida = *temp;
    free(temp);
    return 1;
}

int eliminar_Dato(Lista *lista, char *producto){
    Elem_Lista *temp=lista->inicio, *ant=NULL;
    if (!temp){
        return 0;
    }

    while (temp != NULL)
    {
        if (!strcmp(temp->producto, producto)){
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

int generarLista(Lista **lista){
    *lista = (Lista *) calloc(1, sizeof(*lista));
    if (!lista){
        printf("No se pudo alojar la memoria:\n");
        return 0;
    }
    **lista = lista_default;
    return 1;
}