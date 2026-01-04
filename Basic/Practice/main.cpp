#include<gl/GLUT.h>
#include<cmath>

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++)
    {
        float angle = i*3.c1416/180;
        float x = 40+ 20*cos(angle);
        float y = 40+ 20*sin(angle);
        glVertex2f(x,y);
    }

    glEnd();
    glFlush();
    }

int main(int a, char **b)
    {
        glutInit(&a,b);
        glutInitWindowSize(600,600);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("CIRCLE");

        init();
        glutDisplayFunc(display);
        glutMainLoop();

        return 0;
    }
