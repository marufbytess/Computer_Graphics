#include<gl/GLUT.h>
#include<cmath>

void initGL()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,100,0,100);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        float angle = i*3.1416/180;
        float x = 50+ 20*cos(angle);
        float y = 50+ 20*sin(angle);
        glVertex2f(x,y);
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(600,600);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Create window");

    initGL();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
