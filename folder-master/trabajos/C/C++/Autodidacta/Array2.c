#include<stdio.h>
#include<math.h>
#include<locale.h>

int main(){
	
	int alum;
	float cal;
	printf("Programa que lee las calificaciones de  alumnos e identifica si está aprobado o reprobado\nIngrese el número de alumnos a ingresar\n>");
	scanf("%i", &alum);
	
	for(int i = 0; i < alum; i++)
	{
		printf("Ingrese la calificación del alumno %i", i+1);
		scanf("%f", &cal);
	}
	
	
	return 0;
	
}