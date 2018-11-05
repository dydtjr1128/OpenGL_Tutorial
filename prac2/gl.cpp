#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
float DD = 0.0;
void myDisplay() {	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_LINES);
	glVertex3f(1.0 - DD, 1.0, 0.0);
	glVertex3f(-1.0 + DD, -1.0, 0.0);
	glVertex3f(-1.0 , 1.0 - DD, 0.0);
	glVertex3f(1.0 , -1.0 + DD, 0.0);
	glEnd();
	glFlush();
}

void myTimer() {
	DD += 0.001;
	if (DD > 2.0f)
		DD = 0;
	glutPostRedisplay();
}

int main() {
	glutInitDisplayMode(GLUT_RGB);	
	glutCreateWindow("윈도우창");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(myDisplay);
	glutIdleFunc(myTimer);
	glutMainLoop();
}