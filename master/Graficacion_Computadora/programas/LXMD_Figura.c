#include <GL/glut.h>

/* GC */

void
init()
{
    glClearColor(0.0, 0.40, 0.40, 1.0);
    // definir color de display a negro
    glViewport(0,0,900,800);
    glMatrixMode(GL_PROJECTION);
    //modo proyección
    glLoadIdentity();
    //matriz de identidad
    //glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
    //glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
    glTranslatef(-1.6,-0.8,0.0);
    glShadeModel(GL_SMOOTH);
}

static void
display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.4, 0.2);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.8, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();

    glutSwapBuffers();
}

void
draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.85, 0.85, 0.85);
    glScalef(-0.5, -0.5, 0.0);

    //cabeza uvu 
    glBegin(GL_POLYGON);
        glVertex2f(6.0, 4.1);
        glColor3f (0.78, 0.78, 0.78);
        glVertex2f(7.0, 4.1);
        glColor3f (0.67, 0.67, 0.67);
        glVertex2f(7.4, 3.6);
        glColor3f (0.64, 0.64, 0.64);
        glVertex2f(7.9, 3.6);
        glVertex2f(8.2, 3.3);
        glVertex2f(8.3, 3.3);
        glColor3f (0.63, 0.63, 0.63);
        glVertex2f(8.3, 3.1);
        glColor3f (0.61, 0.61, 0.61);
        glVertex2f(8.3, 3);
        glColor3f (0.58, 0.58, 0.58);
        glVertex2f(8.2, 2.9);
        glColor3f (0.52, 0.51, 0.52);
        glVertex2f(8.1, 2.7);
        glColor3f (0.51, 0.51, 0.51);
        glVertex2f(7.8, 2.5);
        glVertex2f(7.5, 2.4);
        glVertex2f(7.1, 2.4);

        glColor3f (0.5, 0.5, 0.5);
        glVertex2f(7.0, 2.4);
        glVertex2f(6.3, 2.4);
        glVertex2f(6.2, 2.5);

        glColor3f (0.0, 0.0, 0.0);
        glVertex2f(6.0, 2.4);
        glVertex2f(5.9, 2.3);
        glVertex2f(5.8, 2.2);
        glVertex2f(5.5, 2.3);
        glVertex2f(5.4, 2.4);
        glVertex2f(5.3, 2.7);
        glVertex2f(5.3, 2.9);
        glVertex2f(5.3, 3.1);
        glVertex2f(5.4, 3.4);
        glVertex2f(5.6, 3.7);
        glVertex2f(5.6, 3.7);
    glEnd();

    //cuerpecito 1
    glColor3f (0.55, 0.55, 0.55);
    glBegin(GL_POLYGON);
        glVertex2f(6.2, 1.0);
        glVertex2f(6.5, 1.3);
        glVertex2f(6.5, 2.0);
        glVertex2f(6.2, 2.1);
        glVertex2f(6.3, 2.3);
        glColor3f (0.85, 0.85, 0.85);
        glVertex2f(7, 2.3);
        glVertex2f(7.1, 2.1);
        glVertex2f(7.3, 1.9);
        glVertex2f(7.3, 1.6);
        glVertex2f(7.4, 1.4);
        glVertex2f(7.4, 1.2);
        glVertex2f(7.4, 1.0);
        glVertex2f(7.3, 0.9);
        glVertex2f(7.2, 0.7);

        glVertex2f(6.8, 0.5);
        glVertex2f(6.3, 0.5);
        glVertex2f(6.0, 0.6);
        glVertex2f(5.8, 0.6);
        glVertex2f(6.1, 0.9);
    glEnd();

    //bracito
    glColor3f (0.85, 0.85, 0.85);
    glBegin(GL_POLYGON);
        glVertex2f(6.2, 1.5);
        glVertex2f(6.2, 1.7);
        glVertex2f(6.2, 2.1);
        glColor3f (0.78, 0.78, 0.78);
        glVertex2f(6.3, 2.2);
        glColor3f (0.58, 0.58, 0.58);
        glVertex2f(6.5, 2);
        glVertex2f(6.5, 1.3);
        glVertex2f(6.3, 1);
        glColor3f (0.58, 0.58, 0.58);
        glVertex2f(6.0, 1);
        glVertex2f(5.9, 1.2);
        glVertex2f(5.9, 1.4);
        glColor3f (0.58, 0.58, 0.58);
        glVertex2f(6.2, 1.5);
        glVertex2f(6.5, 1.5);
    glEnd();

    //piernita
    glColor3f (0.85, 0.85, 0.85);
    glBegin(GL_POLYGON);
        glVertex2f(7.5, 0.0);
        glVertex2f(6.8, 0.2);
        glVertex2f(6.8, 0.3);
        glColor3f (0.83, 0.83, 0.83);
        glVertex2f(6.8, 0.5);
        glColor3f (0.78, 0.78, 0.78);
        glVertex2f(6.0, 0.6);
        glVertex2f(6.2, 0.5);
        glColor3f (0.64, 0.64, 0.64);
        glVertex2f(6.2, 0.3);
        glVertex2f(6.0, 0.0);
        glVertex2f(7.5, 0.0);
        
    glEnd();

    //collarsito
    glColor3f (0.9, 0.0, 0.2);
    glBegin(GL_POLYGON);
        glVertex2f(7, 2.4);
        glVertex2f(7, 2.3);
        glColor3f (0.0, 0.0, 0.0);
        glVertex2f(6.3, 2.3);
        glVertex2f(6.3, 2.4);
    glEnd();

    //corbata
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(7, 2.3);
        glVertex2f(7.1, 2.1);
        glColor3f (0.0, 0.0, 0.0);
        glVertex2f(7.3, 1.9);
        glVertex2f(7.3, 1.6);
    glEnd();

    //contorno :
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(6.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(6.0, 4.1);
        glVertex2f(7.0, 4.1);
        glVertex2f(7.3, 3.8);
        glVertex2f(7.9, 3.6);
        glVertex2f(8.2, 3.3);
        glVertex2f(8.3, 3.1);
        glVertex2f(8.3, 3.0);
        glVertex2f(8.2, 2.9);
        glVertex2f(8.1, 2.7);
        glVertex2f(8.0, 2.6);
        glVertex2f(7.8, 2.5);
        glVertex2f(7.6, 2.4);
        glVertex2f(7.5, 2.4);
        glVertex2f(7.1, 2.4);
        glVertex2f(7.0, 2.4);
        glVertex2f(7.0, 2.4);
        glVertex2f(7.1, 2.1);
        glVertex2f(7.3, 1.9);
        glVertex2f(7.3, 1.6);
        glVertex2f(7.4, 1.4);
        glVertex2f(7.4, 1.2);

        glVertex2f(7.4, 1.0); // agregar a cuerpo
        glVertex2f(7.3, 0.9);
        glVertex2f(7.2, 0.7);
        glVertex2f(7.1, 0.6);
        glVertex2f(6.9, 0.5);
        //ya no agregar uvu
        glVertex2f(6.8, 0.5);
        
    glEnd();

    //contorno :
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(6.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(6.0, 4.1);
        glVertex2f(5.6, 3.7);
        glVertex2f(5.4, 3.4);
        glVertex2f(5.3, 3.1);
        glVertex2f(5.3, 2.9);
        glVertex2f(5.3, 2.7);
        glVertex2f(5.4, 2.4);
        glVertex2f(5.5, 2.3);
        glVertex2f(5.8, 2.2);  
        glVertex2f(5.9, 2.3); 
        glVertex2f(6.0, 2.4);
        glVertex2f(6.2, 2.5);
        glVertex2f(6.3, 2.4);
        glVertex2f(6.3, 2.3);
        glVertex2f(6.2, 2.1);
        glVertex2f(6.2, 1.7);
        glVertex2f(6.2, 1.5);
        glVertex2f(5.9, 1.4);
        glVertex2f(5.9, 1.2);
        glVertex2f(6.0, 1.0);
        glVertex2f(6.3, 1.0);
        glVertex2f(6.1, 0.9);
        glVertex2f(5.8, 0.6);
        glVertex2f(6.0, 0.6);
        glVertex2f(6.2, 0.5);
        glVertex2f(6.2, 0.3);
        glVertex2f(6.0, 0.0);
        glVertex2f(7.5, 0.0);
        glVertex2f(6.8, 0.2);
        glVertex2f(6.8, 0.3);
        glVertex2f(6.8, 0.5);
    glEnd();

    //correcion
    glColor3f(0.0, 0.40, 0.40);
    glBegin(GL_QUADS);
        glVertex2f(6.8, 0.5);
        glVertex2f(6.8, 0.3);
        glVertex2f(6.8, 0.2);
        glVertex2f(7.6, 0.0);
    glEnd();

    //nariz
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(8.22, 3.33);
        glVertex2f(8.33, 3.28);
        glVertex2f(8.34, 3.1);
        glVertex2f(8.25, 2.96);
        glVertex2f(8.27, 2.96);
        glVertex2f(8.29, 3.18);
    glEnd();

    //ojo
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(7.0, 3.5);
        glVertex2f(7.2, 3.5);
        glVertex2f(7.2, 3.2);
        glVertex2f(7.0, 3.2);
    glEnd();



    glutSwapBuffers();
}

int
main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(900, 800);
    glutInitWindowPosition(300,200);
    glutCreateWindow("ventana");

    init();
    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}