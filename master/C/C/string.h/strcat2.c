#include<stdio.h>
#include<string.h>
#define MAX 20

int main(){
    char *s1, s2[MAX] = {"Buenas"};
    s1 = strcat(s2, " tardes");
    system("cls || clear");
    printf("s1 : %s \n", s2);


    return 0;
}


