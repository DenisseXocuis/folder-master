#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define T 512

typedef struct queueObjects{
    struct object *start, *end;
}queueObjects;

typedef struct object{
    char objectType[T];
    struct queueObjects *subObject;
    struct item *start;
    struct object *next;
}object;

typedef struct item{
    char itemType[T], itemContent[T];
    struct queueObjects *subObject;
    struct item *next;
    bool isFirst;
}item;

FILE *openFile(void);
FILE *createOutputFile(void);

queueObjects *initQueueObjects();
void initObject(queueObjects **objects, char *objectType);
void initItem(item **start, char *itemName, char *itemContent);

void printQueueObjects(queueObjects *objects);
void printObject(object *objeto);
void printItem(item *item);

void removeXMLtags(char *str);
void parseXML(FILE *file, queueObjects *objects);
char *cleanTag(char *tag);

void convertXML(FILE *file);
void fprintQueueToJSON(FILE *outputFile, queueObjects *objects);
void fprintObjectToJSON(FILE *outputFile, object *objeto);
void fprintItemToJSON(FILE* outputFile, item *item, int i);
void fprintSubObjectQueueToJSON(FILE *outputFile, queueObjects *objects);
void fprintSubObjectToJSON(FILE *outputFile, object *objeto);
void fprintSubObjectItemToJSON(FILE* outputFile, item *item, int i);

//Tipo de archivo: Sin archivo=0, XML=1, JSON=2
int fileType = 0, extra=1;

int main(void){
    FILE *inputFile = openFile();
    convertXML(inputFile);
    fclose(inputFile);

    return 0;
}

FILE *openFile(void){
    char fileDirectory[T], *fileExt;
    printf("Arrastre el archivo, o pegue su dirección\n");
    scanf("%s", fileDirectory);

    // Guardar la extensión del archivo en una variable
    fileExt = strrchr(fileDirectory, '.');

    // Dependiendo de la extensión asignarle el valor a fileType
    if(strcmp(fileExt, ".xml") == 0 || strcmp(fileExt, ".XML") == 0){
        fileType = 1;
        printf("Archivo XML detectado\n");
    } else if (strcmp(fileExt, ".json") == 0 || strcmp(fileExt, ".JSON") == 0){
        fileType = 2;
        printf("Archivo JSON detectado\n");
    } else {
        printf("[ERROR] Tipo de arhcivo incorrecto\n");
    }

    // Carga la dirección del archivo en memoria
    if(fileType != 0){
        FILE *openedFile = fopen(fileDirectory,"r");
        if(!openedFile){
            printf("[ERROR] No se pudo abrir el archivo\n");
            exit(1);
        }
        return openedFile;
    } else {
        return NULL;
    }
}

FILE *createOutputFile(void){
    char fileName[T];
    printf("Ingrese un nombre para el nuevo archivo\n");
    scanf("%s", fileName);

    switch (fileType) {
        case 1:
            strcat(fileName, ".json");
            break;
        case 2:
            strcat(fileName, ".xml");
            break;
        default:
            printf("[ERROR] Error desconocido\n");
            return NULL;
            break;
    }

    FILE *createdFile = fopen(fileName, "w");
    if(!createdFile){
        printf("[ERROR] No se pudo crear el nuevo archvo\n");
        exit(1);
    } else if (fileType==2) {
        fprintf(createdFile, "<?xml version=\"1.0\"?>");
    }

    return createdFile;
}

queueObjects *initQueueObjects() {
    queueObjects *newQueue = (queueObjects *)malloc(sizeof(queueObjects));
    if (!newQueue) {
        printf("[ERROR] No se pudo asignar memoria para el catalogo\n");
        printf("Cerrando programa...\n");
        exit(1);
    }

    newQueue->start = NULL;
    newQueue->end = NULL;

    return newQueue;
}

void initObject(queueObjects **objects, char *objectType) {
    object *newObject = (object *)malloc(sizeof(object));
    if (!newObject) {
        printf("[ERROR] No se pudo asignar memoria para el objeto\n");
        printf("Cerrando programa...\n");
        exit(0);
    }

    // Si ya existe un nodo en la colaProcesos
    if ((*objects)->end) {
        // Se hace que el ultimo nodo apunte al nuevoNodo
        ((*objects)->end)->next = newObject;
    } else {
        // Sino, se asigna frente como el nuevoNodo
        (*objects)->start = newObject;
    }
    // Se asgina sig del nuevoNodo como NULL
    strcpy(newObject->objectType, objectType);
    newObject->next = NULL;
    // Se asigna final como el nuevoNodo
    (*objects)->end = newObject;
}

void initItem(item **start, char *itemType, char *itemContent){
    item *newItem = (item *)malloc(sizeof(item));
    if (!newItem) {
    printf("[ERROR] No se pudo asignar memoria para el objeto\n");
    printf("Cerrando programa...\n");
    exit(0);
}
    if (*start) {
        newItem->isFirst=false;
    } else {
        newItem->isFirst=true;
    }

    strcpy(newItem->itemType, itemType);
    strcpy(newItem->itemContent, itemContent);
    newItem->next=*start;
    *start=newItem;
}

void convertXML(FILE *file){
    queueObjects *objects = initQueueObjects();
    parseXML(file, objects);
    fprintQueueToJSON(createOutputFile(), objects);
    printQueueObjects(objects);

}

void parseXML(FILE *file, queueObjects *objects){
    char *buffer = (char *)malloc(sizeof(char)*T);
    char *tagText, *objectType=NULL, *subObjectType=NULL, tag[T], objectTypeT[T], subObjectTypeT[T];
    //Ir linea por linea en el archivo
    while (fgets(buffer, T, file) != NULL) {

        //Buscar los tags del XML
        strcpy(tag, strrchr(buffer, '<'));
        // strcpy(tag, tagT);
        //copyXMLtagToQueue(objects, tag);

        //Remover los tags del buffer
        removeXMLtags(buffer);
        while (*buffer == ' ' || *buffer == '\t') {
            buffer++;
        }

        // printf("%s", tag);
        // if(strcmp(buffer, "\n")!=0)
        //     printf("%s", buffer);

        //Se ignora la etiqueta de version
        if (tag[1]=='?') {
            continue;
        //Se encontró un objeto y no hay ninguno abierto
        } else if (tag[0]=='<' && tag[1]!='/' && objectType==NULL) {
            objectType = cleanTag(tag);
            strcpy(objectTypeT, objectType);
            initObject(&objects, objectType);
            printf("[DBG] Objeto encontrado!\n");
        //Se encontró un objeto, ya existe un objeto por lo que se encontró un subojeto
        } else if (tag[0]=='<' && tag[1]!='/' && objectType!=NULL) {
            subObjectType=cleanTag(tag);
            strcpy(subObjectTypeT, subObjectType);
            //Si existe un item
            if (objects->start->start) {
                //Sino existe una cola de subojetos, crear una
                if(!objects->start->start->subObject){
                    objects->start->start->subObject=initQueueObjects();
                }
                initObject(&objects->start->start->subObject, cleanTag(tag));
            //Sino existe un item
            } else {
                //Sino existe una cola de subojetos, crear una
                if (!objects->start->subObject){
                    objects->start->subObject=initQueueObjects();
                }
                initObject(&objects->start->subObject, cleanTag(tag));
            }
            printf("[DBG] Subojeto encontrado!\n");
        //Se encontró el fin del subobjeto, se cierra el subobjeto
        } else if (strcmp(cleanTag(tag), subObjectTypeT)==0) {
            printf("[DBG] Fin subobjeto encontrado\n");
            subObjectType=NULL;
        //Se encontró el fin del objeto principal, se cierra el objeto
        } else if (strcmp(cleanTag(tag), objectTypeT)==0) {
            printf("[DBG] Fin objeto encontrado\n");
            objectType=NULL;
        } else if (tag[0]=='<' && tag[1]=='/') {
            //Se encuentra abierto el subobjeto
            if (subObjectType) {
                //Si existe un item
                if (objects->start->start) {
                    initItem(&objects->start->start->subObject->start->start, cleanTag(tag), buffer);
                } else {
                    initItem(&objects->start->subObject->start->start, cleanTag(tag), buffer);
                }
            } else {
                initItem(&objects->start->start, cleanTag(tag), buffer);
            }
        }
    }
        //free(buffer);
}

void fprintQueueToJSON(FILE *outputFile, queueObjects *objects){
    fprintf(outputFile, "{\n");
    fprintObjectToJSON(outputFile, objects->start);
    fprintf(outputFile, "}\n");  
}

void fprintSubObjectQueueToJSON(FILE *outputFile, queueObjects *objects){
    if (objects->start) {
        fprintSubObjectToJSON(outputFile, objects->start);
    }
}

void fprintObjectToJSON(FILE *outputFile, object *objeto){
    fprintf(outputFile, "    \"%s\": {\n", objeto->objectType);
    fprintItemToJSON(outputFile, objeto->start, 0);
    if (objeto->next) {
        fprintObjectToJSON(outputFile, objeto->next);
    }
}

void fprintSubObjectToJSON(FILE *outputFile, object *objeto){
    fprintf(outputFile, "        \"%s\": {\n", objeto->objectType);
    fprintSubObjectItemToJSON(outputFile, objeto->start, 0);
    if (objeto->next) {
        fprintSubObjectToJSON(outputFile, objeto->next);
    }
}

void fprintSubObjectItemToJSON(FILE* outputFile, item *item, int i){
    i++;
    if (item->next) {
        fprintSubObjectItemToJSON(outputFile, item->next, i);
    }
    fprintf(outputFile, "            \"%s\": \"%s\"", item->itemType, item->itemContent);

    if (i!=1 || item->subObject) {
        fprintf(outputFile, ",\n");
    } else if (i==1 && !(item->subObject)){
        fprintf(outputFile, "\n        }\n");
    }
    if (item->subObject) {
        fprintSubObjectQueueToJSON(outputFile, item->subObject);
    
    }

}

void fprintItemToJSON(FILE* outputFile, item *item, int i){
    i++;
    if (item->next) {
        fprintItemToJSON(outputFile, item->next, i);
    }

    fprintf(outputFile, "        \"%s\": \"%s\"", item->itemType, item->itemContent);

    if (i!=1 || item->subObject) {
        fprintf(outputFile, ",\n");
    } else if (i==1 && !(item->subObject)){
        fprintf(outputFile, "\n    }\n");
    }
    if (item->subObject) {
        fprintSubObjectQueueToJSON(outputFile, item->subObject);
        fprintf(outputFile, "    }\n");
    }

}


void removeXMLtags(char *buffer) {
    char *ptr = buffer;
    int inTag = 0;

    while (*ptr) {
        if (*ptr == '<') {
            inTag = 1;
        } else if (*ptr == '>') {
            inTag = 0;
        } else {
            if (!inTag) {
                *buffer = *ptr;
                buffer++;
            }
        }
        ptr++;
    }
    *(buffer-1) = '\0';
}

char *cleanTag(char *tag) {
    char *clean;
    
    int j = 0;
    for (int i = 0; tag[i] != '\0'; i++) {
        if (tag[i] != '<' && tag[i] != '>' && tag[i] != '/') {
            clean[j++] = tag[i];
        }
    }
    clean[j-1] = '\0'; // Agregar el caracter nulo al final de la cadena limpio
    return clean;
}

void printQueueObjects(queueObjects *objects){
    if (objects) {
        printf("--------------------------------------------------------\n");
        if (extra == 1) {
        printf("-> Dirección de memoria de cola Objetos: %p <-\n",
                objects);
        printf("-> Direccion de frente: %p\n",
                objects->start);
        printf("-> Dirección de final: %p \n", objects->end);
        }
        printObject(objects->start);
        printf("--------------------------------------------------------\n");
    }
}

void printObject(object *objeto){
    if(objeto){
        printf("-> Comienza objeto\n");
        if (extra == 1) {
            printf("Dirección en Memoria: %p\n", objeto);
            printf("Dirección de item: %p\n", objeto->start);
            printf("Siguiente: %p\n", (objeto->next));
            printf("Dirección de subobjeto: %p\n", objeto->subObject);
        }
        printf("Tipo de objeto: %s\n", objeto->objectType);
        printf("-----------------\n");
        if (objeto->start) {
            printItem(objeto->start);
        } else if (objeto->subObject) {
            printf("--> Imprimiendo subobjeto\n");
            printQueueObjects(objeto->subObject);
        } 
        

    // Si existe otro nodo
        if (objeto->next){
            printObject(objeto->next);
        }
    }
}
void printItem(item *item){
    if(item->next){
        printItem(item->next);
    }
    if(item){
        printf("-> Comineza item\n");
        if (extra == 1) {
            printf("Dirección en Memoria: %p\n", item);
            printf("Siguiente: %p\n", (item->next));
            printf("Dirección de subobjeto: %p\n", item->subObject);
        }
        printf("Tipo de elemento: %s\n", item->itemType);
        printf("Contenido del elemento: %s\n", item->itemContent);
        if (item->isFirst==true) {
            printf("isFirst\n");
        }
        printf("-----------------\n");
    }
    if (item->subObject) {
        printf("Imprimiendo subobjeto\n");
        printQueueObjects(item->subObject);
    }
}
