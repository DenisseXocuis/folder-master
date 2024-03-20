#include<stdio.h>
#include<stdlib.h>
#define T 100
typedef struct{
    int ans; //y datos.........
    char name[T];
    float weight;
}persona;
int main(){
    persona *p;
    int num;
    printf("BONJOUR!.\nIngresa el tamaño de personas, s'il vous plait:\n>");
    scanf(" %d", &num);

    p = (persona *)calloc(num, sizeof(persona));
    //or malloc num * sizeof(persona)

    if(!p)
        printf("srry, no hay memory :(");
    else{
        for(int i = 0; i<num; i++){
            printf("Prenom:\n");
            scanf(" %[^\n]", (p+i)->name);
            printf("Edad:\n");
            scanf("%d", &(p+i)->ans);
            printf("Peso:\n");
            scanf("%f", &(p+i)->weight);
        }
    for(int i = 0; i<num; i++){
        puts("------------------------------------------");
        printf("\t\t\"%s\"\n", (p+i)->name);
        printf("\t\t%d años\n", (p+i)->ans);
        printf("\t\t%g kg\n", (p+i)->weight);
        puts("------------------------------------------");
    }
    free(p);
    }


    return 0;
}