#include<stdio.h>
#include<string.h>

char *invertir_cadena(char *puntero, int i, int j);

int len(char*cadena);

int main(){
	
	char arreglo[40] = {"Eva"}; 
	
	char *puntero = &arreglo[0];
	
	int tamanio = len(puntero); 
	
	char *puntero_b = invertir_cadena(puntero,tamanio-1,0);
	
	printf("\nPuntero_b: %s",puntero_b);
}

char *invertir_cadena(char *puntero, int i, int j){
	static char arreglo_aux[100]; 
	
	if(*puntero){
		printf("%c\n",*puntero);
		puntero +=i;
		arreglo_aux[j] = *puntero; 
		puntero -=i;
		return invertir_cadena(++puntero,i-2,j+1);
	}
		
	else{	
		printf("\n-Inverso: %s",arreglo_aux);
		return arreglo_aux;
	}	
	
}

int len(char *cadena){
	if(*cadena){
		return 1+len(++cadena);
	}
	else
		return 0; 
}

/*

Ejemplo del funcionamiento, Eva

Parametros del llamado de la funcion en el main
-------------------
apuntador -> E ,(incio de la cadena) 
tamaño (i) = 3-1 = 2
j = 0
-------------------


-------------------
Primera iteracion
-------------------
apuntador -> E
muevo 2 en el apuntador -->a
guardo apuntador en arreglo_aux[j]
muevo - (2) en apuntador -> E
-------------------

-------------------
Segunda iteracion
------------------
apuntador -> v
i= 2-2 =0
j = 0+1 = 1

muevo 0 en el apuntador --> v
guardo apuntador en arreglo_aux[j]
muevo 0 en el apuntador -> v


-------------------
Tercera iteracion
------------------
apuntador -> a
i = 0 -2 = -2
j = 1+1 = 2

muevo en el apuntador -2 en el apuntador -->E
guardo apuntador en arreglo_aux[j]
muevo -(-2) en el apuntador -> a


++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++

RESULTADO: avE

*/
