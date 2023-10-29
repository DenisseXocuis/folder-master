#include<stdio.h>
#define T 20
void *concatenacion(char*, char*);

int main(){
    char w[T], w2[T];
    puts("Ingrese una cadena");
    gets(w);
    puts("Ingrese otra cadena para concatenar");
    gets(w2);
    printf("%s", concatenacion(w,w2));

    return 0;
}

void *concatenacion(char *w, char *w2){
    printf("%s %s\n", w,w2);
}