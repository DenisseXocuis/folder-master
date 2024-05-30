#include<stdio.h>
#define T 30
void rev(char *, char *, int *);

int main(){
    char pal[T], *p;
    puts("PALABRA");
    gets(pal);
    p = pal;

    while(*p) //movemos el apuntador al final
        p++;

    p--; //quita null
    
    rev(pal,*p,0);
    //huail

    puts(pal);
    return 0;
}

void rev(char *vec, char *ap, int *i) { // Corrige la firma de la función
    if (*ap == '\0') { // Compara con '\0' en lugar de NULL
        return;
    } else {
        vec[(*i)++] = *ap;
        rev(vec, --ap, i);
    }
}