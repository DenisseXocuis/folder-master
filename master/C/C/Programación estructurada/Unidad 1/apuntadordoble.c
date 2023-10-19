#include<stdio.h>

int main(){
    int x=10, *p, **q, ***r;
    p = &x;
    q = &p;
    r = &q;

    printf("x = %d \n", x);
    printf("p = %d \n", *p);
    printf("q = %d \n", **q);
    printf("r = %d \n", ***r);

    ***r=20;
    putchar('\n');
    printf("x = %d \n", x);
    printf("p = %d \n", *p);
    printf("q = %d \n", **q);
    printf("r = %d \n", ***r);

    return 0;
}