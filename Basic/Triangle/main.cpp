
#include <GL/glut.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
 glBegin(GL_TRIANGLES);
        glVertex2f(2, 2);
        glVertex2f(8, 2);
        glVertex2f(5, 5);
    glEnd();
    glFlush();
}
void init(void)
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 10, 0, 10, -1, 1);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Simple Triangle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
