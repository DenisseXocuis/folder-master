#include<stdio.h>
#include <wchar.h>

int main(){

    int sum;

    for(int num = 2; num <= 100; num += 2)
    {
        sum += num;
    }
    printf("La suma %d\n", sum);
    
    return 0;
}