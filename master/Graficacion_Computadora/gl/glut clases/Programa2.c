#include <GL/glut.h>

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    //glTranslatef(1.0,1.0,0.0);

    glBegin(GL_QUADS);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, 0.5, -0.5);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); //porque ocupamos swap buffers

    glutInitWindowSize(600,600);
    
    glutInitWindowPosition(300,200);

    glutCreateWindow("ventana");

    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glViewport(0,0,500,500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glOrtho(1.0,1.0,1.0,1.0,1.0, -1.0); //cámara
    //gluPerspective(80.0, 1.0, 1.0, 100.00);
    glShadeModel(GL_FLAT);
    gluOrtho2D(0.0, 2.0, 0.0, 2.0);

    glutDisplayFunc(display);
    glutMainLoop();
}