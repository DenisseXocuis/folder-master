#include <stdio.h>
#include <string.h>
#include <ctype.h>

void find_last_word(const char *str) {
    int length = strlen(str);
    int i = length - 1;

    // Saltar espacios en blanco al final de la cadena
    while (i >= 0 && isspace(str[i])) {
        i--;
    }
    
    // Moverse al principio de la última palabra
    while (i >= 0 && !isspace(str[i])) {
        i--;
    }
    
    // Imprimir la última palabra
    while (i < length - 1 && !isspace(str[i + 1])) {
        printf("%c", str[i + 1]);
        i++;
    }
    printf("\n");
}

int main() {
    char str[] = "Esto es una cadena de ejemplo.";
    find_last_word(str);
    return 0;
}
