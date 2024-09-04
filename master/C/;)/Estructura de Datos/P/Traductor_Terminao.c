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
    {   char *Tag_atributo; //nombre del tag
        char *info;  //contenido del tag
        int HayAtributoTAG; //si es que ese tag tiene un atributo, se tomará como anidado pero se imprimirá diferente
        struct atributo_tag *otro; //por si está anidado
    }NODO_ATRIBUTO;

    //FRENTE Y FINAL PARA LA COLA DENTRO DEL NODO COLA
    typedef struct apt_nodo{
        struct atributo_tag *frente2;
        struct atributo_tag *final2;
    }ATRIBUTO;

    //ESTRUCTURA BASE DE COLA DE TAGS
    typedef struct nodocola_tags
    {   //por si está anidado o el tag tiene Atributo 
        struct apt_nodo *Atributo;  
        char *NombreTAG; //Tag principal
        struct nodocola_tags *next;
    }NODO_TAG;

    //APUNTADORES PARA LAS COLA PRINCIPAL
    typedef struct colas{
        //para cola principal
        struct nodocola_tags *frente; 
        struct nodocola_tags *final;
    }HEAD;

    /*_________CREACIÓN DE NODO PARA COLA PRINCIPAL_______ */
    NODO_TAG *nodo(const char *cadena)
    {   
        NODO_TAG *nuevo_nodo = (NODO_TAG *) malloc(sizeof(NODO_TAG));
        if(!nuevo_nodo)
        {
            puts("ERROR! No hay memoria T_T");
            exit(1);
        }
        nuevo_nodo->Atributo = nuevo_nodo->Atributo;
        nuevo_nodo->NombreTAG= cadena;
        nuevo_nodo->next = NULL;
        return nuevo_nodo;
    }

    /*_________CREACIÓN DE NODO PARA EL NODO COLA_______ */
    NODO_ATRIBUTO *nodito_atributo(const char *Tag_Atributo, const char *info)
    {
        NODO_ATRIBUTO *nuevo_nodo = (NODO_ATRIBUTO*) malloc(sizeof(NODO_ATRIBUTO));
        if(!nuevo_nodo)
        {
            puts("ERROR! No hay memoria :(");
            exit(1);
        }
        nuevo_nodo->HayAtributoTAG = 0;
        nuevo_nodo->Tag_atributo = Tag_Atributo;
        nuevo_nodo->info = info;
        nuevo_nodo->otro=NULL;
        return nuevo_nodo;
    }
 
    //INSERTAR NODO EN LA COLA PRINCIPAL CICLICA
    int Insertar_ColaPrincipal(HEAD **Cola_Principal, ATRIBUTO *nodu, char *TAG, int *cierre_anidado)
    {   //se crea nodo de acuerdo al tags
        NODO_TAG *noodito = nodo(TAG);
        //INSERTAR TAG EN COLA PRINCIPAL
        if((*Cola_Principal)->frente == NULL) //<- primer valor
        {
            (*Cola_Principal)->frente = noodito;
            (*Cola_Principal)->final= noodito;
           // (*Cola_Principal)->final->Atributo = nodu;
            noodito->next = noodito; //<- el primer nodo se apunta así mismo
            return 1;
        }
        noodito->next = (*Cola_Principal)->final->next;
        (*Cola_Principal)->final->next = noodito;
        (*Cola_Principal)->final = noodito;
        //(*Cola_Principal)->final->Atributo = nodu;
        return 1;
    }

        //INSERTAR NODO ATRIBUTO EN EL NODO COLA 
    int Inst_Cola2(HEAD **Cola_Princ,ATRIBUTO *Cola2, char *TAG, char *contenido, int *cierre_anidado)
    {
        NODO_ATRIBUTO *noodito = nodito_atributo(TAG, contenido);

        if((Cola2)->frente2 == NULL)
        {
            (Cola2)->frente2 = noodito;
            (Cola2)->final2 = noodito;
            if(cierre_anidado!=1)
            {
                (*Cola_Princ)->frente->Atributo = &Cola2->frente2;
            }
            if(TAG == NULL)//quiere decir que NO es un atributo del TAG y es un elemento nada más 
            {
                return 1;
            }
            (Cola2)->final2->HayAtributoTAG=1;
            return 1;
        }

        (Cola2)->final2->otro= noodito;
        (Cola2)->final2= noodito;
        if(cierre_anidado!=1)
            {   
                (*Cola_Princ)->final->Atributo=NULL;
                (*Cola_Princ)->final->Atributo= noodito;
            }
        if(TAG == NULL)//quiere decir que NO es un atributo del TAG y es un elemento nada más 
        {
                return 1;
        }
        (Cola2)->final2->HayAtributoTAG=1;
        return 1;
    }

    //CREAR LA COLA DE COLAS PARA XML A JSON
    void insertar_cola(char **contenido_archivo, HEAD *head)
    {   ATRIBUTO head2 = {NULL,NULL};
        char *apt_linea, *aux, *Tag_Con_Espacio, *atributo_tag, copia_linea[256], *lineas, *anidado, *apt_linea2;
        //para detectar si hay un elemento anidado a otro elemento
        int raiz =0, cierre_anidado = 0, espacios = 0;
        while(**contenido_archivo)
        {
            
        //hace una copia del contenido del archivo a lineas para ir extrayendo cada linea por linea

        /*tuve muchos errores con strcpy por la asignación de memoria, so, hice mi propia función de copiado */
        lineas = copia_cadena(*contenido_archivo);
        strtok(lineas, "\n"); //<- extrae linea del archivo

        //hace otra copia a esa linea para ir extrayendo varios tags e identificar si hay atributos
        apt_linea = copia_cadena(lineas);
        if(espacios == 1){
            apt_linea = apt_linea2;
            espacios = 0;
        }
        else apt_linea2 = apt_linea;
        

        /* _______TAG______ */
        if(*apt_linea == '<') //<-- checa si existe un <TAG>
            {  
                //checa si el siguiente de < es un /, es decir, el elemento está cerrado (solo para cuando están anidados)
                anidado = copia_cadena(apt_linea);
                if (++anidado == '/'){ 
                    cierre_anidado = 0;
                }
                aux = copia_cadena(apt_linea);

                strtok(++aux, ">"); //<-- extrae todo el TAG <.....>

                // Tag_Con_Espacio solo va a servir para verificar si hay un espacio O NO
                Tag_Con_Espacio = copia_cadena(aux); //<- hace una copia de todo el TAG extraido de <...>
                //si hay un espacio, hay un atributo dentro del TAG
                Tag_Con_Espacio = strchr(Tag_Con_Espacio, ' ');
                if(Tag_Con_Espacio == NULL) //<- si NO hay un atributo
                {

                     Insertar_ColaPrincipal(&head, &head2, aux, &cierre_anidado);

                    //mover apt_linea hasta el contenido del tag para identificar si es una raiz o es un elemento
                    do{
                        apt_linea++;
                    }while(*apt_linea != '>');
                    apt_linea++;

                    if(apt_linea == NULL) //si el elemento está anidado <e> \n info \n <\e>
                    {
                        if(raiz == 1){ //NO es raiz, por lo tanto, los siguientes elementos correspondientes se meterán a la cola que tiene el nodo de cola principal solo para los elementos que están anidados y sin atributos en sus TAGS
                            Inst_Cola2(&head,&head2, NULL, apt_linea, &cierre_anidado);
                            cierre_anidado = 1;
                        }
                        else{ //si es el primero que encuentra, entonces es raiz
                            //hace un salto de linea
                            *contenido_archivo = strchr(*contenido_archivo, '\n');

                            if(*contenido_archivo)
                            {
                                *contenido_archivo = strchr(*contenido_archivo, ' ');
                                raiz = 1;   //<- indica que los demás que se encuentren así, serán elementos y NO raíz
                                continue;
                            }
                        }
                    }  
                    else{ //si es un elemento con contenido <e>text<\e>
                        strtok(apt_linea, "<"); //extrae contenido del tag, todo lo que está dentro de >.....<

                        Inst_Cola2(&head,&head2, NULL, apt_linea, &cierre_anidado); //mete el contenido a la cola que está en el nodo de cola principal
                    }
                    //hace un salto de linea y revisa si es el final del archivo
                    *contenido_archivo = strchr(*contenido_archivo, '\n');
                    if(*contenido_archivo == NULL)
                    {
                        return;  //<- final del archivo
                    }
                    else 
                    {   *contenido_archivo = strchr(*contenido_archivo, ' ');
                        if(*contenido_archivo == NULL){
                            return;
                        }
                        else continue;
                    }
                }
            else //<- si lo encuentra, TAG tiene un atributo :  <NUM ID = "23">
                {   Tag_Con_Espacio++; //skipea el espacio
                    char *informacion, *aux2;
                    //para extraer atributo del tag
                    atributo_tag = Tag_Con_Espacio;
                    //para extraer la información del atributo tag
                    informacion = Tag_Con_Espacio;
                    do{
                        informacion++; //<- mueve "lineas" hasta encontrar comillas en ASCII, así se extrae 23
                    }while(*informacion != 34);
                    strtok(aux, " "); //extrae TAG principal, (NUM)
                    strtok(atributo_tag, "="); //extrae nombre atributo (antes del signo de igual) (ID)
                    
                    Insertar_ColaPrincipal(&head, &head2, aux, &cierre_anidado);
                    Inst_Cola2(&head,&head2, atributo_tag, informacion, &cierre_anidado);

                    //hace un salto de linea y revisa si es el final del archivo

                    *contenido_archivo = strchr(*contenido_archivo, '\n');
                    if(*contenido_archivo == NULL)
                    {
                        return;  //<- final del archivo
                    }
                    else 
                    {   *contenido_archivo = strchr(*contenido_archivo, ' ');
                        if(*contenido_archivo == NULL){
                            return;
                        }
                        else continue;
                    }

                }
            } 
            else{
                //quita espacios
                do{
                    apt_linea++;
                }while(*apt_linea != '<');
                apt_linea2 = apt_linea;
                espacios = 1;

            }
        }       
        return;
        
    }

/*___________________PILA___________________*/
    //ESTRUCTURA BASE DE PILA DE TAGS

    typedef struct nodo_pila
    {
        char *TAG; //tag principal
        char *inf;
        int HayAtributoTAG;
        struct nodo_pila *next;
    }ATRIBUTO_2;

    typedef struct nodopila_tag
    {
        ATRIBUTO *atributo;
        char *NOM_TAG;
        struct nodopila_tag *next;
    }NODO_PILA;

    //Apuntadores para la pila
    typedef struct pila{
        struct nodopila_tag *TOPE;
        struct nodo_pila *HEAD; //lista
    }PILA;

/*______________CREACIÓN NODO PARA PILA______________*/
    NODO_PILA *crearnodo(const char *TAG)
    {
        NODO_PILA *nodito = (NODO_PILA*) malloc(sizeof     (NODO_PILA));
        if(!nodito)
        {
            return 1;
        }
        nodito->NOM_TAG = TAG;
        nodito->next=NULL;
        return nodito;
    }

    //insertar elementos en la pila
    void push(PILA *pila, const char *TAG)
    {
        NODO_PILA* nodito = crearnodo(TAG);
        nodito->next = pila->TOPE;
        pila->TOPE = nodito;
    }

    ATRIBUTO_2 **nodo_atributo2(const char *cadena, const char *contenido)
    {
        ATRIBUTO_2 *nuevo_nodo = (ATRIBUTO_2*)malloc (sizeof(ATRIBUTO_2));
        if(!nuevo_nodo)
        {
            exit(1);
        }
        nuevo_nodo->TAG=cadena;
        nuevo_nodo->inf=contenido;
        nuevo_nodo->next=NULL;
        return nuevo_nodo;

    }

    int puts_elem(PILA **inicio, const char *aux, const char *atributo_tag)
    {
        ATRIBUTO_2 *NUEVO = nodo_atributo2(aux,atributo_tag);
        (*inicio)->TOPE->atributo = NUEVO;
        (*inicio)->HEAD->next = NUEVO;
        (*inicio)->HEAD = NUEVO;
        return 1;

    }

//CREAR PILA PARA JSON A XML
    void insertar_cola2(char **contenido_archivo, PILA *head){
        while(**contenido_archivo)
        {
            char *apt_linea, *aux, *lineas, *atributo_tag, *cerrado;
            static int raiz=0, cierre_anidado=0;
            lineas = copia_cadena(*contenido_archivo); 
            //extraer linea del archivo
            strtok(lineas, "\n");
            apt_linea = copia_cadena(lineas);
            cerrado = copia_cadena(apt_linea);

            /* ______TAG______ */
            if(*apt_linea == '{')
            {
                *contenido_archivo = strchr(*contenido_archivo, '\n');
                if(*contenido_archivo == NULL)
                {
                    return;
                }
                else
                {
                    *contenido_archivo = strchr(*contenido_archivo, ' ');
                    continue;
                }
            }
            else if(strchr(cerrado, '}' ) == NULL){
                do{ //mover hasta encontrar comillas en ASCII
                    apt_linea++;
                }while(*apt_linea != 34);
                apt_linea++;
                aux = copia_cadena(apt_linea);
                strtok(aux, "\"");
                //extrae todo lo de "libro"
                if(cierre_anidado == 0)
                {
                    push(head, aux); 
                }

                lineas = strchr(lineas, ':');
                atributo_tag = copia_cadena(lineas);
                lineas = strchr(lineas, '{'); //si está anidado y NO es raiz
                
                if(lineas != NULL)
                {
                    //pasa a la siguiente linea, quiere decir que eso será entonces otro nodo anidado SOLO si no es RAIZ
                    *contenido_archivo = strchr(*contenido_archivo, '\n');
                    if(raiz==1)
                    { //si ya hay raiz, los demás nodos serán anidados a atributo
                        //salto de linea
                         *contenido_archivo = strchr(*contenido_archivo, ' ');
                         cierre_anidado=1; //indica que lo siguiente será anidado hasta encontrar un cierre
                         continue;

                    }
                    if(*contenido_archivo == NULL)
                    {   
                        return;
                    }
                    else
                    {
                        *contenido_archivo = strchr(*contenido_archivo, ' ');
                        raiz =1;
                        continue;
                    }
                }
                else if(cierre_anidado == 0){
                     do{ //mover hasta encontrar comillas en ASCII
                    atributo_tag++;
                    }while(*atributo_tag != 34);
                    atributo_tag++;
                    strtok(atributo_tag, "\"");
                    //extrae todo lo de "libro"
                    ATRIBUTO_2 *node_atributo = nodo_atributo2(NULL, atributo_tag);
                    head->TOPE->atributo = node_atributo;
                }
                else
                {  
                    do{ //mover hasta encontrar comillas en ASCII
                        atributo_tag++;
                    }while(*atributo_tag != 34);
                    atributo_tag++;
                    strtok(atributo_tag, "\"");
                    puts_elem(&head, aux, atributo_tag);


                }
                 //salto de linea
                     *contenido_archivo = strchr(*contenido_archivo, '\n');
                    if(*contenido_archivo){
                         *contenido_archivo = strchr(*contenido_archivo, ' ');
                         continue;
                    }
            }
            else{
                cierre_anidado = 0;
                *contenido_archivo = strchr(*contenido_archivo, '\n');
                    if(*contenido_archivo){
                         *contenido_archivo = strchr(*contenido_archivo, ' ');
                         continue;
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
                puts("\n El archivo ha sido encontrado!");
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
                    printf(" \"%s\" ", apt->frente->Atributo->frente2->info);
                    //lo escribe en el archivo .json
                    fprintf(*JSON," \"%s\" ",apt->frente->Atributo->frente2->info);
                    apt->frente->Atributo->frente2->info = NULL;
                    printf("\n}\n");
                    fprintf(*JSON, "\n}\n");
                }
                else
                {
                    printf("{\n");
                    fprintf(*JSON, "{\n");
                    printf(" \"%s\": ", apt->frente->NombreTAG);
                        fprintf(*JSON," \"%s\": ",apt->frente->NombreTAG);
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
                if(apt->frente->Atributo->frente2->HayAtributoTAG == 1) //el propio tag tiene atributo
                {
                    printf("{\n");
                    printf("   \"@%s\": %s,\n", apt->frente->Atributo->frente2->Tag_atributo, apt->frente->Atributo->frente2->info);
                    segundo = 2;
                    xml_to_json(&apt->frente->next, &JSON);
                }
                else{
                    if(segundo != 2)
                        printf("{\n");
                    printf("   \"%s\": \"%s\",\n", apt->frente->NombreTAG, apt->frente->Atributo->frente2->info);
                    if(apt->frente->next == NULL){ //si no hay otro elemento
                        printf("  }\n");
                        printf("}\n");
                        fclose(JSON);
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
    HEAD head_default = {NULL,NULL};
    PILA def = {NULL,NULL};
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
                    //fclose(JSON);
                    //liberar cola
                    pause();
                    
            break;
            case 3: //JSON -> XML
            // si es JSON, implementar solo la opción de json a xml ;) 
                    system("cls || clear");
                   insertar_cola2(&contenido_archivo, &def);
                   

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
        puts("[3]. JSON -> XML");
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
    puts("\tTraductor de JSON a XML v0.2");
    puts("\t\t     by:");
    puts("    ©Lara Xocuis Martha Denisse. S22002213");
    puts("          Ingenieria en Informatica");
    puts("\t    \"Estructura de Datos\"");
    puts("~*==========================================*~");

}