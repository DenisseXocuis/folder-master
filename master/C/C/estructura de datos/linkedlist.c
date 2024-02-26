#include<stdio.h>
#include<stdlib.h>

struct lista{
    int valor;
    struct node *next;
};

int main(int argc, char **argv){
    struct lista *nodo;
    nodo = malloc(sizeof(struct lista));
    (*nodo).valor = 23;
    
    return 0;
}