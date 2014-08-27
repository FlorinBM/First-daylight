#include <iostream>
#include <GL/glut.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <unistd.h>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

GLfloat unghi;
VideoCapture video(0);
Mat frame;

CascadeClassifier classifier("haarcascade_frontalface_alt_tree.xml");

vector<Rect> detect;

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

	int pid = fork();

	if (pid > 0)	
	{
		glutMainLoop();
	}
	else
	{
		while (true)
		{
			video >> frame;
			resize(frame, frame, Size(0, 0), 0.5, 0.5);
			cvtColor(frame, frame, CV_BGR2GRAY);
			equalizeHist(frame, frame);
			classifier.detectMultiScale(frame, detect, 1.1, 3, 0, Size(50, 50));
			for (unsigned int i = 0; i < detect.size(); i++)
			{
				rectangle(frame, detect[i], Scalar(0, 255, 0));
			}
			imshow("gica", frame);
			waitKey(1);
		}
	}

	
	return 0;
}