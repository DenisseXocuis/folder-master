/* INFORMATION:::
    Estructura de Datos. Lara Xocuis Martha Denisse - S22002213
    Autocompletado de palabritas

 */
#include <stdlib.h>
#include <stdio.h>

//ESTRUCTURA NODO BASE DE LISTA DE APUNTADORES
typedef struct lista
    {   struct nodito *hijo; //para apuntar al nodito pal arbolito
        struct lista *next; //para el siguiente dato de la lista
    }LISTA;

//ESTRUCTURA NODO BASE PARA ÁRBOL
    typedef struct nodito
    {   char letra;
        struct lista *head; //que apunta a la lista
    }ROOT_NODE;

//CREACIÓN DE NODO ROOT
    ROOT_NODE *crear_nodo(ROOT_NODE **apt)
    {   ROOT_NODE *root = (ROOT_NODE *) malloc(sizeof(ROOT_NODE)); //<- creando memoria para el nodito
        if(!root) exit(1);
        root->head = NULL;
        *apt = root;
        return root;
    }
    
//CREACIÓN DE LISTA DE APUNTADORES
    LISTA *crear_apt(LISTA **apt)
    {   LISTA *nodito = (LISTA*) malloc(sizeof(LISTA));
        if(!nodito) exit(1);
        nodito->next = NULL;
        nodito->hijo = NULL;
       // nodito-> hijo = crear_nodo(&(*apt)); //creando nodo para el hijo INSERTAR LISTA
        *apt = nodito;
        return nodito;
    }

    int *buscar(LISTA **apt)
    { //aplica búsqueda hasta encontrar la entrada de letra, si la encuentra retorna 1 y, entonces, ya no la agrega
        
    }

    int *insert_lista(ROOT_NODE **apt, char c)
    {   if(!buscar_letra(&apt)) //solo la primera letra, si no la encuentra, la inserta normalmente
        {
            //crear_apt(&apt);
            return 1;
        }
        else
        {   (*apt)->head = crear_apt(&(*apt));

        }
    }
//FUNCIÓN PARA INSERTAR EL NODO
    int *insert_nodo(ROOT_NODE **node, char *palabra)
    {   ROOT_NODE *root_node = crear_nodo(&(*node));  //<- crea un nodo default
        if(root_node->letra == '\0')
            root_node->letra = '*'; //porque el primero debe ser el asterisco, verificar si el siguiente es asterisco
        else if(root_node->letra == '*') //<- si ya se insertó el primer elemento, se inserta el nodo desde lista
        {   
            /* if(!buscarlista //checa si existe una lista, si no, inserta en lista, si existe, busca si la primera letra de la palabra ya está para seguir insertando en esa posición de la palabra
            si SI existe la lista y la palabra, crea otro nodo en la lista y lo inserta
            
            ) */
            insert_lista(&(*node), palabra); //acá tendra la función buscar elemento

        }
        /* busca si existe esa letra en la lista de apt
        si no, va insertando en ese nodo
        if (!buscar), <- si no encuentra la letra, ahora si, crea otro nodo en lista apt e inserta la nueva letra
            insert...
        si la encuentra, sigue insertando en ese nodo pa' bajo
        else {  vvv  }
         */
        insert_lista(&(*node), palabra);

        insert_nodo(&(*node)->head->hijo, palabra++);
    }

    void menu()
    {
        system("cls || clear");
        puts("~*============={            }===============*~");
        puts("\tAutoacompletado de palabritas");
        puts("\t\t     by:");
        puts("    ©Lara Xocuis Martha Denisse. S22002213");
        puts("          Ingenieria en Informatica");
        puts("\t    \"Estructura de Datos\"");
        puts("~*==========================================*~");

    }

int main(){
    //*, linea por linea de la palabra va a ir insertando letras, INSERCION DE LAS LETRAS
    char *palabra;
    int op;
    ROOT_NODE *node_default = NULL;
    LISTA *apt_default = NULL;
    menu();
    do{
        printf("Inserta una palabra ;)\n>");
        scanf("%s", palabra); //abeja
        insert_nodo(&node_default, palabra);
        puts("¿Quieres agregar otra?");
        printf("[1] - Oui \n[0] - Non\n>");
        scanf("%d", &op);
    }while(op);

    return 0;
}