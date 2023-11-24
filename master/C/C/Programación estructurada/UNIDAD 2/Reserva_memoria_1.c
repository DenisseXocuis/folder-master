#include<stdio.h>
#include<stdlib.h>  //libreria de sizeof y malloc
int main(){
	char *p;
	p=(char *)malloc(sizeof(char));  //hacemos el cast "casteo" ; void es como null
	printf("Ingresa un caracter:\n");
	scanf("%c", p);
	printf("El valor de de p es: %c\n", *p);
	free(p);//se debe cerrar siempre la memoria para que no se alente cuando se cree muchos datos
	//si no se cierra la memoria ram, se alenta por eso se debe liberar el espacio.
	
	return 0;
	//se creo p como un apuntador, se reserva un espacio con p. 
}
