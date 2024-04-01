#include<stdio.h>
#define T 30
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

void *concatenacion(char *c1, char *c2){
    while(*c1++)
        *c1++;
    while(*c2)
        *c1++ = *c2++;
    *c1 = '\0';
}