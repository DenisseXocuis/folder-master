#include <stdio.h>
#define T 5
int main(){
    int vector[T] = {1,2,3,4,5}, *p, **q;

    p = &vector;
    q = &p;

    while(**q){
        printf("%d", **q);
        (*q)++; //moviendo a p desde q de forma indirecta
    }
    return 0;
}