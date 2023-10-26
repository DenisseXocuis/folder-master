#include<stdio.h>
void menu();
int suma(int n);

int main(){
    int num;
    menu();
    scanf("%d", &num);
    printf("La suma de los digitos pares de de %d es: %d", num , suma(num));


    return 0;
}

void menu(){
    puts("----------------------------------------------------------------");
    puts("Programa que dado un numero muestre la suma de los digitos pares");
    puts("----------------------------------------------------------------");
    printf("Ingresa un numero:\n>");
}

int suma(int n){ 
    int n1,n2, div;
    static int sum = 0;
    if(n > 0){
        n1 = n%10;
        div = n1 % 2;
        if (div ==  0) 
            sum += n1;
        suma(n / 10); 
    }
    else 
        return sum;
}

