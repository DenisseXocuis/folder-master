#include<stdio.h>
#define T 30
void inversa(char *);

int main(){
    char *w, p;
    puts("PALABRA:");
    gets(w);

    p = w;

    inversa(p);
    
    return 0;
}

void inversa(char *si){
    if(*si)
        si++;
}