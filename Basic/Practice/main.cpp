#include<gl/GLUT.h>

void init()
{
    glClearColor(0,0,0,1);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.3f, -0.3f);
        glVertex2f( 0.3f, -0.3f);
        glVertex2f( 0.3f,  0.3f);
        glVertex2f(-0.3f,  0.3f);
    glEnd();

    glLoadIdentity();
    glColor3f(0,1,0);
        glScalef(1.5f,.5f,1.0f);

        glBegin(GL_QUADS);

    glVertex2f(-0.3f, -0.3f);
        glVertex2f( 0.3f, -0.3f);
        glVertex2f( 0.3f,  0.3f);
        glVertex2f(-0.3f,  0.3f);
    glEnd();
    glFlush();

}

int main(int a, char **b)
{
    glutInit(&a,b);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("DDD");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
