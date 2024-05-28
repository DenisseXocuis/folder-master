#include<stdio.h>


int main(){
    int n=5, *apt, **apt2;
    apt = &n;

    printf("%d\n", n);
    printf("%d\n", *apt);

    *apt = 4;

    printf("%d\n", n);
    printf("%d\n", *apt);

    apt2 = &apt;
    //*apt2 = apt;
    **apt2 = 3;

    printf("%d\n", n);
    printf("%d\n", *apt);

    return 0;
}