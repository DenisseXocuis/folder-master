#include <stdio.h>
int primo (int);

int main(){
    int num;
    scanf("%d", &num);
    if(primo(num) == 0)
        puts("no es primo");
    else 
        puts("si es primo");

    return 0;
}

int primo (int n){
    if (n == 1)
        return 0;
    else if (n ==2)
        return 1;

    else {
        for (int i =2; i* i <= n; i++)
            if((n % i)==0)
                return 0;
            else return 1;
    }
}