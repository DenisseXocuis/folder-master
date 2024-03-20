#include <stdio.h>
#define T 20
void inversa(char *);

int main() {
    char w[T];
    puts("Ingresa una palabra");
    gets(w);
    putchar('\n');
    inversa(w);

    return 0;
}

void inversa(char *cadena) { //olaNULL
    if (*cadena != NULL) {
        inversa(cadena + 1);
        printf("%c", *cadena);
    }
}
