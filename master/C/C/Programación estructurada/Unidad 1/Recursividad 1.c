#include<stdio.h> //funcion parametro por valor, parametro por referencia
int suma(int n);
int sum(int n);
signed long long int fac(int n);

int main(){
    int n;
    printf("Ingresa un numero\n>");
    scanf("%d", &n);
    printf("Suma : %d", suma(n)); //suma normal
    putchar('\n');
    printf("Suma: %d", sum(n)); //suma al reverso
    putchar('\n');
    printf("Factorial: %llu", fac(n)); //factorial
    putchar('\n');


    return 0;
}
/*con for*/
int suma(int n){
    int sum2 = 0;
    for(int i = 0; i <= n; i++){
        sum2 += i;
    }
    return sum2;
}
/*al reverso*/
int sum(int n){

    if(n>0)
        return n + sum(n-1);
}
/*factorial*/
long long int fac(int n){

    if(n>1) return n * fac(n-1);
    else return 1;
}