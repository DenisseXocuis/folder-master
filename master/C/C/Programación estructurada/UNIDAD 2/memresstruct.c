#include <stdio.h>
#include <stdlib.h>

void insertar(int *q, int t);
void most(int *q, int t);

int main(){
	int *p, n, i;
	
	puts("Ingrese el tamano del vector la cantidad de productos");
	scanf("%d", &n);
	
	p=(int *)calloc(n, sizeof(int));
	//p=(int *)malloc(n*sizeof(int));
	
	puts("Ingresando los datos del vector");
	insertar(p, n);
	
	puts("Mostrando los datos del vector");
	most(p, n);
	p-=n;
	free(p);
	
	return 0;
}

void insertar(int *q, int t){
	int i;
	
	for(i=0; i<t; i++)
		scanf("%d", (q+i));
}

void most(int *q, int t){
	int i;
	for(i=0; i<t; i++)
		printf("v[%d]=%d\n", i, *(q+i));
}
