#include <stdlib.h>
typedef int Tipo; //para que sea de cualquier tipo
/* Definiciones.. 
    Si un árbol NO está vacío, entonces el primer nodo se llama raíz.
    El nivel de un nodo es su distancia de la raiz, la raiz tiene una distancia de cero a si misma 

    Un árbol puede estar vacio; es decir, no contiene ningún elemento,
    Un árbol no vacío puede constar de un único elemento denominado un nodo, o bien
    Un árbol consta de un nodo, conectado por arcos directos a un número finito de otros
    árboles.

    Las flechas que conectan al nodo se llaman arcos o ramas
    Los nodos terminales (los que no conducen a otro nodo) se denominan hojas
    Los nodos que no son hojas se les llama nodos internos
    El nivel de un nodo es la longitud hasta la raiz
    La altura es la longitud del camino más largo que tiene un nodo
    

. */

/* Propiedades
    Grado es el número de descendientes directos de un determinado nodo
    Grado del árbol es el máximo grado de todos los nodos del árbol
    Nivel es el número de arcos que deben ser recorridos para llegar a un determinado nodo. RAIZ TIENE NIVEL 1
    Altura del árbol es el máximo núm de niveles de todos los nodos (lineas, saltos)



 */

    //Estructura del nodo árbol-base
    typedef struct treenode{
        Tipo Dato;
        struct treenode *len;
        struct treenode *rin; //it's just basically left & right lol
    }TREE_NODE;

    //Función de tipo nodo árbol que crea el nodo base
    TREE_NODE *crear_nodo(Tipo x)
    {
        //crea memoria del nodito ;)
        TREE_NODE *nodito = malloc(sizeof(TREE_NODE));

        if(!nodito) return 1;

        //inicializando:
        nodito->Dato=x;
        nodito->len=NULL;
        nodito->rin=NULL;

        //regresando nodito
        return nodito; 
    }

int main(){
    /*  Triángulo de pascal ;) pqsi
         1
        1 1 
       1 2 1 
     */
    TREE_NODE *raiz = crear_nodo(1);
    TREE_NODE *ramita_l = crear_nodo(1);
    TREE_NODE *ramita_r = crear_nodo(1);

    raiz->len = ramita_l;
    raiz->rin = ramita_r;

    puts("ñañañ");
    
    return 0;
}