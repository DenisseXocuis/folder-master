#include<stdio.h>
#define T 30
int contarcadena(char *pp);
int main (){
	char cadena[T], *p;
	int i=0;
	puts("ingresa una cadena");
	gets(cadena);
	printf("\n Impresion de la cadena \n");
	while(cadena[i]){
		putchar(*(cadena+i));// notacion de apuntador
		i++;
	}
	p=&cadena[0];
	printf("\n Impresion de la cadena mediante el apuntador\n");
		while(*p)
		putchar(*p++);// aritmetica de apuntador
	p--;
	printf("\n Impresion de la cadena mediante el apuntador en reversa\n");
	while(*p)
		putchar(*p--);// aritmetica de apuntador
	p=&cadena[0];
	printf("\n El numero de carecteres de la cadena es %d \n",contarcadena(p));
	return 0;  
}//p es apuntador
int contarcadena(char *pp){
    int ii=0;
    while(*pp){
    	ii++;
    	pp++;
	}
    return ii;
}
