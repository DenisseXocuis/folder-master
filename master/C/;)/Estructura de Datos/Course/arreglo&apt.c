#include<stdio.h>
//atraves de p incrementar
int main(int argc, int **argv){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = arr;
    printf("Incrementando los valores del arreglo mediante apuntador\n");
    while(*p != NULL){
        *p+=1;
        printf("%d\n", *p);
        p++;
    }
    return 0;
}