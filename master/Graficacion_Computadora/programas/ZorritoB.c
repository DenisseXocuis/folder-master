#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define ABOUT "/-----------------------------\\\n" \
              "| Dummy:                      |\n" \
              "|                             |\n" \
              "| Martinez Schleske Alan      |\n" \
              "| Ingenieria en Informatica   |\n" \
              "| Universidad Veracruzana (c) |\n" \
              "|                             |\n" \
              "| (.2024)                     |\n" \
              "\\-----------------------------/\n" \
              "  /                            \n" \
              " /                             \n"

#define RESERVAR_TIPO(tipo) \
    struct _##tipo *nuevo = NULL; \
    if (!(nuevo = malloc(sizeof(*nuevo)))); \
    {\
        fprintf(stderr, "ERROR: espacio no disponible\n");\
        exit(1);\
    }

// Startup of C program and credits to the programmer
void __attribute__((constructor)) init(void) {
    system("clear||cls");
    printf(ABOUT
           "( Presione Enter para empezar...");
    while (getchar() != '\n');
}

void
generarPiernas(void)
{
    // Primera pierna
    glColor3f(33.0, 12.0, 2.0);
    glVertex2f(8.0, 0.0);
    glVertex2f(8.84, 0.41);
    glVertex2f(8.42, 0.47);

    glColor3f(102.0, 43.0, 16.0);
    glVertex2f(8.84, 0.41);
    glVertex2f(8.42, 0.47);
    glVertex2f(8.2, 3.33);

    glColor3f(46.0, 16.0, 2.0);
    glVertex2f(8.42, 0.47);
    glVertex2f(8.2, 3.33);
    glVertex2f(9.5, 3.69);

    glColor3f(69.0, 24.0, 3.0);
    glVertex2f(8.2, 3.33);
    glVertex2f(9.5, 3.69);
    glVertex2f(9.48, 5.72);

    glColor3f(145.0, 60.0, 20.0);
    glVertex2f(9.5, 3.69);
    glVertex2f(9.48, 5.72);
    glVertex2f(7.24, 5.76);

    //Segunda pierna
    glColor3f(33.0, 12.0, 2.0);
    glVertex2f(16.0, 0.0);
    glVertex2f(16.75, 0.34);
    glVertex2f(16.44, 0.43);

    glColor3f(102.0, 43.0, 16.0);
    glVertex2f(16.75, 0.34);
    glVertex2f(16.44, 0.43);
    glVertex2f(17.19, 2.18);

    glColor3f(46.0, 16.0, 2.0);
    glVertex2f(16.44, 0.43);
    glVertex2f(17.19, 2.18);
    glVertex2f(16.31, 3.96);

    glColor3f(69.0, 24.0, 3.0);
    glVertex2f(17.19, 2.18);
    glVertex2f(16.31, 3.96);
    glVertex2f(17.38, 3.58);

    glColor3f(145.0, 60.0, 20.0);
    glVertex2f(16.31, 3.96);
    glVertex2f(17.38, 3.58);
    glVertex2f(18.07, 5.34);

    glColor3f(120.0, 54.0, 23.0);
    glVertex2f(17.38, 3.58);
    glVertex2f(18.07, 5.34);
    glVertex2f(18.41, 4.79);
}

void
generarCuerpo(void)
{
    glColor3f(230.0, 90.0, 25.0);

    glVertex2f(16.31, 3.96);
    glVertex2f(18.07, 5.34);
    glVertex2f(18.0, 6.95);

    glVertex2f(16.31, 3.96);
    glVertex2f(18.0, 6.95);
    glVertex2f(14.0, 6.0);
}

void
display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glScalef(-0.3, -0.3, 0.0);

    glBegin(GL_TRIANGLES);
    // Primera pierna
        glVertex2f(8.0, 0.0);
        glVertex2f(8.84, 0.41);
        glVertex2f(8.42, 0.47);
        
        glColor3f(0.0, 2.0, 0.0);
        glVertex2f(8.84, 0.41);
        glVertex2f(8.42, 0.47);
        glVertex2f(8.2, 3.33);
        
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(8.42, 0.47);
        glVertex2f(8.2, 3.33);
        glVertex2f(9.5, 3.69);
        
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(8.2, 3.33);
        glVertex2f(9.5, 3.69);
        glVertex2f(9.48, 5.72);
        
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(9.5, 3.69);
        glVertex2f(9.48, 5.72);
        glVertex2f(7.24, 5.76);
        
        //Segunda pierna
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(16.0, 0.0);
        glVertex2f(16.75, 0.34);
        glVertex2f(16.44, 0.43);
        
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(16.75, 0.34);
        glVertex2f(16.44, 0.43);
        glVertex2f(17.19, 2.18);
        
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(16.44, 0.43);
        glVertex2f(17.19, 2.18);
        glVertex2f(16.31, 3.96);
        
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(17.19, 2.18);
        glVertex2f(16.31, 3.96);
        glVertex2f(17.38, 3.58);
        
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(16.31, 3.96);
        glVertex2f(17.38, 3.58);
        glVertex2f(18.07, 5.34);
        
        glColor3f(120.0, 54.0, 23.0);
        glVertex2f(17.38, 3.58);
        glVertex2f(18.07, 5.34);
        glVertex2f(18.41, 4.79);
        glColor3f(230.0, 90.0, 25.0);
        
        glVertex2f(16.31, 3.96);
        glVertex2f(18.07, 5.34);
        glVertex2f(18.0, 6.95);
        
        glVertex2f(16.31, 3.96);
        glVertex2f(18.0, 6.95);
        glVertex2f(14.0, 6.0);

    glEnd();

 glPointSize(5.0);
    glBegin(GL_POINTS);
        glVertex2f(16.0,2.0);
        glVertex2f(0.0,0.0);
        glVertex2f(5.0,0.0);
        glVertex2f(14.0,0.0);
    glEnd();
    
    glTranslatef(2.0, 2.0, 0.0);

    glutSwapBuffers();
}

int
main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(900, 800);
    glutInitWindowPosition(600, 600);
    glutCreateWindow("Cuadrado");

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glViewport(0, 0, 900, 800);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* glOrtho(-1, 1, -1, 1, -1, 1); */
    /* gluPerspective(100.0, 1.0, 1.0, -100.0); */
    /* gluOrtho2D(10.0, -0.5, 10.0, 0.0); // trabajar con ortho2d */
    // // Cambia modo de representar las texturas o colores en la figura
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
