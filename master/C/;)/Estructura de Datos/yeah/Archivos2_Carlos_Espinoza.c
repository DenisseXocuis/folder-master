/* El metodo de ordenamiento usado es heapSort ya que planeaba utilizarlo para una implementacion de externalSort, pero fui filtrado por todo
   el conocimiento previo requerido para external, entonces le baje un poco a la dificultad y decidi mejor practicar heap, ya que ordena en lugar :D.
   Todavia hay varias mejoras que hay que hacerle, como diferenciar el nombre de los parametros modo de insertar y modo de heapsort
   modificar la funcion de insertar para que diferencie entre archivos binarios y de texto, crear una funcion de visualizacion de arr para no repetir
   codigo, validaciones despues de mallocar memoria etc, etc.
   Carlos Eduardo Espinoza Chapa */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define Computadora struct computadora

typedef struct computadora{
    char marca[21];
    char procesador[25];
    long int memoria; // originalmente lo iba a poner como char y hacer validacion y conversion entre las distintas escalas, pero me dio flojera todo el codigo de relleno
    char hd[3]; // Iba a ponerlo como int y tratarlo como booleano, pero por claridad mejor lo voy a poner como char
    char monitor[21];
} Computadora;

FILE* abrirArchivo(char *modo);
int insertar(char *modo);
int transcripcion();
int sortBinary(int modo);
void heapSort(Computadora *compu, int size, int modo);
void heapify(Computadora *compu, int size, int index, int modo);
void swap(Computadora *arr1, Computadora *arr2);
void sortCSV(int modo);
int menu();

int main(){
    int c, m, o;
    while (1){
        c = menu();
        if (c==1){
            insertar("wb+"); //Iba a dejar que el usuario escogiera la forma de apertura del archivo, pero ya no quiero lidiar con el codigo de relleno
            continue; //para manejar la insercion en el texto plano y no llenarlo de basura, pk me causaria problemas con mi funcion de sortcsv
        } else if (c==2){
            transcripcion();
            continue;
        } else if (c==3){
            printf("Ingrese 1 para ordenar un archivo binario:\n");
            printf("Ingrese 2 para ordenar un archivo de texto:\n");
            printf("Ingrese 0 para volver al programa\n");
            scanf("%d", &m);
            switch (m){
                case 1:
                    printf("Ingrese 1 para ordenarlo por capacidad de memoria\n");
                    printf("O ingrese otro numero para ordenarlo alfabeticamente:\n");
                    fflush(stdin);
                    scanf("%d", &o);
                    sortBinary(o);
                    break;
                case 2:
                    printf("Ingrese 1 para ordenarlo por capacidad de memoria\n");
                    printf("O ingrese otro numero para ordenarlo alfabeticamente:\n");
                    fflush(stdin);
                    scanf("%d", &o);
                    sortCSV(o);
                    break;
                default:
                    break;
            }
        }
        else {
            printf("Programa finalzado:\n");
            return 0;
        }
    } 
}
// Funcion de control
FILE* abrirArchivo(char *modo){
    char *nombre;
    FILE *fp;
    nombre = (char *) calloc(24, sizeof(*nombre));
    printf("Ingrese el nombre del archivo a abrir:\n");
    fflush(stdin);
    scanf("%23s", nombre);
    if (!(fp = fopen(nombre, modo))){
        printf("Error al abrir el Archivo:\n");
        return NULL;
    } free(nombre);
    return fp;
}
//Funcion de escritura de archivos
int insertar(char *modo){
    FILE *fp;
    Computadora compu;
    int i, n;
    fp = abrirArchivo(modo);
    if (!fp){
        printf("Error de insercion en el archivo:\n");
        return 0;
    }
    printf("Ingrese la cantidad de registros a ingresar:\n");
    scanf("%d", &n);
    for(i=0;i < n; i++){
        printf("Ingrese la marca de la computadora:\n");
        scanf("%s", compu.marca);
        printf("Ingrese el procesador de la computadora:\n");
        scanf("%s", compu.procesador);
        printf("Ingrese la capacidad (En Bytes) de la computadora:\n");
        scanf("%ld", &compu.memoria);
        printf("La computadora cuenta con hdmi?\n");
        scanf("%s", compu.hd);
        printf("Ingrese el monitor incluido en el equipo:\n");
        scanf("%s", compu.monitor);
        fwrite(&compu, sizeof(Computadora), 1, fp);
    } fclose(fp);
    return 1;
}
// funcion de transcripcion de archivo binario a texto
int transcripcion(){
    FILE *fp1, *fp2;
    Computadora compu;
    printf("Por favor ingrese el archivo binario del que se sacaran los datos:\n");
    fp1 = abrirArchivo("rb+");
    if (!fp1){
        printf("Error al abrir el primer archivo especificado:\n");
        return 0;
    }
    printf("Ingrese el archivo de texto al que se va a transferir los datos:\n");
    fp2 = abrirArchivo("w+");
    if (!fp2){
        printf("Error al abrir el segundo archivo especificado:\n");
        fclose(fp1);
        return 0;
    }
    while (!feof(fp1)){
        fread(&compu, sizeof(compu), 1, fp1);
        if (feof(fp1)){
            break;
        }
        fprintf(fp2, "%s,%s,%ld,%s,%s\n", compu.marca, compu.procesador, compu.memoria, compu.hd, compu.monitor);
    }
    fclose(fp1);
    fclose(fp2);
    return 1;
}
// modo 1 para sortear por memoria
int sortBinary(int modo){
    Computadora *compu;
    int size=100, i=0, j=0;
    FILE *fp;
    fp = abrirArchivo("rb+");
    if (!fp){
        printf("Error de apertura del archivo:\n");
        return 0;
    }
    compu = (Computadora *) calloc(size, sizeof(*compu));
    while (!feof(fp)){
        if (i >= size){
            compu = realloc(compu, sizeof(*compu)*(size += 100));
            if (!compu){
            printf("Error Fatal:\n");
            return 0;
            }
        }
        fread(&compu[i], sizeof(Computadora), 1, fp);
        if (feof(fp)){
            break;
        }
        i++;
    }
    heapSort(compu, i, modo);
    printf("Imprimiendo los elementos registrados en el archivo:\n");
    for (j=0; j<i; j++){
        printf("\nComputadora[%d]:\nMarca: %s\nProcesador: %s\nMemoria: %ld\nHD: %s\nMonitor: %s\n",
                j+1, compu[j].marca, compu[j].procesador, compu[j].memoria, compu[j].hd, compu[j].monitor);
    }
    fclose(fp);
    free(compu);
    return 1;
}

void heapSort(Computadora *compu, int size, int modo){
    int i;
    //Construye el conjunto
    for (i=((size/2)-1); i>=0; i--){
        heapify(compu, size, i, modo);
    }
    for (i=(size-1); i>0 ;i--){
        swap(&compu[0], &compu[i]);
        heapify(compu, i, 0, modo);
    }
}

void heapify(Computadora *compu, int size, int index, int modo){
    int largest = index;
    int left = (2*index)+1;
    int right = (2*index)+2;
    long long int croot, cleft2, cright;
    if (modo == 1){
        croot = compu[largest].memoria;
        cleft2 = compu[left].memoria;
        cright = compu[right].memoria;
    } else {
        croot = (long int) compu[largest].marca[0];
        cleft2 = (long int) compu[left].marca[0];
        cright = (long int) compu[right].marca[0];
    }

    if ((left < size) && cleft2 > croot){
        largest = left;
        if (modo == 1){
            croot = compu[largest].memoria; 
        } else {
            croot = (long int ) compu[largest].marca[0];
        }
    }

    if ((right <size) && cright > croot){
        largest = right;
        if (modo == 1){
            croot = compu[largest].memoria; 
        } else {
            croot = (long int ) compu[largest].marca[0];
        }
    }

    if (largest != index){
        swap(&compu[index], &compu[largest]);
        heapify(compu, size, largest, modo);
    }
}

void swap(Computadora *arr1, Computadora *arr2){
    Computadora temp;
    temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

void sortCSV(int modo){
    FILE *fp;
    Computadora *compu;
    int n=100, i=0, size=0, j;
    fp = abrirArchivo("r+");
    if (!fp){
        printf("Error de apertura en el archivo:\n");
        return;
    }
    compu = (Computadora *) calloc(n, sizeof(*compu));
    while (!feof(fp)){
        if (size >= n){
            compu = realloc(compu, sizeof(*compu)*(n += 100));
            if (!compu){
            printf("Error en reallocacion:\n");
            return;
            }
        }
        fscanf(fp, "%[^,],%[^,],%ld,%[^,],%s", compu[i].marca, compu[i].procesador, &compu[i].memoria, compu[i].hd, compu[i].monitor);
        fgetc(fp);
        if (feof(fp)){
            break;
        }
        i++;
    }

    heapSort(compu, i, modo);
    printf("Imprimiendo los elementos registrados en el archivo:\n");
    for (j=0; j<i; j++){
        printf("\nComputadora[%d]:\nMarca: %s\nProcesador: %s\nMemoria: %ld\nHD: %s\nMonitor: %s\n",
                j+1, compu[j].marca, compu[j].procesador, compu[j].memoria, compu[j].hd, compu[j].monitor);
    }
    fclose(fp);
    free(compu);
}

int menu(){
    int i;
    printf("Ingrese 1 para guardar un nuevo archivo:\n");
    printf("Ingrese 2 realizar un transferencia de un archivo binario a texto:\n");
    printf("Ingrese 3 para mostrar los datos ordenados:\n");
    printf("Ingrese cualquier otro valor para salir del programa:\n");
    fflush(stdin);
    scanf("%d", &i);
    return i;
}