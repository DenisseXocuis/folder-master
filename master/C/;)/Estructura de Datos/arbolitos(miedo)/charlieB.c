#include <stdio.h>
#include <stdlib.h>

// Estructura base de nodo para lista de nodos
typedef struct lista {
    int clave;
    struct pagina *izquierda, *derecha;
    struct lista *next;
} LISTA;

// Estructura base de nodo lista
typedef struct pagina {
    int m; // Magnitud de la página
    struct lista *head;
} PAGE;

// Definición del orden del árbol B
#define T 3 // Orden del árbol B

// Función para crear un nuevo nodo del árbol B
PAGE *createNode() {
    PAGE *newPage = (PAGE *)malloc(sizeof(PAGE));
    newPage->m = 0;
    newPage->head = NULL;
    return newPage;
}

// Función para insertar una clave en un nodo hoja del árbol B
void insertInLeaf(PAGE *page, int key) {
    LISTA *newNode = (LISTA *)malloc(sizeof(LISTA));
    newNode->clave = key;
    newNode->izquierda = NULL;
    newNode->derecha = NULL;
    newNode->next = NULL;

    if (page->head == NULL) {
        page->head = newNode;
        page->m++;
        return;
    }

    LISTA *current = page->head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
    page->m++;
}

// Función para dividir un nodo hijo de un nodo del árbol B
void splitChild(PAGE *parent, int index, PAGE *child) {
    PAGE *newChild = createNode();
    newChild->m = T - 1;

    // Copiar las últimas (T - 1) claves y punteros de 'child' a 'newChild'
    for (int i = 0; i < T - 1; i++) {
        newChild->head = child->head->next;
        child->head = child->head->next;
    }

    child->m = T - 1;

    // Insertar 'newChild' como hijo de 'parent'
    // Aquí deberías tener lógica para manejar punteros izquierda y derecha
}

// Función para insertar una clave en un árbol B
void insert(PAGE **root, int key) {
    PAGE *rootPtr = *root;
    if (rootPtr == NULL) {
        *root = createNode();
        insertInLeaf(*root, key);
    } else {
        // Lógica de inserción en un nodo no hoja
    }
}

// Función para buscar una clave en un árbol B
LISTA *search(PAGE *root, int key) {
    if (root == NULL)
        return NULL;

    LISTA *current = root->head;
    while (current != NULL) {
        if (current->clave == key)
            return current;
        current = current->next;
    }

    return NULL;
}

// Función principal
int main() {
    PAGE *root = NULL;

    // Insertar elementos en el árbol B
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 30);

    // Buscar una clave en el árbol B
    int keyToFind = 12;
    LISTA *foundNode = search(root, keyToFind);
    if (foundNode != NULL)
        printf("Clave %d encontrada.\n", keyToFind);
    else
        printf("Clave %d no encontrada.\n", keyToFind);

    return 0;
}
