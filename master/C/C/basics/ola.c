#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m=7;
    n = !(m==9); //!m es lo mismo que m = 0, not m=0, not, si es falsa la condicion da 1

    printf("%d\n",n);

    return 0;
}