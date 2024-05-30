#include<stdio.h>
#include<string.h>

struct persona{
    int edad;
    char *nombre;
    float peso;
};
void llenado(struct persona *per){
    scanf("%d", &per->edad);
    scanf("%f", &per->peso);
    scanf("%s", &per->nombre);
    //strcpy(per->nombre, "deniso"); //or may be scanf idk
}
int main(){

    struct persona variable;
    llenado(&variable);
    return 0;   
}