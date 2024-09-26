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
    static int sum = 0;
    if(inicio == 1){
        sum += 2;
        return primos(inicio+2,fin);
    }
    for(int i=2; i*i <= inicio; i++){
        if((inicio % i) == 0)
            return primos(inicio+1, fin);
    }
    if(inicio<=fin){
        sum+=inicio;
        return primos(inicio+1, fin);
    }
    else
        return sum;
}   