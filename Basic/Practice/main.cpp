#include<gl/GLUT.h>

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glLoadIdentity();
    glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f( 0.4f, -0.4f);
        glVertex2f( 0.4f,  0.4f);
        glVertex2f(-0.4f,  0.4f);
    glEnd();

    glColor3f(0,1,0);
    glScalef(1.5,0.5,0);
    glLoadIdentity();
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.4f);
        glVertex2f( 0.4f, -0.4f);
        glVertex2f( 0.4f,  0.4f);
        glVertex2f(-0.4f,  0.4f);
    glEnd();

    glFlush();
}

int main(int a, char **b)
{
    glutInit(&a, b);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Done");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
