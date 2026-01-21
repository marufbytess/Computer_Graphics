#include <windows.h>
#include <GL/glut.h>
#include <cmath>

// animation variables
float cloudX = 0;
float birdX = -20;
float cubeAngle = 0.0f;

bool dayMode = true;
bool birdsActive = false;

// initialization
void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// background
void setBackground()
{
    if(dayMode)
        glClearColor(0.4, 0.7, 1.0, 1.0);
    else
        glClearColor(0.05, 0.05, 0.2, 1.0);
}

// circle utility
void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        float angle = i * 3.1416f / 180;
        glVertex2f(cx + cos(angle)*r, cy + sin(angle)*r);
    }
    glEnd();
}

// cloud
void drawCloud(float x, float y)
{
    glColor3f(1,1,1);
    drawCircle(x, y, 3);
    drawCircle(x+4, y+1, 3);
    drawCircle(x+8, y, 3);
}

// tree
void drawTree(int x)
{
    // trunk
    glColor3f(0.4,0.2,0);
    glBegin(GL_QUADS);
        glVertex2f(x,25);
        glVertex2f(x+2,25);
        glVertex2f(x+2,33);
        glVertex2f(x,33);
    glEnd();

    // leaves
    glColor3f(0,0.6,0);
    drawCircle(x+1, 36, 4);
}

// house
void drawHouse(int x)
{
    glColor3f(0.8, 0.5, 0.3);
    glBegin(GL_QUADS);
        glVertex2f(x,25);
        glVertex2f(x+15,25);
        glVertex2f(x+15,38);
        glVertex2f(x,38);
    glEnd();

    glColor3f(0.6,0.1,0.1);
    glBegin(GL_TRIANGLES);
        glVertex2f(x-2,38);
        glVertex2f(x+17,38);
        glVertex2f(x+7.5,48);
    glEnd();

    glColor3f(0.3,0.1,0);
    glBegin(GL_QUADS);
        glVertex2f(x+6,25);
        glVertex2f(x+9,25);
        glVertex2f(x+9,33);
        glVertex2f(x+6,33);
    glEnd();

    glColor3f(0.7,0.9,1);
    glBegin(GL_QUADS);
        glVertex2f(x+2,30);
        glVertex2f(x+5,30);
        glVertex2f(x+5,34);
        glVertex2f(x+2,34);

        glVertex2f(x+10,30);
        glVertex2f(x+13,30);
        glVertex2f(x+13,34);
        glVertex2f(x+10,34);
    glEnd();

    drawTree(x-12);
    drawTree(x+22);
}

// bird
void drawBird(float x, float y)
{
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x+2, y+1);
        glVertex2f(x+2, y+1);
        glVertex2f(x+4, y);
    glEnd();
}

// bird group
void drawBirdGroup()
{
    drawBird(birdX, 80);
    drawBird(birdX+6, 82);
    drawBird(birdX+12, 79);
    drawBird(birdX+18, 83);
}

// rotating cube
void drawCubeOnTree(float x, float y, float size)
{
    float d = size * 0.3f;

    glPushMatrix();

    glTranslatef(x + size/2, y + size/2, 0);
    glRotatef(cubeAngle, 0, 0, 1);
    glTranslatef(-(x + size/2), -(y + size/2), 0);

    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x+size, y);
        glVertex2f(x+size, y+size);
        glVertex2f(x, y+size);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_QUADS);
        glVertex2f(x, y+size);
        glVertex2f(x+size, y+size);
        glVertex2f(x+size+d, y+size+d);
        glVertex2f(x+d, y+size+d);
    glEnd();

    glColor3f(0,1,1);
    glBegin(GL_QUADS);
        glVertex2f(x+size, y);
        glVertex2f(x+size+d, y+d);
        glVertex2f(x+size+d, y+size+d);
        glVertex2f(x+size, y+size);
    glEnd();

    glPopMatrix();
}

// display
void display()
{
    setBackground();
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // ground
    glColor3f(0.2,0.6,0.2);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(100,0);
        glVertex2f(100,25);
        glVertex2f(0,25);
    glEnd();

    // road
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
        glVertex2f(0,10);
        glVertex2f(100,10);
        glVertex2f(100,15);
        glVertex2f(0,15);
    glEnd();

    // road lines
    glColor3f(1,1,1);
    for(float i=0;i<100;i+=8)
    {
        glBegin(GL_QUADS);
            glVertex2f(i,12);
            glVertex2f(i+4,12);
            glVertex2f(i+4,13);
            glVertex2f(i,13);
        glEnd();
    }

    // sun / moon
    glColor3f(dayMode ? 1:1, dayMode ? 1:1, dayMode ? 0:1);
    drawCircle(85,80,6);

    // clouds
    drawCloud(cloudX,85);
    drawCloud(cloudX+30,88);

    // houses
    drawHouse(15);
    drawHouse(60);

    // birds
    if(birdsActive)
        drawBirdGroup();

    // cube on right tree
    drawCubeOnTree(83, 36, 4);

    glFlush();
}

// keyboard
void keyboard(unsigned char key, int, int)
{
    if(key=='b' || key=='B') birdsActive = true;
    if(key=='s' || key=='S') birdsActive = false;
}

// mouse
void mouse(int button, int state, int, int)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        dayMode = !dayMode;
}

// animation
void idle()
{
    cloudX += 0.003f;
    if(cloudX > 100) cloudX = -20;

    if(birdsActive)
    {
        birdX += 0.05f;
        if(birdX > 100) birdX = -20;
    }

    cubeAngle += 0.3f;
    if(cubeAngle > 360) cubeAngle = 0;

    glutPostRedisplay();
}

// main
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(900,600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Village Scene with Rotating Cube");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);

    glutMainLoop();
}
