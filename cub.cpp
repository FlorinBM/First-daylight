#include <iostream>
#include <GL/glut.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

GLfloat unghi;
VideoCapture video(0);
Mat frame;

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
	glRotatef(unghi, 0, 1, 0);
	glutWireTeapot(2);
	glutSwapBuffers();
}

void timer(int value)
{
	unghi = unghi + 1;
	if (unghi > 360)
		unghi = 0;

	video >> frame;
		imshow("gica", frame);
		waitKey(1);

	glutPostRedisplay();
	glutTimerFunc(2, timer, value + 1);
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
	glutTimerFunc(2, timer, 0);

	glutMainLoop();
	return 0;
}