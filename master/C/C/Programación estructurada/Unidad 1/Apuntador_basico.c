#include<stdio.h>

int main(){

    int num = 10;
    int *a = &num;

    printf("%d\n", *a);

    *a = 12;

    printf("%d\n", num);

    return 0;
}
