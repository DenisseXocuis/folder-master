//memoria dinamica
#include<stdio.h>

int main(){
	char c,cadena[]="Veracruz";
	int i, vector[]={1,2,3,4,5};
	float f;
	double d;
	printf ("El tamano del caracter %d\n", sizeof(c));        //"c"se puede sustituir por char y da lo mismo
	printf ("El tamano de la cadena %d\n", sizeof(cadena));
	printf ("El tamano del entero %d\n", sizeof(i));         //"i"se puede sustituir por int y da lo mismo
	printf ("El tamano del flotante %d\n", sizeof(f));       //"f"se puede sustituir por float y da lo mismo
	printf ("El tamano del doble %d\n", sizeof(d));         //"d"se puede sustituir por double y da lo mismo
	
	return 0;
}

