#include<gl/GLUT.h>

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluOrtho2D(0,30,0,30);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(1,0,0);

    glVertex2f(2,2);
    glVertex2f(8,2);
    glVertex2f(8,8);
    glVertex2f(2,8);

    glEnd();
    glFlush();

    }



int main(int a, char **b)
{
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Quad");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
