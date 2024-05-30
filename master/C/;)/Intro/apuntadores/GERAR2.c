#include <stdio.h>
#define T 20
void inversa(char *);

int main() {
    char w[T], *apt;
    puts("Ingresa una palabra");
    gets(w);
    putchar('\n');
    apt = w; 
    inversa(apt);
    return 0;
}

void inversa(char *cadena) { //olaNULL
    if (*cadena != NULL) {
        inversa(cadena + 1);
        printf("%c", *cadena);
    }
}
