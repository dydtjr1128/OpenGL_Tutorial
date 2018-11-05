#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <stdio.h>
float day, time, year;
void myd() {
	glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(0, 0, 300, 300);
	
	glColor3f(0.9, 0.1, 0.1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	gluLookAt(0.0, 0.7, 0.1,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
	glPushMatrix();
		glRotatef((GLfloat)year, 0.0, 0.1, 0.0);
		glutWireSphere(0.25, 30, 10);//еб╬Г
	glPopMatrix();
	glPushMatrix();
		glRotatef((GLfloat)day, 0.0, 0.1, 0.0);
		glTranslatef(0.5, 0.0, 0.0);
		glPushMatrix();
			glRotatef((GLfloat)time, 0.0, 0.1, 0.0);
			glColor3f(0.2, 0.2, 0.5);
			glutWireSphere(0.1, 10, 5);
		glPopMatrix();
		glPushMatrix();
			glRotatef((GLfloat)day, 0.1, 0.1, 0.0);
			glTranslatef(-0.15, 0.15, 0.0);
			glRotatef((GLfloat)time, 0.1, 0.1, 0.0);
			glColor3f(0.1, 0.1, 0.1);
			glutWireSphere(0.05, 10, 5);
		glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
	//glFlush();
}
void mt(int val) {
	day += 3;
	year += 0.7;
	time += 1;
	glutTimerFunc(20, mt, 1);
	glutPostRedisplay();
}
void mykey(unsigned char key, int x, int y) {
	if (key == 'y')
		year+=5.0;
	if (key == 'd') {
		day += 5.0;
		year += 0.7;
	}
	if (key == 't') {
		time += 1.0;
		day += 5;
	}
	if (key == 'r') {
		glutTimerFunc(1,mt,1);
	}
	printf("%f\n", day);
	glutPostRedisplay();
}
void myreshape(int w, int h) {
	printf("%d %d\n",w,h);
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0,w, h);
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("my title");
	glViewport(0, 0, 300, 300);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -30.0, 30.0);
	
	glutDisplayFunc(myd);
	glutReshapeFunc(myreshape);
	glutKeyboardFunc(mykey);
	
	glutMainLoop();
	return 0;
}