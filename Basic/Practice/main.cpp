#include<gl/Glut.h>
#include<cmath>

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,20,0,20);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<360;i++)
    {
        float angle = i*3.1416/180;
        float x = 10+ 5*cos(angle);
        float y = 10+ 5*sin(angle);
        glVertex2f(x,y);
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("create");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
