#include<GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);

    glBegin(GL_QUADS);

        glVertex2f(0.1f, 0.1f);
        glVertex2f(0.3f, 0.1f);
        glVertex2f(0.3f, 0.3f);
        glVertex2f(0.1f, 0.3f);
        glEnd();

        glPushMatrix();
        glTranslatef(0.5f,0.0f,0.0f);
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(0.3f, 0.1f);
        glVertex2f(0.3f, 0.3f);
        glVertex2f(0.1f, 0.3f);
        glEnd();

        glPopMatrix();
        glPushMatrix();

        glFlush();

}

void init (void)
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,1,0,1,-1,1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Transformations Example");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
