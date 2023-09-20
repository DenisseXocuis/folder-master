/*Funciones por parámetro por valor y retorno de valor
CÁLCULO DE ÁREAS*/
#include<stdio.h>
#define pi 3.1416
float cir(float r); //1
float tri(float b, float h); //2
float cua(float l); //3
float rec(float b, float h); //4
float pen(float l, float ap); //5
float trap(float B, float b, float h); //6
float rombo(float B, float b); //7
float romboide(float B, float h); //8
void menu();
int main(){
    int op,op2;
    float r,b,h,l,ap,B;
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1: puts("Ingrese el radio: ");
                    scanf("%f", &r);
                    printf("El area del circulo es de: %g cm² \n", cir(r));
            break;
            case 2: puts("Ingrese la base y la altura: ");
                        scanf("%f %f",&b,&h);
                        printf("El area del triangulo es de: %g cm²\n", tri(b,h));
            break;
            case 3: puts("Ingrese el lado: ");
                        scanf("%f", &l);
                        printf("El area del cuadrado es de %g cm²\n", cua(l));
            break;
            case 4: puts("Ingrese la base y la altura: ");
                        scanf("%f %f", &b,&h);
                        printf("El area del rectangulo es de %g cm²\n", rec(b,h));
            break;
            case 5: puts("Ingrese el lado y el apotema: ");
                        scanf("%f %f", &l, &ap);
                        printf("El area del pentagono es de %g cm²\n", pen(l,ap));
            break;
            case 6: puts("Ingrese la base mayor, base menor y la altura: ");
                        scanf("%f %f %f", &B, &b,&h);
                        printf("El area del trapecio es de %g cm²\n", trap(B,b,h));
            break;
            case 7: puts("Ingrese la diagonal mayor y la diagonal menor: ");
                        scanf("%f %f", &B, &b);
                        printf("El area del rombo es de %g cm²\n", rombo(B, b));
            break;
            case 8: puts("Ingrese la base y la altura: ");
                        scanf("%f %f", &B, &h);
                        printf("El area del rombo es de %g cm²\n", romboide(B,h));
            break;
            case 0: puts("\nSaliendo.....\n");
            break;
            default:puts("\nERROR: Opcion no valida\n");
            }
        }while(op);

    return 0;
}

void menu(){
    puts("\n--------------------------------");
    puts("--Programa para calcular areas--");
    puts("--------------------------------");
    puts("[1] Circulo");
    puts("[2] Triangulo");
    puts("[3] Cuadrado");
    puts("[4] Rectangulo");
    puts("[5] Pentagono");
    puts("[6] Trapecio");
    puts("[7] Rombo");
    puts("[8] Romboide");
    puts("[0] Salir");
    printf("Opcion: \n > ");

}

//CIRCULO
float cir(float r){
    return pi *r*r;
}
//TRIANGULO
float tri(float b, float h){
    return (b*h)/2;
}
//CUADRADO
float cua(float l){
    return l*l;
}
//RECTANGULO
float rec(float b, float h){
    return b*h;
}
//PENTAGONO
float pen(float l, float ap){
    return ((5*l) * ap) / 2;
}
//TRAPECIO 
float trap(float B, float b, float h){
    return ((B+b) * h)/2;
}
//ROMBO 
float rombo(float B, float b){
    return (B*b) / 2;
}
//ROMBOIDE
float romboide(float B, float h){
    return B*h;
}