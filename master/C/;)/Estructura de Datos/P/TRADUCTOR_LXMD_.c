/* TRADUCTOR DE XML A JSON Y VICEVERSA
    Lara Xocuis Martha Denisse S22002213
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#define T 256
// variable de control para entrada de archivo
enum _bool{FALSE, TRUE}BOOL; 
void loading();
void menu();
void pause();
void about();
/* ______________COLA DE COLAS_______________ */
//ESTRUCTURA BASE DE CONTENIDO DE TAG
    typedef struct atributo_tag
    {   char *Tag_atributo; //contenido del tag
        char *info;
        int HayAtributoTAG;
        struct atributo_tag *atributo;
    }ATRIBUTO;

//ESTRUCTURA BASE DE COLA DE TAGS
    typedef struct nodocola_tags
    {   ATRIBUTO *Atributo;
        char *NombreTAG;
        struct nodocola_tags *next;
    }NODO_TAG;

//APUNTADORES PARA LAS DOS COLAS
    typedef struct colas{
        struct nodocola_tags *frente;
        struct nodocola_tags *final;
        struct atributo_tag *frente2;
        struct atributo_tag *final2;
    }HEAD;

/*_________CREACIÓN DE NODO_______ */
    NODO_TAG *nodo(const char *cadena)
    {   NODO_TAG *nuevo_nodo = (NODO_TAG *) malloc(sizeof(NODO_TAG));
        if(!nuevo_nodo)
        {
            puts("ERROR! No hay memoria T_T");
            exit(1);
        }
        nuevo_nodo->Atributo = NULL;
        nuevo_nodo->NombreTAG= cadena;
        nuevo_nodo->next = NULL;
        return nuevo_nodo;
    }

    ATRIBUTO **nodo_atributo(const char *cadena, const char *contenido){
        ATRIBUTO *nuevo_nodo = (ATRIBUTO*) malloc(sizeof(ATRIBUTO));
        if(!nuevo_nodo)
        {
            puts("ERROR! No hay memoria :(");
            exit(1);
        }
        if(cadena == NULL){
            nuevo_nodo->info = contenido;
            nuevo_nodo->atributo=NULL;
        }
        else{
            nuevo_nodo->Tag_atributo=cadena;
            nuevo_nodo->info = contenido;
            nuevo_nodo->atributo=NULL;
        }
        return nuevo_nodo;
    }

//CREAR LA COLA DE COLAS
    void insertar_cola(char **contenido_archivo, HEAD *head)
    {   int EsContenidoElemento = 0; //control de entrada de atributo para el elemento
      while(**contenido_archivo)
        {  
        char *apt_linea, *aux, *Tag_Con_Espacio, *atributo_tag, copia_linea[256], *lineas;
        lineas = copia_cadena(*contenido_archivo);
        strtok(lineas, "\n"); //<- extrae linea del archivo
        /* if(){

        } */

        /*tuve muchos errores con strcpy por la asignación de memoria
            so, hice mi propia función de copiado */
        apt_linea = copia_cadena(lineas);
        /* ____Atributo de TAG___ */
        if (*apt_linea == ' ') //<- hay un elemento del TAG porque detecta un espacio
        {
            apt_linea += 2; //<- skipea el espacio del tab
            EsContenidoElemento = 1; //<- indica que es contenido del TAG y NO atributo. Es decir, se meterá en COLA PRINCIPAL 
        }
        /* _______TAG______ */
        if(*apt_linea == '<') //<-- checa si existe un <TAG>
            {  
            aux = copia_cadena(apt_linea);

            strtok(++aux, ">"); //<-- extrae todo el TAG <.....>
            // solo va a servir para verificar si hay un espacio O NO
            Tag_Con_Espacio = copia_cadena(aux);
            Tag_Con_Espacio = strchr(Tag_Con_Espacio, ' ');
            if(Tag_Con_Espacio == NULL) //<-- si hay un espacio entre <...>
            {
                NODO_TAG *nodito = nodo(aux);
                //INSERTAR TAG EN COLA PRINCIPAL
                if((head)->frente == NULL){  //<- inserta raiz en primer nodo
                    //inicializando cola principal de jerarquía
                    (head)->frente = nodito;
                    (head)->final = nodito; 
                }
                else{ 
                    (head)->final->next = nodito;
                    (head)->final= nodito;    
                }
                //mover apt_linea hasta el contenido del tag para identificar si es una raiz o es un elemento
                do{
                    apt_linea++;
                }while(*apt_linea != '>');
                apt_linea++;
                //si no es raiz o raiz vacia
                if(apt_linea == '<' ||  apt_linea == '\n')
                {
                    continue;
                }  
                else{ // 
                    strtok(apt_linea, "<"); //extrae contenido del tag
                    ATRIBUTO *nodito_atributo = nodo_atributo(NULL,apt_linea);
                    (head)->final->Atributo = nodito_atributo;
                    (head)->frente2= nodito_atributo;
                    (head)->final2= nodito_atributo;
                }
                *contenido_archivo = strchr(*contenido_archivo, '\n');
                if(*contenido_archivo == NULL)
                {
                    return;
                }
                else if(**contenido_archivo != 10){ //si es diferente a \n
                    do{
                        apt_linea++;
                    }while(*apt_linea != '>');
                    apt_linea++;
                    strchr(apt_linea, "<"); //agarra el elemento
                    (head)->final->Atributo->info = apt_linea;
                    *contenido_archivo = strrchr(*contenido_archivo, '\n');
                    if(*contenido_archivo == NULL)
                    {
                        return;
                    }
                    else if(*contenido_archivo == 32)
                    {
                        *contenido_archivo = strchr(*contenido_archivo, ' ');
                        continue;
                    }
                }
                else 
                {   *contenido_archivo = strchr(*contenido_archivo, ' ');
                    if(*contenido_archivo == NULL){
                        return;
                    }
                    else continue;
                }
            }
            else //<- si lo encuentra, TAG tiene un atributo :  <TAG ID = "23">
            {   Tag_Con_Espacio++; //skipea el espacio
                char *informacion, *aux2;
                //para extraer atributo del tag
                atributo_tag = Tag_Con_Espacio;
                //para extraer la información del atributo tag
                informacion = Tag_Con_Espacio;
                do{
                    informacion++; //<- mueve "lineas" hasta encontrar comillas en ASCII
                }while(*informacion != 34);
                strtok(aux, " "); //extrae TAG principal
                strtok(atributo_tag, "="); //extrae nombre atributo (antes del signo de igual)
                NODO_TAG *nodito = nodo(aux);
                ATRIBUTO *nodito_atributo = nodo_atributo(atributo_tag,informacion);
                    //si la raiz tiene atributo
                    if((head)->frente == NULL){ 
                        (head)->frente = nodito;
                        (head)->final = nodito;
                        (head)->final->Atributo = nodito_atributo;
                        (head)->frente2= nodito_atributo;
                        (head)->final2=nodito_atributo;
                        //HayAtributoTAG me va a ayudar a controlar la conversión e imprimir bien los atributos
                        (head)->final->Atributo->HayAtributoTAG = 1;
                    }
                    else if(EsContenidoElemento == 1)
                    {
                        (head)->final->next = nodito;
                        (head)->final=nodito; 
                        (head)->final2->atributo= nodito_atributo;
                        (head)->final2= nodito_atributo;
                    }
                    else 
                    {
                        (head)->final->next = nodito;
                        (head)->final=nodito;  
                        (head)->final2->atributo=nodito_atributo;
                        (head)->final2=nodito_atributo;
                        (head)->final->Atributo->HayAtributoTAG = 1;
                    }
                
                if(apt_linea != '<' ||  apt_linea != "\n") //si no es raiz o raiz vacia */
                *contenido_archivo = strchr(*contenido_archivo, '\n');
                if(*contenido_archivo == NULL)
                {
                    return;
                }
                else if(**contenido_archivo != 10){
                    do{
                        apt_linea++;
                    }while(*apt_linea != '>');
                    apt_linea++;
                    strchr(apt_linea, "<");
                    (head)->final->Atributo->info = apt_linea;
                    *contenido_archivo = strrchr(*contenido_archivo, '\n');
                    if(*contenido_archivo == NULL)
                    {
                        return;
                    }
                    else if(*contenido_archivo == 32)
                    {
                        *contenido_archivo = strchr(*contenido_archivo, ' ');
                        continue;
                    }
                }
                else 
                {   *contenido_archivo = strchr(*contenido_archivo, ' ');
                    continue;
                }

            }
            } 
        }       
        return;   
    }
//verifica si existe el archivo y la extensión es correcta
    char *leer_archivo(const char *name, char *contenido)
    {   FILE *archivo;
        long tamanio;
        archivo = fopen(name,"r"); //<- abre el archivo
        if(archivo != NULL) //<-si existe el archivo
        {
            char *ver_extension = strrchr(name,'.'); //<-extrae todo después del punto
            //verifica si la extensión es .json o
            if(ver_extension != NULL && strcmp(ver_extension, ".json") == 0)
            {   BOOL = TRUE; //<- existe entrada de archivo válido
                fseek(archivo, 0, SEEK_END); //moviendo *archivo al final
                tamanio = ftell(archivo); //desde el final obtenemos la longitud
                rewind(archivo); //ir al inicio again
                contenido = malloc(tamanio + 1); //para el nulo
                if(!contenido)
                {
                    puts("Oops! NO hay memoria pal archivo, ni modo");
                    fclose(archivo);
                    return NULL;
                }
                //copia el contenido del archivo en la cadena
                size_t Bytes = fread(contenido, 1, tamanio, archivo);
                contenido[tamanio + 1] = '\0';
                puts("\n El archivo ha sido encontrado y traducido!");
                return contenido;
            }
            else if(ver_extension != NULL && strcmp(ver_extension, ".xml") == 0)
            {   BOOL = TRUE; //<- existe entrada de archivo válido
                fseek(archivo, 0, SEEK_END); //moviendo *archivo al final
                tamanio = ftell(archivo); //desde el final obtenemos la longitud
                rewind(archivo); //ir al inicio again
                contenido = malloc(tamanio + 1); //para el nulo
                if(!contenido)
                {
                    puts("Oops! NO hay memoria pal archivo, ni modo");
                    fclose(archivo);
                    return NULL;
                }
                //copia el contenido del archivo en la cadena
                size_t Bytes = fread(contenido, 1, tamanio, archivo);
                contenido[tamanio + 1] = '\0';
                puts("\n El archivo ha sido encontrado y traducido!");
                return contenido;
            }
            else
            {
                puts("\nOops! El archivo ingresado no es .json o .xml");
            }
        }
        else
        {
            puts("\nERROR! No se encontro el archivo");
        } 
    }

    /*_________CONVERTIR DE XML A JSON_______ */
    void xml_to_json(HEAD *apt, FILE **JSON){
        //crea el archivo para poner la conversión 
        *JSON = fopen("ArchivoConvertido_XMLtoJSON.json", "w");
        static int primero=0, segundo=0; //para controlar si se imprimió un tag con o sin atributo
        if(*JSON != NULL) //si se crea el archivo
        {
            if(apt->frente == apt->final) //es decir, hay más texto
            {
                if(apt->frente->NombreTAG==NULL) // ¿ya se escribió el tag?
                {
                    printf(" \"%s\" ", apt->frente->Atributo->info);
                    //lo escribe en el archivo .json
                    //fprintf(*JSON," \"%s\" ",apt->frente->Atributo->info);
                    apt->frente->Atributo->info = NULL;
                    printf("\n}\n");
                    fprintf(*JSON, "\n}\n");
                }
                else
                {
                    printf("{\n");
                    //fprintf(*JSON, "{\n");
                    printf(" \"%s\": ", apt->frente->NombreTAG);
                    //fprintf(*JSON," \"%s\": ",apt->frente->NombreTAG);
                    apt->frente->NombreTAG=NULL; //ya ha sido escrito nombre tag
                    if(apt->frente->next == NULL){
                        xml_to_json(apt, &JSON); 
                    } //si no hay otro elemento,entonces solo hay info sin atributo
                    
                }
            }
        else if(apt->frente->NombreTAG!=NULL)
            {   if(primero == 0)
                {
                    printf("{\n");
                    printf("  \"%s\": ", apt->frente->NombreTAG);
                    primero = 1; //ya se imprimió el elemento
                }
                if(apt->frente->Atributo->HayAtributoTAG == 1) //el propio tag tiene atributo
                {
                    printf("{\n");
                    printf("   \"@%s\": %s,\n", apt->frente->Atributo->Tag_atributo, apt->frente->Atributo->info);
                    segundo = 2;
                    xml_to_json(&apt->frente->next, &JSON);
                }
                else{
                    if(segundo != 2)
                        printf("{\n");
                    printf("   \"%s\": \"%s\",\n", apt->frente->NombreTAG, apt->frente->Atributo->info);
                    if(apt->frente->next == NULL){ //si no hay otro elemento
                        printf("  }\n");
                        printf("}\n");
                       // fclose(JSON);
                    }
                    else xml_to_json(&apt->frente->next, &JSON);
                }

            }
        }
        else
        {
            puts("ERROR, no se pudo crear el archivo de traduccion");
        }
    }

    //porque tuve problemas con el strcpy :(
    int copia_cadena(char *string)
    {
        size_t longitud = strlen(string) + 1; //para el nulo
        char *destino = malloc(longitud);
        if(!destino)
        {
            puts("OOPS, no hay memoria. Ni modo");
            return 1;
        }
        strcpy(destino, string);
        return destino;
    
    }

int main(){
    HEAD head_default = {NULL,NULL,NULL,NULL};
    HEAD head_default2 = {NULL,NULL};
    FILE *JSON;
    int op;
    BOOL = FALSE;  //<- no hay entrada de ningún archivo
    //loading(); 
    do{ 
            //verificar que únicamente se escojan las opciones mostradas (1,4 y 0)
            do
            {   menu(BOOL);
                scanf("%d", &op);
            }
            while(BOOL == FALSE && op != 1 && op !=4 && op != 0);
            
        switch(op)
        {
            case 1: system("cls || clear");
                    char *name; 
                    printf("Escriba el nombre y la extension del archivo\n>");
                    scanf("%s", name);
                    char *contenido_archivo = leer_archivo(name, &contenido_archivo);
                    pause();
            break;
            case 2: //XML -> JSON
                    system("cls || clear");
                    insertar_cola(&contenido_archivo,&head_default);
                    xml_to_json(&head_default, &JSON);
                    fclose(JSON);
                    //liberar cola
                    pause();
                    
            break;
            case 3: //JSON -> XML
                    system("cls || clear");
                   // insertar_cola2(&contenido_archivo, &head_default2);

            break;
            case 4: about();
                    pause();
            break;
            default: puts("\nAu revoir!");
            break;
        }
    }while(op);

    return 0;
}

void menu(enum _bool BOOL){
    system("cls || clear");
    puts("~*============={            }===============*~");
    puts("   ¡BIENVENIDO AL TRADUCTOR DE JSON A XML!");
    if(!BOOL){ //<- si NO hay indicación de entrada de un archivo válido
        puts("[1]. Subir archivo");
        puts("[4]. About");
        puts("[0]. Salir del programa");
        puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
        printf("\tOpcion: \n>");
    } 
    else{ 
        puts("[1]. Cambiar archivo");
        puts("[2]. XML  -> JSON");
        puts("[3]. JSON -> XML (sin terminar)");
        puts("[4]. About");
        puts("[0]. Salir del programa");
        puts("~*<>><<>><<>><<>><<>><<>><<>><<>><<>><<><<<>*~");
        printf("\tOpcion: \n>");

    }
}

void loading(){
    //just for fun
    for(int i=0;i<1; i++){
        system("cls || clear");
        printf("Loading \"Traductor_LXMD.c\"");
        fflush(stdout);
       // sleep(1);
        printf(".");
        fflush(stdout);
        //sleep(1);
        printf(".");
        fflush(stdout);
       // sleep(1);
        printf(".");
        fflush(stdout);
       // sleep(1);
    }

    system("cls || clear");
}

void pause(){
    puts("Presione ENTER para volver al menu de opciones");
    getchar();
    getchar();
}

void about(){
    system("cls || clear");
    puts("~*============={            }===============*~");
    puts("\tTraductor de JSON a XML v0.1");
    puts("\t\t     by:");
    puts("    ©Lara Xocuis Martha Denisse. S22002213");
    puts("          Ingenieria en Informatica");
    puts("\t    \"Estructura de Datos\"");
    puts("~*==========================================*~");

}


