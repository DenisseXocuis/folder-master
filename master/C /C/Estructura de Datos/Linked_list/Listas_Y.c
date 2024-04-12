/*SIN TYPEDEF*/
/*  agregar_final();
    inserte un nuevo nodo al final de la lista
    eliminar();
    posicion del nodo
    ordenar la lista
    invertir lista
    eliminar duplicados
*/
//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>

//CREAR UN NUEVO NODO
struct nodo *crear_nodo(int datos);

//IMPRIMIR LISTA
void print_lista(struct nodo *head);

//AGREGAR
void agregar(struct nodo *head, int datos);

//DEFINIENDO EL REGISTRO PARA LOSO NODOS DE LA LISTA
struct nodo
{
    //Almacenar informacion
    int dato;
    //Almacenar la direcioon del siguiente nodo
    struct nodo *link;
};

int main(int argc, char const *argv[])
{
    //falta liberar memoria
    //declarar el apuntador inicial
    struct nodo *head = NULL;

    //agregar nodos
    agregar(&head, 2);
    agregar(&head, 1);
    agregar(&head, 5);
    agregar(&head, 3);

    print_lista;
    return 0;
}

//Crear un nuevo nodo
struct nodo *crear_nodo(int datos)
{
    //asignar memoria al nuevo nodo
    struct nodo *nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    //Falta verificar que tengamos memoria
    //almacenar datos en el miembro dato del nodo
    nuevo->dato = datos;
    //inicializar link a NULL
    nuevo->link = NULL;
    //regrese el apuntador al nuevo nodo
    return nuevo;
}

//imprimir lista
void print_lista(struct nodo *head)
{
    //para recorrer la lista de principio a fin, usaremos aux para avanzar, 
    //hasta que el siguiente nodo sea igual a NULLa 
    puts(" ");
    struct nodo *aux;

    for(aux=head; aux!=NULL; aux=aux->link)
    {
        printf("Elemento: %d\n", aux->dato);
    }
}

//agregamos nodos al inicio de la lista
void agregar(struct nodo *head, int datos)
/*
    La funcion agregar lleva un doble apuntador, por que?, porque
    necesita modificar el valor de HEAD dentro de la funcion.
    Necesitamos el doble apubntador para actualizar HEAD, 
    la razon es que HEAD ya es un apuntador a un NODO, entonces
    pars cambiar el valor al que HEAD apunta, se necesita un 
    apuntador a HEAD.

    El primer * nos permite acceder al valor al que apunta HEAD.

    El segundo * nos permite modificar el valor al que apunta HEAD
*/
{
    // crear un nuevo nodo, usando la funcion crear_nodo
    struct nodo *nuevo = crear_nodo(datos);

    /*Apuntando al HEAD actual, es decir al nodo que se 
    encuentra actualmente al inicio de la lista*/
   /*  nuevo->link = *head;

    //Actuaslizar el valor de HEAD
    *head = nuevo; */
}