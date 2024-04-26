#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define Nodo struct nodo
#define ListaDob struct listadoble

struct nodo{
    int dato;
    Nodo *siguiente;
};

struct listadoble{
    Nodo *inicio;
    Nodo *final;
};
Nodo *inicio=NULL;
Nodo *final=NULL;

void insertar(ListaDob *list, int dato);
Nodo *nuevoElemento(int dato);
void visualizarLista(ListaDob nlista);
int eliminarNodo(ListaDob *lista);
void insertarI(ListaDob *list, int dato);
int comparar(int esperar, int inicio);

int main(){
    ListaDob Lista1, Stack, Final, Eval;
    char palabra[100], ch;
    int i, len, eval[100];
    Lista1.inicio=Lista1.final=NULL;
    Stack.inicio=Stack.final=NULL;
    Final.inicio=Final.final=NULL;
    Eval.inicio=Eval.final=NULL;
    printf("Caracteres permitidos: + - * / ( )\n");
    printf("Ingrese la expresion\n");
    fgets(palabra, 100, stdin);
    len = strlen(palabra)-1;
    for (i=0;i<len;i++){
        printf("Caracter: %c\n", palabra[i]);
        if (palabra[i] != ' ')
            insertar(&Lista1, palabra[i]);
    }
    Nodo *esperar = Lista1.inicio;
    while (esperar != NULL){
        if ((esperar->dato >= '(' && esperar->dato <= '/') || (esperar->dato == '^')){
            if (esperar->dato != ')'){
                if (Stack.inicio != NULL){
                    while (comparar(esperar->dato, Stack.inicio->dato) != 0){
                        insertar(&Final, eliminarNodo(&Stack));
                        if (Stack.inicio == NULL){
                            break;
                        }
                    }
                }
                insertarI(&Stack, esperar->dato);
            }
            else{
                while (Stack.inicio->dato!='('){
                    insertar(&Final, eliminarNodo(&Stack));
                }
                eliminarNodo(&Stack);
            }
        }
        else{
            insertar(&Final, esperar->dato);
        }
        esperar = esperar->siguiente;
    }
    while(Stack.inicio != NULL){
        insertar(&Final, eliminarNodo(&Stack));
    }
    printf("\nResultado Final: ");
    visualizarLista(Final);
    while (Final.inicio!=NULL){
        ch = Final.inicio->dato;
        int A=0, B=0, val=0;
        if (isdigit(ch)){
            eval[i] = Final.inicio->dato;
        }else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            eval[i] = Final.inicio->dato;
        }
    return 0;
    }
}

void insertar(ListaDob *list, int dato){
    Nodo *nuevo =nuevoElemento(dato);
    if (list->inicio==NULL && list->final==NULL){
        list->inicio=nuevo;
        list->final=nuevo;
    } else{
        list->final->siguiente=nuevo;
        list->final=nuevo;
    }
}

Nodo *nuevoElemento(int dato){
    Nodo *q=(Nodo*) malloc(sizeof(Nodo));
    q->dato=dato;
    q->siguiente=NULL;
    return q;
}

void visualizarLista(ListaDob nlista){
    if (nlista.inicio!=NULL){
        Nodo *aux=nlista.inicio;
        while (aux != NULL){
            printf("%c ", aux->dato);
            aux=aux->siguiente;
        }
    }
}

int eliminarNodo(ListaDob *lista){
    Nodo *aux=lista->inicio;
    int dato=aux->dato;
    lista->inicio=lista->inicio->siguiente;
    free(aux);
    return dato;
}

void insertarI(ListaDob *list, int dato){
    Nodo *nuevo=nuevoElemento(dato);
    if(list->inicio==NULL && list->final==NULL){
        list->inicio=nuevo;
        list->final=nuevo;
    } else{
        nuevo->siguiente=list->inicio;
        list->inicio=nuevo;
    }
}

int comparar(int esperar, int inicio){
    int verificar;
    if ((esperar=='*' || esperar=='+' || esperar=='-' || esperar=='/') && inicio=='^'){
        verificar = 1;
    } else if ((esperar=='+' || esperar=='-') && (inicio=='*' || inicio=='/')){
        verificar=1;
    }else{
        verificar = 0;
    }
    return verificar;
}