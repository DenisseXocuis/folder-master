#include<stdio.h>

int main(){

    int  m=3,n=5,*p = &m,*q = &n;
    printf("%d\n", q-p);
    printf("%d", *q-*p);



}