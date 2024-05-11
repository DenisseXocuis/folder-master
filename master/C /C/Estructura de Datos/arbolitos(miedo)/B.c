/* lista de nodos */
#include <stdio.h>
#include <stdlib.h>
/* pagina lista y nodo */

typedef struct lista
{   int clave;
    struct pagina* izquierda, derecha;
    struct lista *next;
}LISTA;

typedef struct pagina //<-lista de nodos
{
    int m; //magnitud de la página
    struct lista *head;
}PAGE;

int main()
{   PAGE *node_default = NULL;

    /* inserto ordenado, just en páginas hoja
    
     */

    return 0;
}