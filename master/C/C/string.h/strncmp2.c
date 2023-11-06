#include<stdio.h>
#include<string.h>
#define MAX 10

int main(){
    char st1[MAX] = {"Hola"}, st2[MAX] = {"HOLA"};
    int *apt;
    apt = strncmp(st1,st2,1);
    system("cls || clear");
    if(!apt) puts("Las dos cadenas son iguales");
    else puts("Las dos cadenas son diferentes");
}



