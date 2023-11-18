#include <GL/glut.h>
// Output hasil clipping Garis Dengan Algoritma Cohen-Sutherland

class Colors {
public:
    float red[3] = {1.0, 0.0, 0.0};
    float green[3] = {0.18, 0.49, 0.23};
    float blue[3] = {0.08, 0.39, 0.75};
    float pink[3] = {1.0, 0.4, 0.6};
    float purple[3] = {0.39, 0.34, 0.82};
};
Colors colors;

float xMin = -5, xMax = 5, yMin = -5, yMax = 5;

void viewPort() {
    glColor3fv(colors.red);
    glLineWidth(5.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xMin, yMin);
    glVertex2d(xMax, yMin);
    glVertex2d(xMax, yMax);
    glVertex2d(xMin, yMax);
    glEnd();
}
void lines() {
    glLineWidth(3);
    glBegin(GL_LINES);
    // GARIS A' B'
    glColor3fv(colors.green);
    // Titik A'
    glVertex2f(-3.571, -5);
    // Titik B'
    glVertex2f(3.571, 5);

    // GARIS C D
    glColor3fv(colors.blue);
    // Titik C
    glVertex2f(-3, 3);
    // Titik D
    glVertex2f(-2, 3);

    // GARIS E' F
    glColor3fv(colors.purple);
    // Titik E
    glVertex2f(4, -4);
    // Titik F
    glVertex2f(5, -2.5);

    // GARIS G' H'
    glColor3fv(colors.pink);
    // Titik G'
    glVertex2f(-3.5, 5);
    // Titik H'
    glVertex2f(1.5, -5);

    /*
    Garis IJ Tidak Dibuat
    Karena Garis IJ Fully Invicible
    */
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    viewPort();
    lines();
    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(xMin, yMax, yMin, yMax);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0, 0, 0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("SOAL B.2 - UTS GRAFKOM 2023 - 2206050");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}