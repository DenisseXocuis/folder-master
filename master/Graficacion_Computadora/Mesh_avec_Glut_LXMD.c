/* Mallado 2D con GL/glut =) */

/*  Proyecto Mallado2D con Grafo Dirigido 'Ponderado' usando GL/glut
 *  'Grafo de vertices'
 *  Lara Xocuis Martha Denisse. S22002213   
 *  Graficación por computadora
 *  15/09/24
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#define P 40

enum _bool{FALSE,TRUE}BOOL;

/* DEFINICIÓN DE ESTRUCTURAS BASE PARA LOS NODOS */
    typedef struct nodo_vertice
    {   
        int V;
        float x,y;
    }NODO_VERTICE;

    typedef struct lista_adyacencia
    {
        struct nodo_vertice *vertice;
        struct lista_adyacencia *next;
    }L_V;

    typedef struct grafo
    {
        struct nodo_vertice *vertice;
        struct lista_adyacencia *l_v;
        struct grafo *next;
        int T;
    }GRAFO;

    typedef struct lista_criterio
    {
        float d;
        int Vi,Vf;
        struct lista_criterio *next;
    }DISTANCIAS;

    GRAFO *grafo_head = NULL;
    int window = 0; //no hay ventana abierta

    /*__________CREACIÓN DE NODOS__________*/
    NODO_VERTICE *crear_vertices(float x, float y, int ID)
    {
        NODO_VERTICE *nodito = malloc(sizeof(NODO_VERTICE));
        if(!nodito) exit(1);
        nodito->V = ID;
        nodito->x=x;
        nodito->y=y;
        return nodito;
    }

    L_V *crear_arista(NODO_VERTICE *nodito)
    {
        L_V *new = malloc(sizeof(L_V));
        if(!new) exit(1);
        new->vertice=nodito;
        new->next=NULL;
        return new;
    }

    GRAFO *lista_adyacencia(NODO_VERTICE *nodito)
    {
        GRAFO *new = malloc(sizeof(GRAFO));
        if(!new) exit(1);
        new->vertice=nodito;
        new->l_v=NULL;
        new->next=NULL;
        new->T++;
        return new;
    }

    DISTANCIAS *lista_criterios(float d, int Vf, int Vi)
    {
        DISTANCIAS *nodito = malloc(sizeof(DISTANCIAS));
        if(!nodito) exit(1);
        nodito->d = d;
        nodito->Vf = Vf;
        nodito->Vi = Vi;
        nodito->next = NULL;
        return nodito;
    }

    /*__________CALCULAR DISTANCIA ENTRE DOS PUNTOS__________*/
    float calcular_distancia(NODO_VERTICE *V2 , NODO_VERTICE *V1)
    {
        float d = sqrt( pow((V2->x - V1->x), 2) + pow((V2->y - V1->y),2));
        return d;
    }
    
    /*__________INSERTAR EN LA LISTA 'PRINCIPAL' DE GRAFO__________*/
    void *crear_grafo(NODO_VERTICE *nodito, GRAFO **grafo_head, int ID)
    {
        GRAFO *new = lista_adyacencia(nodito),
              *aux;
        new->T= ID;
        new->next= *grafo_head;
        *grafo_head=new;
    }

    /*__________BUSCAR EN LISTA DE DISTANCIAS__________ */
    int buscar_distancia(DISTANCIAS **head, float d)
    {
        if(!(*head)) return 0;
        else if((*head)->d == d) return 1;
        return buscar_distancia(&(*head)->next, d);
    }

    /*__________CREAR LISTA DE DISTANCIAS__________*/
    void *generar_distancias(GRAFO **head_grafo, DISTANCIAS **head_distancias)
    {
        if((*head_grafo)->next == NULL) return NULL; 

        GRAFO *main = *head_grafo;
        while(main)
        {
            GRAFO *nxt = main->next;
            while(nxt)
            {
                float d = calcular_distancia(main->vertice, nxt->vertice);
                //si no encuentra una distancia igual en la lista
                if(!buscar_distancia(&(*head_distancias), d))
                {
                    DISTANCIAS *new = lista_criterios(d, main->T, nxt->T);
                    new->next = *head_distancias;
                    *head_distancias = new;
                }
                nxt = nxt->next;
            }
            main = main->next;
        }
    }

    /*__________ORDENAR LISTA DE DISTANCIAS__________*/
    void ordenar_lista(DISTANCIAS **head_distancias)
    {
        DISTANCIAS *i = *head_distancias, *j, *aux = malloc(sizeof(DISTANCIAS));
        while(i != NULL)
        {
            j = i->next;
            while(j != NULL)
            {
                if(i->d > j->d)
                {   //guardamos i en aux
                    aux->d = i->d;
                    aux->Vf = i->Vf;
                    aux->Vi = i->Vi;
                    //se pasa j a i
                    i->d = j->d;
                    i->Vf = j->Vf;
                    i->Vi = j->Vi;
                    //se pasa aux a j
                    j->d = aux->d;
                    j->Vf = aux->Vf;
                    j->Vi = aux->Vi;
                }
                j = j->next;
            }
            i = i->next;
        }

    }

    /*__________CÁLCULO DE PERCENTILES (GRADO DE APROXIMACIÓN DE FORMA 'DINÁMICA')__________*/
    float percentil(DISTANCIAS **head_distancias)
    {
        DISTANCIAS *aux; int i=1,j;
        //cuenta la cantidad de distancias que hay en la lista vv
        for(aux = *head_distancias; aux->next != NULL; aux = aux->next) i++;

        float Perc = (P * i)/100,
              valor1,valor2;

        /* saber si tiene punto flotante */
        double redondeov = floor(Perc);
        //si es diferente, tiene punto decimal
        if(Perc != redondeov)
        {
            int c1 = Perc, c2 = Perc + 1;
            //identificar las distancias de esas dos posiciones para el promedio
            for(j=1, aux = *head_distancias; j<c1; j++) aux = aux->next;
            valor1 = aux->d;
            for(j=1, aux = *head_distancias; j<c2; j++) aux = aux->next;
            valor2 = aux->d;

            return (valor1+valor2)/2;
        }
        else //si no es diferente, numero entero 
        {
            for(j=1, aux = *head_distancias; j<Perc; j++) aux = aux->next; 
            return aux->d;
        }
    }

    /*__________BUSCAR VÉRTICE EN EL GRAFO__________*/
    GRAFO *buscar_vertice(GRAFO **head, int ID )
    {
        if(!*head) return NULL;
        else if((*head)->vertice->V == ID) return *head;
        return buscar_vertice(&(*head)->next, ID);
    }

    /*__________INSERTAR VÉRTICE EN LA LISTA DE ARISTAS DE CADA VÉRTICE__________*/
    void insertar_arista(GRAFO **nodo, L_V *nodo_arista)
    {
        L_V *aux = (*nodo)->l_v;
        if((*nodo)->l_v)
        {
            while(aux)
            {
                if(aux->vertice == nodo_arista->vertice) return;
                aux = aux->next;
            }
            aux = (*nodo)->l_v;
            while(aux->next) aux = aux->next;
            aux->next = nodo_arista;
        }
        else
        {
            (*nodo)->l_v = nodo_arista;
        }
    }

    /*__________CHECAR CUALES CUMPLEN EL UMBRAL Y AGREGAR__________*/
    void vertice_adyacente(DISTANCIAS **head_distancias, float umbral, GRAFO **head_grafo)
    {
        DISTANCIAS *aux;  NODO_VERTICE *nodito;
        for(aux = *head_distancias; aux->next != NULL; aux = aux->next)
        {
            //¿cumple con el umbral predefinido?
            if(aux->d <= umbral)
            {
                //obtiene la posición de cada nodito :)
                GRAFO *noditoA = buscar_vertice(&(*head_grafo), aux->Vf),
                      *noditoB = buscar_vertice(&(*head_grafo), aux->Vi);
                L_V *Adyacencia_Node = crear_arista(noditoB->vertice),
                    *Adyacencia_Node2 = crear_arista(noditoA->vertice);

                insertar_arista(&noditoA, Adyacencia_Node);
                insertar_arista(&noditoB, Adyacencia_Node2);
            }
        }
    }
    
    /*__________CONTAR TRIANGULOS (SI HAY CONEXIÓN)__________*/
    int contar_triangulos(GRAFO **head) 
    {
        int tri = 0;
        GRAFO *main = *head;
        //si existe el vertice, buscar en los siguientes vertices quienes dan la "vuelta"
        while(main) //porque será el vertice "principal que recorrerá"
        {
            L_V *ady1 = main->l_v;

            while(ady1)
            {
                GRAFO *v1 = buscar_vertice(head, ady1->vertice->V);

                L_V *ady2 = v1->l_v;

                while(ady2){
                    if(ady2->vertice->V != main->vertice->V)
                    {
                        GRAFO *v2 = buscar_vertice(head, ady2->vertice->V);
                        L_V *ady3 = v2->l_v;
                        while(ady3)
                        {
                            if(ady3->vertice->V == main->vertice->V)
                            {
                                tri++;
                                break;
                            }
                            ady3 = ady3->next;
                        }
                    }
                    ady2 = ady2->next;
                }
                ady1 = ady1 ->next;
            }     
            main = main->next;
        }
        return tri/6;
    }

    void imprimir_grafo(GRAFO *grafo_head)
    {
        GRAFO *actuel = grafo_head;
        system("cls || clear");
        puts("~*============={            }===============*~");
        while(actuel)
        {
            printf("[v%d]: ", actuel->vertice->V, actuel->vertice->x, actuel->vertice->y);
            //imprimir la vista de adyacencia  [aristas] de ese nodo
            L_V *aristas = actuel->l_v;
            while(aristas)
            {
                printf(" v%d (%g,%g) ->", aristas->vertice->V, aristas->vertice->x, aristas->vertice->y);
                aristas = aristas->next;
            }
            printf("NULL\n");
            actuel = actuel->next; //avanzar
        }
        puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
    }
  
    /*__________DIBUJAR__________ */
    void draw()
    {   //limpiar el buffer de color y profundidad
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 1.0); //color azul :)
        glScalef(1.5, 1.5, 1.0); //modificar escala 

        //mostrar la unión de los vértices
        glBegin(GL_LINES);  //para lineas conectadas

            GRAFO *i = grafo_head;
            while(i)
            {
                L_V *j = i->l_v;
                while(j)
                {
                    glVertex2f(i->vertice->x, i->vertice->y);
                    glVertex2f(j->vertice->x, j->vertice->y); 
                    j = j->next;
                }
                i = i->next;
            }
        glEnd();

        glFlush();
    }

    void control_teclado(unsigned char key, int x, int y)
    {
        if(key == 13) //para el enter :)
        {
            glutDestroyWindow(glutGetWindow());
            window = 0; // Marcar que la ventana gráfica ya no está activa
        }
    }
    /*Menú interactivo ^^ */
    void menu(enum _bool BOOL)
    {   
        system("cls || clear");
        puts("╔═.✵.════════════════════════════════════════╗");
        puts("\t          -ˋˏ ༻✿༺ ˎˊ-");
        puts("\t       .Mallado2D v1.2.");
        if(!BOOL){//<- si NO hay entrada de vértices de antemano
            puts("⤷ [1]. Crear Vertices");
            puts("⤷ [5]. About");
            puts("⤷ [0]. Salir del programa");
            puts("╚════════════════════════════════════════.✵.═╝");
            printf("\tOpcion: \n>");
        } 
        else{  //no mostrar si no hay triángulos creados todavía  ;))
            puts("[1]. Crear mas vertices");
            puts("[2]. Triangulos Creados");
            puts("[3]. Ver adyacencias y coordenadas");
            puts("[4]. Mostrar graficamente");
            puts("[5]. About");
            puts("[0]. Salir del programa");
            //puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
            puts("╚════════════════════════════════════════.✵.═╝");
            printf("\tOpcion: \n>");
        }   
    }

    void pause()
    {
        puts("Pulse ENTER para regresar al menu");
        getchar();
        getchar();
    }

    void about()
    {
        system("cls || clear");
        puts("╔═.✵.════════════════════════════════════════╗");
        puts("\t          -ˋˏ ༻✿༺ ˎˊ-");
        puts("\t       .Mallado2D v1.2.");
        puts("\t© Lara Xocuis Martha Denisse ®");
        puts("\t       █║▌│█│║▌║││█║▌║▌║");
        puts("          Ingenieria en Informatica");
        puts("\t\"Graficacion por Computadora\"");
        puts("╚════════════════════════════════════════.✵.═╝");
    }

    void warning()
    {
        puts("\n[W A R N I N G]\nNo se pueden generar triangulos ya que NO hay vertices suficientes");
        puts("CONSEJO: Agregar otros vertices :)\n");   
    }

int main(int argc, char **argv)
{   
    DISTANCIAS *distancias_head = NULL;
    int op, vertices, ID = 0, T = 0, j = 0;
    float x,y, c;
    BOOL = FALSE;
    glutInit(&argc, argv);
    do
    {
        do
        {   menu(BOOL);
            scanf("%d", &op);
        }while(op != 1 && op != 2 && op != 3 && op != 4 && op !=5 && op != 0);

        switch(op)
        {     
            case 1:
                system("cls || clear");
                puts("~*============={            }===============*~");
                printf("       ¿Cuantos vertices desea crear?\n>");
                scanf("%d", &vertices);

                for(int i=0; i<vertices; i++, j++)
                {   system("cls || clear");
                    puts("~*==============={            }=================*~");
                    printf("Ingrese las coordenadas (x,y) para su Vertice %d\n", j+1);
                    printf("x = "); scanf("%f", &x);
                    printf("y = "); scanf("%f", &y);
                    //agregar todos los vertices en la lista para el grafo 
                    NODO_VERTICE *node = crear_vertices(x,y, ++ID);
                    crear_grafo(node, &grafo_head, ++T);
                }
                puts("Todos los vertices han sido agregados en el plano de forma exitosa!");
                //verificar_t(&grafo_head, T);
                if(T>=3) BOOL = TRUE;
                else warning();
                //crear lista de distancias, después lo ordena  y crea umbral
                generar_distancias(&grafo_head, &distancias_head);
                if(BOOL) //<- si existe entrada exitosa de coordenadas sin warning
                {
                    ordenar_lista(&distancias_head);
                    //float c = criterio(&distancias_head); //mediana
                    c = percentil(&distancias_head);
                    /* checar cuales vértices son los que son <= que el criterio,
                    agregarlos a lista de vertices y crear lista de adyacencia */
                    vertice_adyacente(&distancias_head, c, &grafo_head);
                }
                pause();
                break;
            case 2: //checar aristas del grafo para revisar si hay triángulos
                    system("cls || clear");
                    puts("~*============={            }===============*~");
                    printf("HAY %d TRIANGULO(S)\n", contar_triangulos(&grafo_head));
                    puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
                    pause();
                break;
            case 3: imprimir_grafo(grafo_head);
                    pause();
                break;

            case 4: 
                    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

                    glutInitWindowSize(800, 600); 

                    glutInitWindowPosition(100,100);

                    glutCreateWindow("mes triangles");

                    glClearColor(1.0, 1.0, 1.0, 1.0);

                    gluOrtho2D(0.0, 15.0, 0.0, 15.0); // rango coordenadas visible

                    glutDisplayFunc(draw);
                    window = 1;
                    glutKeyboardFunc(control_teclado);
                    while(window)
                    {
                        glutMainLoopEvent();
                    }

                    //glutMainLoop();
                    
                break;
            case 5: about();
                    pause();
                break;
            default: puts("Saliendo del programa...");
        }
    }while(op);

    return 0;
}