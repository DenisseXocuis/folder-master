#include<stdio.h>
#include<stdlib.h>
#define T 3
typedef struct {
    char prenom[50];
    char nom[50];
    int age;
    float weight;
    float height;
}datos;
int main(){
    datos persona[T];
    for(int i=0; i<T;i++){
        puts("---------Llenado de estructura--------------");
        putchar('\n');
        puts("Ingresa el nombre");
        gets(persona[i].prenom);
        puts("Ingresa el apellido");
        gets(persona[i].nom);
        puts("Ingresa edad");
        scanf("%d", &persona[i].age);
        puts("Ingresa el peso");
        scanf("%f", &persona[i].weight);
        puts("Ingresa la estatura");
        scanf("%f", &persona[i].height);
        getchar();
        system("clear||cls");

    }
    puts("----------Mostrando la estructura------------");
    for(int i=0; i<T; i++){
        printf("Nombre: \t%s\n", persona[i].prenom);
        printf("Apellido \t%s\n", persona[i].nom);
        printf("Edad: \t\t %d\n", persona[i].age);
        printf("Peso: \t\t %.2f\n", persona[i].weight);
        printf("Estatura \t%.2f\n", persona[i].height);
        puts("---------------------------------------------");
    }
    int mayor = persona[0].height;
    int pos;
    for(int i = 0; i < T; i++)
	{
		if(persona[i].height > mayor)
			mayor = persona[i].height;
            pos = i;
	}
    printf("La persona con la altura mas alta fue: %s\n", persona[pos].prenom);
    return 0;
}