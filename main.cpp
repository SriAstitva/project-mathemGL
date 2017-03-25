#include <gl/freeglut.h>
#include <iostream>
#include <cmath>

#define PRECISION 0.0001
#define ZOOM 0.01
#define PI 3.14159265359

double scaleFactorX = 1 /(4 * PI), scaleFactorY = 0.25;

using namespace std;

void plotSine() {
    double x = -4*PI, y;
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
        glColor3f(0.5, 0.5, 0.5);
        glVertex2d(-1, 0);
        glVertex2d(1, 0);

        glVertex2d(0, 1);
        glVertex2d(0, -1);
	glEnd();

	glBegin(GL_POINTS);
        glColor3f(1, 1, 1);
        do {
            y = sin(x);
            x = x + PRECISION;

            glVertex2d(x * scaleFactorX, y * scaleFactorY);
		} while(x<=4*PI);
	glEnd();
	glFlush();

	scaleFactorX += ZOOM;

	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sine Function Plot");
	glutDisplayFunc(plotSine);
	glutMainLoop();
	return 0;
}
