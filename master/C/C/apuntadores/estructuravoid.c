#include <stdio.h>
struct fecha{
    unsigned int dia, mes, anyo;
};

struct persona{
    char nombre [20];
    unsigned int edad;
    int altura;
    int peso;
    struct fecha fec;
};

struct personaempleado{
    struct persona unapersona;
    unsigned int salario;
    unsigned int horas_por_semana;
};

    /*prototipos de funciones*/
void entrada(struct personaempleado *p);
void muestra(struct personaempleado up);

void main(){
  
    struct personaempleado p; 
    p = unapersona.nombre;
    entrada(&p);
    muestra(p);

}

void entrada(struct personaempleado *p){
    puts("Introduzca un nombre");
    gets(p);
  
}