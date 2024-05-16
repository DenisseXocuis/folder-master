#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Definición de la estructura del nodo del árbol trie
typedef struct Nodo {
    char letra;
    struct ListaNodoRaiz *hijos; // Lista de apuntadores a nodos raíz
    bool finPalabra; // Indica si el nodo es el final de una palabra
} Nodo;

// Definición de la estructura del nodo de la lista de apuntadores a nodos raíz
typedef struct ListaNodoRaiz {
    struct NodoRaiz *raiz;
    struct ListaNodoRaiz *siguiente;
} ListaNodoRaiz;

// Función para crear un nuevo nodo del árbol trie
Nodo *crear_nodo(char letra) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->letra = letra;
    nuevo->hijos = NULL;
    nuevo->finPalabra = false;
    return nuevo;
}

// Función para insertar una palabra en el árbol trie
void insertar(Nodo *raiz, const char *palabra) {
    Nodo *actual = raiz;
    while (*palabra) {
        if (actual->hijos == NULL) {
            actual->hijos = (ListaNodoRaiz *)malloc(sizeof(ListaNodoRaiz));
            actual->hijos->raiz = crear_nodo(*palabra);
            actual->hijos->siguiente = NULL;
        } else {
            ListaNodoRaiz *temp = actual->hijos;
            while (temp->siguiente != NULL && temp->raiz->letra != *palabra) {
                temp = temp->siguiente;
            }
            if (temp->raiz->letra != *palabra) {
                temp->siguiente = (ListaNodoRaiz *)malloc(sizeof(ListaNodoRaiz));
                temp->siguiente->raiz = crear_nodo(*palabra);
                temp->siguiente->siguiente = NULL;
            }
        }
        actual = actual->hijos->raiz;
        palabra++;
    }
    actual->finPalabra = true; // Marcar el último nodo como el final de una palabra
}

// Función para buscar una palabra en el árbol trie
bool buscar(Nodo *raiz, const char *palabra) {
    Nodo *actual = raiz;
    while (*palabra) {
        if (actual->hijos == NULL) {
            return false; // La palabra no está en el árbol
        }
        ListaNodoRaiz *temp = actual->hijos;
        while (temp != NULL) {
            if (temp->raiz->letra == *palabra) {
                actual = temp->raiz;
                break;
            }
            temp = temp->siguiente;
        }
        if (temp == NULL) {
            return false; // No se encontró la letra en la lista de hijos
        }
        palabra++;
    }
    return (actual != NULL && actual->finPalabra); // Verificar si el nodo actual es el final de una palabra
}

int main() {
    Nodo *raiz = crear_nodo('*'); // Raíz del árbol trie
    
    char palabra[100]; // Buffer para almacenar la palabra ingresada por el usuario
    
    printf("Ingrese palabras (escriba 'salir' para terminar):\n");
    
    // Ciclo para ingresar palabras
    while (1) {
        printf("> ");
        scanf("%s", palabra);
        
        if (strcmp(palabra, "salir") == 0) {
            break; // Salir del ciclo si el usuario escribe "salir"
        }
        
        // Insertar la palabra en el árbol trie
        insertar(raiz, palabra);
    }
    
    // Buscar palabras
    printf("\nBusqueda de palabras:\n");
    while (1) {
        printf("> ");
        scanf("%s", palabra);
        
        if (strcmp(palabra, "salir") == 0) {
            break; // Salir del ciclo si el usuario escribe "salir"
        }
        
        if (buscar(raiz, palabra)) {
            printf("La palabra '%s' está en el árbol.\n", palabra);
        } else {
            printf("La palabra '%s' no está en el árbol.\n", palabra);
        }
    }
    
    return 0;
}
