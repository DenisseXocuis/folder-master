/* Este es el remix :p, la estructura fundamental del codigo sigue siendo la misma pero aprovechando que tengo un poquito mas de practica
   hice algunas modificaciones al codigo original de la practica de cadenas, eliminando la transicion rara antigua de pilas dinamicas a estaticas
   al momento de evaluar y pasando la evaluacion a una funcion, se agrego el faltante de operador de exponentes, y se estandarizo el formato para
   que no estuviera tan revuelto y añadiendo comentarios para ayudar a la claridad

   Falta agregar soporte de varios digitos y decimales, pero base de datos me esta comiendo el tiempo, asi que lo dejare a futuro jsjsj */
// Carlos Eduardo Espinoza Chapa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define Elem_Lista struct elem_lista
#define Lista struct lista_doble

struct elem_lista
{
    int dato;
    Elem_Lista *siguiente;
    Elem_Lista *anterior;
};

struct lista_doble
{
    Elem_Lista *inicio;
    Elem_Lista *final;
} lista_default = {NULL, NULL};

int generarLista(Lista **lista);
int insertarI(Lista *lista, int dato);
int insertarF(Lista *lista, int dato);
int eliminar_Elem(Lista *lista, Elem_Lista *nodo);
void imprimir(Lista *lista);
int comparar(int esperar, int inicio);
int validarCaracteres(char *t);
int validarParentesis(char *p);
int validarMultiDiv(char *q);
int pedirExpresion(char *palabra);
double evaluarExpresion(Lista *salida);

int main()
{
    Lista *original, *pila, *salida;
    char expresion[100];
    int i;
    generarLista(&original);
    generarLista(&pila);
    generarLista(&salida);
    pedirExpresion(expresion);
    for (i = 0; i < strlen(expresion) - 1; i++)
    {                                          // va transcribiendo los caracteres de la expresion del arreglo a una lista dinamica
        if (expresion[i] != ' ')               //elimina espacios que pudieran existir, si quisiera que el programa fuera compatible con varios digitos
            insertarF(original, expresion[i]); //siento que aqui es donde deberia hacer la conversion de datos :D
    }
    //Se empieza con shunting para convertir a postfix
    // Mientras existan caracteres por leer de la expresion
    while (original->inicio != NULL)
    { // si el token es un operador lo agrega a la pila temporal, si es un numero lo agrega a la cola final
        if ((original->inicio->dato >= '(' && original->inicio->dato <= '/') || original->inicio->dato == '^')
        { //checa los tokens, y los va agregando a la pila temp mientras no se encuentre un parentesis cerrado
            if (original->inicio->dato != ')')
            { //checa si la pila esta vacia
                if (pila->inicio != NULL)
                { //si no compara el token en espera con el de inicio de la pila para ver que precedencia tiene
                    while ((comparar(original->inicio->dato, pila->inicio->dato)) != 0)
                    { // mientras el token en la pila original tiene menor prioridad que el token al comienzo de la pila temp, lo pasa a la cola de salida
                        insertarF(salida, eliminar_Elem(pila, pila->inicio));
                        if (!pila->inicio)
                        {
                            break;
                        }
                    }
                }
                // por si la pila se encuentra vacia de tokens
                insertarI(pila, original->inicio->dato);
            }
            else
            {                                     //si se encontro un parentesis cerrado en la pila original, va pasando los datos de la pila temp a la cola final hasta encontrar su parentesis
                while (pila->inicio->dato != '(') // abierto
                {
                    insertarF(salida, eliminar_Elem(pila, pila->inicio));
                }
                eliminar_Elem(pila, pila->inicio); //elimina el parentesis abierto restante
            }
        }
        else
        { // en caso de que sea un numero en la pila original, lo pasa directamente a la cola de salida
            insertarF(salida, original->inicio->dato);
        } //mueve el inicio de la lista original
        original->inicio = original->inicio->siguiente;
    } // en caso de que queden operadores en la pila temp, cuando ya esta vacia la original, se agregan los restantes a la cola de salida
    while (pila->inicio != NULL)
    {
        insertarF(salida, eliminar_Elem(pila, pila->inicio));
    }

    printf("\nResultado Evaluado Final:\n%.2lf", evaluarExpresion(salida));

    return 0;
}

// asigna memoria e inicializa en 0s
int generarLista(Lista **lista)
{
    *lista = (Lista *)calloc(1, sizeof(*lista));
    if (!lista)
    {
        printf("No se pudo alojar la memoria:\n");
        return 0;
    }
    **lista = lista_default; //segun yo esta demas debido a calloc(), pero lo dejo asi para asegurarme en lo que testeo mas
    return 1;
}

// inserta al inicio, util para pilas
int insertarI(Lista *lista, int dato)
{
    Elem_Lista *temp;
    temp = (Elem_Lista *)calloc(1, sizeof(*temp));
    temp->dato = dato;
    temp->siguiente = NULL;
    temp->anterior = NULL;
    if (!lista->inicio)
    {
        lista->inicio = temp;
        lista->final = temp;
    }
    else
    {
        lista->inicio->anterior = temp;
        temp->siguiente = lista->inicio;
        lista->inicio = temp;
    }
    return 1;
}

// inserta al final de una lista, util para colas
int insertarF(Lista *lista, int dato)
{
    Elem_Lista *temp;
    temp = (Elem_Lista *)calloc(1, sizeof(*temp));
    temp->dato = dato;
    temp->anterior = NULL;
    temp->siguiente = NULL;
    if (!lista->inicio)
    {
        lista->inicio = temp;
        lista->final = temp;
    }
    else
    {
        lista->final->siguiente = temp;
        temp->anterior = lista->final;
        lista->final = temp;
    }
    return 1;
}

// Elimina nodos de una lista y libera memoria
int eliminar_Elem(Lista *lista, Elem_Lista *nodo)
{
    Elem_Lista *temp;
    int dato = 0;
    temp = (Elem_Lista *)calloc(1, sizeof(*temp));
    temp = nodo;
    if (nodo)
    {
        if (temp->anterior == NULL && temp->siguiente == NULL)
        {
            dato = temp->dato;
            lista->inicio = NULL;
            lista->final = NULL;
        }
        else if (temp == lista->inicio)
        {
            lista->inicio = lista->inicio->siguiente;
            lista->inicio->anterior = NULL;
            temp->siguiente = NULL;
            dato = temp->dato;
        }
        else if (temp == lista->final)
        {
            lista->final = lista->final->anterior;
            lista->final->siguiente = NULL;
            temp->anterior = NULL;
            dato = temp->dato;
        }
        else
        {
            temp->anterior->siguiente = temp->siguiente;
            temp->siguiente->anterior = temp->anterior;
            temp->siguiente = temp->anterior = NULL;
            dato = temp->dato;
        }
        free(temp);
        return dato;
    }
    return dato;
}

// funcion para ver los elementos en la lista
void imprimir(Lista *lista)
{
    Elem_Lista *temp = lista->inicio;
    int i = 0;

    while (temp != NULL)
    {
        printf("Elemento Numero [%d] de la lista\n%d\n", i, temp->dato);
        i++;
        temp = temp->siguiente;
    }
    return;
}

// compara el orden de los operadores y regresa si es menor o mayor que el que ya esta
int comparar(int esperar, int inicio)
{
    int verificar;
    if ((esperar == '*' || esperar == '+' || esperar == '-' || esperar == '/') && inicio == '^')
    {
        verificar = 1;
    }
    else if ((esperar == '+' || esperar == '-') && (inicio == '*' || inicio == '/'))
    {
        verificar = 1;
    }
    else
    {
        verificar = 0;
    }
    return verificar;
}

//Valida que los caracteres sean validos
int validarCaracteres(char *t)
{
    while (*t != '\0')
    {
        if (*t < '(' && *t > '9')
        {
            printf("Expresion no valida:\n");
            return 0;
        }
        t++;
    }
    return 1;
}

//Valida que los parentesis esten completos
int validarParentesis(char *p)
{
    int abrir = 0, cerrar = 0;

    while (*p != '\0')
    {
        if (*p == '(')
            abrir++;
        if (*p == ')')
            cerrar++;
        p++;
    }

    if (abrir == cerrar)
        return 1;
    else
        return 0;
}

//Valida que los operadores tengan su pareja de operandos
int validarMultiDiv(char *q)
{
    while (*q != '\0')
    {
        if (*q == '*' || *q == '/')
        {
            if (*(q + 1) == '\0' || (q - 1) == NULL)
            {
                printf("Error de formato\n");
                return 0;
            }
        }
        q++;
    }
    return 1;
}

// Se asegura de que la expresion matematica este correcta
int pedirExpresion(char *palabra)
{
    do
    {
        printf("Ingresa una expresion matematica. Puede contener\n");
        printf("Digitos del 0-9\n");
        printf("Operadores binarios (+ - * / ^)\n");
        printf("Parentesis como signo de agrupacion\n");
        fgets(palabra, 100, stdin);
    } while ((validarCaracteres(palabra) && validarMultiDiv(palabra) && validarParentesis(palabra)) != 1);
    return 1;
}

// Evalua una expresion ya ordena de forma postfix
double evaluarExpresion(Lista *salida)
{
    Lista *temp, *aux;
    int ch = 0;
    double A = 0, B = 0, val = 0;
    generarLista(&temp);
    aux = salida;
    while (aux != NULL)
    {
        ch = aux->inicio->dato;
        if (isdigit(ch))
        {
            insertarF(temp, (eliminar_Elem(aux, aux->inicio)) - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            eliminar_Elem(aux, aux->inicio);
            A = eliminar_Elem(temp, temp->final);
            B = eliminar_Elem(temp, temp->final);
            val = 0;
            switch (ch)
            {
            case '*':
            {
                val = B * A;
                break;
            }

            case '/':
            {
                val = B / A;
                break;
            }

            case '+':
            {
                val = B + A;
                break;
            }

            case '-':
            {
                val = B - A;
                break;
            }
            case '^':
            {
                val = pow(B, A);
                break;
            }
            }
            insertarF(temp, val);
            if (!aux->inicio)
            {
                break;
            }
        }
        if (!aux->inicio)
        {
            break;
        }
    }
    return eliminar_Elem(temp, temp->inicio);
}