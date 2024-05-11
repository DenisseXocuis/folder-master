#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol Trie
typedef struct ROOT_NODE {
    char letter; // La letra que representa este nodo
    struct LISTA *lista_apt; // Apuntador a la lista de hijos
    char isEndOfWord; // Flag para indicar si este nodo es el final de una palabra
} ROOT_NODE;

// Definición de la estructura de la lista de apuntadores a los hijos del árbol Trie
typedef struct LISTA {
    struct ROOT_NODE *hijo; // Apuntador al nodo hijo
    struct LISTA *next; // Apuntador al siguiente nodo en la lista
} LISTA;

// Función para inicializar un nuevo nodo del árbol Trie
ROOT_NODE* createRootNode(char letter) {
    ROOT_NODE* newNode = (ROOT_NODE*)malloc(sizeof(ROOT_NODE));
    newNode->letter = letter;
    newNode->lista_apt = NULL;
    newNode->isEndOfWord = 0;
    return newNode;
}

// Función para inicializar una nueva lista de apuntadores a los hijos del árbol Trie
LISTA* createLista(ROOT_NODE *hijo) {
    LISTA* newList = (LISTA*)malloc(sizeof(LISTA));
    newList->hijo = hijo;
    newList->next = NULL;
    return newList;
}

// Función para insertar una palabra en el árbol Trie
void insertWord(ROOT_NODE *root, char *word) {
    ROOT_NODE *currentNode = root;

    // Recorrer cada letra de la palabra
    for (int i = 0; word[i] != '\0'; i++) {
        char letter = word[i];
        LISTA *child = currentNode->lista_apt;
        LISTA *prevChild = NULL;
        // Buscar si ya existe un nodo con esta letra
        while (child != NULL && child->hijo->letter != letter) {
            prevChild = child;
            child = child->next;
        }
        if (child == NULL) {
            // Si no existe, crear un nuevo nodo y enlazarlo
            ROOT_NODE *newNode = createRootNode(letter);
            LISTA *newChild = createLista(newNode);
            if (prevChild == NULL) {
                currentNode->lista_apt = newChild;
            } else {
                prevChild->next = newChild;
            }
            currentNode = newNode;
        } else {
            // Si ya existe, seguir al siguiente nodo
            currentNode = child->hijo;
        }
    }

    // Marcar el último nodo como el final de la palabra
    currentNode->isEndOfWord = 1;
}

// Función principal
int main() {
    // Crear el nodo raíz del árbol Trie
    ROOT_NODE *root = createRootNode('*'); // Usamos '*' como raíz

    // Insertar palabras en el árbol Trie
    insertWord(root, "abeja");
    insertWord(root, "perro");
    insertWord(root, "arbol");

    // Insertar más palabras para probar
    insertWord(root, "casa");
    insertWord(root, "carro");

    // Ahora puedes realizar búsquedas u otras operaciones en el árbol Trie

    return 0;
}