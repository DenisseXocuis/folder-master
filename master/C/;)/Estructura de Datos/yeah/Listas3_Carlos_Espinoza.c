#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Elem_Lista struct elem_lista
#define Lista struct lista_doble
#define Puesto struct local_pesc

struct local_pesc
{
    int ocupado;
    char negocio[25];
    char admin[30];
    float medidas;
    float precio;
};


// no se me ocurre un nombre original para los elem
struct elem_lista
{
    Puesto local;// para mantener los datos del local juntos, aunque bien pude ponerlos aca
    Elem_Lista *siguiente;
};
// lista doble pk si
struct lista_doble
{
    Elem_Lista *inicio;
    Elem_Lista *final;
} lista_default = {NULL, NULL};

int generarLista(Lista **lista);
int insertarI(Lista *lista);
int insertarF(Lista *lista);
Puesto eliminar_Elem(Lista *lista);
void imprimir(Lista *lista);
int eliminar_Dato(Lista *lista, char *negocio);
int ingresar_Local(Puesto *local);

int main(){
    //esqueleto de programa para probar las funciones, pk me dio flojera escribir el menu (0v0)/
    Lista *lista;
    generarLista(&lista);
    if (!lista){
        return 0;
    }
    insertarI(lista);
    insertarI(lista);
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
int insertarI(Lista *lista){
    Elem_Lista *temp = (Elem_Lista *) calloc(1, sizeof(Elem_Lista));
    if (!temp){
        printf("No se pudo alojar la memoria del elemento\n");
        return 0;
    }
    ingresar_Local(&temp->local);
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
int insertarF(Lista *lista){
    Elem_Lista *temp = (Elem_Lista *) calloc(1, sizeof(Elem_Lista));
    if (!temp){
        printf("No se pudo alojar la memoria del elemento\n");
        return 0;
    }
    ingresar_Local(&temp->local);
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
        printf("Elemento Numero [%d] de la lista:\n", i);
        printf("Nombre del negocio: %s\n", temp->local.negocio);
        printf("Propietario registrado: %s\n", temp->local.admin);
        printf("Medidas del local: %f m^2\n", temp->local.medidas);
        printf("Precio de renta: %f mex\n", temp->local.precio);
        i++;
        temp = temp->siguiente;
    }
    return;
}

Puesto eliminar_Elem(Lista *lista){
    Elem_Lista *temp = lista->inicio;
    Puesto dato = temp->local;
    lista->inicio = lista->inicio->siguiente;
    free(temp);
    return dato;
}

int eliminar_Dato(Lista *lista, char *negocio){
    Elem_Lista *temp=lista->inicio, *ant=NULL;
    if (!temp){
        return 0;
    }

    while (temp != NULL)
    {
        if (!strcmp(temp->local.negocio, negocio)){
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

int ingresar_Local(Puesto *local){
    local->ocupado = 1;
    printf("Ingrese el nombre del negocio:\n");
    fflush(stdin);
    scanf("%24[^\n]", local->negocio);
    printf("Ingrese el nombre del propietario:\n");
    fflush(stdin);
    scanf("%29[^\n]", local->admin);
    printf("Ingrese las medidas (m^2) del local:\n");
    fflush(stdin);
    scanf("%f", &local->medidas);
    printf("Ingrese el precio de renta:\n");
    fflush(stdin);
    scanf("%f", &local->precio);
    return 1;
}