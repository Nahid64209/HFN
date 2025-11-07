#include <GL/glut.h>

void display()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // --- Sky ---
    glColor3f(0.53, 0.81, 0.98);
    glBegin(GL_QUADS);
    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();

    // --- Grass ---
    glColor3f(0.0, 0.8, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 0);
    glVertex2f(-1, 0);
    glEnd();

    // --- River
    glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(0.6, -1);   // bottom-left
    glVertex2f(1.0, -1);   // bottom-right
    glVertex2f(1.0, 0.0);  // top-right
    glVertex2f(0.7, 0.0);  // top-left
    glEnd();

    // --- Sun
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(4);
    glBegin(GL_POINTS);
    float cx = 0.7, cy = 0.7; // center
    float r = 0.15;           // radius
    for (float x = -r; x <= r; x += 0.005)
    {
        for (float y = -r; y <= r; y += 0.005)
        {
            if (x * x + y * y <= r * r)  // check inside circle
            {
                glVertex2f(cx + x, cy + y);
            }
        }
    }
    glEnd();

    // --- House body ---
    glColor3f(0.76, 0.60, 0.42);
    glBegin(GL_QUADS);
    glVertex2f(-0.6, -0.4);
    glVertex2f(-0.2, -0.4);
    glVertex2f(-0.2, 0.1);
    glVertex2f(-0.6, 0.1);
    glEnd();

    // --- Roof ---
    glColor3f(0.8, 0.1, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6, 0.1);
    glVertex2f(-0.2, 0.1);
    glVertex2f(-0.4, 0.35);
    glEnd();

    // --- Door ---
    glColor3f(0.4, 0.2, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.43, -0.4);
    glVertex2f(-0.37, -0.4);
    glVertex2f(-0.37, -0.1);
    glVertex2f(-0.43, -0.1);
    glEnd();

    // --- Tree trunk ---
    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(0.3, -0.4);
    glVertex2f(0.4, -0.4);
    glVertex2f(0.4, 0.0);
    glVertex2f(0.3, 0.0);
    glEnd();

    // --- Tree leaves ---
    glColor3f(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.35, 0.4);
    glVertex2f(0.15, 0.0);
    glVertex2f(0.55, 0.0);
    glEnd();

    // --- Birds ---
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-0.8, 0.7); glVertex2f(-0.75, 0.75);
    glVertex2f(-0.8, 0.7); glVertex2f(-0.85, 0.75);
    glVertex2f(-0.6, 0.8); glVertex2f(-0.55, 0.85);
    glVertex2f(-0.6, 0.8); glVertex2f(-0.65, 0.85);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 640);
    glutCreateWindow("OpenGL House Scene with Circular Sun and River");
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutMainLoop();
    return 0;
}
// CHANGE KORLAM