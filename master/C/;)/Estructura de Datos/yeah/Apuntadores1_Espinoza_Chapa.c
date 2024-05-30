#include<stdio.h>
int main(){
    int n, *p1, **p2;
    printf("Ingrese el valor de n:\n");
    scanf("%d", &n);
    p1 = &n;
    p2 = &p1;
    printf("El valor del apuntador[1] es: %d\n", *p1);
    printf("El valor del apuntador[2] es: %d\n", **p2);
    printf("Modifique el valor de n:\n");
    scanf("%d", &n);
    printf("El valor del apuntador[1] es: %d\n", *p1);
    printf("El valor del apuntador[2] es: %d\n", **p2);
    return 0;
}