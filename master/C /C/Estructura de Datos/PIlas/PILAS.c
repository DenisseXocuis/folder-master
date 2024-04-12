#include <stdio.h>
#include <stdlib.h>
#define T 3
int push(int *p, int x){
    int *tope;
    if (tope == T - 1)
        puts("Oops, u have an overflow!\n");
    else {
        
    }
    
}
int pop(){
}
int pila_vacia(){

}
int main(){
    int pila[3], elemento;

    for(int i = 0; i<=T; i++){
        scanf("%d", elemento);
        push(pila, elemento); //meter dato
    }
    return 0;
    //pila_vacia, regresa el tope, sacar pop y meter pila 2
}