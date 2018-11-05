#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
float xx = 300;
float yy = 300;
void MyDisplay() {
	glViewport(0, 0, xx, yy);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(TopLeftX /xx, (yy - TopLeftY) / yy, 0.0);
	glVertex3f(TopLeftX / xx, (yy - BottomRightY) / yy, 0.0);
	glVertex3f(BottomRightX / xx, (yy - BottomRightY) / yy, 0.0);
	glVertex3f(BottomRightX / xx, (yy - TopLeftY) / yy, 0.0);
	glEnd();
	glFlush();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		TopLeftX = X;
		TopLeftY = Y;
	}
}

void MyMouseMove(GLint X, GLint Y) {
	BottomRightX = X;
	BottomRightY = Y;
	glutPostRedisplay();
	printf("%d",BottomRightX);
}
void MyReshape(int NewWidth, int NewHeight) {
	xx = NewWidth;
	yy = NewHeight;
	glViewport(0, 0, NewWidth, NewHeight);	
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Drawing Example");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);

	glutMainLoop();
	return 0;
}
