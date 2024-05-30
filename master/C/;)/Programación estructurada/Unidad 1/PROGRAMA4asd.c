#include <stdio.h>
#include <stdbool.h>

bool esPrimo(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int inicio, fin, suma = 0;

    printf("Ingresa el inicio del rango: ");
    scanf("%d", &inicio);
    printf("Ingresa el fin del rango: ");
    scanf("%d", &fin);

    // Validar que el rango sea válido
    if (inicio >= fin || inicio < 0) {
        printf("El rango no es válido. Asegúrate de que el inicio sea menor que el fin y ambos sean no negativos.\n");
        return 1;
    }

    for (int i = inicio; i <= fin; i++) {
        if (esPrimo(i)) {
            suma += i;
        }
    }

    // Mostrar el resultado
    printf("La suma de números primos en el rango de %d a %d es: %d\n", inicio, fin, suma);

    return 0;
}
