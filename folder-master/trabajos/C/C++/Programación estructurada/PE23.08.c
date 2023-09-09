#include<stdio.h>
int suma(int x,int y); //función prototipo, "int x" se le llama argumento 1 
int main(){
    int x,y,z; //zona de declaración de variables locales
    printf("Ingresa dos números \n");
    scanf("%d %d", &x,&y);
    z = suma (x,y); //parámetro o argumento por valor, pasamos un valor por un elemento de variable
    printf("El resultado de %d + %d = %d\n", x,y,z);
    return 0;

}

int suma(int x,int y){
    int z;
    z = x + y; 
    return z;
}