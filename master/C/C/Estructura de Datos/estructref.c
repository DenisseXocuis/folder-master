#include<stdio.h>
#include<string.h>

//void *, función suma, recibir 2 param, dig tipo y que haga la suma, float, string and integer
struct persona{
    int edad;
    char *nombre;
    float peso;
};
void llenado(struct persona *per){
    scanf("%d", &per->edad);
    scanf("%f", &per->peso);
    strcpy(per->nombre, "deniso"); //or may be scanf idk
}
int main(){
    struct persona variable;
    llenado(&variable);
    return 0;   
}