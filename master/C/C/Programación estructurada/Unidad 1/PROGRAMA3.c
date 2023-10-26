#include<stdio.h>
int divisores(int n, int div);

void menu();

int main(){
    int num;
    scanf("%d", &num);
    int i = num;
    printf("La suma de los divisores de %d es: %d", num , divisores(num,i));

}

void menu(){
    puts("------------------------------------------------------------------------");
    puts("Programa que dado un numero muestra la suma de sus divisores o multiplos");
    puts("------------------------------------------------------------------------");
    printf("Ingresa un numero:\n>");
}

int divisores(int n , int div){
    if(div == 1)
        return 1;
    else if((n % div) == 0)
        return div + divisores(n, div-1);
    else
        return divisores(n, div-1);
}
