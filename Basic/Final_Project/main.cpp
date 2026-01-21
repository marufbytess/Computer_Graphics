#include <GL/glut.h>
#include <cmath>

// ---------------- GLOBALS ----------------
float cloudX = 0.0f;
float turbineAngle = 0.0f;

// ---------------- CLOUD ----------------
void drawCloud(float x, float y)
{
    glColor3f(1, 1, 1);
    for (int k = 0; k < 3; k++) {
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float a = i * 3.1416f / 180;
            glVertex2f(x + k * 5 + cos(a) * 3.5,
                       y + sin(a) * 3.5);
        }
        glEnd();
    }
}

// ---------------- TREE ----------------
void drawTree(float x, float y)
{
    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 2.5, y);
    glVertex2f(x + 2.5, y + 8);
    glVertex2f(x, y + 8);
    glEnd();

    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float a = i * 3.1416f / 180;
        glVertex2f(x + 1.25 + cos(a) * 5,
                   y + 11 + sin(a) * 5);
    }
    glEnd();
}

// ---------------- FOOTBALL ----------------
void drawFootball(float x, float y)
{
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float a = i * 3.1416f / 180;
        glVertex2f(x + cos(a) * 2,
                   y + sin(a) * 2);
    }
    glEnd();
}

// ---------------- WIND TURBINE ----------------
void drawTurbine(float x, float y)
{
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.7, y);
    glVertex2f(x + 0.7, y);
    glVertex2f(x + 0.7, y + 25);
    glVertex2f(x - 0.7, y + 25);
    glEnd();

    glPushMatrix();
    glTranslatef(x, y + 25, 0);
    glRotatef(turbineAngle, 0, 0, 1);

    glBegin(GL_QUADS);
    glVertex2f(0, -1);
    glVertex2f(14, -1);
    glVertex2f(14, 1);
    glVertex2f(0, 1);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-14, -1);
    glVertex2f(0, -1);
    glVertex2f(0, 1);
    glVertex2f(-14, 1);
    glEnd();

    glPopMatrix();
}

// ---------------- HOUSE ----------------
void drawHouse(float x)
{
    glColor3f(0.9f, 0.6f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(x, 25);
    glVertex2f(x + 14, 25);
    glVertex2f(x + 14, 35);
    glVertex2f(x, 35);
    glEnd();

    glColor3f(0.6f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 1, 35);
    glVertex2f(x + 15, 35);
    glVertex2f(x + 7, 43);
    glEnd();

    // Door
    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(x + 6, 25);
    glVertex2f(x + 8, 25);
    glVertex2f(x + 8, 33);
    glVertex2f(x + 6, 33);
    glEnd();

    // Windows
    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(x + 2, 29);
    glVertex2f(x + 4, 29);
    glVertex2f(x + 4, 31);
    glVertex2f(x + 2, 31);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x + 10, 29);
    glVertex2f(x + 12, 29);
    glVertex2f(x + 12, 31);
    glVertex2f(x + 10, 31);
    glEnd();
}
// ---------------- INIT ----------------
void initGL()
{
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 160, 0, 100);   // VERY WIDE FRAME
    glMatrixMode(GL_MODELVIEW);
}

// ---------------- DISPLAY ----------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Ground
    glColor3f(0.2f, 0.7f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(160, 0);
    glVertex2f(160, 25);
    glVertex2f(0, 25);
    glEnd();

    // River
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(0, 5);
    glVertex2f(160, 5);
    glVertex2f(160, 9);
    glVertex2f(0, 9);
    glEnd();

    // Road
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(0, 11);
    glVertex2f(160, 11);
    glVertex2f(160, 16);
    glVertex2f(0, 16);
    glEnd();

    // Road dividers
    glColor3f(1, 1, 1);
    for (int i = 5; i < 160; i += 18) {
        glBegin(GL_QUADS);
        glVertex2f(i, 13.2);
        glVertex2f(i + 7, 13.2);
        glVertex2f(i + 7, 14);
        glVertex2f(i, 14);
        glEnd();
    }

    // Sun
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float a = i * 3.1416f / 180;
        glVertex2f(145 + cos(a) * 6,
                   85 + sin(a) * 6);
    }
    glEnd();

    // Clouds
    drawCloud(15 + cloudX, 80);
    drawCloud(60 + cloudX, 85);
    drawCloud(110 + cloudX, 78);

    // Mountains
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_TRIANGLES);
    glVertex2f(10, 25);
    glVertex2f(40, 75);
    glVertex2f(70, 25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(65, 25);
    glVertex2f(100, 78);
    glVertex2f(135, 25);
    glEnd();

    // Houses
    drawHouse(20);
    drawHouse(45);
    drawHouse(70);
    drawHouse(95);

    // Trees
    drawTree(10, 25);
    drawTree(130, 25);

    // Football
    drawFootball(12, 25);

    // Wind turbine
    drawTurbine(150, 25);

    glFlush();
}

// ---------------- ANIMATION ----------------
void update()
{
    cloudX += 0.004f;
    if (cloudX > 50) cloudX = -50;

    turbineAngle += 0.35f;
    glutPostRedisplay();
}

// ---------------- MAIN ----------------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Wide E-Village Day Scenario");

    initGL();
    glutDisplayFunc(display);
    glutIdleFunc(update);

    glutMainLoop();
    return 0;
}
