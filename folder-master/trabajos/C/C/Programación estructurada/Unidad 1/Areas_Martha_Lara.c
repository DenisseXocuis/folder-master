#include<stdio.h>
#include<stdlib.h>
#define pi 3.1416
float cir(float r);
float tri(float b, float h);
float cua(float l);
float rec(float b, float h);
float pen(float l, float ap);
float trap(float B, float b, float h);
float rombo(float B, float b);
float romboide(float B, float h);
void menu();
void menuerror();
int main(){
    int op,e;
    float r,b,h,l,ap,B;
    do{
        system("clear||cls");
        fflush(stdin);
        menu();
        scanf("%d", &op);
        if(op<=9 && op>0)
            e=1;
        else if(op==0)
            e=0;
        switch(op){
            case 1: puts("Ingrese el radio: ");
                    scanf("%f", &r);
                    printf("El area del circulo es de: %g cm²", cir(r)); 
            break;
            case 2: puts("Ingrese la base y la altura: ");
                    scanf("%f %f",&b,&h);
                    printf("El area del triangulo es de: %g cm²", tri(b,h));
            break;
            case 3: puts("Ingrese el lado: ");
                    scanf("%f", &l);
                    printf("El area del cuadrado es de %g cm²", cua(l));
            break;
            case 4: puts("Ingrese la base y la altura: ");
                    scanf("%f %f", &b,&h);
                    printf("El area del rectangulo es de %g cm²", rec(b,h));
            break;
            case 5: puts("Ingrese el lado y el apotema: ");
                    scanf("%f %f", &l, &ap);
                    printf("El area del pentagono es de %g cm²", pen(l,ap));
            break;
            case 6: puts("Ingrese la base mayor, base menor y la altura: ");
                    scanf("%f %f %f", &B, &b,&h);
                    printf("El area del trapecio es de %g cm²", trap(B,b,h));
            break;
            case 7: puts("Ingrese la diagonal mayor y la diagonal menor: ");
                    scanf("%f %f", &B, &b);
                    printf("El area del rombo es de %g cm²", rombo(B, b));
            break;
            case 8: puts("Ingrese la base y la altura: ");
                    scanf("%f %f", &B, &h);
                    printf("El area del romboide es de %g cm²", romboide(B,h));
            break;
            case 9: system("clear");
                    putchar('\n');
                    puts("Programa para calcular areas by Lara Xocuis Martha Denisse©\nProgramacion estructurada");
            break;
            case 0: puts("Saliendo.....");
            break;
            default:system("clear");
                    menuerror();
                    e=2;              
            }
    if(e==1){
        puts("\nIngrese cualquier tecla para continuar"); 
        getchar();
        getchar();
        }
    else if(e==2){
        puts("Ingrese cualquier tecla para volver a intentar");
        getchar();
        getchar();
        }
    }while(op);
    return 0;
}
void menu(){
    puts("--------------------------------");
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
    puts("[9] Acerca de...");
    puts("[0] Salir");
    printf("Opcion: \n > ");
}
void menuerror(){
    puts("--------------------------------");
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
    puts("[9] Acerca de...");
    puts("[0] Salir");
    printf("Opcion:");
    printf("\n > ");
    puts("¡ERROR! : Opcion no valida, ingrese una de las opciones disponibles");
    putchar('\n');
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