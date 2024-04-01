#include<stdio.h>

int main(){
    int *p=0;
    float *q=0;

    for(int i=0; i <10; i++){
        printf("\n%d\t%d\t%f", i, *p++);
    }
}