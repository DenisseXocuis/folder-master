#include<stdio.h>
//void llenado(struct persona *);
struct persona{
    int edad;
    char *nombre;
    float peso;
};
int main(){
    struct persona per;
    //llenado(&per);
    int o = 23;
    float a = 1.2;
    float dato = o;
    float suma = a + dato;

    printf("%.2f", suma);
    return 0;   
}
/* void llenado(struct persona *per){
    scanf("%d", &per->edad);
    scanf("%f", &per->peso);
    scanf("%s", &per->nombre);
} */