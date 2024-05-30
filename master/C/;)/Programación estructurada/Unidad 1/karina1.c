#include <stdio.h>
#include <string.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int matricula;
    int claveCarrera;  // 01 Electrónica y Comunicaciones, 02 Mecatrónica, 03 Informática
};

int main() {
    struct Estudiante estudiantes[2];
    int cantidadEstudiantes[3] = {0}; // Inicializamos a cero para cada carrera

    // Registrar datos de los estudiantes
    for (int i = 0; i < 2; i++) {
        printf("Estudiante %d:\n", i + 1);
        printf("Nombre completo: ");
        scanf(" %[^\n]s", estudiantes[i].nombre);
        printf("Matrícula: ");
        scanf("%d", &estudiantes[i].matricula);
        printf("Clave de carrera (01 Electrónica, 02 Mecatrónica, 03 Informática): ");
        scanf("%d", &estudiantes[i].claveCarrera);

        // Incrementar el contador de estudiantes para la carrera correspondiente
        if (estudiantes[i].claveCarrera >= 1 && estudiantes[i].claveCarrera <= 3) {
            cantidadEstudiantes[estudiantes[i].claveCarrera - 1]++;
        } else {
            printf("Clave de carrera no válida. No se contará en ninguna carrera.\n");
        }
    }

    // Mostrar la cantidad de estudiantes por cada carrera
    printf("\nCantidad de estudiantes por carrera:\n");
    printf("Electrónica y Comunicaciones: %d estudiantes\n", cantidadEstudiantes[0]);
    printf("Mecatrónica: %d estudiantes\n", cantidadEstudiantes[1]);
    printf("Informática: %d estudiantes\n", cantidadEstudiantes[2]);

    return 0;
}
