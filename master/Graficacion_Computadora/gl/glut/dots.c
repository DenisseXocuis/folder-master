#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

// Variable para controlar si la ventana gráfica está activa
int showDisplay = 0;

// Función de visualización
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Aquí puedes dibujar lo que desees
    // Ejemplo simple: dibujar un triángulo
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.0, 0.5);
    glEnd();

    glutSwapBuffers();
}

// Función de manejo de teclado
void keyboard(unsigned char key, int x, int y) {
    if (key == 13) { // ENTER
        glutDestroyWindow(glutGetWindow());
        showDisplay = 0; // Marcar que la ventana gráfica ya no está activa
    }
}

// Inicialización de OpenGL
void initGL() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

// Mostrar la ventana gráfica
void showDisplayWindow() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Display");

    initGL();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    // No usar glutMainLoop(); Aquí solo procesamos eventos.
    while (showDisplay) {
        glutMainLoopEvent(); // Procesar eventos de la ventana actual
    }
}

// Función del menú
void menu() {
    int option;
    while (1) {
        printf("[1]. Crear mas vertices\n");
        printf("[2]. Triangulos Creados\n");
        printf("[3]. Ver adyacencias y coordenadas\n");
        printf("[4]. Mostrar graficamente\n");
        printf("[5]. About\n");
        printf("[0]. Salir del programa\n");
        printf("Elija una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Implementa tu código para crear más vértices
                break;
            case 2:
                // Implementa tu código para mostrar triángulos creados
                break;
            case 3:
                // Implementa tu código para ver adyacencias y coordenadas
                break;
            case 4:
                showDisplay = 1;
                showDisplayWindow();
                break;
            case 5:
                // Implementa tu código para "About"
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Opción inválida\n");
                break;
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    menu();
    return 0;
}
