#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <stdio.h>
int sx, sy, ex, ey;
float width=300, height=300;
void myDisplay() {
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glColor3f(0.7, 0.7, 0.2);
	glBegin(GL_POLYGON);
		glVertex3f((GLfloat)sx / width, (GLfloat)(height - sy) / height, 0.0);
		glVertex3f((GLfloat)ex / width, (GLfloat)(height - sy) / height, 0.0);
		glVertex3f((GLfloat)ex / width, (GLfloat)(height - ey) / height, 0.0);
		glVertex3f((GLfloat)sx / width, (GLfloat)(height - ey) / height, 0.0);
	glEnd();
	glutSwapBuffers();
}
void myMouse(GLint button, GLint state, GLint x, GLint y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		sx = x;
		sy = y;
	}
}
void myMotion(GLint x, GLint y) {
	ex = x;
	ey = y;

	glutPostRedisplay();
}
void myReshape(GLint w, GLint h) {
	width = w;
	height = h;
}
int main() {
	
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(300, 300);
	glutCreateWindow("gl EX");
	glClearColor(1.0, 1.0, 1.0, 1.0);	

	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutMotionFunc(myMotion);
	glutReshapeFunc(myReshape);
	glutMainLoop();
}