/*  INFORMATION
    Estructura de datos. Lara Xocuis Martha Denisse - S22002213 
    Árbol multicamino - Árbol B
*/
#include <stdio.h>
#include <stdlib.h>

//ESTRUCTURA BASE DE NODO PARA LISTA DE NODOS
    typedef struct lista
    {   int clave;
        struct pagina *izquierda, *derecha;
        struct lista *next;
    }LISTA;

//ESTRUCTURA BASE DE NODO LISTA
    typedef struct pagina //<-lista de nodos
    {   int m; //magnitud de la página
        struct lista *head;
    }PAGE;

//FUNCIÓN BUSCAR: retorna el apuntador en la posición donde se encuentra el valor (si está)
    LISTA *buscar(PAGE *root, int clave)
    {
        if(!root) return NULL;
        LISTA *actuel = root->head;
        while(actuel != NULL)
        {
            if(actuel->clave == clave) return actuel;
            actuel = actuel->next;
        }
        return NULL; //<- no lo encontró
    }
//FUNCIÓN CREAR NUEVO NODO BASE PÁGINA
    PAGE *new_page(PAGE **root)
    {   PAGE *new_nodito = (PAGE *) malloc(sizeof(PAGE));
        if(!new_nodito) exit(1);
        new_nodito->head=NULL;
        new_nodito->m=0;
        return new_nodito;
    }

//FUNCIÓN CREAR NUEVO NODO BASE LISTA
    LISTA *new_nodo(int clave)
    {   LISTA *new_nodito = (LISTA *) malloc(sizeof(LISTA));
        if(!new_nodito) exit(1);
        new_nodito->clave = clave;
        new_nodito->derecha = NULL;
        new_nodito->izquierda = NULL;
        new_nodito->next= NULL;
        return new_nodito;
    }

    int *insertar_AB(PAGE **root, int clave)
    {   LISTA *new = new_nodo(clave);

        //si la lista no existe
        if((*root)->head == NULL)
        {
            (*root)->head = new;
            (*root)->m++;
            return 1;
        }

        LISTA *actuel = (*root)->head;
        while(actuel->next != NULL)
            actuel = actuel->next;
        
        actuel->next = new;
        (*root)->m++;

        //Si no la encuentra...
        if(buscar(&(*root), clave) == NULL)
        {

        }
    }

int main()
{   PAGE *node_default = NULL;

    return 0;
}