/* INFORMATION:::
    Estructura de Datos. Lara Xocuis Martha Denisse - S22002213
 */
#include <stdlib.h>

//ESTRUCTURA NODO BASE DE LISTA DE APUNTADORES
typedef struct lista
    {   struct nodito *hijo; //para apuntar así mismo
        struct lista *next; //para el siguiente dato de la lista
    }LISTA;

//ESTRUCTURA NODO BASE PARA ÁRBOL
    typedef struct nodito
    {   char letra;
        struct lista *head; //que apunta a la lista
    }ROOT_NODE;

//CREACIÓN DE NODO ROOT
    ROOT_NODE *crear_nodo(char c)
    {   ROOT_NODE *root = (ROOT_NODE *) malloc(sizeof(ROOT_NODE)); //<- creando memoria para el nodito
        if(!root) exit(1);
        root->head = NULL;
        root->letra = c; //acá se va a insertar la letra extraida de la palabra leida
        return root;
    }
    
//CREACIÓN DE LISTA DE APUNTADORES
    LISTA *crear_apt()
    {   LISTA *nodito = (LISTA*) malloc(sizeof(LISTA));
        if(!nodito) exit(1);
        nodito->next = NULL;
        nodito-> hijo = NULL;
        return nodito;
    }

    int *insert_lista(char c)
    {
        
    }
//FUNCIÓN PARA INSERTAR EL NODO
    int *insert_nodo(char *c)
    {   ROOT_NODE *root_node = crear_nodo(c);
        if(root_node == NULL)
            root_node->letra = '*'; //porque el primero debe ser el asterisco, verificar si el siguiente es asterisco
        insert_lista(c);
            /* 
                si el siguiente es asterisco, insertar en lista

                insert_lista, crear memoria para nodito y crear otro nodo para el hijo
                
                meter función buscar para ver si está el mismo elemnto: si existe, busca el apt del elemento
            */
    }

//FUNCIÓN PARA EXTRAER LETRAS DE LA PALABRA Y HACER INSERCIÓN EN CADA UNA
void *letra(char *palabra)
{     
    insert_nodo(palabra);
}
int main(){
    //*, linea por linea de la palabra va a ir insertando letras, INSERCION DE LAS LETRAS
    char *palabra;
    int op;
    ROOT_NODE node_default = {NULL};
    do{
        printf("Inserta una palabra ;)\n>");
        scanf("%s", palabra); //abeja
        letra(palabra);
        /* 
            -extrae cada caracter de la palabra y lo va insertando en otra función para ir creando el arbol general de palabras
         */
        puts("¿Quieres agregar otra?");
        printf("[1] - Oui \n[0] - Non\n>");
        scanf("%d", &op);
    }while(op);

    return 0;
}