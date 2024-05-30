#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int clave;
	char nombre[25];
	float precio;
}dato;

void insertar(dato *q, int t);
void most(dato *q, int t);

int main(){
	dato *p;
	int i, num;
	puts("Ingresa el tamanio del vector de estructuras");
	scanf("%d", &num);
	
	//p=(dato *)calloc(num, sizeof(dato));
	p=(dato *)malloc(num*sizeof(dato));
	
	printf("Llenando el vector de estructuras de %d elementos\n", num);
	insertar(p, num);
	
	printf("Mostrando el vector de estructuras de %d elementos\n", num);
	most(p, num);
	
	free(p);
	
	return 0;
}

void insertar(dato *q, int t){
	int i;
	
	for (i=0; i<t; i++){
		printf("Clave:\n");
		scanf("%d", &(q+i)->clave);
		printf("Nombre:\n");
		scanf("%s", &(q+i)->nombre);
		printf("Precio:\n");
		scanf("%f", &(q+i)->precio);
	}
}

void most(dato *q, int t){
	int i;
	
	for (i=0; i<t; i++){
		printf("Clave:%d\n", (q+i)->clave);
		printf("Nombre:%s\n", (q+i)->nombre);
		printf("Precio:%.2f\n", (q+i)->precio);
	}
}
