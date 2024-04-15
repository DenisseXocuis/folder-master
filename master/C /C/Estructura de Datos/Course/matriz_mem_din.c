#include<stdio.h> //capturar, liberar
#include<stdlib.h>
typedef struct{
    int edad;
    /* char *nombre;
    float peso; */
}persona;
int main(){
    persona **per;
    int n,p;
    printf("BONJOUR!.\nIngresa el tamaño de filas, s'il vous plait :) :\n>");
    scanf(" %d", &n);
    per = (persona *)calloc(n, sizeof(persona));
    //or malloc num * sizeof(persona)
    if(!per)
        printf("srry, no hay memory :(");
    else{
        //asignando memoria pa' la otra fila :)
        for(int i=0; i<n; i++){
                printf("Ingresa el tamanio de personas por casilla para la posicion %d \n>", i+1);
                scanf(" %d", &p);
                for(int j=0; j<p; j++){
                    per[i] = (persona **)calloc(p, sizeof(persona *));
                    if(!per[i])
                        break;
                }
                system("cls || clear");
                for(int j=0; j<p; j++){
                    puts("---------Llenado de la matriz---------");
                    printf("Posicion: %d %d\n Edad:\n>", i+1,j+1);
                    scanf("%d", &per[i][j].edad);
                    system("cls || clear");
                }
        }
        system("cls || clear");
        puts("---------Imprimiendo la matriz---------");
        for(int i=0; i<n; i++){
            for(int j=0; j<p; j++){
                printf("|Edad :%d|", per[i][j]);
            }
            putchar('\n');
        }
        for(int i=0; i<n; i++){
            free(per[i]);
        }
        free(per);
    }
    return 0;
}