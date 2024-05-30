#include<stdio.h>

int main(){
    int x= 75, y=33;
    printf("La operación and de %d AND %d = %d\n", x,y,x&y);
    printf("La operación or de %d OR %d = %d\n", x,y,x|y);
    printf("La operación xor de %d ^ %d = %d\n", x,y,x^y);
    printf("El desplazamiento izquierda de %d << %d = %d\n", x,2,x<<2);
    printf("El desplazamiento izquierda de %d << %d = %d\n", y,2,y<<2);
    printf("El desplazamiento derecha de %d << %d = %d\n", x,2,x>>2);
    printf("Complemento ~%d = %d\n", y,~y);

    return 0;
}