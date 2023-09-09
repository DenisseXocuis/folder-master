#include<stdio.h>

int main(){

    int a,b, sum1 = 0,sum2 = 0; 
    printf("Ingrese dos numeros \n>");
    scanf("%d %d", &a,&b); 

    for(int i = 1, j = 1; i <= a && j <= b; i++ ){
        if(a % i == 0)
            if (i <= a)
                sum1 += i;
        else if(b % i == 0)
            if (j <= b)
                sum2 += j; 
    }

    if(sum2 == a && sum2 == b)
        printf("Los numeros son amigos");
    else 
        printf("NO son numeros amigos");

    return 0;
}