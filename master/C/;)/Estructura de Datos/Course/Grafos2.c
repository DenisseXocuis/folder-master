#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <strings.h>

#define ABOUT "/-----------------------------\\\n" \
              "| Dummy:                      |\n" \
              "|                             |\n" \
              "| Martinez Schleske Alan      |\n" \
              "| Ingenieria en Informatica   |\n" \
              "| Universidad Veracruzana (c) |\n" \
              "|                             |\n" \
              "| (.2024)                     |\n" \
              "\\-----------------------------/\n" \
              "  /                            \n" \
              " /                             \n"

#define RESERVAR_TIPO(tipo) \
    struct _##tipo *nuevo = NULL; \
    if (!(nuevo = malloc(sizeof(*nuevo)))) \
    {\
        fprintf(stderr, "ERROR: espacio no disponible\n");\
        exit(1);\
    }

#define UNIR_NODO(gr, src, dest, peso) \
    do {\
        Grafo busc = NULL;\
        busc = buscarNodo((gr), (src));\
        unirNodos(&busc->vecinos, (gr), (peso), (dest));\
    } while (0)

#define FNULL {NULL, 0}

struct _Vertice
{
    int    num_ocurr;
    char   *palabra;
    double prob;
    struct _Arista *vecinos;
    struct _Vertice *sig;
};

struct _Arista
{
    double costo;
    int num_inter;
    struct _Vertice *nodo;
    struct _Arista *sig;
};

typedef struct
{
    FILE *md;
    char nombre[128];
    int total_pal;
} Archivo;

typedef struct _Vertice * Grafo;
typedef struct _Arista  * Arista;

int total_pal = 0;

// Startup of C program and credits to the programmer
void __attribute__((constructor)) init(void) {
    system("clear||cls");
    printf(ABOUT
           "( Presione Enter para empezar...");
    while (getchar() != '\n');
}

void menu(Grafo);
void opciones(Grafo *gr, Archivo *arch, int op);
int continuar(void);
int leerTexto(Grafo *, Archivo *);
int unirTexto(Grafo *gr, Archivo *arch);
double bayesiano(Grafo *, Grafo);

Grafo aniadirNodo(char *pal, Grafo *);
Grafo buscarNodo(Grafo, char *pal);
Grafo *buscarNodoPorArista(Arista, char *pal);
Arista unirNodos(Arista *ar, Grafo busq, int peso, char *dest);
void imprimirGrafo(Grafo);
void imprimirPesos(Grafo);

int
main(void)
{
    Archivo texto = FNULL;
    Grafo gr = NULL;

    do
    {
        int op;
        printf("%s\n",
                gr ? "Predictor listo" : "Cargue un archivo");
        printf("--------------------------\n\n");
        
        printf("[1] Agregar texto\n");
        if (gr)
        {
            printf("[2] Predecir frase\n"
                   "[3] Mostrar palabras\n"
                   "[4] Mostrar conexiones\n"
                   "[5] Buscar frase mas comun\n");
        }
        printf("[0] Salir\n\n> ");
        scanf(" %d", &op);
        opciones(&gr, &texto, op);
    } while (1);

    return 0;
}

void
menu(Grafo gr)
{
    system("cls || clear");
    printf("%s\n",
            gr ? "Predictor listo" : "Cargue un archivo");
    printf("--------------------------\n\n");

    printf("[1] Agregar texto\n");
    if (gr)
    {
        printf("[2] Predecir frase\n"
               "[3] Mostrar palabras\n"
               "[4] Mostrar conexiones\n"
               "[5] Buscar frase mas comun\n");
    }
    printf("[0] Salir\n\n> ");
}

void
opciones(Grafo *gr, Archivo *arch, int op)
{
    switch (op)
    {
        char buff[128];
        case 1:
            printf(" Ingrese nombre del texto: ");
            scanf(" %[^\n]", buff);

            strcpy(arch->nombre, buff);

            leerTexto(gr, arch);
            unirTexto(gr, arch);
            break;
        case 2:
            printf("Ingrese dos o mas palabras: ");
            scanf(" %[^\n]", buff);

            // predecir()
            break;
        case 3:
            imprimirGrafo(*gr);
            putchar('\n');
            break;
        case 4:
            imprimirPesos(*gr);
            putchar('\n');
            break;
        case 5:
            printf("Ingrese una palabra: ");
            scanf(" %[^\n]", buff);

            // frases_comunes()
            break;
        case 0:
            exit(0);
    }
}

int
continuar(void)
{
    int op;

    printf("Desea continuar? (1: Si | 0: No) ");
    scanf(" %d", &op);

    while (getchar() != '\n');
    return op;
}

int
leerTexto(Grafo *gr, Archivo *arch)
{
    if (!arch->md)
    {
        if (!(arch->md = fopen(arch->nombre, "r+")))
        {
            fprintf(stderr, "ERROR: %s no se pudo abrir\n", arch->nombre);
            return 0;
        }
    }

    char buff[2048];
    fgets(buff, 2048, arch->md);

    if (*buff == '\0' || *buff == '\n' || *buff == '.' || *buff == ',')
    {
        return leerTexto(gr, arch);
    }

    char *palabra = strtok(buff, " ,.");
    while (palabra)
    {
        aniadirNodo(palabra, gr);
        arch->total_pal++;

        if (strchr(palabra, '@'))
        {
            return 1;
        }

        palabra = strtok(NULL, " ,.\n");
    }

    leerTexto(gr, arch);
    if (arch->md)
    {
        fclose(arch->md);
        arch->md = NULL;
    }

    return 1;
}

int
unirTexto(Grafo *gr, Archivo *arch)
{
    if (!arch->md)
    {
        if (!(arch->md = fopen(arch->nombre, "r+")))
        {
            fprintf(stderr, "ERROR: %s no se pudo abrir\n", arch->nombre);
            return 0;
        }
    }

    char buff[2048];
    fgets(buff, 2048, arch->md);

    if (*buff == '\n')
    {
        return unirTexto(gr, arch);
    }

    char *pal1 = strtok(buff, " ,."),
         *pal2 = strtok(NULL, " ,.");
    while (*buff)
    {
        Grafo busc1 = buscarNodo(*gr, pal1),
              busc2 = buscarNodo(*gr, pal2);

        if (busc1 && busc2)
        {
            UNIR_NODO(*gr, pal1, pal2, 0);

            if (strchr(pal2, '@'))
            {
                return 1;
            }

            pal1 = pal2;
            pal2 = strtok(NULL, " ,.");

            continue;
        }

        break;
    }

    if (*buff != '\0')
    {
        unirTexto(gr, arch);
    }

    if (arch->md)
    {
        fclose(arch->md);
        arch->md = NULL;
    }
    
    return 1;
}

double
bayesiano(Grafo *pal1, Grafo pal2)
{
    if (buscarNodoPorArista((*pal1)->vecinos, pal2->palabra))
    {
        (*pal1)->vecinos->num_inter++;
        return 0.0;
    }

    return (double) (*pal1)->vecinos->num_inter / ((double) total_pal / 2);
}

void
imprimirGrafo(Grafo gr)
{
    if (!gr) return;

    printf("%s -> ", gr->palabra);
    for (Arista i = gr->vecinos; i != NULL; i = i->sig)
    {
        printf("%s (%g%%)-> ", i->nodo->palabra, i->nodo->prob);
    }
    printf("NULL\n");

    imprimirGrafo(gr->sig);
}

void
imprimirPesos(Grafo gr)
{
    if (!gr) return;

    printf("0 -> ");
    for (Arista i = gr->vecinos; i != NULL; i = i->sig)
    {
        printf("%g -> ", i->costo);
    }
    printf("NULL\n");

    imprimirPesos(gr->sig);
}

Grafo
aniadirNodo(char *pal, Grafo *gr)
{
    if (*gr)
    {
        Grafo busc = buscarNodo(*gr, pal);
        if (!strcasecmp(busc ? busc->palabra : "", pal))
        {
            busc->num_ocurr++;
            busc->prob = (double) busc->num_ocurr / total_pal;
            return NULL;
        }
        (*gr)->sig = aniadirNodo(pal, &(*gr)->sig);

        return *gr;
    }


    RESERVAR_TIPO(Vertice);

    nuevo->num_ocurr = nuevo->prob = 0;
    nuevo->vecinos = NULL;
    nuevo->palabra = pal;
    nuevo->sig = *gr;
    *gr = nuevo;
    total_pal++;

    return *gr;
}

Grafo
*buscarNodoPorArista(Arista ar, char *pal)
{
    if (!ar || !pal) return NULL;

    return !strcasecmp(ar->nodo->palabra, pal) ? &ar->nodo : buscarNodoPorArista(ar->sig, pal); 
}

Grafo
buscarNodo(Grafo gr, char *pal)
{
    if (!gr || !pal) return NULL;

    return !strcasecmp(gr->palabra, pal) ? gr : buscarNodo(gr->sig, pal);
}

Arista
unirNodos(Arista *ar, Grafo busq, int peso, char *dest)
{
    if (*ar)
    {
        if (*dest == '\0')
        {
            return NULL;
        }
        (*ar)->sig = unirNodos(&(*ar)->sig, busq, peso, dest);

        return *ar;
    }

    RESERVAR_TIPO(Arista);

    nuevo->nodo = buscarNodo(busq, dest);
    nuevo->costo = peso;
    nuevo->sig = *ar;
    *ar = nuevo;
    (*ar)->num_inter++;

    return *ar;
}
