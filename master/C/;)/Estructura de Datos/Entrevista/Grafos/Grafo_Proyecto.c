/*  Proyecto Parcial 2: EL PREDICTOR
 *  'Grafo dirigido ponderado de palabras de un texto'
 *  Lara Xocuis Martha Denisse. S22002213   
 *  Estructura de Datos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Prob_Ocurrencia(d,m) ((float)d/m)
enum _bool{FALSE,TRUE}BOOL;

/* Estructura Básica del Nodo */
    typedef struct node
    {   char *mot;
        float PA; //probabilidad de ocurrencia
    }NODE;

/*____Estructura Básica de Lista de Adyacencia____*/
    typedef struct lista_adyacencia
    {   struct node *nodito;
        float peso; //por teorema de bayes
        struct lista_adyacencia *next;
        int visitado;
    }ADYACENCIA;

/*____Estructura Base de Lista de Vértices____*/
    typedef struct graf
    {   struct node *nodito;
        struct graf *next;
        struct lista_adyacencia *adyacencia;
    }GRAFO;

        /* Prototipos */
    NODE *crear_nodo(char *, int, int);
    GRAFO *nodo_grafo(NODE *);
    char *leer_archivo(const char *, char*);
    int conteo_palabras(const char *);
    char *copiar(const char *);
    char *signos(char *);
    char *minusculas(char *);
    int frecuencia(char *, const char*);
    int buscar_palabra(GRAFO **, char *);
    void quitar_salto_linea(char *);
    int adyacencia_list(GRAFO **, char *, const char *, int);
    void *ocurrencia_conjunta(GRAFO **, char *, int, char *);
    void *lista_vertices(GRAFO **, int, char*, char*);
    void menu(enum _bool);
    void pause();
    void imprimir_nodos(GRAFO **, int);
    void imprimir_aristas(GRAFO **, int );
    void about();

    /*__________CREACIÓN DE NODOS__________*/
    NODE *crear_nodo(char *mot, int d, int m)
    {   NODE *new = malloc(sizeof(NODE));
        if(!new) exit(1);
        new->mot = mot;
        new->PA = Prob_Ocurrencia(d,m);
        return new;
    }

    GRAFO *nodo_grafo(NODE *nodito)
    {   GRAFO *new = malloc(sizeof(GRAFO));
        if(!new) exit(1);
        new->nodito = nodito;
        new->adyacencia = NULL;
        new->next = NULL;
        return new;
    }

    ADYACENCIA *nodo_arista(NODE *nodito, float bayes)
    {   ADYACENCIA *new = malloc(sizeof(ADYACENCIA));
        if(!new) exit(1);
        new->nodito = nodito;
        new -> peso = bayes;
        new-> next = NULL;
        new->visitado=0;
        return new;
    }

   /*__________LEER ARCHIVO__________*/
    char *leer_archivo(const char *name, char *contenido)
    {   FILE *archivo;
        archivo = fopen(name, "r");
        long size;
        if(archivo)
        {   BOOL = TRUE; //<- existe entrada de archivo
            fseek(archivo, 0, SEEK_END); //<- mueve *archivo hasta el final
            size = ftell(archivo);
            rewind(archivo);
            contenido = malloc(size + 1);
            if(!contenido)
            {
                puts("Oops!, NO hay memoria pal archivo, ni modo");
                fclose(archivo);
                return NULL;
            }

            unsigned long Bytes = fread(contenido,1,size,archivo);
            contenido[size+1] = '\0';
            puts("El archivo ha sido encontrado!");
            return contenido;
        }
        else
        {
            puts("No se encontro =(");
            return NULL;
        }
    }

    /*__________CONTAR TODAS LAS PALABRAS__________*/
    int conteo_palabras(const char *texto)
    {   int cantidad = 0;
        while(*texto)
        {
            if(*texto == ' ' || *texto == '.' || *texto == ':' || *texto == ';') cantidad++;
            texto++;
        }
        return cantidad;
    }

    char *copiar(const char *texto)
    {
        unsigned long size = strlen(texto)+1;
        char *dest = malloc(size);
        if(!size)
        {
            puts("OOPS, no hay memory. Ni modo =(");
            return NULL;
        }
        strcpy(dest, texto);
        return dest;
    }

    /*__________ELIMINAR SIGNOS DE UNA PALABRA__________*/
    char *signos(char *palabra)
    {   int size = strlen(palabra);
        char ult_letra = palabra[size-1];
        if(ult_letra == '.' || ult_letra == ':' || ult_letra == ';' || ult_letra == ',')
        palabra[size - 1] = '\0';
        return palabra;
    }

    /*__________CONVERTIR PALABRA A MINUSCULAS__________*/
    char *minusculas(char *palabra)
    {
        if(*palabra){
            if (*palabra >= 'A' && *palabra <= 'Z'){
                *palabra = *palabra + ('a' - 'A');
            }
            minusculas(palabra + 1); // Llamada recursiva para el siguiente carácter
        }
        return palabra;
    }

    /*__________CALCULAR LA FRECUENCIA DE UNA PALABRA__________*/
    int frecuencia(char *palabra, const char  *texto)
    {   int cantidad = 0, size; 
        while(texto)
        {   char *mot = copiar(texto);

            strtok(mot, " "); //<- extrae la palabra
            strtok(mot, "\n"); //<- quita salto de linea
            signos(mot); //quitará los signos si tiene
            texto = strchr(texto, ' ');
            if(texto) texto++; //avanza el texto
            palabra = minusculas(palabra);
            mot = minusculas(mot);
            if(!strcmp(mot,palabra)) cantidad++;
        }
        return cantidad;

    }
    
    /*__________BUSCAR PALABRA EN LA LISTA DE VERTICES__________*/
    int buscar_palabra(GRAFO **lista, char *mot)
    {   if(!*lista) return 0; //no hay lista
        //la encontró
        else if(!strcmp((*lista)->nodito->mot, mot))
            return 1;
        else if((*lista)->next)
            buscar_palabra(&(*lista)->next, mot);
        else return 0; //no la encontró
    }

    int buscaren_ady(ADYACENCIA **lista, char *mot)
    {   if(!*lista) return 0; //no hay lista de ady
        else if(!strcmp((*lista)->nodito->mot,mot)) return 1;
        else if((*lista)->next)
            buscaren_ady(&(*lista)->next,mot);
        else return 0;
    }

    /* Para quitar salto de linea*/
    void quitar_salto_linea(char *texto)
    {   int size = strlen(texto);
        static int i = 0;
        i++;
        if(texto[i] == '\n') texto[i] = ' ';
        if(i == size)
        {
            texto[++i] = '\0';
            return;
        }
        quitar_salto_linea(texto);
    }

    /*__________CALCULAR LA INTERSECCIÓN AnB__________*/
    int interseccion(char *A, char *B, char* texto)
    {   
        char  *actuel = copiar(texto),
              *prev = actuel; int n =0;
        while(texto)
        {
            strtok(actuel, " ");
            strtok(actuel, "\n");
            signos(actuel);
            actuel = minusculas(actuel);
            //cuenta las veces que B sigue tras de A
            int a = strcmp(actuel,B),
                b = strcmp(prev,A);
            if(!a && !b) n++;
            texto = strchr(texto, ' ');
            if(texto)
            {
                while(*texto == ' ') texto++;
            }
            prev = actuel;
            if(texto) actuel = copiar(texto);
        }
        return n;
    }

    //busca nodo en toda la lista y retorna su posición
    GRAFO **buscar_nodo(GRAFO **lista, char *palabra)
    {   if(!*lista) return NULL;
        else if(!strcmp((*lista)->nodito->mot, palabra)) return *lista;
        return buscar_nodo(&(*lista)->next, palabra);
    }

    /*__________PALABRA QUE SIGUE A OTRA PALABRA__________*/
    int adyacencia_list(GRAFO **grafo, char *mot , const char *texto, int m)
    {        
        char *prev = NULL, *mot_actuel = copiar(texto),
             *respal2 = copiar(texto);
        double AnB = 0;
        while(*texto)
        {   //extrae cada palabra del texto y compara con la palabra a buscar
            strtok(mot_actuel, " ");
            strtok(mot_actuel, "\n");
            signos(mot_actuel);
            mot_actuel = minusculas(mot_actuel);
            if(!prev || strcmp(mot_actuel,mot))
            {
                texto = strchr(texto, ' ');
                if(texto)
                {
                    while(*texto == ' ') texto++;
                }
                if(!texto) break;
                prev = mot_actuel;
                mot_actuel = copiar(texto);
            }
            else
            {
                //buscar y retornar el apuntador de la lista de vertices donde esté prev para ahí insertar mot en la lista de adyacencia
                AnB = interseccion(prev, mot_actuel, respal2);

                //retorna el puntero del prev
                GRAFO *noditoA = buscar_nodo(&*grafo, prev), 
                     *noditoB = buscar_nodo(&*grafo, mot_actuel);

                if(!buscaren_ady(&noditoA->adyacencia, mot_actuel))
                { //si no está, la inserta
                    /* BAYES... */
                    double PAnB = Prob_Ocurrencia(AnB, m),
                        PB_A = Prob_Ocurrencia(PAnB, noditoA->nodito->PA),
                        Bayes = (PB_A * noditoA->nodito->PA) / noditoB->nodito->PA;

                    ADYACENCIA *nodito2 = nodo_arista(noditoB->nodito, Bayes),
                        *piv = noditoA->adyacencia;

                    //insertar nodo en la lista de adyacencia de ese nodo
                    if(noditoA->adyacencia)
                    {   
                        while(piv->next)
                            piv = piv->next;
                        piv -> next = nodito2; 
                    }
                    else
                    {
                        noditoA->adyacencia = nodito2;
                    }

                    //mot actuel será la palabra que se va a insertar en la lista de la palabra prev
                    //insertar función de node 
                }
                //avanza el texto
                texto = strchr(texto, ' ');
                if(texto)
                {
                    /* while(*texto == ' ' || *texto == '<' || *texto == '>' || *texto == '(' || *texto == ')' || *texto == '!' || *texto == '¡' || *texto == '?' || *texto == '¿') texto++; */

                    while(*texto == ' ') texto++;
                }
                if(!texto) break;
                prev = mot_actuel;
                mot_actuel = copiar(texto);
            }
        }
    }
   

    /*__________CREAR LISTA DE ADYACENCIA__________*/
    void *ocurrencia_conjunta(GRAFO **grafo, char *texto, int m, char *texto_original)
    {   //extrae la palabra
        while(texto)
        {
            char *mot = copiar(texto);
            strtok(mot, " ");
            strtok(mot, "\n");
            signos(mot);
            mot = minusculas(mot);
            adyacencia_list(&*grafo, mot, texto_original, m);

            texto = strchr(texto, ' ');
            if(texto)
            {
                while(*texto == ' ') texto++;
            }
        }
    }

    /*__________CREAR LISTA DE VERTICES__________*/
    void *lista_vertices(GRAFO **grafo,int m, char *texto, char *respaldo)
    {  char *respal2 = copiar(respaldo);
        while(respaldo)
        {   GRAFO *nodito2, *piv = *grafo;
            //extraer la palabra 
            char *mot = copiar(respaldo);
            strtok(mot, " ");
            strtok(mot, "\n");
            signos(mot);
            minusculas(mot);
            //quitar la palabra extraida del respaldo
            
            respaldo = strchr(respaldo, ' ');
            if(respaldo)
            {
                /* while(*respaldo == ' ' || *respaldo == '<' || *respaldo == '>' || *respaldo == '(' || *respaldo == ')' || *respaldo == '!' || *respaldo == '¡' || *respaldo == '?' || *respaldo == '¿') respaldo++; */
                while(*respaldo == ' ') respaldo++;
            }
            
            //si no existe la palabra, agregarla
            if(!buscar_palabra(&*grafo, mot))
            {
                //calcular la frecuencia de todo el texto

                int d = frecuencia(mot, respal2);
                //datos para el nodo
                NODE *nodito = crear_nodo(mot,d,m);
                //nodito del grafo
                nodito2 = nodo_grafo(nodito);

                //insertar nodo en lista de vertices
                if(*grafo)
                {
                    while(piv->next)
                        piv = piv->next;    

                    piv->next = nodito2;
                }
                else //si no hay lista
                {  
                    *grafo = nodito2;
                }

            }
        }
    }


void imprimir_nodos(GRAFO **grafo, int m)
{   system("cls || clear");
    puts("~*============={            }===============*~");
    puts("\t        Nodos y Valores:");
    printf("Total de palabras: %d\n", m);
    GRAFO *aux = *grafo;
    for(; aux; aux = aux->next)
    {
        if(!strcmp(aux->nodito->mot, "\0")) break;
        printf("  [%s]|\tP(A) = %.4f%\n", aux->nodito->mot, aux->nodito->PA);
    }
    puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
}

void imprimir_aristas(GRAFO **grafo, int m)
{   system("cls || clear");
    puts("~*============={            }===============*~");
    puts("\t        Aristas y Pesos:");
    printf("Total de palabras: %d\n", m);
    GRAFO *aux = *grafo; ADYACENCIA *aux2;
    for(; aux; aux = aux->next)
    {
        if(!strcmp(aux->nodito->mot, "\0")) break;
        printf(" [%s] v \n ", aux->nodito->mot);
        for(aux2 = aux->adyacencia; aux2 ; aux2 = aux2->next)
        {
            if(!strcmp(aux2->nodito->mot, "\0")) break;
            printf("%s [%.4f]", aux2->nodito->mot, aux2->peso);
        }
        printf(" -> NULL \n");
    }
    puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
}

char *palabra_final(char *frase)
{   char  *actuel = copiar(frase),
              *prev = actuel; int n =0;
        while(frase)
        {
            strtok(actuel, " ");
            strtok(actuel, "\n");
            signos(actuel);
            actuel = minusculas(actuel);
            

            frase = strchr(frase, ' ');
            if(frase)
            {
                while(*frase == ' ') frase++;
            }
            prev = actuel;
            if(frase) actuel = copiar(frase);
        }
        return prev;

}

char *predecir(GRAFO **nodo)
{    ADYACENCIA *aux = (*nodo)->adyacencia;
    char *menor_word = aux->nodito->mot;
   float mayor = aux->peso, menor = aux->peso;
    while(aux)
    {   if(aux->visitado)
        {
            if(aux->next) aux = aux  ->next;
            return NULL;
        }
        else if(aux->peso > mayor)
        {   menor_word = aux->nodito->mot;
            mayor = aux->peso;
        }
        else if(aux->peso < menor)
        {
            menor = aux->peso;
            menor_word = aux->nodito->mot;
        }
        if(aux->next)aux = aux->next;
        else break;
    }
    aux->visitado= 1;

    return menor_word;
}

void menu(enum _bool BOOL)
{   
    system("cls || clear");
    puts("~*============={            }===============*~");
    puts("\t   ¡BIENVENID@ AL PREDICTOR!");
    if(!BOOL){ //<- si NO hay indicación de entrada de un archivo válido
        puts("[1]. Subir archivo");
        puts("[6]. About");
        puts("[0]. Salir del programa");
        puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
        printf("\tOpcion: \n>");
    } 
    else{ 
        puts("[1]. Subir otro archivo");
        puts("[2]. Nodos y Valores");
        puts("[3]. Aristas y Pesos");
        puts("[4]. Frases mas comunes");
        puts("[5]. ///////Borrar Grafo");
        //como siempre no me da tiempo de implementar la eliminación =')
        puts("[6]. About");
        puts("[0]. Salir del programa");
        puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
        printf("\tOpcion: \n>");
    }
}

void pause()
{
    puts("Pulse ENTER para regresar al menu");
    getchar();
    getchar();
}

void about(){
    system("cls || clear");
    puts("~*============={            }===============*~");
    puts("\t\tPredictor v0.1");
    puts("\t\t     by:");
    puts("    ©Lara Xocuis Martha Denisse. S22002213");
    puts("          Ingenieria en Informatica");
    puts("\t    \"Estructura de Datos\"");
    puts("~*==========================================*~");

}

int main()
{   GRAFO *def = NULL;
    BOOL = FALSE; int op, m; char name[50], frase[128], *respaldo;
    do
    {
        do
        {   menu(BOOL);
            scanf("%d", &op);
        } while (BOOL == FALSE && op != 1 && op !=  6 && op != 0);

        switch(op)
        {
            case 1: system("cls || clear");
                    printf("Escriba el nombre del archivo\n>");
                    scanf("%s", name);
                    //hace una copia de todo el archivo para poder manipularlo mejor como un char *
                    char *contenido_archivo = leer_archivo(name, contenido_archivo);
                    
                    if(contenido_archivo)
                    {
                        //hace un conteo de todas las palabras
                        m = conteo_palabras(contenido_archivo);

                        //crea un respaldo del texto
                        respaldo = copiar(contenido_archivo);
                        quitar_salto_linea(respaldo);

                        //crea una lista de vertices
                        lista_vertices(&def, m, contenido_archivo, respaldo);

                        //crea una lista de adyacencia dependiendo la lista de vertices
                        /* encontrar un prev a cada palabra del texto

                        contar todas las ocurrencias de ese prev y palabra actual

                        meter palbra actual en la lista de vertices donde está el nodo prev

                        calcular teorema de bayes para ese peso
                        
                        */

                        ocurrencia_conjunta(&def, respaldo, m, contenido_archivo); 
                    }
                    pause(); 
            break;
            case 2: 
            
            imprimir_nodos(&def, m);
            pause(); 
            break;

            case 3:
            imprimir_aristas(&def,m);
            pause();
            break;

            case 4:
            system("cls || clear");
            puts("~*============={            }===============*~");
            printf("Ingresa una frase: \n>");
            scanf(" %[^\n]", frase);
            char *sentence = copiar(frase);
            char *palabra = palabra_final(sentence);
            //dirección del nodo donde está la palabra
            printf("%s ", sentence);
            while(palabra){
                GRAFO *nodito_inicio = buscar_nodo(&def, palabra);
                palabra = predecir(&nodito_inicio);
                if(palabra == NULL) break;
                printf("%s ", palabra);
            }
            putchar('\n');
            pause();
            break;
            case 6:
            about();
            pause();

            break;

            default:
            puts("Saliendo...");
        }
    }while(op);
    
    return 0;
}