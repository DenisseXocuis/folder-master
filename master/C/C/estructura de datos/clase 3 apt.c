#include<stdio.h>

int main(){

    int a = 10;
    int *p = &a;
    int *q = p;
    printf("Variable: %d\n", a);
    printf("Apuntador p: %d\n", *p);
    printf("Apuntador q: %d\n", *q);
    putchar('\n');
    *p = 52;
    printf("Variable modificada por p: %d\n", a);
    *q = 34;
    printf("Variable modificada por q e imprimiendo  %d\n", *q);

    return 0;
}
