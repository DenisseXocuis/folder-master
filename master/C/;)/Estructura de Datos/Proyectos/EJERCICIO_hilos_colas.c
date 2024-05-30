#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

#define NUM_TRABAJADORES 3

typedef struct Cola_str{
    struct Nodo_str *frente; 
    struct Nodo_str *final;
}Cola;

typedef struct Nodo_str{
    int dato; 
    struct Nodo_str *sig;
}Nodo;

void ingresar_dato(Cola *cola,int dato_arg);
int get(Cola *cola);

void *atender_clientes(void *arg);

int main(){ 
    
    Cola cola; 
    //Inicializar cola
    cola.final=NULL;
    cola.frente=NULL;
    
    int cola_num;
    //Generacion de la cola
    for(int i=0; i<100; i++)
        ingresar_dato(&cola,i);


    pthread_t trabajadores[NUM_TRABAJADORES];
    //Atencion a cada dato de la cola
    while(cola.frente != NULL){   
        
        for(int i=0;i<NUM_TRABAJADORES;i++){
            cola_num=get(&cola);
            pthread_create(&trabajadores[i],NULL,atender_clientes,&cola_num);
        }
    }
    return 0;

}

void ingresar_dato(Cola *cola,int dato_arg){
  
    Nodo *nuevo= (Nodo*)malloc(sizeof(Nodo));
    
    if(nuevo != NULL){
      
      nuevo->dato = dato_arg;  
      
    //Primer elemento insertado

      if(cola->frente ==NULL){  
          cola->frente = nuevo;
          nuevo->sig = cola->final;
          cola->final = nuevo; 
      }
      
      //Demas elementos inserados
      else{
        cola->final->sig = nuevo; 
        nuevo->sig = NULL; 
        cola->final = nuevo;
      }

        //printf("Dato ingresado: %d\n",cola->final->dato);
    
    }
    
}

int get(Cola *cola){

    //CASO: Cola vacia 
    if(cola->frente==NULL){
        puts("Cola vacia");
        return -123; //Valor arbitrario 
    }

    int num=0; 

    //CASO: Unico elemento
    if(cola->final == cola->frente){
        puts("UNICO ELEMENTO");
        num = cola->frente->dato;
        free(cola->final); 
        cola->final=NULL; 
        cola->frente=NULL; 
        //printf("NUM: %d\n",num);
        return num;
    }

    //CASO: n elementos agregados
    Nodo *aux = cola -> frente -> sig;
    num = cola->frente->dato; 
    free(cola->frente);
    cola->frente = aux;

    return num;
} 

void *atender_clientes(void *arg){

    clock_t inicio,fin;
    double tiempo_transcurrido;

    inicio = clock();

    int *num = (int*)arg;
    int resultado = *num-1;

    fin = clock();
    tiempo_transcurrido = (double)(fin-inicio);
    printf("Num_cola: %d/Resultado: %d/Tiempo de ejecucion: %f\n",*num,resultado,tiempo_transcurrido);

    return NULL;

}