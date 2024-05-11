/* INFORMATION:::
    Estructura de Datos. Lara Xocuis Martha Denisse - S22002213
    Autocompletado de palabritas - Árbol Trie
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
        struct lista *lista_apt; //que apunta a la lista
    }ROOT_NODE;

//CREACIÓN DE NODO ROOT
    ROOT_NODE *crear_nodo(ROOT_NODE **apt, char letra)
    {   ROOT_NODE *nuevo = (ROOT_NODE *) malloc(sizeof(ROOT_NODE)); //<- creando memoria para el nodito
        if(!nuevo) exit(1);
        nuevo->letra = letra;
        nuevo->lista_apt = NULL;
        return nuevo;
    }
    
//CREACIÓN DE LISTA DE APUNTADORES
    LISTA *crear_apt(ROOT_NODE *nodo)
    {   LISTA *nodito = (LISTA*) malloc(sizeof(LISTA));
        if(!nodito) exit(1);
        nodito->next = NULL;
        nodito->hijo = nodo;
        return nodito;
    }

    int *buscar(ROOT_NODE *apt, char letra)
    { //aplica búsqueda hasta encontrar la entrada de letra, si la encuentra retorna 1 y, entonces, ya no la agrega
        /* comenzar desde árbol raiz
            recorrer hijos en nodo actual y checar si ese hijo coincide con la letra
         */
        LISTA *tmp  = apt->lista_apt;
        if(apt->letra == letra)
            return 1; //<- encontró la letra
        else if(apt->lista_apt == NULL) //<- checar si tiene hijos, si es así, buscar en cada hijo
            return 0;
        while(tmp->next != NULL)
        {
            if(tmp->hijo->letra == letra)
                return 1; //encontró la letra
            tmp = tmp->next;
        }
        return 0; //<- no la encontró
    }

    int *insert_lista(ROOT_NODE **apt, char c)
    {   /* if(!buscar_letra(&apt)) //solo la primera letra, si no la encuentra, la inserta normalmente
        {
            //crear_apt(&apt);
            return 1;
        }
        else
        {  

        } */
    }

//FUNCIÓN PARA INSERTAR EL NODO, func principal
    int *insert_nodo(ROOT_NODE *root, char *letra)
    {   ROOT_NODE *node = NULL;
        LISTA *apt = root->lista_apt;

        while(letra)
        {   //busca si la letra existe en los hijos de la raiz '*'
            if(!(buscar(&root,letra)))
            {
                if(root->letra == '\0')
                {   root = crear_nodo(&root,'*'); //<- porque el primero debe ser asterisco
                    root->lista_apt = crear_apt(&node);
                    node = crear_nodo(&root, letra); //mete a después
                }
            }
        }
        
            while(letra)
            {
                if(root->letra == '\0') //<- si no hay una raíz creada
                {   root = crear_nodo(&root,'*'); //asigna * al primer nodo

                }
                else if(root->letra == '*') //<- si ya se insertó el primero
                {
                    if(!(buscar(&root,letra))) //<- si no la encuentra retorna 0, por lo tanto se inserta
                    {
                        node = crear_nodo(&root, letra);
                        root->lista_apt = crear_apt(node);
                        letra++;
                    }
                }
            }
       

        /* for(; letra != '\0'; letra++)
        {
            if(root_node->letra == '\0')
                root_node->letra = '*';
            else if(root_node->letra == '*')
                //buscar();, si retorna 1 quiere decir que ya existe y agrega al siguiente nodo
                root = apt->hijo;
        }

        if(root_node->letra == '\0')
            root_node->letra = '*'; //porque el primero debe ser el asterisco, verificar si el siguiente es asterisco
        else if(root_node->letra == '*') //<- si ya se insertó el primer elemento, se inserta el nodo desde lista
        {   
            if(!buscarlista //checa si existe una lista, si no, inserta en lista, si existe, busca si la primera letra de la letra ya está para seguir insertando en esa posición de la letra
            si SI existe la lista y la letra, crea otro nodo en la lista y lo inserta
            
            )

        } */
        /* busca si existe esa letra en la lista de apt
        si no, va insertando en ese nodo
        if (!buscar), <- si no encuentra la letra, ahora si, crea otro nodo en lista apt e inserta la nueva letra
            insert...
        si la encuentra, sigue insertando en ese nodo pa' bajo
        else {  vvv  }
         */
    }

    void menu()
    {
        system("cls || clear");
        puts("~*============={            }===============*~");
        puts("\t\t Arbol Trie");
        puts("\t\t     by:");
        puts("    ©Lara Xocuis Martha Denisse. S22002213");
        puts("          Ingenieria en Informatica");
        puts("\t    \"Estructura de Datos\"");
        puts("~*==========================================*~");

    }

int main(){
    char *letra = "abeja";
    int op;
    ROOT_NODE node_default = {NULL};
    LISTA apt_default = {NULL};
    menu();
    insert_nodo(&node_default, letra);

   /*  do{
        printf("Inserta una letra ;)\n>");
        scanf("%s", letra); //abeja
        insert_nodo(&node_default, letra);
        puts("¿Quieres agregar otra?");
        printf("[1] - Oui \n[0] - Non\n>");
        scanf("%d", &op);
    }while(op); */

    return 0;
}