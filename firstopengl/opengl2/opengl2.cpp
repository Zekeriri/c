#define FREEGLUT_STATIC
#include <GL/freeglut.h>
#include<math.h>
void define_to_OpenGL();
///////////////////////////////////
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	// Task 2
	int w = 600;
	int h = 400;
	int x = 50;
	int y = 50;
	glutInitWindowSize(w, h);
	glutInitWindowPosition(x, y);
	glutCreateWindow("Graphics Primitives");
	glutDisplayFunc(define_to_OpenGL);
	glutMainLoop();
}
///////////////////////////////////
void define_to_OpenGL()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	// The stuff to appear on screen goes here
	// Task 2
	// glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int L = -100;
	int R = 500;
	int B = -200;
	int T = -200;
	gluOrtho2D(L, R, B, T);
	// Task 3
	glLineWidth(1.0);
	glColor3f(0 , 0 , 0 );
	glBegin(GL_LINES);
	glVertex2f(0 , 0 ); // start location
	glVertex2f(450 , 0 ); // end location
	glEnd();
	// Task 4
	glPointSize(100);
	glColor3f(255 , 255 , 0 );
	glBegin(GL_POINTS);
	glVertex2f(0 , 0 );
	glEnd();
	// Task 5
	int i;
	float x, y;
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	for (i = 0; i < 361; i = i + 5)
	{
		x = (float)i;
		y = 100.0 * sin(i * (6.284 / 360.0));
		glVertex2f(x, y);
	}
	glEnd();

	// Tasks 6, 7 and 8
	glBegin(GL_TRIANGLES);
	glVertex2f(-50 , 50 );
	glVertex2f(-50 , 0 );
	glVertex2f(0 , 0 );
	glEnd();
	glFlush();
}