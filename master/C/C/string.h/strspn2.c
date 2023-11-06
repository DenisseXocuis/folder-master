#include <stdio.h>
#include <string.h>

int main() {
    const char *s1 = "12345abcde", *ch = "1234567890";
    size_t lon = strspn(s1, ch);

    if (lon > 0) {
        printf("Longitud de la cadena que contiene los caracteres : %zu\n", lon);
    } else {
        printf("No se encuentra\n");
    }
    return 0;
}



