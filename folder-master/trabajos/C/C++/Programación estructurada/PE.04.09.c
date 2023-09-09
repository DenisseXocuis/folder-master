#include<stdio.h>

int main(){
    int a,b,i = 1,sum = 0, sum2 = 0;

    printf("Ingrese dos números enteros\n>");
    scanf("%d %d", &a, &b); 

    /*Divisores del primer num*/
    while(i <= a/2){
        if(a % i == 0){
            sum += i;
            
        }
          i++;

    }

    i = 1;

    /*Divisores del segundo num*/
    while(i <= b/2){
        if(b%i == 0) {
            sum2 += i; 
        }
        i++;

    }

    if(sum2 == a && sum == b)
        printf("Los números son amigos");
    else 
        printf("NO son numeros amigos");

    return 0;
}