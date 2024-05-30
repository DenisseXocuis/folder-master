//Clase 16 de Abril 2024 Tema:PILAS 
#include <stdio.h>
#include <stdlib.h>

struct nodo
{
	float e; 
	struct nodo *sig;
}; 

int es_vacia(struct nodo *p)
{
	return p == NULL; 
}

int push(struct nodo **p, strcut nodo *elemento)
{
	elemnto->sig = *p; 
	*p = elemento;
	return 1; 
}

int mete_p(struct nodo **p, float e)
{

//CON ESTO SE PUEDE CREAR UNA FUNCIÓN CREAR NODO
	struct nodo *nuevo; 
	nuevo = (struct nodo *)malloc(sizeof(struct nodo)); 
	if(!nuevo)
	{
		return 0; 
	}
	nuevo->e = e;
	nuevo->sig = NULL; 
// ...
	return push(p, nuevo); 
}

struct nodo *pop(struct nodo **p)
{
	if(es_vacia(*p))
	{
		puts("Estas intentado hacer pop en una pila vacía");
		return NULL; 
	}

	struct nodo *aux = *p;
	*p = (*p) -> sig;  

	return aux; 
}

// crear la función imprimir_p(p)
void imprimir_p(struct nodo **p)
{
	if(es_vacia(*p))
	{
		puts("NO HAY ELEMENTOS, pila vacía T.T");
	
	}

	struct nodo *aux = pop(p); //para ir vaciando pop
	struct nodp *paux = NULL; 

	while(aux !=NULL)
	{
		printf("%.2f\n", aux->e);
		push(&aux, aux); 
		aux = pop(p);
	}
	aux = pop(&aux); 
/*
	COMO LO CAMBIAN POR RECURSION 
	while(aux !=NULL)
	{
		printf("%.2f\n", aux->e);
		push(&aux, aux); 
		aux = pop(p);
	}
*/
}


int main(int argc, char const *argv[])
{
	struct nodo *p = NULL; 
	mete_p(p, 3.4); 
	mete_p(&p, 5.5); 
	mete_p(&p, 6.6); 
	mete_p(&p 9.03); 

imprimir_p

	return 0;
}

