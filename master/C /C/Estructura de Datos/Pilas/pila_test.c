#include <stdio.h>
#include <stdlib.h>

struct nodo
{
	float e;
	struct nodo *sig;
};

int es_vacia(struct nodo *P)
{
	return P == NULL;
}

/* NO ES OPTIMO PARA UNA PILA porque no usará ni push ni pop, la estamos tratando como una lista
una pila siempre lleva su push y su pop

	void borrar_p(NODO **P){
		NODO *new;
		if(es_vacia(*P))
		{
			puts("Srry no se puede sacar nada");
			return;
			//exit(1);
		}
		nuevo = *P;
		*P = nuevo->sig;
		free(nuevo);
	}
 */


int push(struct nodo **P, struct nodo *elemento)
{
	elemento->sig = *P;
	*P = elemento;
	return 1;
}

int mete_p(struct nodo **P, float e)
{
	struct nodo *nuevo;
	nuevo = (struct nodo *)malloc(sizeof(struct nodo));
	if(!nuevo)
	{
		return 0;
	}
	nuevo->e = e;
	nuevo->sig = NULL;

	return push(P, nuevo);
}

struct nodo *pop(struct nodo **P)
{
	if(es_vacia(*P))
	{
		puts("Estas intentando hacer pop en una pila vacía!!");
		return NULL;
	}

	struct nodo *aux = *P;
	*P = (*P)-> sig;
	return aux;
}

void imprimir_p(struct nodo **P)
{
	if(es_vacia(*P))
	{
		puts("No hay elementos, pila vacía T.T!!");
	}

	//struct nodo *aux = //para ir vaciando pop
	struct nodo *aux = pop(P);
	struct nodo *Paux = NULL;

	while(aux != NULL)
	{
		printf("%.2f\n", aux->e);
		push(&Paux, aux);
		aux = pop(P);
	}
	aux = pop(&Paux);
	/*
	COMO LO CAMBIAN POR RECURSION*/
	/*while(aux != NULL)
	{
		printf("%.2f\n", aux->e);
		push(&Paux, aux);
		aux = pop(P);
	}*/

}

//WARNING!! ESTO NO, lo maneja como una lista
void imprimir_GPT(struct nodo *P){
	if(es_vacia(P))
	{
		puts("Ojo, toy vacia");
		return;
		//exit(1);
	}
	struct nodo *aux=P;
	while(aux)
	{
		printf("%.2f\n", aux->e);
		aux = aux->sig;	
	}
}


void borrar_p(struct nodo **P)
{
	
}

/*void borrar_p(struct nodo **P, float dato)
{
	struct nodo *nuevo;

	la pila esta vacia?
		Ojo, estas intencando sacar de una pila vacia

	//buscar elemento a borrar
	borrar_p(P);
		nuevo = pop(P);

		Necesitamos un auxiliar aux, Paux

		while(nuevo)
		{	
			e == dato
					liberar
			else 
				o que no se encontró  o mandarlo a aux para seguir recorriendo la pila
			nuevo a aux con un push ;)
		}
}*/

int main(int argc, char const *argv[])
{
	struct nodo *p = NULL;
	mete_p(&p, 3.4);
	mete_p(&p, 5.5);
	mete_p(&p, 6.6);
	mete_p(&p, 9.03);

	imprimir_p(&p);

	borrar_p(&p);

	imprimir_GPT(p);
	return 0;
}