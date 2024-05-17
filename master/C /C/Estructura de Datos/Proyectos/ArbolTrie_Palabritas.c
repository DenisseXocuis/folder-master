/* INFORMATION:::
    Estructura de Datos. Lara Xocuis Martha Denisse - S22002213
    Autocompletado de palabritas - Árbol Trie
 */
#include <stdlib.h>
#include <stdio.h>
enum _bool{FALSE,TRUE}BOOL;

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
    ROOT_NODE *crear_nodo(char letra)
    {   ROOT_NODE *nuevo = (ROOT_NODE *) malloc(sizeof(ROOT_NODE)); //<- creando memoria para el nodito
        if(!nuevo) exit(1);
        nuevo->letra = letra;
        nuevo->lista_apt = NULL;
        return nuevo;
    }
    
//CREACIÓN DE LISTA DE APUNTADORES
    LISTA *crear_apt(ROOT_NODE **nodo)
    {   LISTA *nodito = (LISTA*) malloc(sizeof(LISTA));
        if(!nodito) exit(1);
        nodito->hijo = *nodo;
        nodito->next = NULL;
        return nodito;
    }



    int *buscar(ROOT_NODE **apt, char **letra)
    {
        if((*apt)->letra == '*')
        {
            if(!((*apt)->lista_apt)) return 0; //<- no hay lista, no la encontró
            if((*apt)->lista_apt->hijo->letra == *letra) return 1; //la encontró

            //busca en toda la lista de raices
            LISTA *tmp = (*apt)->lista_apt;
            while(tmp->next != NULL)
            {
                if(tmp->hijo->letra == *letra) return 1; //la encontró
                tmp = tmp->next;
            }
            //si no la encontró...
            ROOT_NODE *tmp2 = crear_nodo(**letra);
            tmp->next = crear_apt(&tmp2);
            (*letra)++;

            return 0;
        }
    }

//FUNCIÓN PARA INSERTAR EL NODO, func principal
    int *insert_nodo(ROOT_NODE **root, LISTA **apt, char *letra)
    {   ROOT_NODE *node, *temp_root = NULL;
        BOOL = FALSE;

        while(!BOOL)
        { 
            //si no existe raiz, crea un nodo
            if(!(*root)) *root = crear_nodo('*');

            //busca si la letra existe en los hijos de la raiz '*'
            if(!(buscar(&(*root),&letra)))
            //si no está la letra, inserta toda la palabra
            {
                LISTA **aux;
                if((*apt) == NULL)
                {   temp_root = (*root);
                    while(*letra != '\0')
                    {   //crea el nodo y lo inserta en la lista
                        node = crear_nodo(*letra);
                        *apt = crear_apt(&node);

                        //inserta la lista en la raiz principal
                        temp_root->lista_apt = *apt;
                        temp_root = temp_root->lista_apt->hijo;
                        letra++;
                    }
                }
                else //si ya existe una lista
                {
                    *aux = *apt;
                    while((*aux)->next != NULL)
                        *aux = (*aux)->next; //aux se usará como raiz provisional
                    temp_root = (*aux)->hijo; //asigna aux a temp root
                    
                    while(*letra != '\0') //inserta toda la palabra
                    {
                        node = crear_nodo(*letra);
                        *aux = crear_apt(&node);
                        temp_root->lista_apt = *aux;
                        letra++;
                        temp_root = temp_root->lista_apt->hijo;
                    }
                }               
                node = crear_nodo('.');
                *apt = crear_apt(&node);
                temp_root->lista_apt = *apt; //<- la palabra ha terminao
                (*apt) = (*root)->lista_apt; //actualiza lista de raices
                BOOL = TRUE; //<- palabra ingresada con éxitoP
            }
        }
        return 1;
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
    char *letra ;
    int op;
    ROOT_NODE *node_default = NULL;
    LISTA *lista_default = NULL;
    do{
        system("cls || clear");
        menu();
        printf("Inserta una palabra ;)\n>");
        scanf("%s", letra); 
        insert_nodo(&node_default, &lista_default, letra);
        puts("¿Quieres agregar otra?");
        printf("[1] - Oui \n[0] - Non\n>");
        scanf("%d", &op);
    }while(op);

    return 0;
}