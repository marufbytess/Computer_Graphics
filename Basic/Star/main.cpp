#include<GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(5,10);
    glVertex2f(2.5,7.5);
    glVertex2f(7.5,7.5);
    glEnd();

     glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(2.5,7.5);
    glVertex2f(0,5);
    glVertex2f(2.5,2.5);
    glEnd();

     glColor3f(1,0,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2f(2.5,2.5);
    glVertex2f(5,0);
    glVertex2f(7.5,2.5);
    glEnd();

     glColor3f(1,.5,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(7.5,2.5);
    glVertex2f(10,5);
    glVertex2f(7.5,7.5);
    glEnd();

     glColor3f(1,0,1);
    glBegin(GL_QUADS);
    glVertex2f(2.5,7.5);
    glVertex2f(2.5,2.5);
    glVertex2f(7.5,2.5);
    glVertex2f(7.5,7.5);
    glEnd();

    glFlush();
}

void init (void)
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,10,0,10,-1,1);
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Drawing Points");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
