#include<stdio.h>
#include<string.h>

int main(int argc, char **argv){
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int ma[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};


    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%i ", ma[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
    for(int i=0; i<45; i++){
        printf("%i ", ma[0][i]);
        putchar('\n');
    }



    return 0;
}