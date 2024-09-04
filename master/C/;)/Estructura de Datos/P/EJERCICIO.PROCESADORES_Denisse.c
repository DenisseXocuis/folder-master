#include<stdlib.h>
#include<stdio.h>
#define TIEMPO 2
void menu();
void pause();
void about();

/* WIP

    se presentan problemas con la eliminación del nodo
    se sigue trabajando en ello
    -Lara Xocuis Martha Denisse

 */
enum _bool{FALSE,TRUE}BOOL; //control de entrada de tareas
typedef int TipoTarea;

/* ___________COLA DE PROCESOS____________ */
        //estructura de nodo base para cola de procesos
        typedef struct nodo{
            TipoTarea PID, t;
            struct nodo *next;
        }NODE;

        //apuntadores para cola (frente y final)
        typedef struct cola{
            struct nodo *frente;
            struct nodo *final;
        }COLA_TAREAS;

        //crea nodo base de cola de procesos
        NODE *nodo_cola(TipoTarea x){
            NODE *nod = (NODE*) malloc(sizeof(NODE));
            if(!nod)
            {   puts("ERROR, NO HAY MEMORIA, ni modo :cola");
                exit(1);
            }
            nod->PID= x;
            nod->t=TIEMPO; //segundos
            nod->next=NULL;
            return nod; //regresa el nodo creado
        }

        //crea cola de tareas, inicializando cada nodo creado
        int cola_tareas(COLA_TAREAS *head, TipoTarea task){
            NODE *nodo = nodo_cola(task);
            //primer valor NULL : Cola vacía
            if(head->frente==NULL){
                head->frente=nodo;
                head->final=nodo;
                return 1;
            }
            head->final->next=nodo;
            head->final=nodo;
            return 1;
        }

/*___________PROCESADORES_______________*/
        //estructura nodo base para cola circular de procesadores
        typedef struct nodo_procesador{
            NODE *TASK; //apuntador a nodo de procesos
            int contador_procesos;
            struct nodo_procesador *next; 
        }PROCESADOR;

        //apuntadores para cola 2 (frente y final)
        typedef struct cola2{
            struct nodo_procesador *frente;
            struct nodo_procesador *final;
            struct nodo *frente2;
            struct nodo *final2;
        }COLA_PROCESOS;

        //creación de los 3 procesadores cicliclos
        int procesadores(COLA_PROCESOS *head){
            for(int i=0; i<3; i++){ //serán 3 procesadores
                PROCESADOR *new_procesador = (PROCESADOR*) malloc(sizeof(PROCESADOR));
                if(!new_procesador) return 0;                    
                if(head->frente==NULL){ //sin procesadores (nodo 1)
                    head->frente=new_procesador;
                    head->final=new_procesador;
                    new_procesador->next=new_procesador; //el primer nodo apunta hacia si mismo
                }
                else{
                    //el nuevo nodo apunta al primer nodo
                    new_procesador->next = head->final->next;
                    head->final->next = new_procesador;
                    head->final = new_procesador;
                }
            }
            return 1;
        }

        /*_______________LLENAR COLA CIRCULAR DE PROCESADORES_____________________*/
        //desencola 1 nodo de la cola de tareas
        NODE *desencolar(COLA_TAREAS **head){ 
            if((*head)->frente==NULL){ //ya no hay tareas
                return NULL;
            }
            else{
                NODE *nodito = (*head)->frente;
                (*head)->frente = (*head)->frente->next; //asigna frente al otro nodo siguiente
                nodito->next=NULL;
                return nodito;
            }
        }

        //encola el nodo desencolado en TASK, es decir, procesador 1
        int llenar(COLA_PROCESOS *head_procesos, COLA_TAREAS **head_tareas, int *tareas_atendidas, int *tareas_total){
                static int pasarsiguiente=0;
            //desencola y llena en 1 procesador 3 veces (porque ese es el límite)
                NODE *nodito = desencolar(&head_tareas); //nodito desencolado
                //si nodito no apunta nada, quiere decir que no hay más tareas en la cola de tareas
                *tareas_total -=1;
                    //si NO está lleno el procesador, 
                    if (head_procesos->frente->contador_procesos<3){
                        if(*tareas_total >= 0){
                            //mete el nodo desencolado al proceso
                            head_procesos->frente->TASK = nodito;
                        }
                        if(head_procesos->frente != NULL){
                                //si es el primer nodo en agregar, lo hace circular y atiende
                            if(head_procesos->frente2==NULL){
                                //TASK en este caso es el apuntador a la otra cola circular que tiene el procesador
                                head_procesos->frente2 = head_procesos->frente->TASK;
                                head_procesos->final2 = head_procesos->frente->TASK; 
                                head_procesos->frente2->next = nodito;
                                head_procesos->frente->contador_procesos += 1;
                                pasarsiguiente++;
                                atender(&head_procesos, &tareas_atendidas);
                            }
                            else if(nodito !=NULL){
                                //nuevo nodo apunta al primer nodo
                                nodito->next= head_procesos->final2->next;
                                head_procesos->final2->next = nodito;
                                head_procesos->final2 = nodito;
                                head_procesos->frente->contador_procesos += 1;
                                pasarsiguiente++;
                                atender(&head_procesos, &tareas_atendidas);
                            } 
                            //si son 3 nodos por procesador, pasar al siguiente
                            if(pasarsiguiente==3){
                                head_procesos->frente = head_procesos->frente->next;
                                pasarsiguiente=0;
                                head_procesos->frente2=NULL;
                                head_procesos->final2=NULL;
                            }
                            else if(*tareas_total < 0){
                                 if(head_procesos->frente->TASK != NULL)
                                    atender(&head_procesos, &tareas_atendidas);
                                head_procesos->frente = head_procesos->frente->next;
                            }
                        }
                        else head_procesos->frente = head_procesos->frente->next;
                        
                    }
                    else if(head_procesos->frente->contador_procesos==3){
                        //si está lleno
                        atender(&head_procesos, &tareas_atendidas);
                        head_procesos->frente = head_procesos->frente->next;
                    }
                
            }

        /*__________________________ATENDER PROCESOS________________
            atiende a tooodas las tareas (decrementar el tiempo) que están ahí
            va eliminando las tareas terminadas y vuelve a asignar hasta que no queden tareas :)))

                       frente2 v    final2 v
            |TASK| -> >*|NODO1| -> |NODO2|*--
        */
            int atender(COLA_PROCESOS **head, int **tareas_atendidas){
            NODE *PID_ACTUAL = (*head)->frente->TASK;
            NODE *PID_PRIMERO= PID_ACTUAL;
            do{ //si hay tareas en el procesador vv
                if((*head)->frente->TASK != NULL){
                    
                    //decrementa el tiempo
                    PID_ACTUAL->t--;
                    //si por alguna razón el tiempo llega a cero, se borra de la existencia el nodo de tarea, claro que si ;)
                    if(PID_ACTUAL->t == 0){
                        //y para eso necesitamos un apuntador al nodo que vamos a eliminar
                        NODE **temp = &PID_ACTUAL;
                        (*head)->frente->TASK = PID_PRIMERO;
                        (*head)->final = (*head)->frente;
                        free(*temp); //se mata
                        **tareas_atendidas +=1;
                        (*head)->frente->contador_procesos--;
                        PID_ACTUAL = (*head)->frente->TASK;
                        PID_PRIMERO= PID_ACTUAL;
                        break;
                    }
                    else if((*head)->frente->contador_procesos ==3){
                        //si no es cero, pasa al otro procesador
                        (*head)->frente->TASK = (*head)->frente->TASK->next;
                    }
                }
                PID_ACTUAL = PID_ACTUAL->next;
            }while(PID_ACTUAL != PID_PRIMERO);

                return 0;
            }
            

int main(){
    //cola para procesos y cola para procesadores
    COLA_TAREAS cola = {NULL,NULL};
    COLA_PROCESOS cola_circular ={NULL,NULL}; //inicializa frente y final en NULL
    int op, tareas, PID, t=TIEMPO, tareas_atendidas=0, temptareas;
    procesadores(&cola_circular); //crea los 3 procesadores

    BOOL = FALSE; //no hay entradas de tarea
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            //asignar tareas vv
            case 1: BOOL = TRUE; //hay entrada para la cola de procesos
                    system("cls || clear");
                    printf("¿Cuantas tareas desea agregar a la cola de procesos?: \n>");
                    scanf(" %d", &tareas); //num de tareas agregadas a la cola de procesos
                    temptareas = tareas;
                    for(int i=0; i<=tareas-1; i++){
                        printf("\tAsigne PID #%d:\n>", i+1);
                        scanf("%d", &PID);
                        cola_tareas(&cola, PID); //crea cola de procesos dependiendo la cantidad de tareas
                    }
                    puts("LISTO! Ha creado su cola de procesos");
                    pause();
            break;
            //Procesar tareas
            case 2: if(!BOOL){
                     puts("ERROR, no hay ningun PID detectado");
                     pause();
                    }
                    else{   system("cls || clear");
                            for(int i=0; tareas_atendidas<=tareas; i++){
                                //desencola el nodo de la cola de procesos y lo encola al nodo de procesador hasta que se llene
                                llenar(&cola_circular, &cola, &tareas_atendidas, &temptareas); 
                            }             
                            puts("FINAOL");  
                            pause();  
                                   
                    }
            break;
            //about
            case 3: about();
                    pause();
            break; 

            default: puts("chaitoo ;)"); break;
            break;
        }
    }while(op);
    return 0;
}


//////////

void menu(){
    system("clear || cls");
    puts("--------------------------");
    printf("  Simulador de procesos\n");
    puts("--------------------------");
    puts("1. Asignar PID's");
    puts("2. Procesar tareas");
    puts("3. About");
    puts("0. Salir");
    printf("Opcion: \n>");
}
void pause(){
    puts("Pulse enter para regresar al menu");
    getchar();
    getchar();
}

void about(){
    system("clear || cls");
    puts("----------------------------------------");
    puts("       Estructura de datos");
    puts("     \"Simulador de procesos\"");
    puts("by Martha Denisse Lara Xocuis S22002213");
    puts("----------------------------------------");
    putchar('\n');

    puts("Marzo 9 de Abril del 2024");
    putchar('\n');
    putchar('\n');
}