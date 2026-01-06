#include<gl/GLUT.h>
#include<cmath>

void init ()
{

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
    glLoadIdentity();
    glScalef(0,1,.0);
     glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f( 0.4f, -0.4f);
        glVertex2f( 0.4f,  0.4f);
        glVertex2f(-0.4f,  0.4f);
    glEnd();

}

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DdD")

    init();
    glutDialsFunc(display);
    glutMainLoop();
    return 0;
}
