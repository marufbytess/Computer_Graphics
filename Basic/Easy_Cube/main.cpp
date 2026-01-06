#include <GL/glut.h>

float angle = 0.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0, 0, -5);
    glRotatef(angle, 1, 1, 0);   // 🔄 Rotation added

    glBegin(GL_QUADS);

    // Front (Red)
    glColor3f(1, 0, 0);
    glVertex3f(-1,-1, 1);
    glVertex3f( 1,-1, 1);
    glVertex3f( 1, 1, 1);
    glVertex3f(-1, 1, 1);

    // Back (Green)
    glColor3f(0, 1, 0);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1, 1,-1);
    glVertex3f( 1, 1,-1);
    glVertex3f( 1,-1,-1);

    // Top (Blue)
    glColor3f(0, 0, 1);
    glVertex3f(-1, 1,-1);
    glVertex3f(-1, 1, 1);
    glVertex3f( 1, 1, 1);
    glVertex3f( 1, 1,-1);

    // Bottom (Yellow)
    glColor3f(1, 1, 0);
    glVertex3f(-1,-1,-1);
    glVertex3f( 1,-1,-1);
    glVertex3f( 1,-1, 1);
    glVertex3f(-1,-1, 1);

    // Right (Cyan)
    glColor3f(0, 1, 1);
    glVertex3f( 1,-1,-1);
    glVertex3f( 1, 1,-1);
    glVertex3f( 1, 1, 1);
    glVertex3f( 1,-1, 1);

    // Left (Magenta)
    glColor3f(1, 0, 1);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1,-1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1,-1);

    glEnd();
    glutSwapBuffers();
}

// 🔄 Timer to update rotation
void timer(int)
{
    angle += 1.0f;               // Increase angle
    glutPostRedisplay();         // Redraw
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating 3D Cube");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);   // 🔄 Start rotation

    glutMainLoop();
    return 0;
}
