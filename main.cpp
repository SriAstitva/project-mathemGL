#include <gl/freeglut.h>

void display() {
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
		glColor3f(1.0, 0.2, 0.7);
		glVertex2f(0.75, 0.75);
		glColor3f(1.0, 0.3, 0.7);
		glVertex2f(0.75, -0.75);
		glColor3f(1.0, 0.6, 0.7);
		glVertex2f(-0.75, -0.75);
		glColor3f(1.0, 0.9, 0.7);
		glVertex2f(-0.75, 0.75);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Setup Test");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
