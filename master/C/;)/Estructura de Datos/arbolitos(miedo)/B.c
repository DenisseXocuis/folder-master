/*  INFORMATION
    Estructura de datos. Lara Xocuis Martha Denisse - S22002213 
    Árbol multicamino - Árbol B
    K: grado del arbol
    Propiedades de las hojas:
        -K : min de elementos
        -2K: max de elementos
    

    Propiedades de la raiz:
        -Almacena entre 1 y 2K


    m=5
    max. children = m
    max. keys = m-1


*/
#include <stdio.h>
#include <stdlib.h>
#define T 2

//estructura base para nodo-clave
    typedef struct node
    {   int clave;
        struct key *izquierda, *derecha;
        struct node *next; //hijos
    }NODE;

//estructura base para key-list
    typedef struct key //<-lista de nodos
    {   int k, isroot;
        //¿Cuántas llaves tendrá el nodo?, es una raiz?
        struct node *head;
    }KEY_LIST;


//crear nodo-clave
    NODE *new_nodo(int clave)
    {   NODE *new_nodito = malloc(sizeof(NODE));
        if(!new_nodito) exit(1);
        new_nodito->clave = clave;
        new_nodito->derecha = NULL;
        new_nodito->izquierda = NULL;
        new_nodito->next= NULL;
        return new_nodito;
    }

//crear key-list
    KEY_LIST *crear_bt(NODE *nodito)
    {   KEY_LIST *new_nodito = malloc(sizeof(KEY_LIST));
        if(!new_nodito) exit(1);
        new_nodito->head = nodito;
        new_nodito->k=0;
        return new_nodito;
    }

//FUNCIÓN BUSCAR: retorna el apuntador en la posición donde }se encuentra el valor (si está)
    NODE *buscar(KEY_LIST *root, int clave)
    {
        //se debe tener memoria en la cual se requiere trabajar
        if(root)
        {
            //verificar si la clave buscada se encuentra en toda la página
            if(root->head->clave != clave)
            {
                NODE *actuel = root->head;
                while(actuel)
                {
                    if(actuel->clave == clave)
                    {
                           
                    }
                }
            }
        }
        else   
        {

        }



        if(!root) return NULL;
        NODE *actuel = root->head;
        while(actuel != NULL)
        {
            if(actuel->clave == clave) return actuel;
            actuel = actuel->next;
        }
        return NULL; //<- no lo encontró
    }


    /* insertar nueva key para el árbol
    1. encontrar el nodo correcto para insertar
    2. dividir si está lleno (m-1)
     */
    void *insertar_bt(KEY_LIST **root, int clave)
    {   NODE *new = new_nodo(clave);

        //si la lista no existe
        if(!*root)
        {   //asignar nodo raíz e insertar la clave
            (*root) = crear_bt(new);
            (*root)->k++;
            return;
        }
        else  //si existe una lista
        {
            //si está llena, divide
            if((*root)->k == T - 1)
            {

            }
            else //si no está llena y existe la lista, insertar hasta el final pero de forma ordenada
            {
                NODE *actuel = (*root)->head;
                while (actuel->next != NULL)
                    actuel = actuel->next;
                actuel->next = new;
                (*root)->k++;
            }

            //buscar para inserción

            //si ese nodo NO está lleno, insertar en orden ascendente
            //si ese nodo está lleno, dividir, empuje la llave mediana hacia arriba, y haga de las llaves izquierdas un nodo hijo izquierdo y de las llaves derechas un nodo hijo derecho. 
        }

        NODE *actuel = (*root)->head;
        while(actuel->next != NULL)
            actuel = actuel->next;
        
        actuel->next = new;
        (*root)->k++;

        //Si no la encuentra...
        if(buscar(&(*root), clave) == NULL)
        {

        }
    }

    void destroy_bt();

    int buscar_bt();

int main()
{   KEY_LIST *node_default = NULL;
    insertar_bt(&node_default, 2);

    return 0;
}