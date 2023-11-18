#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>

GLfloat light_diffuse[] = {1, 1, 1, 1};
GLfloat light_diffuse2[] = {0.117, 0.156, 0.615, 1};

GLfloat light_position[] = {-3.5f, 3.0f, -8.0f, 1.0f};
GLfloat light_position2[] = {3.5f, 3.0f, 8.0f, 1.0f};

struct vec3
{
    float x, y, z;
};

class dots
{
private:
    int numOfPoint[3] = {5, 10, 20};

public:
    // Huruf I
    GLfloat I[5][3] = {{}, {-6, 1.5}, {-5, 2.5}, {-5, -1.5}, {-6, -2.5}};

    // Huruf T
    GLfloat T[10][3] = {{}, {-4, 2.5}, {0, 2.5}, {-1, 1.5}, {-1.5, 1.5}, {-1.5, -1.5}, {-2, -2.5}, {-2.5, -1.5}, {-2.5, 1.5}, {-3, 1.5}};

    // Huruf G
    GLfloat G[20][3] = {{}, {5, 2.5}, {2, 2.5}, {1, 1.5}, {1, -1.5}, {2, -2.5}, {5, -2.5}, {6, -1.5}, {6, -0.5}, {5, 0.5}, {3, 0.5}, {4, -0.5}, {4.5, -0.5}, {5, -1}, {4.5, -1.5}, {2.5, -1.5}, {2, -1}, {2, 1}, {2.5, 1.5}, {6, 1.5}};

    void setZ(GLfloat z)
    {
        for (int i = 0; i < 20; ++i)
        {
            if (i < 5)
            {
                I[i][2] = z;
            }
            if (i < 10)
            {
                T[i][2] = z;
            }
            G[i][2] = z;
        }
    }
};

vec3 normalCalculate(GLfloat dots1[3], GLfloat dots2[3], GLfloat dots3[3])
{
    vec3 U = {dots2[0] - dots1[0], dots2[1] - dots1[1], dots2[3] - dots1[3]};
    vec3 V = {dots3[0] - dots1[0], dots3[1] - dots1[1], dots3[3] - dots1[3]};
    vec3 normal = {
        U.y * V.z - U.z * V.y,
        U.z * V.x - U.x * V.z,
        U.x * V.y - U.y * V.x};
    return normal;
}

vec3 normalize(const vec3 coordinate)
{
    float divider = sqrt(pow(coordinate.x, 2) + pow(coordinate.y, 2) + pow(coordinate.z, 2));
    vec3 newCoordinate = {
        coordinate.x / divider,
        coordinate.y / divider,
        coordinate.z / divider};
    return newCoordinate;
}

void setNormalizedNormal(GLfloat dots1[3], GLfloat dots2[3], GLfloat dots3[3])
{
    vec3 normal = normalCalculate(dots1, dots2, dots3);
    vec3 normalized_normal = normalize(normal);
    glNormal3f(normalized_normal.x, normalized_normal.y, normalized_normal.z);
}

void objectSides(GLfloat p1[3], GLfloat p2[3], GLfloat p3[3], GLfloat p4[3])
{
    setNormalizedNormal(p1, p2, p3);
    glVertex3fv(p1);
    glVertex3fv(p2);
    glVertex3fv(p3);
    glVertex3fv(p4);
}

void frontAndRear_I(GLfloat points[5][3])
{
    setNormalizedNormal(points[1], points[2], points[3]);
    for (int i = 1; i <= 4; i++)
    {
        glVertex3fv(points[i]);
    }
}
void frontAndRear_T(GLfloat points[10][3])
{
    glBegin(GL_POLYGON);
    setNormalizedNormal(points[1], points[2], points[3]);
    glVertex3fv(points[1]);
    glVertex3fv(points[2]);
    glVertex3fv(points[3]);
    glVertex3fv(points[8]);
    glVertex3fv(points[9]);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3fv(points[4]);
    glVertex3fv(points[5]);
    glVertex3fv(points[6]);
    glVertex3fv(points[7]);
    glVertex3fv(points[8]);
    glEnd();
}
void frontAndRear_G(GLfloat points[20][3])
{
    glBegin(GL_POLYGON);
    setNormalizedNormal(points[1], points[2], points[3]);
    glBegin(GL_POLYGON);
    setNormalizedNormal(points[1], points[2], points[3]);
    glVertex3fv(points[1]);
    glVertex3fv(points[2]);
    glVertex3fv(points[3]);
    glVertex3fv(points[18]);
    glVertex3fv(points[19]);
    glEnd();
    glBegin(GL_POLYGON);
    setNormalizedNormal(points[1], points[2], points[3]);
    glVertex3fv(points[3]);
    glVertex3fv(points[4]);
    glVertex3fv(points[16]);
    glVertex3fv(points[17]);
    glVertex3fv(points[18]);
    glEnd();
    glBegin(GL_POLYGON);
    setNormalizedNormal(points[1], points[2], points[3]);
    glVertex3fv(points[4]);
    glVertex3fv(points[15]);
    glVertex3fv(points[16]);
    glEnd();
    glBegin(GL_POLYGON);
    setNormalizedNormal(points[1], points[2], points[3]);
    glVertex3fv(points[4]);
    glVertex3fv(points[5]);
    glVertex3fv(points[6]);
    glVertex3fv(points[7]);
    glVertex3fv(points[14]);
    glVertex3fv(points[15]);
    glEnd();
    glBegin(GL_POLYGON);
    setNormalizedNormal(points[1], points[2], points[3]);
    glVertex3fv(points[7]);
    glVertex3fv(points[8]);
    glVertex3fv(points[12]);
    glVertex3fv(points[13]);
    glVertex3fv(points[14]);
    glEnd();
    glBegin(GL_POLYGON);
    setNormalizedNormal(points[1], points[2], points[3]);
    glVertex3fv(points[8]);
    glVertex3fv(points[9]);
    glVertex3fv(points[10]);
    glVertex3fv(points[11]);
    glVertex3fv(points[12]);
    glEnd();
    glEnd();
}

void sidesDrawer(int endPoint, GLfloat front_points[][3], GLfloat rear_points[][3])
{
    for (int i = 1; i < endPoint; i++)
    {
        objectSides(front_points[i], front_points[i + 1], rear_points[i + 1], rear_points[i]);
    }
    objectSides(front_points[endPoint], front_points[1], rear_points[1], rear_points[endPoint]);
}

void ITG(void)
{
    dots front;
    dots rear;
    front.setZ(0.5);
    rear.setZ(-0.5);

    // HURUF I
    glBegin(GL_QUADS);
    // I depan
    frontAndRear_I(front.I);
    // I belakang
    frontAndRear_I(rear.I);
    // sisi-sisi I
    sidesDrawer(4, front.I, rear.I);
    glEnd();

    // HURUF T
    // T Depan
    frontAndRear_T(front.T);
    // T Belakang
    frontAndRear_T(rear.T);
    // sisi-sisi T
    glBegin(GL_QUADS);
    sidesDrawer(9, front.T, rear.T);
    glEnd();

    // HURUF G
    // G Depan
    frontAndRear_G(front.G);
    // G Belakang
    frontAndRear_G(rear.G);
    // Sisi-sisi G
    glBegin(GL_QUADS);
    sidesDrawer(19, front.G, rear.G);
    glEnd();
}

void display()
{
    glRotatef(0.4, 0, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.003, 0.345, 0.313, 1.0);
    ITG();
    glutSwapBuffers();
    glutPostRedisplay();
}

void init()
{
    // pencahayaan
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); // Konfigurasi Cahaya ke-1
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT1); // Konfigurasi Cahaya ke-2
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse2);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
    // Buffer
    glEnable(GL_DEPTH_TEST);
    // setup projection
    glMatrixMode(GL_PROJECTION);
    glOrtho(-10, 10, -5, 5, -7, 7);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 350);
    glutCreateWindow("SOAL B.4 - UTS GRAFKOM 2023 - 2206050");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}