#include <iostream>
#include <GL/glut.h>

using namespace std;

void Initialise(void)
{
	glClearColor(1, 1, 1, 1);
}

void reshape(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	gluPerspective(60, (GLfloat) width / (GLfloat) height, 0.1, 600000);
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glColor3f(0, 0, 0);
	glTranslatef(0, 0, 0);
	glScalef(3, 2, 1);
	glRotatef(30, 1, 0, 0);
	glutWireTeapot(2);
	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Cubul");

	Initialise();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}