#include <GL/glut.h>
// Contoh Class dan penggunannya
class Colors {
public:
    float red[3] = {1.0, 0.0, 0.0};
    float green[3] = {0.18, 0.49, 0.23};
    float blue[3] = {0.08, 0.39, 0.75};
    float pink[3] = {1.0, 0.4, 0.6};
    float purple[3] = {0.39, 0.34, 0.82};
};
Colors colors;

float xMin = -3, xMax = 3, yMin = -3, yMax = 3;

void Objek() {
    glColor3fv(colors.blue);
    glutSolidCube(1);
    glColor3fv(colors.green);
    glutWireCube(2);
    glColor3fv(colors.red);
    glutWireCube(3);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(45, 1, 1, 1);
    Objek();
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
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("SOAL A.5 - UTS GRAFKOM 2023 - 2206050");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}