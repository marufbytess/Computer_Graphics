#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // 🔄 Rotate 30 degree CLOCKWISE
    glRotatef(-30.0f, 0, 0, 1);   // negative = clockwise (Z-axis)

    glColor3f(1, 0, 0);           // Red triangle
    glBegin(GL_TRIANGLES);
        glVertex2f( 0.0f,  0.5f); // Top
        glVertex2f(-0.5f, -0.5f); // Left
        glVertex2f( 0.5f, -0.5f); // Right
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangle Rotation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
