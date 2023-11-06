#include<stdio.h>
int factorial(int);

int main(){
    int num;
    printf("ingresa un numero: \n>");
    scanf("%d", &num);
    printf("el factorial de %d es %d", num, factorial(num));

    return 0;
}

int factorial(int n){
    return ( n>=1 ? (n * factorial(n-1)): 1);
}