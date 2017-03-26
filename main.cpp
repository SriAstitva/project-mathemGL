#include <gl/freeglut.h>
#include <iostream>
#include <cmath>

#define PRECISION 0.0001
#define ZOOM 0.01
#define PI 3.14159265359
#define MULT_FACTOR 0.1

double scaleFactorX = 1 /(4 * PI), scaleFactorY = 0.25;
int clickPosX, clickPosY;
float t = 0;

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
        for(int i=0 ; i<100 ; i++){
            for(int j=0 ; j<100 ; j++){
                if (i == j ){
                   glVertex2d(i * scaleFactorX, j * scaleFactorY);
                   glVertex2d(-i * scaleFactorX, -j * scaleFactorY);
                }
            }
        }
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
	scaleFactorY += ZOOM;

	glutPostRedisplay();
}

void plotCos() {
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
            y = cos(x);
            x = x + PRECISION;
            glVertex2d(x * scaleFactorX, y * scaleFactorY);
		} while(x<=4*PI);
	glEnd();
	glFlush();

	scaleFactorX += ZOOM;
	scaleFactorY += ZOOM;

	glutPostRedisplay();
}

void plotTan() {
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
            y = tan(x);
            x = x + PRECISION;

            glVertex2d(x * scaleFactorX, y * scaleFactorY);
		} while(x<=4*PI);
	glEnd();
	glFlush();

	scaleFactorX += ZOOM;
	scaleFactorY += ZOOM;

	glutPostRedisplay();
}

/*void getMouseCoordinates(int button, int state, int x, int y) {
    clickPosX = x;
    clickPosY = y;
    cout<<"x:"<<x<<" y:"<<y;
}*/

void plotEllipse(){
    glClearColor(1,1,1,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	float x,y,px,py,pt;
        glBegin(GL_LINES);

            x = 8*sin(t);
            y = 3*cos(t);
            glColor3f(1.0, 0, 0);
            glVertex2f(-6 *MULT_FACTOR,0*MULT_FACTOR);
            glVertex2f(x*MULT_FACTOR,y*MULT_FACTOR);
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(x*MULT_FACTOR,y*MULT_FACTOR);
            glVertex2f(6*MULT_FACTOR,0*MULT_FACTOR);
        glEnd();

        glPointSize(4);
        glBegin(GL_POINTS);
            glColor3f(0.0, 0.0, 1.0);
            glVertex2f(6 *MULT_FACTOR,0*MULT_FACTOR);
            glVertex2f(-6 *MULT_FACTOR,0*MULT_FACTOR);
            glColor3f(0, 0, 0);
            glVertex2f(x*MULT_FACTOR,y*MULT_FACTOR);
        glEnd();

       glPointSize(2);
       glBegin(GL_POINTS);
            pt = 0;
            while(pt<=t){
              px = 8*sin(pt);
              py = 3*cos(pt);
              glColor3f(0.5, 0.5, 0.5);
              glVertex2f(px*MULT_FACTOR,py*MULT_FACTOR);
              pt = pt + PI / 5000;
            }
       glEnd();


        if(t < 2*PI) {
            t = t + PI / 5000;
            glutPostRedisplay();
        }

	glFlush();
}

int main(int argc, char** argv) {
    int type;
	glutInit(&argc, argv);

    cout<< "Select option : \n 1) SIN() \n 2) COS() \n 3) TAN() \n 4) Ellipse \n" ;
    cin >> type;

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(600, 100);
	glutCreateWindow("Function Plot");

	switch(type) {
        case 1 :
        	glutDisplayFunc(plotSine);
			cout<<"lim (x->0) (sin x / x ) = 1"<<endl;
            break ;
        case 2 :
        	glutDisplayFunc(plotCos);
          	break ;
        case 3 :
        	glutDisplayFunc(plotTan);
          	break ;
        case 4 :
        	glutDisplayFunc(plotEllipse);
          	break ;
   	}
//    glutMouseFunc(getMouseCoordinates);
	glutMainLoop();
	return 0;
}
