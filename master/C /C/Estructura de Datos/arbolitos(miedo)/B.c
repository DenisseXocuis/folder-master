/*  INFORMATION
    Estructura de datos. Lara Xocuis Martha Denisse - S22002213 
    Árbol multicamino - Árbol B
    m=5
    max. children = m
    max. keys = m-1
*/
#include <stdio.h>
#include <stdlib.h>

//estructura base para nodo-clave
    typedef struct node
    {   int clave;
        struct key *izquierda, *derecha;
        struct node *next; //hijos
    }NODE;

//estructura base para key-list
    typedef struct key //<-lista de nodos
    {   int k; //¿Cuántas llaves tendrá el nodo?
        struct lista *head;
    }KEY_LIST;

//FUNCIÓN BUSCAR: retorna el apuntador en la posición donde }se encuentra el valor (si está)
    NODE *buscar(KEY_LIST *root, int clave)
    {
        if(!root) return NULL;
        NODE *actuel = root->head;
        while(actuel != NULL)
        {
            if(actuel->clave == clave) return actuel;
            actuel = actuel->next;
        }
        return NULL; //<- no lo encontró
    }

//FUNCIÓN CREAR NUEVO NODO BASE PÁGINA
    KEY_LIST *crear_bt(KEY_LIST **root)
    {   KEY_LIST *new_nodito = (KEY_LIST *) malloc(sizeof(KEY_LIST));
        if(!new_nodito) exit(1);
        new_nodito->head=NULL;
        new_nodito->k=0;
        return new_nodito;
    }

//FUNCIÓN CREAR NUEVO NODO BASE LISTA
    NODE *new_nodo(int clave)
    {   NODE *new_nodito = (NODE *) malloc(sizeof(NODE));
        if(!new_nodito) exit(1);
        new_nodito->clave = clave;
        new_nodito->derecha = NULL;
        new_nodito->izquierda = NULL;
        new_nodito->next= NULL;
        return new_nodito;
    }

    void *insertar_bt(KEY_LIST **root, int clave)
    {   NODE *new = new_nodo(clave);

        //si la lista no existe
        if((*root)->head == NULL)
        {
            (*root)->head = new;
            (*root)->m++;
            return 1;
        }

        NODE *actuel = (*root)->head;
        while(actuel->next != NULL)
            actuel = actuel->next;
        
        actuel->next = new;
        (*root)->m++;

        //Si no la encuentra...
        if(buscar(&(*root), clave) == NULL)
        {

        }
    }

    void destroy_bt();

    int buscar_bt();

int main()
{   KEY_LIST *node_default = NULL;

    return 0;
}