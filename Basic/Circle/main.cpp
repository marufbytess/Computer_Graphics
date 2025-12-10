#include <GL/glut.h>
#include <math.h>

#define PI 3.1416

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    float radius = 0.5f;     // circle radius
    int   segments = 100;    // more segments = smoother circle

    glBegin(GL_LINE_LOOP);   // outline of circle
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * PI * (float)i / (float)segments; // angle

        float x = radius * cosf(theta); // x = r cos θ
        float y = radius * sinf(theta); // y = r sin θ

        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

void init(void)
{
    // background color: black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // simple 2D projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle with cos/sin");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
