#include<stdio.h>
#define T 30
void inversa(char *);

int main(){
    char w[T], p;
    puts("PALABRA:");
    gets(w);

    p = w[0];

    inversa(p);
    
    return 0;
}

void inversa(char *si){
    if(*si)
        si++;
}