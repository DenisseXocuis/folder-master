#include<stdio.h>
void menu();
int primos(int inicio,int fin);

int main(){
    int a,b;
    menu();
    scanf("%d", &a);
    scanf("%d", &b);
    printf("La suma de los números primos de %d hasta %d es: %d",a,b, primos(a,b));


    return 0;
}

void menu(){
    puts("-----------------------------------------------------------------------");
    puts("Programa que dado un rango de números sume los números primos del rango");
    puts("-----------------------------------------------------------------------");
    printf("Ingresa un rango a-b:\n>");
}

int primos(int inicio,int fin){
    int sum = 0;
    while(inicio<=fin){
        if(((inicio % inicio) == 0) && ((inicio % 1) == 0))
            if((inicio%2) != 0){
                sum += inicio;
                inicio++;
            }
    }
    return sum;
}