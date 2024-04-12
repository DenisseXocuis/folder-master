#include <stdlib.h>
#include <stdio.h>
/* INFORMATION del programita if u don know what this is supposed to do :::  
(ordenarlas alfabeticamente, eliminarlas, agregar)
    abra->kadabra->alakazam-> mega-alakazam
    charmander blalblablablalblab :)

    :: invertir la lista ::
    recursión
        caso base
            1. Si la lista estaba vacía
            2. si tenía solo un elemento
            if(head ==NULL || head -> link == NULL)
                {

                }
            -> recursión
                la función se va a llamar para invertir el orden de la sublista (empieza a partir del segundo elemento)

    what u do
    how u resolve it ;)

 */

typedef int TipoElemento;
void menu();
void error();

enum _bool{FALSE, TRUE}BOOL;

typedef struct nodo{
    TipoElemento dato;
    struct nodo *next;
}NODO;

//función de tipo nodo
NODO *nodo(TipoElemento x){
    NODO *new_node = (NODO *) malloc(sizeof(NODO));
    if(!new_node) return 0;
    new_node->dato=x;
    new_node->next=NULL;
    return new_node;
}

void *imprimir(NODO **lista){
    NODO *aux;
    puts("Lista:");
    for(aux = *lista; aux != NULL; aux->next)
        printf("%d ->", aux->dato);
    puts("NULL");
}

int insertar(NODO **lista, TipoElemento x){
    NODO *n = nodo(x); //crea un nodo y se lo asigna a n
    n->next= *lista;
    *lista = n;
   /*  for(lista->actual == lista, lista->anterior==NULL ; lista->actual != NULL; lista->anterior){
    } */
    return 1;
}

int main(){
    int op;
    NODO *Lista = NULL;
    TipoElemento d;
    BOOL = FALSE;
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1: BOOL = TRUE; //existe entrada de lista
                    puts("BOnJOUR, qué elemento vas a insertar en tu lista  ^^"); scanf("%d", &d);
                    insertar(&Lista, d);
                    puts("D'accord! You elemento ya esta en la lista :)");
                    puts("Pulsa enter para regresar al menu principal");
                    getchar();
                    getchar();
                    
            break;
            case 2: if(!BOOL) error();
                    else printf("%d", imprimir(&Lista));
            break;

            case 3:
            break;

            case 4:
            break;

            default:
    }
    }while(op);

    return 0;
}

void menu(){ //menu interactivo
    system("clear || cls");
    puts("------------------------------------");
    puts("Lista enlazada con memoria dinamica");
    puts("------------------------------------");
    puts("1. Insertar elemento"); //inserta y ordena el elemento
    puts("2. Imprimir lista");
    puts("3. Eliminar elemento");
    puts("4. Info :) ");
    puts("0. Salir");
    printf("Opcion: \n>");
}

void error(){
    puts("ERROR! Pulsa enter para regresar al menu principal");
    getchar();
    getchar();
}
