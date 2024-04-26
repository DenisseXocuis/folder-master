#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *arr, int len);
void swap(int *arg, int *arg2);

int main(int argc, char **args){
    int *a, n, i=0;
    printf("Enter size of array\n");
    scanf("%d", &n);
    a = (int *) malloc(sizeof(a) * n);
    for (i = 0; i < n; i++){
        printf("Enter elements[%d]:\n", i);
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);
    printf("Sorted:\n");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    free(a);
    return 0;

}

void bubbleSort(int *arr, int len){
    for (int i = 0; i < len-1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void swap(int *arg, int *arg2){
    *arg += *arg2;
    *arg2 = *arg - *arg2;
    *arg -= *arg2;
}