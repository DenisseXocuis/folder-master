#include <stdio.h>
#include <stdlib.h>

// Funciones
void menu(int *n);
int** crearMatriz(int n);
void llenarMatriz(int n, int** matriz);
void mostrarMatriz(int n, int** matriz);
void liberarMatriz(int n, int** matriz);

int main() {
    int n;
    menu(&n);

    // Crear matriz de n x n
    int** matriz = crearMatriz(n);

    int opcion;
    do {
        menu(&n);
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                llenarMatriz(n, matriz);
                break;
            case 2:
                mostrarMatriz(n, matriz);
                break;
            case 3:
                printf("Ingrese la nueva dimensión de la matriz: ");
                scanf("%d", &n);
                liberarMatriz(n, matriz);
                matriz = crearMatriz(n);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 4);

    liberarMatriz(n, matriz);

    return 0;
}

void menu(int *n) {
    printf("\nMenú interactivo:\n");
    printf("1. Llenar la matriz\n");
    printf("2. Mostrar la matriz\n");
    printf("3. Redimensionar la matriz\n");
    printf("4. Salir\n");
    printf("Dimensiones actuales de la matriz: %dx%d\n", *n, *n);
}

int** crearMatriz(int n) {
    int** matriz = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        matriz[i] = (int*)malloc(n * sizeof(int));
    }
    return matriz;
}

void llenarMatriz(int n, int** matriz) {
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int n, int** matriz) {
    printf("Matriz:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void liberarMatriz(int n, int** matriz) {
    for (int i = 0; i < n; ++i) {
        free(matriz[i]);
    }
    free(matriz);
}
