#include <stdio.h>
#include <stdlib.h>

// ALVAREZ ESCAMILLA ALEXIS INSERCION DE VALORES EN UN ARBOL B
struct ArbolB{
    struct Pagina* raiz;
};

struct Pagina
{
    struct Cola* cola;
    int magnitud;
};

struct Cola
{
    struct NodoCola *frente;
    struct NodoCola *ultimo;
};


struct NodoCola
{
    int dato;
    struct NodoCola* sig;
    struct Pagina* izquierda;
    struct Pagina* derecha;
};

struct Cola* crearCola() {
    struct Cola* nuevaCola = (struct Cola*)malloc(sizeof(struct Cola));
    nuevaCola->frente = NULL;
    nuevaCola->ultimo = NULL;
    return nuevaCola;
}
struct Pagina* crearPagina() {
    struct Pagina* nuevaPagina = (struct Pagina*)malloc(sizeof(struct Pagina));
    nuevaPagina->cola = crearCola();
    nuevaPagina->magnitud = 0;
    return nuevaPagina;
}
struct ArbolB* crearArbolB() {
    struct ArbolB* nuevoArbol = (struct ArbolB*)malloc(sizeof(struct ArbolB));
    nuevoArbol->raiz = crearPagina();

    return nuevoArbol;
}
void insertarColaOrdenada(struct Cola ** cola, int numero) {
    struct NodoCola* nuevoNodo = (struct NodoCola*)malloc(sizeof(struct NodoCola));
    nuevoNodo->dato = numero;
    nuevoNodo->sig = NULL;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    if ((*cola)->ultimo == NULL || numero < (*cola)->frente->dato) {
        nuevoNodo->sig = (*cola)->frente;
        (*cola)->frente = nuevoNodo;
        if ((*cola)->ultimo == NULL)
            (*cola)->ultimo = nuevoNodo;
        return;
    }

    struct NodoCola* temp = (*cola)->frente;
    while (temp->sig != NULL && temp->sig->dato < numero) {
        temp = temp->sig;
    }
    nuevoNodo->sig = temp->sig;
    temp->sig = nuevoNodo;
    if (temp->sig->sig == NULL)
        (*cola)->ultimo = nuevoNodo;
}

void deleteExceptMiddle(struct Pagina* pagina) {
    if (pagina->cola->frente == NULL || pagina->cola->frente->sig == NULL) {
        return;
    }

    struct NodoCola* slow = pagina->cola->frente;
    struct NodoCola* fast = pagina->cola->frente;
    struct NodoCola* prev = NULL;

    while (fast != NULL && fast->sig != NULL) {
        prev = slow;
        slow = slow->sig;
        fast = fast->sig->sig;
    }

    struct NodoCola* middleNode = slow;

    struct NodoCola* temp = pagina->cola->frente;
    while (temp != middleNode) {
        struct NodoCola* next = temp->sig;
        free(temp);
        temp = next;
    }
    temp = middleNode->sig;
    while (temp != NULL) {
        struct NodoCola* next = temp->sig;
        free(temp);
        temp = next;
    }

    middleNode->sig = NULL;
    pagina->cola->frente = middleNode;
    pagina->cola->ultimo = middleNode;
    pagina->magnitud = 1;
    return;
}

struct NodoCola* obtenerNodoMedio(struct Cola* cola) {
    if (cola == NULL || cola->frente == NULL) {
        return NULL;
    }

    struct NodoCola* slow = cola->frente;
    struct NodoCola* fast = cola->frente;

    while (fast != NULL && fast->sig != NULL) {
        slow = slow->sig;
        fast = fast->sig->sig;
    }

    return slow;
}

void eliminarUltimoNodoCola(struct Cola* cola) {
    if (cola->frente == NULL) {
        return;
    }

    struct NodoCola* actual = cola->frente;
    struct NodoCola* anterior = NULL;

    while (actual->sig != NULL) {
        anterior = actual;
        actual = actual->sig;
    }

    if (anterior == NULL) {  
        cola->frente = NULL;
        cola->ultimo = NULL;
    } else {
        anterior->sig = NULL;
        cola->ultimo = anterior;
    }

    free(actual);
}

// este literalmente busca al padre del nodo que necesita dividirse
struct Pagina* buscarPaginaConHijoMagnitud5(struct Pagina* pagina) {
    if (pagina == NULL) {
        return NULL;
    }

    struct NodoCola* nodo = pagina->cola->frente;
    while (nodo != NULL) {
        
        if (nodo->izquierda != NULL && nodo->izquierda->magnitud == 5) {
            return pagina;
        }
        
        if (nodo->derecha != NULL && nodo->derecha->magnitud == 5) {
            return pagina;
        }
        nodo = nodo->sig;
    }

    nodo = pagina->cola->frente;
    struct Pagina* resultado = NULL;
    while (nodo != NULL) {
        resultado = buscarPaginaConHijoMagnitud5(nodo->izquierda);
        if (resultado != NULL) {
            return resultado;
        }
        nodo = nodo->sig;
    }

    nodo = pagina->cola->ultimo;
    if (nodo != NULL) {
        resultado = buscarPaginaConHijoMagnitud5(nodo->derecha);
        if (resultado != NULL) {
            return resultado;
        }
    }

    return NULL;
}

//esta funcion es la clave del arbol , esta divide y el arbol y corrobora si hay padre o no
//  tambien corrobora si le cabe valores al padre y si esta lleno se llama recursivamente dividir nodo hasta que se no quede ningun padre con 
struct Pagina* dividirNodo(struct Pagina* pagina, struct ArbolB* raizBuena) {
    struct NodoCola* medio = obtenerNodoMedio(pagina->cola);
    struct NodoCola* actual = pagina->cola->frente;
    struct Pagina* padre = buscarPaginaConHijoMagnitud5(raizBuena->raiz);

    if (padre != NULL) {
        struct Pagina* nuevaPaginaConPadre = crearPagina();
        
        

        insertarColaOrdenada(&nuevaPaginaConPadre->cola, pagina->cola->frente->sig->sig->sig->dato);
        insertarColaOrdenada(&nuevaPaginaConPadre->cola, pagina->cola->ultimo->dato);
        if(pagina->cola->frente->izquierda == NULL){
            insertarColaOrdenada(&nuevaPaginaConPadre->cola, medio->dato);
            nuevaPaginaConPadre->magnitud = 3;
        }else{
            nuevaPaginaConPadre->magnitud = 2;
        }
        
        nuevaPaginaConPadre->cola->frente->izquierda = medio->derecha;
        nuevaPaginaConPadre->cola->frente->derecha = pagina->cola->ultimo->izquierda;
        nuevaPaginaConPadre->cola->frente->sig->izquierda = pagina->cola->ultimo->izquierda;
        nuevaPaginaConPadre->cola->frente->sig->derecha = pagina->cola->ultimo->derecha;

        insertarColaOrdenada(&padre->cola, medio->dato);
        padre->magnitud++;
        
        struct NodoCola* nodoSubidoAnterior = padre->cola->frente;
        struct NodoCola* nodoSubido = NULL;
        struct NodoCola* nodoSubidoSiguiente = NULL;

        while (nodoSubidoAnterior != NULL && nodoSubidoAnterior->sig != NULL && nodoSubidoAnterior->sig->dato != medio->dato) {
            nodoSubidoAnterior = nodoSubidoAnterior->sig;
        }

        if (nodoSubidoAnterior != NULL && nodoSubidoAnterior->sig != NULL) {
            nodoSubido = nodoSubidoAnterior->sig;
            nodoSubidoSiguiente = nodoSubido->sig;
        }

        if (nodoSubido != NULL) {
            nodoSubidoAnterior->derecha = pagina;
            nodoSubido->izquierda = pagina;
            nodoSubido->derecha = nuevaPaginaConPadre;

            if (nodoSubidoSiguiente != NULL) {
                nodoSubidoSiguiente->izquierda = nuevaPaginaConPadre;
            }
        } else {
            printf("Error: no se encontró el nodo anterior al nodo medio en la cola del padre.\n");
        }
        nodoSubido->izquierda = pagina;
        nodoSubido->derecha = nuevaPaginaConPadre;
      
        if(padre->cola->frente->dato == medio->dato){
            padre->cola->frente->izquierda = pagina;
            padre->cola->frente->derecha = nuevaPaginaConPadre;
            padre->cola->frente->sig->izquierda = nuevaPaginaConPadre;
        }
        eliminarUltimoNodoCola(pagina->cola);
        eliminarUltimoNodoCola(pagina->cola);
        eliminarUltimoNodoCola(pagina->cola);
        pagina->magnitud = 2;

        if (padre->magnitud == 5) {
            dividirNodo(padre, raizBuena);
        }

        return padre;
    }
    
    if(!buscarPaginaConHijoMagnitud5(pagina) && pagina->cola->frente->izquierda == NULL){
        // EN CASO DE QUE NO TENGA PADRE ENTONCES ES NUEVA RAIZ
        struct Pagina* nuevaPaginaIzquierda = crearPagina();
        struct Pagina* nuevaPaginaDerecha = crearPagina();

        insertarColaOrdenada(&nuevaPaginaIzquierda->cola, pagina->cola->frente->dato);
        insertarColaOrdenada(&nuevaPaginaIzquierda->cola, pagina->cola->frente->sig->dato);
        nuevaPaginaIzquierda->magnitud = 2;
        nuevaPaginaIzquierda->cola->frente->izquierda = pagina->cola->frente->izquierda;
        nuevaPaginaIzquierda->cola->frente->derecha = pagina->cola->frente->derecha;
        nuevaPaginaIzquierda->cola->frente->sig->izquierda = pagina->cola->frente->derecha;
        nuevaPaginaIzquierda->cola->frente->sig->derecha = pagina->cola->frente->sig->derecha;
        
        insertarColaOrdenada(&nuevaPaginaDerecha->cola, medio->dato);
        insertarColaOrdenada(&nuevaPaginaDerecha->cola, medio->sig->dato);
        insertarColaOrdenada(&nuevaPaginaDerecha->cola, pagina->cola->ultimo->dato);
        nuevaPaginaDerecha->magnitud = 3;
        nuevaPaginaDerecha->cola->frente->izquierda = medio->derecha;
        nuevaPaginaDerecha->cola->frente->derecha = pagina->cola->ultimo->izquierda;
        nuevaPaginaDerecha->cola->frente->sig->izquierda = pagina->cola->ultimo->izquierda;
        nuevaPaginaDerecha->cola->frente->sig->derecha = pagina->cola->ultimo->derecha;

        medio->izquierda = nuevaPaginaIzquierda;
        medio->derecha = nuevaPaginaDerecha;
        raizBuena->raiz = pagina;

        deleteExceptMiddle(pagina);
        return pagina;
    }
        // EN CASO DE QUE NO TENGA PADRE ENTONCES ES NUEVA RAIZ
        struct Pagina* nuevaPaginaIzquierda = crearPagina();
        struct Pagina* nuevaPaginaDerecha = crearPagina();

        insertarColaOrdenada(&nuevaPaginaIzquierda->cola, pagina->cola->frente->dato);
        insertarColaOrdenada(&nuevaPaginaIzquierda->cola, pagina->cola->frente->sig->dato);
        nuevaPaginaIzquierda->magnitud = 2;
        nuevaPaginaIzquierda->cola->frente->izquierda = pagina->cola->frente->izquierda;
        nuevaPaginaIzquierda->cola->frente->derecha = pagina->cola->frente->derecha;
        nuevaPaginaIzquierda->cola->frente->sig->izquierda = pagina->cola->frente->derecha;
        nuevaPaginaIzquierda->cola->frente->sig->derecha = pagina->cola->frente->sig->derecha;
        
        insertarColaOrdenada(&nuevaPaginaDerecha->cola, medio->sig->dato);
        insertarColaOrdenada(&nuevaPaginaDerecha->cola, pagina->cola->ultimo->dato);
        nuevaPaginaDerecha->cola->frente->izquierda = medio->derecha;
        nuevaPaginaDerecha->magnitud = 2;
        nuevaPaginaDerecha->cola->frente->derecha = pagina->cola->ultimo->izquierda;
        nuevaPaginaDerecha->cola->frente->sig->izquierda = pagina->cola->ultimo->izquierda;
        nuevaPaginaDerecha->cola->frente->sig->derecha = pagina->cola->ultimo->derecha;

        medio->izquierda = nuevaPaginaIzquierda;
        medio->derecha = nuevaPaginaDerecha;
        raizBuena->raiz = pagina;

        deleteExceptMiddle(pagina);
        return pagina;
}


int buscarValor(struct Pagina* raiz, int valor) {
    if (raiz == NULL) {
        return 0; 
    }
   
    struct NodoCola* aux = raiz->cola->frente;
    while (aux != NULL) {
        if (aux->dato == valor) {
            return 1; 
        }
        aux = aux->sig;
    }
    
    aux = raiz->cola->frente;
    while (aux != NULL) {
        if (aux->dato > valor) {
            return buscarValor(aux->izquierda, valor); 
        } else if (aux->sig == NULL || valor < aux->sig->dato) {
            return buscarValor(aux->derecha, valor); 
        }
        aux = aux->sig;
    }

    return 0; // El valor no se encontró en ninguna página
}

int buscarValorEnHojas(struct Pagina* raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }

    struct NodoCola* aux = raiz->cola->frente;
    while (aux != NULL) {
        if (aux->izquierda != NULL) {
            // Si el nodo tiene un hijo izquierdo, sigue recorriendo el árbol
            int encontrado = buscarValorEnHojas(aux->izquierda, valor);
            if (encontrado) {
                return 1;
            }
        } else {
            // Si el nodo no tiene un hijo izquierdo, es una hoja
            while (aux != NULL) {
                if (aux->dato == valor) {
                    return 1;
                }
                aux = aux->sig;
            }
            // Si no se encontró el valor en esta hoja, continúa con la siguiente hoja
            aux = raiz->cola->frente;
            while (aux != NULL && aux->derecha == NULL) {
                aux = aux->sig;
            }
            if (aux != NULL) {
                aux = aux->derecha->cola->frente;
            }
        }
    }

    return 0; // El valor no se encontró en ninguna hoja
}

// esta funcion inserta un valor al arbol, recibe una pagina, el valor y la raiz del arbol, esta mediante recursivad busca la pagina correcta donde insertar el valor y lo mete en su cola
void insertarArbolB(struct Pagina *raiz, int valor, struct ArbolB* raizOriginal) {
   

    if (raiz->cola->frente == NULL) {
        insertarColaOrdenada(&raiz->cola, valor);
        raiz->magnitud++;
        return;
    }

    struct NodoCola *aux = raiz->cola->frente;
    struct Pagina *paginaActual = NULL;

    // Encontrar la página actual donde se debe insertar el valor
    while (aux != NULL) {
        if (valor < aux->dato) {
            paginaActual = aux->izquierda;
            break;
        } else if (aux->sig == NULL || valor < aux->sig->dato) {
            paginaActual = aux->derecha;
            break;
        }
        aux = aux->sig;
    }

    if (paginaActual == NULL) {
        if (raiz->magnitud == 4) {
            insertarColaOrdenada(&raiz->cola, valor);
            raiz->magnitud++;
            dividirNodo(raiz, raizOriginal);
            return;
        } else {
            insertarColaOrdenada(&raiz->cola, valor);
            raiz->magnitud++;
        }
    } else {
        insertarArbolB(paginaActual, valor, raizOriginal);
    }
    return;
}


// esta funcion imprime el arbol por completo, recorriendo nivel por nivel
void imprimirArbolB(struct Pagina *pagina, int nivel) {
    if (pagina == NULL) {
        return;
    }
    struct NodoCola *nodo = pagina->cola->frente;
    if (nodo != NULL) {
        printf("Nivel %d: ", nivel+1);
        while (nodo != NULL) {
            printf("%d ", nodo->dato);
            nodo = nodo->sig;
        }
        printf("\n");
    }


    nodo = pagina->cola->frente;
    while (nodo != NULL) {
        imprimirArbolB(nodo->izquierda, nivel + 1);
        nodo = nodo->sig;
    }

    if (pagina->cola->ultimo != NULL) {
        imprimirArbolB(pagina->cola->ultimo->derecha, nivel + 1);
    }
}


// funcion que libera el arbol 
void liberarMemoriaArbol(struct Pagina* pagina) {
    if (pagina == NULL) {
        return;
    }

    struct NodoCola* nodo = pagina->cola->frente;
    while (nodo != NULL) {
        liberarMemoriaArbol(nodo->izquierda);
        struct NodoCola* temp = nodo;
        nodo = nodo->sig;
        free(temp);
    }

    free(pagina->cola);
    free(pagina);
}
int main(int argc, char const *argv[]) {

    struct ArbolB* arbolito =crearArbolB();
    insertarArbolB(arbolito->raiz,1,arbolito);
    insertarArbolB(arbolito->raiz,2,arbolito);
    insertarArbolB(arbolito->raiz,3,arbolito);
    insertarArbolB(arbolito->raiz,4,arbolito);
    insertarArbolB(arbolito->raiz,5,arbolito);
    
    insertarArbolB(arbolito->raiz,6,arbolito);
    insertarArbolB(arbolito->raiz,7,arbolito);
    insertarArbolB(arbolito->raiz,8,arbolito);
    insertarArbolB(arbolito->raiz,9,arbolito);
    insertarArbolB(arbolito->raiz,10,arbolito);
    insertarArbolB(arbolito->raiz,11,arbolito);
    insertarArbolB(arbolito->raiz,12,arbolito);
    insertarArbolB(arbolito->raiz,13,arbolito);
    insertarArbolB(arbolito->raiz,14,arbolito);
    insertarArbolB(arbolito->raiz,15,arbolito);
    insertarArbolB(arbolito->raiz,16,arbolito);
    insertarArbolB(arbolito->raiz,17,arbolito);
    insertarArbolB(arbolito->raiz,18,arbolito);
    insertarArbolB(arbolito->raiz,19,arbolito);
    insertarArbolB(arbolito->raiz,20,arbolito);
    insertarArbolB(arbolito->raiz,21,arbolito);
    insertarArbolB(arbolito->raiz,22,arbolito);
    insertarArbolB(arbolito->raiz,23,arbolito);
    insertarArbolB(arbolito->raiz,24,arbolito);
    insertarArbolB(arbolito->raiz,25,arbolito);
    insertarArbolB(arbolito->raiz,26,arbolito);
    insertarArbolB(arbolito->raiz,27,arbolito);
    insertarArbolB(arbolito->raiz,28,arbolito);
    insertarArbolB(arbolito->raiz,29,arbolito);
    insertarArbolB(arbolito->raiz,30,arbolito);
    insertarArbolB(arbolito->raiz,31,arbolito);
    insertarArbolB(arbolito->raiz,32,arbolito);
    insertarArbolB(arbolito->raiz,33,arbolito);
    insertarArbolB(arbolito->raiz,34,arbolito);
    insertarArbolB(arbolito->raiz,35,arbolito);
    insertarArbolB(arbolito->raiz,36,arbolito);
    insertarArbolB(arbolito->raiz,37,arbolito);
    insertarArbolB(arbolito->raiz,38,arbolito);
    insertarArbolB(arbolito->raiz,39,arbolito);
    insertarArbolB(arbolito->raiz,40,arbolito); 
    
    imprimirArbolB(arbolito->raiz,0);

     int x,y;
    x =buscarValor(arbolito->raiz,33);
    y = buscarValor(arbolito->raiz,43);
    printf("El valor 33 es  %d \n",x);
    printf("El valor 43 es  %d",y);
    liberarMemoriaArbol(arbolito->raiz);
    free(arbolito);

    return 0;
}