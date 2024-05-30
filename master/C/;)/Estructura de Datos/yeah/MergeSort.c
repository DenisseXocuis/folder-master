#include<stdio.h>
#include<stdlib.h>

void mergesort();
void merge();

int main(){
    int *a, n, i=0;
    printf("Enter size of array\n");
    scanf("%d", &n);
    a = (int *) malloc(sizeof(a) * n);
    for (i = 0; i < n; i++){
        printf("Enter elements[%d]:\n", i);
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n-1);
    printf("Sorted:\n");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}

void mergesort(int *a, int first, int last){
    int mid;
    if (first < last){
        mid = (first+last) / 2;
        mergesort(a, first, mid);
        mergesort(a, mid+1, last);
        merge(a, first, mid, last);
    }
}

void merge(int *array, int first, int mid, int last){
    int *temp = (int *) malloc(sizeof(array) * sizeof(*array));
    int i, j, k;
    i=first;
    j=mid+1;
    k=first;
    while (i<=mid && j<=last){
        if(array[i]<=array[j]){
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }
    if(i>mid){
        while (j<=last){
            temp[k++] = array[j++];
        }
    } else {
        while (i<=mid){
            temp[k++] = array[i++];
        }
    }
    for (i=first;i<=last; i++){
        array[i] = temp[i];
    }
    free(temp);
}