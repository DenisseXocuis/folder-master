#include<stdio.h>
#define T 30
int main(){
    char w[T], *p;

    puts("PALABRA"); //ola NULL
    gets(w);
    p = w; //o

    while(*p){
        p++;
    }
    --p;
    while(*p){
        /* printf("%c", *p); */
        putchar(*p);
        p--;
    }
    
    return 0;
}