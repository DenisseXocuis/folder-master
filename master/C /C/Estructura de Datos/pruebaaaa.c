#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct node *next_node;
} NODO;

// Función para insertar un elemento al inicio de la lista
int insertar_al_inicio(NODO **inicio, int dato) {
    NODO *nuevo_nodo = (NODO *)malloc(sizeof(NODO));
    if (!nuevo_nodo)
        return 0;
    nuevo_nodo->valor = dato;
    nuevo_nodo->next_node = *inicio;
    *inicio = nuevo_nodo;
    return 1;
}

// Función para buscar un elemento en la lista de manera recursiva
NODO *buscar_anterior_recursivo(NODO *actual, int dato_buscar, NODO *anterior) {
    if (actual == NULL || actual->valor == dato_buscar) // Casos base: final de la lista o elemento encontrado
        return anterior;
    return buscar_anterior_recursivo(actual->next_node, dato_buscar, actual); // Llamada recursiva
}

// Función para buscar un elemento en la lista y retornar la dirección del nodo anterior
NODO *buscar_anterior(NODO *inicio, int dato_buscar) {
    return buscar_anterior_recursivo(inicio, dato_buscar, NULL);
}

int main() {
    NODO *inicio = NULL;
    
    // Insertar elementos en la lista
    insertar_al_inicio(&inicio, 1);
    insertar_al_inicio(&inicio, 2);
    insertar_al_inicio(&inicio, 3);
    insertar_al_inicio(&inicio, 4);
    insertar_al_inicio(&inicio, 5);

    int valor_buscar = 2;

    // Buscar el elemento y obtener la dirección del nodo anterior
    NODO *anterior = buscar_anterior(inicio, valor_buscar);

    // Verificar si el elemento fue encontrado
    if (anterior != NULL && anterior->next_node != NULL) {
        printf("Elemento a buscar: %d\n", valor_buscar);
        printf("Elemento anterior en la lista: %d\n", anterior->valor);
        printf("Dirección del puntero al siguiente elemento: %p\n", (void *)anterior->next_node);
    } else {
        printf("Elemento %d no encontrado en la lista.\n", valor_buscar);
    }

    return 0;
}
