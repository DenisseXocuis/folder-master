#include <GL/glut.h>

// Función que se llama para dibujar en la ventana
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpia el buffer de color y profundidad

    // Dibuja un triángulo simple
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f( 0.5f, -0.5f);
    glVertex2f( 0.0f,  0.5f);
    glEnd();

    glFlush(); // Asegura que todos los comandos OpenGL se ejecuten
}

// Función que se llama al redimensionar la ventana
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); // Configura el sistema de coordenadas
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // Inicializa GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Configura el modo de visualización
    glutInitWindowSize(500, 500); // Tamaño de la ventana
    glutInitWindowPosition(100, 100); // Posición de la ventana
    glutCreateWindow("Mi Primer Programa con GLUT"); // Crea la ventana

    glClearColor(0.0, 0.0, 0.0, 0.0); // Configura el color de fondo
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); // Configura el sistema de coordenadas

    glutDisplayFunc(display); // Configura la función de dibujo
    glutReshapeFunc(reshape); // Configura la función de redimensionamiento

    glutMainLoop(); // Entra en el bucle principal de GLUT

    return 0;
}
