#include<stdio.h>
#include<math.h>
#include<locale.h>


int main(){
	setlocale(LC_ALL,"");
	
	int per, may,min,i;
	float prom, desv;
	
	printf("Programa que lee las edades de un grupo de personas y obtiene calculos correspondientes\n¿Cuántas personas desea agregar?\n>");
	scanf("%i", &per);
	
	int gru[per];
	
	//lectura de cada edad y guardada en cada índice
	for(i = 0; i < per; i++)
	{
		printf("Ingrese la edad de la persona %d\n>", i+1);
		scanf("%d", &gru[i]); //guarda la edad de la persona en la posición i
	}

	desv=0;
	prom=0;
	may= gru[0];
	min = gru[0];

	//mayor o menor
	for(i = 0; i < per; i++)
	{
		if(gru[i] > may) //mayor
			may = gru[i];
		if(gru[i] < min) //menor
			min = gru[i];
		prom = prom + gru[i]; //acumulador de edades
	}

	prom = prom/per;

	for(i=0; i < per; i++)
	{
		desv = desv + pow((gru[i] - prom),2); //sumador de la edad menos el promedio al cuadrado
	}

	desv = sqrt(desv/per); //desviación estándar

	printf("Las edades fueron:\n");

	for(i = 0; i < per; i++)
	{
		printf("%d \n", gru[i]);
	}
	
	printf("\nEdad mayor: %d", may);
	printf("\nEdad menor: %d", min);
	printf("\nPromedio: %.2f", prom);
	printf("\nDesviación estandar: %.2f", desv);	
	
	
	return 0;
}