#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define T 30
void saltolin(char *);

typedef struct {
    char nombre[T], nomdueño[T];
    unsigned tel;
    float peso;
}datos;

struct{
    int c;
}pe = {0},ga = {0},ot = {0};

int main(){
    unsigned MAX,tipo;
    float mayor,gamayor,omayor;
    mayor = gamayor= omayor=0;
    system("cls || clear");
    puts("Control de las mascotas de una veterinaria");
    puts("¿Cuantas mascotas desea agregar?");
    scanf("%d", &MAX);
    datos p[MAX], g[MAX], o[MAX];

    for(int i=0; i<=(MAX-1); i++){
        system("cls || clear");
        printf("Mascotas a ingresar al sistema: %d\n",MAX);
        printf("¿Que tipo de mascota es la mascota %d?", i+1);
        printf("\n\t1:Perro\n\t2:Gato\n\t3:Otro\n>");
        do{
            scanf("%d", &tipo);
            getchar();
            if(tipo==1){
                system("cls || clear");
                pe.c++;
                printf("Ingrese el nombre de la mascota:\n");
                fgets(p[i].nombre, sizeof(p[i].nombre), stdin);
                printf("Ingrese el nombre del dueño de la mascota:\n");
                fgets(p[i].nomdueño, sizeof(p[i].nomdueño), stdin);
                printf("Ingrese el telefono: \n");
                scanf("%d", &p[i].tel);
                printf("Ingrese el peso: \n");
                scanf("%f", &p[i].peso);
                if(p[i].peso > mayor){
                    mayor = p[i].peso;
                }
                getchar();
            }
            else if(tipo ==2){
                system("cls || clear");
                ga.c++;
                printf("Ingrese el nombre de la mascota:\n");
                fgets(g[i].nombre, sizeof(g[i].nombre), stdin);
                printf("Ingrese el nombre del dueño de la mascota:\n");
                fgets(g[i].nomdueño,sizeof(g[i].nomdueño), stdin);
                printf("Ingrese el telefono: \n");
                scanf("%d", &g[i].tel);
                printf("Ingrese el peso: \n");
                scanf("%f", &g[i].peso);
                if(g[i].peso > gamayor){
                    gamayor = g[i].peso;
                }
                getchar();
            }
            else{
                system("cls || clear");
                ot.c++;
                printf("Ingrese el nombre de la mascota:\n");
                fgets(o[i].nombre, sizeof(o[i].nombre), stdin);
                printf("Ingrese el nombre del dueño de la mascota:\n");
                fgets(o[i].nomdueño,sizeof(o[i].nomdueño), stdin);
                printf("Ingrese el telefono: \n");
                scanf("%d", &o[i].tel);
                printf("Ingrese el peso: \n");
                scanf("%f", &o[i].peso);
                if(o[i].peso > omayor){
                    omayor = o[i].peso;
                }
                getchar();
            }
        }while(tipo<1 || tipo>3);
    }
    system("cls || clear");
    printf("El total de mascotas ingresadas fue de: %d\n", MAX);
    printf("Donde hubo: \n\tPerros: %d\n\tGatos: %d\n\tOtros: %d\n\t", pe.c, ga.c,ot.c);
    putchar('\n');
    for(int i=0; i<MAX; i++){
        if((omayor == o[i].peso) && (ot.c >0)){
            saltolin(o[i].nombre);
            printf("\"%s\" tuvo el mayor peso del tipo \"otros\" con %g kg\n", o[i].nombre, o[i].peso);
        }
        if(gamayor == g[i].peso && (ga.c >0)){
            saltolin(g[i].nombre);
            printf("\"%s\" tuvo el mayor peso de todos los gatos con %g kg\n", g[i].nombre, g[i].peso);
        }
        if(mayor == p[i].peso && (pe.c >0)){
            saltolin(p[i].nombre);
            printf("\"%s\" tuvo el mayor peso del todos los perros con %g kg\n",p[i].nombre , p[i].peso);
        }
    }
    return 0;
}

void saltolin(char *cadena){
    int t = strlen(cadena);
    if (t > 0 && cadena[t - 1] == '\n')
        (cadena[t - 1] = '\0');
    return *cadena;
}