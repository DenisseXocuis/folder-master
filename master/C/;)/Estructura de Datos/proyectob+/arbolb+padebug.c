 /* Information......
 *      ÁRBOL B 
 *      ESTRUCTURA DE DATOS
 *      - ALVAREZ ESCAMILLA ALEXIS
 *      - LARA XOCUIS MARTHA DENISSE
 *      - MARTINEZ SCHLESKE ALAN
 *      - SOLANO DORANTES JORGE SAMUEL
*/
#include <stdio.h>
#include <stdlib.h>
enum menuBool{FALSE,TRUE}BOOL; //<- para llevar un control del menu

//estructura base de nodo base para claves
typedef struct NodoCola
{
    int dato;
    struct NodoCola* sig;
    struct Pagina* izquierda, *derecha;
}NodoCola;

//apuntadores para la cola
typedef struct Cola
{
    struct NodoCola *frente, *ultimo;
}Cola;

//estructura base de página para el árbol
typedef struct Pagina
{   
    struct Cola* cola;
    int magnitud;
}Pagina;

//estructura de raiz de arbolB+
typedef struct ArbolB{
    struct Pagina* raiz;
}ArbolB;

/* PROTOTIPO DE FUNCIONES */
    Cola* crearCola();
    Pagina* crearPagina();
    ArbolB* crearArbolB();
    void insertarColaOrdenada(Cola **, int );
    void deleteExceptMiddle(Pagina* );
    NodoCola* obtenerNodoMedio(Cola* );
    void eliminarUltimoNodoCola(Cola* );
    Pagina* buscarPaginaConHijoMagnitud5(Pagina* );
    Pagina* dividirNodo(Pagina* , ArbolB* );
    NodoCola* buscarValor(Pagina* , int );
    void insertarArbolB(Pagina *, int , ArbolB* );
    void eliminar(int, Pagina *);
    void fusion(Pagina *, Pagina *);
    void rebalance(Pagina *, ArbolB *);
    void imprimirArbolB(Pagina *, int );
    NodoCola *dfs(Pagina *, int );
    void liberarMemoriaArbol(Pagina* );
    void menu(enum menuBool );
    void pause();

// Funciones basicas de creacion
Cola* crearCola()
{
    Cola* nuevaCola = (Cola*)malloc(sizeof(Cola));
    nuevaCola->frente = NULL;
    nuevaCola->ultimo = NULL;
    return nuevaCola;
}

Pagina* crearPagina()
{
    Pagina* nuevaPagina = (Pagina*)malloc(sizeof(Pagina));
    nuevaPagina->cola = crearCola();
    nuevaPagina->magnitud = 0;
    return nuevaPagina;
}


ArbolB* crearArbolB()
{
    ArbolB* nuevoArbol = (ArbolB*)malloc(sizeof(ArbolB));
    nuevoArbol->raiz = crearPagina();
    return nuevoArbol;
}

// función que inserta de forma ordenada
void insertarColaOrdenada(Cola **cola, int numero)
{
    NodoCola* nuevoNodo = (NodoCola*)malloc(sizeof(NodoCola));
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

    NodoCola* temp = (*cola)->frente;
    while (temp->sig != NULL && temp->sig->dato < numero) {
        temp = temp->sig;
    }
    nuevoNodo->sig = temp->sig;
    temp->sig = nuevoNodo;
    if (temp->sig->sig == NULL)
        (*cola)->ultimo = nuevoNodo;
}

// esta se le ingresa una cola de tamaño 5 y elimina todos los nodos excepto el de enmedio
void deleteExceptMiddle(Pagina* pagina) {
    if (pagina->cola->frente == NULL || pagina->cola->frente->sig == NULL) {
        return;
    }

    NodoCola* slow = pagina->cola->frente;
    NodoCola* fast = pagina->cola->frente;
    NodoCola* prev = NULL;

    while (fast != NULL && fast->sig != NULL) {
        prev = slow;
        slow = slow->sig;
        fast = fast->sig->sig;
    }

    NodoCola* middleNode = slow;

    NodoCola* temp = pagina->cola->frente;
    while (temp != middleNode) {
        NodoCola* next = temp->sig;
        free(temp);
        temp = next;
    }
    temp = middleNode->sig;
    while (temp != NULL) {
        NodoCola* next = temp->sig;
        free(temp);
        temp = next;
    }

    middleNode->sig = NULL;
    pagina->cola->frente = middleNode;
    pagina->cola->ultimo = middleNode;
    pagina->magnitud = 1;
    return;
}

// esta es muy esencial, esta al contrario de deleteExceptMiddle me devuelve un puntero nodo cola hacia la direccion de nodo que esta justo enmedio de una cola
NodoCola* obtenerNodoMedio(Cola* cola) {
    if (cola == NULL || cola->frente == NULL) {
        return NULL;
    }

    NodoCola* slow = cola->frente;
    NodoCola* fast = cola->frente;

    while (fast != NULL && fast->sig != NULL) {
        slow = slow->sig;
        fast = fast->sig->sig;
    }

    return slow;
}

// esta es una simple eliminacion de un nodo dentro de una cola, elimina el ultimo valor de la cola que reciba la funcion
void eliminarUltimoNodoCola(Cola* cola) {
    if (cola->frente == NULL) {
        return;
    }
    NodoCola* actual = cola->frente;
    NodoCola* anterior = NULL;

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

// OJO A ESTA. esta recibe la pagina que es la raiz del arbol, y devuelve aquella pagina que tienen un hijo con 5 valores, la uso para realizar la division de paginas
// es muy util ya que me sirve en subir valores cuando paginas hoja se tienen que dividir y ademas en caso de que se llene el padre tambien para dividirse el mismo
Pagina* buscarPaginaConHijoMagnitud5(Pagina* pagina) {
    if (pagina == NULL) {
        return NULL;
    }

    NodoCola* nodo = pagina->cola->frente;
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
    Pagina* resultado = NULL;
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

//*********MUCHO TEXTO ***********/
//  Esta funcion es la clave de la insercion en el arbol b+, recibe 2  parametros, LA PAGINA QUE SE DIVIDIRA Y LA PAGINA RAIZ DEL ARBOL B+
// se tienen 2 apuntadores primordiales, EL MEDIO DE LA PAGINA Y EL PAPA DE LA PAGINA, 
    Pagina* dividirNodo(Pagina* pagina, ArbolB* raizBuena) {
    NodoCola* medio = obtenerNodoMedio(pagina->cola);
    NodoCola* actual = pagina->cola->frente;
    Pagina* padre = buscarPaginaConHijoMagnitud5(raizBuena->raiz);

    //Si tiene padre entonces accede a esta condicion if
    if (padre != NULL) {
        //creo nueva pagina
        Pagina* nuevaPaginaConPadre = crearPagina();
        
        // le asigno los valores correspondientes por que esta nueva pagina sera la derecha del nodo que subira
        insertarColaOrdenada(&nuevaPaginaConPadre->cola, pagina->cola->frente->sig->sig->sig->dato);
        insertarColaOrdenada(&nuevaPaginaConPadre->cola, pagina->cola->ultimo->dato);
        // verifico si es pagina hoja, si ess hoja entonces dejo el nodo medio tambien en la pagina derecha, si no realizo una simple division normal
        if(pagina->cola->frente->izquierda == NULL){
            insertarColaOrdenada(&nuevaPaginaConPadre->cola, medio->dato);
            nuevaPaginaConPadre->magnitud = 3;
        }else{
            nuevaPaginaConPadre->magnitud = 2;
        }
        
        // le asigno derecha y izquierda a las nuevas paginas divididas
        nuevaPaginaConPadre->cola->frente->izquierda = medio->derecha;
        nuevaPaginaConPadre->cola->frente->derecha = pagina->cola->ultimo->izquierda;
        nuevaPaginaConPadre->cola->frente->sig->izquierda = pagina->cola->ultimo->izquierda;
        nuevaPaginaConPadre->cola->frente->sig->derecha = pagina->cola->ultimo->derecha;

        // subo el valor de enmedio de la pagina dentro de la pagina padre 
        insertarColaOrdenada(&padre->cola, medio->dato);
        padre->magnitud++;
        
        // verifica que todos los nodos de la cola de la pagina del padre se encuentren apuntando a las paginas correctas
        NodoCola* nodoSubidoAnterior = padre->cola->frente;
        NodoCola* nodoSubido = NULL;
        NodoCola* nodoSubidoSiguiente = NULL;
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

        //en la pagina original eliminamosl los 3 ultimos nodos para quedarnos con los tres primeros de esta forma terminariamos la division
        // pagina quedaria con dos valores, nuevaPaginaConPadre quedaria con 3 o 2 valores, dependiendo  si es pagina hoja o no la que se divide 
        //y el padre tendria un nodo mas en su cola debido al nodo resultante de la division de la pagina.
        eliminarUltimoNodoCola(pagina->cola);
        eliminarUltimoNodoCola(pagina->cola);
        eliminarUltimoNodoCola(pagina->cola);
        pagina->magnitud = 2;

        // y simplemente si se llena el padre tambien entonces se llama recursivamente a la funcion dividirNodo, hasta que no se tenga padre o que el padre tenga espacio suficiente
        if (padre->magnitud == 5) {
            dividirNodo(padre, raizBuena);
        }

        return padre;
    }
    

    // Aqui en caso reitero en que no se tenga padre, se realiza una division con dos paginas nuevas
    if(!buscarPaginaConHijoMagnitud5(pagina) && pagina->cola->frente->izquierda == NULL){
        // creo dos paginas
        Pagina* nuevaPaginaIzquierda = crearPagina();
        Pagina* nuevaPaginaDerecha = crearPagina();

        //inserto los valores de la pagina  izquierda y asigno izq y derecha
        insertarColaOrdenada(&nuevaPaginaIzquierda->cola, pagina->cola->frente->dato);
        insertarColaOrdenada(&nuevaPaginaIzquierda->cola, pagina->cola->frente->sig->dato);
        nuevaPaginaIzquierda->magnitud = 2;
        nuevaPaginaIzquierda->cola->frente->izquierda = pagina->cola->frente->izquierda;
        nuevaPaginaIzquierda->cola->frente->derecha = pagina->cola->frente->derecha;
        nuevaPaginaIzquierda->cola->frente->sig->izquierda = pagina->cola->frente->derecha;
        nuevaPaginaIzquierda->cola->frente->sig->derecha = pagina->cola->frente->sig->derecha;
        
           //inserto los valores de la pagina derecha y asigno izq y derecha
        insertarColaOrdenada(&nuevaPaginaDerecha->cola, medio->dato);
        insertarColaOrdenada(&nuevaPaginaDerecha->cola, medio->sig->dato);
        insertarColaOrdenada(&nuevaPaginaDerecha->cola, pagina->cola->ultimo->dato);
        nuevaPaginaDerecha->magnitud = 3;
        nuevaPaginaDerecha->cola->frente->izquierda = medio->derecha;
        nuevaPaginaDerecha->cola->frente->derecha = pagina->cola->ultimo->izquierda;
        nuevaPaginaDerecha->cola->frente->sig->izquierda = pagina->cola->ultimo->izquierda;
        nuevaPaginaDerecha->cola->frente->sig->derecha = pagina->cola->ultimo->derecha;

        // designo que el nodo resultante de la division su izq y derecha sean las nuevas paginas
        medio->izquierda = nuevaPaginaIzquierda;
        medio->derecha = nuevaPaginaDerecha;
        
        // como no hay padre por ende el nodo que sube se vuelve raiz
        raizBuena->raiz = pagina;

        // elimino todos los nodos de la pagina raiz excepto el de enmedio, para que quede corrrecto
        deleteExceptMiddle(pagina);
        return pagina;
    }
        // EN CASO DE QUE NO TENGA PADRE ENTONCES ES NUEVA RAIZ
        
        Pagina* nuevaPaginaIzquierda = crearPagina();
        Pagina* nuevaPaginaDerecha = crearPagina();

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



// FUNCION DE BUSQUEDA, DEVULVE UN PUNTERO NODOCOLA QUE COINCIDA CON EL VALOR DESEADO
NodoCola* buscarValor(Pagina* raiz, int valor) {
    if (raiz == NULL) {
        return NULL; 
    }

   
    NodoCola* aux = raiz->cola->frente;
    while (aux != NULL) {
        if (aux->dato == valor) {
            return aux; 
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

    return NULL; 
}


// esta funcion inserta un valor al arbol, recibe una pagina, el valor y la raiz del arbol, esta mediante recursivad busca la pagina correcta donde insertar el valor y lo mete en su cola
void insertarArbolB(Pagina *raiz, int valor, ArbolB* raizOriginal) {
   
    // comprobamos si esta vacio el arbol, si esta entonces es nueva raiz
    if (raiz->cola->frente == NULL) {
        insertarColaOrdenada(&raiz->cola, valor);
        raiz->magnitud++;
        return;
    }

    // LOGICA PARA BUSCAR EL LUGAR DONDE SE VA A INSERTAR EL VALOR
    // mediante un while comparo en cada pagina el valor que se ingreso con el valor que tiene su cola, esto lo hago recursivamente , ya que se ejecuta hasta
    // que pagina actual sea NULL, significando que no hay mas paginas abajo , entonces se puede insertar en la pagina actual.
    NodoCola *aux = raiz->cola->frente;
    Pagina *paginaActual = NULL;

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
    // verificacion si se llego a la pagina correcta para insertar el valor
    if (paginaActual == NULL) {
        // si tienen 4 claves, entonces se inserta la quitan y se divide la pagina
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
        // si no es la adecuada, se llama recursivamente hasta llegar a la pagina hoja donde se debe insertar
        insertarArbolB(paginaActual, valor, raizOriginal);
    }
    return;
}

// PRUEBAS-------------------------
/*
NodoCola
*eliminacionPruebas(NodoCola *nodo, int clave)
{
    if (!nodo)
    {
        return NULL;
    }

    static NodoCola *ant = NULL;
    NodoCola *busc = NULL;

    if (nodo->clave == clave)
    {
        busc = nodo;
    }
    else
    {
        ant = nodo;
        busc = buscarElem(nodo->sig, clave);
    }

    if (!busc)
    {
        if (nodo->derecha && nodo->izquierda)
        {
            busc = buscarElem(nodo->derecha->cola->frente, clave);
            if (!busc)
            {
                busc = buscarElem(nodo->izquierda->cola->frente, clave);
            }
        }
    }

    if (nodo->derecha)   
    {

    }

    return busc;
}   
*/

/*void eliminar(int valor, ArbolB *raizOriginal)
{
    
}*/

// https://www.programiz.com/dsa/deletion-from-a-b-plus-tree
// la fuente que estoy usando ahorita
void eliminar(int valor, Pagina* raizOriginal)
{
    if(raizOriginal == NULL || valor == 0){
        return;
    }

    // lo que voy a hacer es que cuando encuentre la clave
    // y lo elimiar, voy a utilizar herm_izq y herm_der
    // para ver si puedo fusionar o rebalancear
    NodoCola *busc = dfs(raizOriginal, valor),
            *herm_izq, *herm_der,
            *prev = NULL, *actuel = raizOriginal->cola->frente;
    Cola *head_temp = raizOriginal->cola;
    
    if(!busc)
    {
        printf("La clave %d no se encuentra en el arbol =(\n", valor);
        pause();
        return;
    }
    else
    {   //yea perdonen, kamehameha ;)
        //herm_izq = ;

        //tiene hijos?
        if(busc->derecha != NULL)
        {
            eliminar(valor, busc->derecha);
        }
        else
        { //no tiene, es una entrada de datos == hoja            
            //cuando sea un nodo hoja...
        
            if(head_temp->frente == head_temp->ultimo)
            {
                free(head_temp);
            }

            if(head_temp->frente == busc)
            {
                head_temp->frente=busc->sig;
                free(busc);
            }

            while(actuel != busc)
            {
                prev = actuel;
                actuel = actuel->sig;
            }
            if(actuel->sig != NULL)
            {
                prev->sig=actuel->sig;
                free(actuel);
            }
            else
            {
                eliminarUltimoNodoCola(raizOriginal->cola);
            }
            


            raizOriginal->magnitud--;
            
            if(raizOriginal->magnitud < 2)
            {
                //rebalance(busc->izquierda, raizOriginal);
            }
        }
        /*  deniso's notes
            1. checar si tiene hijos, si no tiene, es una entrada de datos
            2. eliminar clave
            3. checar si después de eliminar, el árbol está balanceado
             */
        if (busc->izquierda != NULL && busc->derecha != NULL)
        {
            // hacer la rotacion necesaria dependiendo del caso
            // en otras palabras, un monton de casos en forma de ifs
            // o bien en forma de switches jeje
        }
        else
        {
            // lo mismo, pero para otros casos xd
        }
    }

    // se podria comprobar si el valor buscado es igual al
    // frente de la derecha, para que pueda determinar que
    // caso de balanceo puede usar
    

    /*  deniso's notes
        si se elimina la clave y el recuento de claves minimas se sigue cumpliendo, se mueven las claves de forma normal y NO se debe balancear, es decir, no se hace ninguna fusión.
        se vuelve a hacer una copia
        
        23
            23 24 25 26
        -se elimina 23
        
        23                              24
            24 25 26 -------------->        24 25 26

        **si el recuento de claves mínimas no se cumple:
        pedir prestado a la derecha solo ocurrirá con los nodos más a la izquierda ya que no tienen hermanos izquierdos, es decir

              no tiene hermano <- [14]  
        notienehermano    <-[7 8]     14 20 21

       la fusión solo ocurre cuando tiene hermanos a la izquierda
    
 */
    }

void fusion(Pagina *pagina, Pagina *pag_hermana)
{

    NodoCola *nodo_a_fusionar = pagina->cola->frente;

    //Mientras haya nodos en la pagina a fusionar se inserta en la pagina hermana de manera ordenada
    //Y se avanza al siguiente nodo
    while(nodo_a_fusionar != NULL)
    {
        insertarColaOrdenada(&pag_hermana->cola, nodo_a_fusionar->dato);
        nodo_a_fusionar = nodo_a_fusionar->sig;
    }

    NodoCola *nodo_padre = pagina->cola->frente;

    while(nodo_padre != NULL)
    {
        if(nodo_padre->izquierda == pagina)
        {
            nodo_padre->izquierda = pag_hermana;
        }

        if(nodo_padre->derecha == pagina)
        {
            nodo_padre->derecha = pag_hermana;
        }

        nodo_padre = nodo_padre->sig;
    }

    free(pagina->cola);
    free(pagina);
}

void rebalance(Pagina *pagina, ArbolB *raizOriginal)
{
    if(pagina->magnitud < 2)
    {
        //punteros para fusionar a la izq o der
        Pagina *hermano_izq = pagina->cola->frente->izquierda;
        Pagina *hermano_der = pagina->cola->frente->derecha;

        if(hermano_izq != NULL && hermano_izq->magnitud > 2)
        {
            fusion(pagina, hermano_izq);
        }

        else if(hermano_der != NULL && hermano_der->magnitud > 2)
        {
            fusion(pagina, hermano_der);
        }
    }
}

// esta funcion imprime el arbol por completo, recorriendo nivel por nivel
void imprimirArbolB(Pagina *pagina, int nivel) {
    if (pagina == NULL) {
        return;
    }
    NodoCola *nodo = pagina->cola->frente;
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


NodoCola *dfs(Pagina *pagina, int dato){
    
    if(pagina == NULL)
        return NULL;

    NodoCola *actual = pagina->cola->frente;
    
    while(actual != NULL) 
    {
        if(actual->dato == dato)
            return actual;
        
        NodoCola *enc_izq = dfs(actual->izquierda, dato);

        if(enc_izq != NULL)
            return enc_izq;

        actual = actual->sig;
    }

    NodoCola *enc_der = dfs(pagina->cola->ultimo->derecha, dato);
    
    if(enc_der != NULL)
    {
        return enc_der;
    }
        
    return NULL;
}


// funcion que libera el arbol 
void liberarMemoriaArbol(Pagina* pagina) {
    if (pagina == NULL) {
        return;
    }

    NodoCola* nodo = pagina->cola->frente;
    while (nodo != NULL) {
        liberarMemoriaArbol(nodo->izquierda);
        NodoCola* temp = nodo;
        nodo = nodo->sig;
        free(temp);
    }
    free(pagina->cola);
    free(pagina);
}

    //menu principal
void menu(enum menuBool BOOL){
    puts("~*============={            }===============*~");
    puts("\t\t   ARBOL B+");
    puts("[1] - Insertar clave");
    if(BOOL)
    {
        puts("[2] - Buscar clave");
        puts("[3] - Eliminar clave");
        puts("[4] - Imprimir Arbol B+");
    }
    puts("[0] - Salir");
    puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
    printf("\tOpcion: \n>");
}

void pause()
{
    puts("Pulse ENTER para para volver al menu de opciones");
    getchar();
    getchar();
}

int main()
{
    ArbolB* arbolito = crearArbolB();
    
    int op, bt_key, O, keydt;
    //para llevar control del menu
    BOOL = FALSE; //<- no hay entrada de ninguna clave
        do{
            do{
                system("cls || clear");
                menu(BOOL);
                scanf("%d", &op);
                //repetir si no hay una entrada de clave
            }while(BOOL == FALSE && op != 1 && op != 0);

            switch(op)
            {   
                //inserción
                case 1:
                    do{
                        system("cls || clear");
                        puts("~*============={            }===============*~");
                        printf("Ingrese una clave:\n>");
                        scanf("%d", &bt_key);
                        insertarArbolB(arbolito->raiz, bt_key,arbolito);
                        puts("Desea agregar otra clave?");
                        printf("[1] - Si\n[2] - No\n>");
                        scanf("%d", &O);                
                    }while(O == 1);
                    BOOL = TRUE;
                    puts("LISTO!");
                    pause();
                break;
                case 2:
                    system("cls || clear");
                    puts("~*============={            }===============*~");
                    printf("Ingrese la clave a buscar:\n>");
                    scanf("%d", &bt_key);
                    NodoCola *clave_enc = dfs(arbolito->raiz, bt_key);
                    if(clave_enc) printf("Clave encontrada: %d\n", bt_key);
                    else puts("La clave no existe en el arbol");
                    puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
                    pause();
                break;
                case 3:
                    system("cls || clear");
                    puts("~*============={            }===============*~");
                    printf("Ingrese la clave a eliminar\n>");
                    scanf("%d", &keydt);
                    eliminar(keydt, arbolito->raiz);
                    puts("La clave ha sido eliminada exitosamente");
                    puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
                    pause();
                
                eliminar(4, arbolito);
                break;
                case 4:
                    system("cls || clear");
                    puts("~*============={            }===============*~");
                    imprimirArbolB(arbolito->raiz,0);
                    puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
                    pause();
                break;
                default: puts("Saliendo...");
            }
        }while(op);

        

    /* NodoCola* pruebaBusqueda = buscarValor(arbolito->raiz,41);
 
    if (!pruebaBusqueda)
    {
        printf("No existe el numero");
    }
    printf("El valor buscado encontrado es  %d \n",pruebaBusqueda->dato);
    
    liberarMemoriaArbol(arbolito->raiz);
    free(arbolito); */
    return 0;

}